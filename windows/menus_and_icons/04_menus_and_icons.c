#include "windows.h"
#include "04_resource.h"

const char g_szClassName[] = "myWindowClass";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_LBUTTONDOWN: {
            char szFileName[MAX_PATH];
            HINSTANCE hInstance = GetModuleHandle(NULL);

            GetModuleFileName(hInstance, szFileName, MAX_PATH);
            MessageBox(hwnd, szFileName, "This program is: ", MB_OK | MB_ICONINFORMATION);
        }
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    //Step 1: Register window class
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);
    wc.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
    wc.lpszClassName = g_szClassName;
    wc.hIcon = LoadIcon(GetModuleHandle(NULL),
                        MAKEINTRESOURCE(IDI_MYICON));
    wc.hIconSm = (HICON) LoadImage(GetModuleHandle(NULL),
                                   MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed", "Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Create Window
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, "Awesome window is awesome.",
                          WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
                          NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window creation error", "Error",
                   MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }


    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: message loop
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
