#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QDebug>
#include <QWidget>
#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QDesktopWidget>
#include <QSystemTrayIcon>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QIcon>
#include <QMessageBox>
#include <QSettings>
#include <QStandardPaths>
#include <QDir>

#include "settingsdata.h"
#include "winkeyboardhook.h"
#include "settingsdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private slots:
    void loadSettings();
    void saveSettings();
    void updatedSettings();
    void handlePressedArrowKey(DWORD pressedKey);
    void handlePressedKey(DWORD pressedKey);
    void toggleWindowVisibility();
    void adjustDot(bool checked);
    void showSettingsDialog();
    void resetDot();
    void showAboutDlg();
    void quitProgram();

private:
    static const QString SETTINGS_FILE_NAME;
    static const int     DEFAULT_CROSSHAIR_SIZE;
    static const QColor  DEFAULT_CONTOUR_COLOR;
    static const QColor  DEFAULT_FILL_COLOR;

    QString settingsFileName;

    QIcon *applicationIcon;
    QSystemTrayIcon *systrayIcon;

    QMenu *systrayMenu;
    QAction *showHideAction;
    QAction *adjustDotAction;
    QAction *resetDotAction;
    QAction *settingsAction;
    QAction *aboutAction;
    QAction *closeAction;

    SettingsData currentSettings;

    SettingsDialog *settingsDialog;



    void createActions();
    void createSystrayIcon();
    void moveNorth();
    void moveSouth();
    void moveWest();
    void moveEast();

    inline int getCrosshairSize()
    {
        // assuming the crosshair is of quadratic dimension and width() and height() are equal
        return width();
    }

    inline void setCrosshairSize(int size)
    {
        setFixedSize(size, size);
    }

    inline QPoint getCrosshairPosition()
    {
        return QPoint(
            x() + width() / 2,
            y() + height() / 2
        );
    }

    inline void setCrosshairPosition(QPoint &centerPoint)
    {
        move(
            centerPoint.x() - width() / 2,
            centerPoint.y() - height() / 2
        );
    }

};

#endif // MAINWINDOW_H
