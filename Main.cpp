#include <windows.h>
#include <iostream>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void PrintVKInfo(UINT uMsg, WPARAM wParam, LPARAM lParam);
void PrintCharInfo(UINT uMsg, WPARAM wParam, LPARAM lParam);

int main(wchar_t** args, size_t argc) {
    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = nullptr;
    wc.lpszClassName = L"Keyboard Info Class";

    RegisterClass(&wc);

    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        L"Keyboard Info Class",         // Window class
        L"Windows Keyboard Info Test",  // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        nullptr,       // Parent window    
        nullptr,       // Menu
        nullptr,       // Instance handle
        nullptr        // Additional application data
    );

    if (hwnd == nullptr)
    {
        return 0;
    }

    ShowWindow(hwnd, SW_SHOWNORMAL);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;

}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    
    case WM_KEYDOWN:
        PrintVKInfo(uMsg, wParam, lParam);
        return 0;

    case WM_CHAR:
        PrintCharInfo(uMsg, wParam, lParam);
        return 0;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);



        FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

        EndPaint(hwnd, &ps);
    }
    return 0;

    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void PrintCharInfo(UINT uMsg, WPARAM wParam, LPARAM lParam) {
    std::wcout << L"WM_CHAR: " << wParam << L" " << ((wchar_t)wParam) << L"\n";
}

#define PRINT_VKINFO(VK, uMsg, wParam, lParam) case VK: std::wcout << #VK << L" Scan:" << ((lParam & 0xff0000) >> 16) << L"\n"; break;

enum {
    VK_Number0 = 0x30,
    VK_Number1 = 0x31,
    VK_Number2 = 0x32,
    VK_Number3 = 0x33,
    VK_Number4 = 0x34,
    VK_Number5 = 0x35,
    VK_Number6 = 0x36,
    VK_Number7 = 0x37,
    VK_Number8 = 0x38,
    VK_Number9 = 0x39,
    VK_A = 0x41,
    VK_B = 0x42,
    VK_C = 0x43,
    VK_D = 0x44,
    VK_E = 0x45,
    VK_F = 0x46,
    VK_G = 0x47,
    VK_H = 0x48,
    VK_I = 0x49,
    VK_J = 0x4A,
    VK_K = 0x4B,
    VK_L = 0x4C,
    VK_M = 0x4D,
    VK_N = 0x4E,
    VK_O = 0x4F,
    VK_P = 0x50,
    VK_Q = 0x51,
    VK_R = 0x52,
    VK_S = 0x53,
    VK_T = 0x54,
    VK_U = 0x55,
    VK_V = 0x56,
    VK_W = 0x57,
    VK_X = 0x58,
    VK_Y = 0x59,
    VK_Z = 0x5A,
};


void PrintVKInfo(UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (wParam) {
        PRINT_VKINFO(VK_Number0, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number1, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number2, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number3, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number4, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number5, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number6, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number7, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number8, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Number9, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_A, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_B, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_C, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_D, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_E, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_G, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_H, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_I, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_J, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_K, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_L, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_M, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_N, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_O, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_P, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Q, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_R, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_S, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_T, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_U, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_V, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_W, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_X, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Y, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_Z, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LBUTTON, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_RBUTTON, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_CANCEL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_MBUTTON, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_XBUTTON1, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_XBUTTON2, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_BACK, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_TAB, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_CLEAR, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_RETURN, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_SHIFT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_CONTROL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_MENU, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_PAUSE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_CAPITAL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_KANA, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_JUNJA, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_FINAL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_HANJA, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_ESCAPE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_CONVERT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NONCONVERT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_ACCEPT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_MODECHANGE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_SPACE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_PRIOR, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NEXT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_END, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_HOME, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LEFT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_UP, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_RIGHT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_DOWN, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_SELECT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_PRINT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_EXECUTE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_SNAPSHOT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_INSERT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_DELETE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_HELP, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LWIN, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_RWIN, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_APPS, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_SLEEP, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD0, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD1, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD2, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD3, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD4, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD5, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD6, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD7, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD8, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMPAD9, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_MULTIPLY, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_ADD, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_SEPARATOR, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_SUBTRACT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_DECIMAL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_DIVIDE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F1, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F2, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F3, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F4, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F5, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F6, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F7, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F8, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F9, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F10, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F11, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F12, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F13, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F14, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F15, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F16, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F17, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F18, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F19, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F20, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F21, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F22, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F23, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_F24, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NUMLOCK, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_SCROLL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LSHIFT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_RSHIFT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LCONTROL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_RCONTROL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LMENU, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_RMENU, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_BROWSER_BACK, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_BROWSER_FORWARD, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_BROWSER_REFRESH, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_BROWSER_STOP, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_BROWSER_SEARCH, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_BROWSER_FAVORITES, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_BROWSER_HOME, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_VOLUME_MUTE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_VOLUME_DOWN, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_VOLUME_UP, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_MEDIA_NEXT_TRACK, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_MEDIA_PREV_TRACK, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_MEDIA_STOP, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_MEDIA_PLAY_PAUSE, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LAUNCH_MAIL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LAUNCH_MEDIA_SELECT, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LAUNCH_APP1, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_LAUNCH_APP2, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_1, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_PLUS, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_COMMA, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_MINUS, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_PERIOD, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_2, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_3, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_4, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_5, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_6, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_7, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_8, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_102, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_PROCESSKEY, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_PACKET, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_ATTN, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_CRSEL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_EXSEL, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_EREOF, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_PLAY, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_ZOOM, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_NONAME, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_PA1, uMsg, wParam, lParam)
        PRINT_VKINFO(VK_OEM_CLEAR, uMsg, wParam, lParam)
        
        default:
            std::cout << "WM_CHAR for VK: " << wParam << " Scan:" << ((lParam & 0xff0000) >> 16) << "\n";
            break;
    }
}