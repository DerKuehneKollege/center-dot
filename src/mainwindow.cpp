#include "mainwindow.h"

const QString MainWindow::SETTINGS_FILE_NAME = "centerdot.ini";
const int     MainWindow::DEFAULT_CROSSHAIR_SIZE = 5;
const QColor  MainWindow::DEFAULT_CONTOUR_COLOR = QColor(Qt::black);
const QColor  MainWindow::DEFAULT_FILL_COLOR = QColor(Qt::white);


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // set window properties
    setWindowTitle(tr("Center Dot"));

    // load icon
    applicationIcon = new QIcon(":/icons/centerdot.ico");
    setWindowIcon(*applicationIcon);

    // set window flags
    // - FramelessWindowHint for window without border and title bar
    // - Tool for window without taskbar item
    // - WindowStaysOnTopHint for the window to stay on top
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);

    // set window size to given value
    setCrosshairSize(DEFAULT_CROSSHAIR_SIZE);

    // draw no background, keep window transparent, background will be drawn
    setAutoFillBackground(false);
    setAttribute(Qt::WA_TranslucentBackground);

    // set settings file name and try to load settings file if any
    settingsFileName = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/" + SETTINGS_FILE_NAME;
    loadSettings();

    // save settings on close
    connect(QApplication::instance(), SIGNAL(aboutToQuit()), this, SLOT(saveSettings()));

    // prepare keyboard hook
    WinKeyboardHook *winKeyboardHook = WinKeyboardHook::getInstance();
    if (!winKeyboardHook->connect()) {
        QMessageBox::warning(this, tr("Warning"), tr("Failed to establish hook to keyboard."));
    }
    connect(winKeyboardHook, SIGNAL(keyPressed(DWORD)), this, SLOT(handlePressedKey(DWORD)));

    settingsDialog = nullptr;

    // setup actions
    createActions();

    // setup systray
    createSystrayIcon();

    // show message on program start informing the user
    systrayIcon->showMessage(tr("Center Dot"), tr("Center dot was started and is showing the additional crosshair."));
}

MainWindow::~MainWindow()
{
}

void MainWindow::paintEvent(QPaintEvent *)
{
    // paint window by drawing a rectangle with black border and white fill
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(currentSettings.contourColor); // TODO dynamic contour color
    painter.setBrush(currentSettings.fillColor); // TODO dynamic filling color
    painter.drawEllipse(0, 0, width(), height());
}

void MainWindow::loadSettings()
{
    qDebug() << "Trying to load program settings from" << settingsFileName;

    QSettings settings(settingsFileName, QSettings::IniFormat, this);

    // read window position
    bool xIsInt = false;
    bool yIsInt = false;

    int x = settings.value("x", -1).toInt(&xIsInt);
    int y = settings.value("y", -1).toInt(&yIsInt);

    if (!xIsInt || !yIsInt || x < 0 || y < 0) {
        qDebug() << "No windows position found, using default";
        resetDot();
    } else {
        qDebug() << "Windows position found: (x y) =" << x << y;
        move(x, y);
    }
    currentSettings.xPosition = pos().x();
    currentSettings.yPosition = pos().y();

    // read crosshair size
    bool crosshairSizeIsInt = false;
    int crosshairSizeRead = settings.value("size", DEFAULT_CROSSHAIR_SIZE).toInt(&crosshairSizeIsInt);
    if (!crosshairSizeIsInt || crosshairSizeRead < 3 || crosshairSizeRead > 20) {
        crosshairSizeRead = DEFAULT_CROSSHAIR_SIZE;
    }
    currentSettings.crosshairSize = crosshairSizeRead;
    setCrosshairSize(crosshairSizeRead);

    // read contour color
    QString contourColorRead = settings.value("contourColor", DEFAULT_CONTOUR_COLOR.name()).toString();
    if (!QColor::isValidColor(contourColorRead)) {
        contourColorRead = DEFAULT_CONTOUR_COLOR.name();
    }
    currentSettings.contourColor = QColor(contourColorRead);

    // read fill color
    QString fillColorRead = settings.value("fillColor", DEFAULT_FILL_COLOR.name()).toString();
    if (!QColor::isValidColor(fillColorRead)) {
        fillColorRead = DEFAULT_FILL_COLOR.name();
    }
    currentSettings.fillColor = QColor(fillColorRead);
}

void MainWindow::saveSettings()
{
    QSettings settings(settingsFileName, QSettings::IniFormat, this);

    // window position
    settings.setValue("x", pos().x());
    settings.setValue("y", pos().y());

    // crosshair size
    settings.setValue("size", currentSettings.crosshairSize);

    // colors
    settings.setValue("contourColor", currentSettings.contourColor.name(QColor::HexArgb));
    settings.setValue("fillColor", currentSettings.fillColor.name(QColor::HexArgb));

    settings.sync();

    // log error or success
    if (settings.status() != QSettings::NoError) {
        qWarning() << "Error saving the settings, error code:" << settings.status();
    } else {
        qDebug() << "Settings saved";
    }
}

void MainWindow::updatedSettings()
{
    currentSettings = settingsDialog->getSettingsData();

    QPoint newPoint(currentSettings.xPosition, currentSettings.yPosition);
    setCrosshairPosition(newPoint);

    QPoint crosshairPos = getCrosshairPosition();
    setCrosshairSize(currentSettings.crosshairSize);
    setCrosshairPosition(crosshairPos);

    showMinimized();
    showNormal();

    qDebug() << "Updated settings";
}

void MainWindow::handlePressedArrowKey(DWORD pressedKey)
{
    switch (pressedKey) {
        case VK_UP:
            moveNorth();
            break;

        case VK_DOWN:
            moveSouth();
            break;

        case VK_LEFT:
            moveWest();
            break;

        case VK_RIGHT:
            moveEast();
            break;

        case VK_RETURN:
            // stop adjusting crosshair when enter key is pressed
            adjustDotAction->setChecked(false);
            break;
    }
}

void MainWindow::handlePressedKey(DWORD pressedKey)
{
    switch (pressedKey) {
        // Ctrl+H pressed?
        case 0x48: // H key
            // TODO Move to own function CtrlPressed in WinKeyboardHook
            if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
                toggleWindowVisibility();
            }
            break;
    }
}

void MainWindow::toggleWindowVisibility()
{
    if (isHidden()) {
        showHideAction->setText(tr("&Hide"));
        show();
        qDebug() << "Window shown";
    } else {
        showHideAction->setText(tr("&Show"));
        hide();
        qDebug() << "Window hidden";
    }
}

void MainWindow::adjustDot(bool checked)
{
    WinKeyboardHook* keyboardHookInstance = WinKeyboardHook::getInstance();

    if (checked) {
        qDebug() << "Enabled adjustment mode";

        if (!keyboardHookInstance->connect()) {
            QMessageBox::warning(this, tr("Warning"), tr("Failed to establish hook to keyboard."));
            return;
        }
        
        systrayIcon->showMessage(tr("Center Dot"), tr("Use the arrow keys on your keyboard to adjust the crosshair position. If you're done you can press Return or uncheck 'Adjust crosshair' again in the menu."));

        connect(keyboardHookInstance, SIGNAL(keyPressed(DWORD)), this, SLOT(handlePressedArrowKey(DWORD)));
    } else {
        qDebug() << "Disabled adjustment mode";

        // TODO disconnect now works for all slots, only delete the arrow key one
        disconnect(keyboardHookInstance, SIGNAL(keyPressed(DWORD)), 0, 0);
        keyboardHookInstance->disconnect();
    }
}

void MainWindow::showSettingsDialog()
{
    if (settingsDialog == nullptr) {
        settingsDialog = new SettingsDialog(this);
        connect(settingsDialog, SIGNAL(accepted()), this, SLOT(updatedSettings()));
    }
    settingsDialog->setSettingsData(currentSettings);
    settingsDialog->show();
}

void MainWindow::resetDot()
{
    if (settingsDialog != nullptr && settingsDialog->isVisible()) {
        settingsDialog->close();
    }

    currentSettings.crosshairSize = DEFAULT_CROSSHAIR_SIZE;
    currentSettings.contourColor = DEFAULT_CONTOUR_COLOR;
    currentSettings.fillColor = DEFAULT_FILL_COLOR;

    QPoint screenCenterPoint = QDesktopWidget().availableGeometry().center();
    setCrosshairPosition(screenCenterPoint);

    updatedSettings();
}

void MainWindow::showAboutDlg()
{
    QString text = QString(
        QCoreApplication::applicationName() + "\n" +
        tr("Version") + " " + QCoreApplication::applicationVersion() + "\n" +
        tr("Shows a centered crosshair as a layer above your game.") + "\n"
        "(c) 2016 Atomkraftzwerg"
    );

    QMessageBox::about(this, tr("About Center Dot"), text);
}

void MainWindow::quitProgram()
{
    QApplication::quit();
}

void MainWindow::createActions()
{
    showHideAction = new QAction(tr("&Hide"), this);
    showHideAction->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));
    connect(showHideAction, SIGNAL(triggered()), this, SLOT(toggleWindowVisibility()));

    adjustDotAction = new QAction(tr("&Adjust dot"), this);
    adjustDotAction->setCheckable(true);
    adjustDotAction->setChecked(false);
    connect(adjustDotAction, SIGNAL(toggled(bool)), this, SLOT(adjustDot(bool)));

    resetDotAction = new QAction(tr("&Reset dot"), this);
    connect(resetDotAction, SIGNAL(triggered()), this, SLOT(resetDot()));

    settingsAction = new QAction(tr("&Settings..."), this);
    connect(settingsAction, SIGNAL(triggered()), this, SLOT(showSettingsDialog()));

    aboutAction = new QAction(tr("A&bout..."), this);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(showAboutDlg()));

    closeAction = new QAction(tr("&Exit"), this);
    connect(closeAction, SIGNAL(triggered()), this, SLOT(quitProgram()));
}

void MainWindow::createSystrayIcon()
{
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::warning(this, tr("System tray is unavailable"), tr("System tray unavailable"));
        return;
    }

    systrayIcon = new QSystemTrayIcon(*applicationIcon, this);
    systrayIcon->setToolTip(tr("Center Dot"));

    systrayMenu = new QMenu(this);
    systrayMenu->addAction(showHideAction);
    systrayMenu->addSeparator();
    systrayMenu->addAction(adjustDotAction);
    systrayMenu->addAction(resetDotAction);
    systrayMenu->addAction(settingsAction);
    systrayMenu->addSeparator();
    systrayMenu->addAction(aboutAction);
    systrayMenu->addAction(closeAction);
    systrayIcon->setContextMenu(systrayMenu);

    systrayIcon->show();
}

void MainWindow::moveNorth()
{
    QPoint position = pos();
    position.setY(position.y() - 1);
    move(position);
    qDebug() << "Moved north, new position:" << position;
}

void MainWindow::moveSouth()
{
    QPoint position = pos();
    position.setY(position.y() + 1);
    move(position);
    qDebug() << "Moved south, new position:" << position;
}

void MainWindow::moveEast()
{
    QPoint position = pos();
    position.setX(position.x() + 1);
    move(position);
    qDebug() << "Moved east, new position:" << position;
}

void MainWindow::moveWest()
{
    QPoint position = pos();
    position.setX(position.x() - 1);
    move(position);
    qDebug() << "Moved west, new position:" << position;
}
