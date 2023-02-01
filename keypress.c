#include <windows.h>

INPUT input;

void InputEvent(DWORD keyCode, DWORD event) {
    input.ki.wVk = keyCode;
    input.ki.dwFlags = event; // 0 for press
    SendInput(1, &input, sizeof(INPUT));
}

void ReleaseKey(DWORD keyCode) {
    InputEvent(keyCode, KEYEVENTF_KEYUP);
}

void PressKey(DWORD keyCode) {
    InputEvent(keyCode, 0);
}

int main() {
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0; // hardware scan code for the key
    input.ki.time = 0; // use system time stamp
    input.ki.dwExtraInfo = 0;

    PressKey(VK_LMENU);
    PressKey(VK_SPACE);
    ReleaseKey(VK_SPACE);
    ReleaseKey(VK_LMENU);

    return 0;
}

