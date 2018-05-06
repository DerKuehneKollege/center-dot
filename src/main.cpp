#include "mainwindow.h"

#include <qt_windows.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;

    app.setOrganizationName("Atomkraftzwerg");
    app.setOrganizationDomain("atomkraftzwerg.de");
    app.setApplicationName("Center Dot");
    app.setApplicationDisplayName("Center Dot");
    app.setApplicationVersion("1.0.2");

    qDebug() << "Starting" << app.applicationDisplayName() << app.applicationVersion();

    // show window
    mainWindow.show();

    // make window "transparent", do not activate window on click
    HWND winHandle = (HWND)mainWindow.effectiveWinId();
    ShowWindow(winHandle, SW_HIDE); // hide the window and activates another window
    SetWindowLong(
        winHandle,
        GWL_EXSTYLE,
        GetWindowLong(winHandle, GWL_EXSTYLE) | WS_EX_TRANSPARENT // make window with transparent background
    );
    ShowWindow(winHandle, SW_SHOW);

    return app.exec();
}
