#ifndef WINKEYBOARDHOOK_H
#define WINKEYBOARDHOOK_H

#include <QObject>
#include <windows.h>

class WinKeyboardHook : public QObject
{
    Q_OBJECT

public:
    // Returns the current singleton instance or a new one of none existing
    static WinKeyboardHook *getInstance();

    bool isConnected();
    bool connect();
    bool disconnect();

signals:
    // Broadcasts a key has been pressed
    void keyPressed(DWORD key);

    // Broadcast a key has been released
    void keyReleased(DWORD key);

private:
    // Constructor
    explicit WinKeyboardHook();

    // Callback function, handling keyboard input
    static LRESULT CALLBACK handleKeyboardEvent(int nCode, WPARAM wParam, LPARAM lParam);

    // Singleton instance
    static WinKeyboardHook* instance;

    // Instance of the Windows keyboard hook
    HHOOK keyboardHook = NULL;
};

#endif // WINKEYBOARDHOOK_H
