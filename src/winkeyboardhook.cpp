#include "winkeyboardhook.h"

WinKeyboardHook* WinKeyboardHook::instance = NULL;

WinKeyboardHook::WinKeyboardHook() : QObject()
{
    // Assign to null
    keyboardHook = NULL;
}

WinKeyboardHook* WinKeyboardHook::getInstance()
{
    if (instance == NULL) {
        instance = new WinKeyboardHook();
    }

    return instance;
}

bool WinKeyboardHook::isConnected()
{
    return (keyboardHook != NULL);
}

bool WinKeyboardHook::connect()
{
    if (keyboardHook == NULL) {
        keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, handleKeyboardEvent, GetModuleHandle(NULL), 0);
    }

    return (keyboardHook != NULL);
}

bool WinKeyboardHook::disconnect()
{
    bool unhookSucceeded = UnhookWindowsHookEx(keyboardHook);
    keyboardHook = NULL;

    return unhookSucceeded;
}

LRESULT CALLBACK WinKeyboardHook::handleKeyboardEvent(
    int nCode,
    WPARAM wParam,
    LPARAM lParam
) {
    if (nCode == HC_ACTION) {
        if (wParam == WM_KEYDOWN) {
            // Handle key press
            KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)lParam;
            emit WinKeyboardHook::getInstance()->keyPressed((DWORD)pKeyboard->vkCode);
        } else if (wParam == WM_KEYUP) {
            // Handle key release
            KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)lParam;
            emit WinKeyboardHook::getInstance()->keyReleased((DWORD)pKeyboard->vkCode);
        }
    }

    return CallNextHookEx(NULL, nCode, wParam, lParam);
}
