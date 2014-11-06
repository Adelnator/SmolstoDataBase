/*#include <windows.h> // ������������ ����, ���������� WINAPI

// �������� ������� ��������� ��������� � ���������������� ���������:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = L"�� �������! ...�� ������ �� �� �������"; // ������ � ����������

// ����������� �������:
int WINAPI WinMain(HINSTANCE hInst, // ���������� ���������� ����������
	HINSTANCE hPrevInst, // �� ����������
	LPSTR lpCmdLine, // �� ����������
	int nCmdShow) // ����� ����������� ������
{
	TCHAR szClassName[] = L"��� �����"; // ������ � ������ ������
	HWND hMainWnd; // ������ ���������� �������� ������
	MSG msg; // ����� ��������� ��������� MSG ��� ��������� ���������
	WNDCLASSEX wc; // ������ ���������, ��� ��������� � ������ ������ WNDCLASSEX
	wc.cbSize = sizeof(wc); // ������ ��������� (� ������)
	wc.style = CS_HREDRAW | CS_VREDRAW; // ����� ������ ������
	wc.lpfnWndProc = WndProc; // ��������� �� ���������������� �������
	wc.lpszMenuName = NULL; // ��������� �� ��� ���� (� ��� ��� ���)
	wc.lpszClassName = szClassName; // ��������� �� ��� ������
	wc.cbWndExtra = NULL; // ����� ������������� ������ � ����� ���������
	wc.cbClsExtra = NULL; // ����� ������������� ������ ��� �������� ���������� ����������
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // ��������� �����������
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); // ���������� ��������� ����������� (� ����)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // ���������� �������
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���������� ����� ��� �������� ���� ����
	wc.hInstance = hInst; // ��������� �� ������, ���������� ��� ����, ������������ ��� ������
	if (!RegisterClassEx(&wc)){
		// � ������ ���������� ����������� ������:
		MessageBox(NULL, L"�� ���������� ���������������� �����!", L"������", MB_OK);
		return NULL; // ����������, �������������, ������� �� WinMain
	}
	// �������, ��������� ������:
	hMainWnd = CreateWindow(
		szClassName, // ��� ������
		L"����������� ������� ���������", // ��� ������ (�� ��� ������)
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, // ������ ����������� ������
		CW_USEDEFAULT, // ������� ������ �� ��� �
		NULL, // ������� ������ �� ��� � (��� ������ � �, �� ������ �� �����)
		CW_USEDEFAULT, // ������ ������
		NULL, // ������ ������ (��� ������ � ������, �� ������ �� �����)
		(HWND)NULL, // ���������� ������������� ����
		NULL, // ���������� ����
		HINSTANCE(hInst), // ���������� ���������� ����������
		NULL); // ������ �� ������� �� WndProc
	if (!hMainWnd){
		// � ������ ������������� �������� ������ (�������� ��������� � ��):
		MessageBox(NULL, L"�� ���������� ������� ����!", L"������", MB_OK);
		return NULL;
	}
	ShowWindow(hMainWnd, nCmdShow); // ���������� ������
	UpdateWindow(hMainWnd); // ��������� ������
	while (GetMessage(&msg, NULL, NULL, NULL)){ // ��������� ��������� �� �������, ���������� ��-�����, ��
		TranslateMessage(&msg); // �������������� ���������
		DispatchMessage(&msg); // ������� ��������� ������� ��
	}
	return msg.wParam; // ���������� ��� ������ �� ����������
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC; // ������ ���������� ���������� ������ �� ������
	PAINTSTRUCT ps; // ���������, ���-��� ���������� � ���������� ������� (�������, ���� � ��)
	RECT rect; // ���-��, ������������ ������ ���������� �������
	COLORREF colorText = RGB(255, 0, 0); // ����� ���� ������
	switch (uMsg) {
	case WM_PAINT: // ���� ����� ����������, ��:
		hDC = BeginPaint(hWnd, &ps); // �������������� �������� ����������
		GetClientRect(hWnd, &rect); // �������� ������ � ������ ������� ��� ���������
		SetTextColor(hDC, colorText); // ������������� ���� ������������ ����������
		DrawText(hDC, mainMessage, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); // ������ �����
		EndPaint(hWnd, &ps); // ����������� ��������
		break;
	case WM_DESTROY: // ���� ������ ���������, ��:
		PostQuitMessage(NULL); // ���������� WinMain() ��������� WM_QUIT
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam); // ���� ������� ������
	}
	return NULL; // ���������� ��������
}*/

#include <windows.h> // ������������ ����, ���������� WINAPI

// �������� ������� ��������� ��������� � ���������������� ���������:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR mainMessage[] = L"�������� ������ �������"; // ������ � ����������

// ����������� �������:
int WINAPI WinMain(HINSTANCE hInst, // ���������� ���������� ����������
	HINSTANCE hPrevInst, // �� ����������
	LPSTR lpCmdLine, // �� ����������
	int nCmdShow) // ����� ����������� ������
{
	TCHAR szClassName[] = L"��� �����"; // ������ � ������ ������
	HWND hMainWnd; // ������ ���������� �������� ������
	MSG msg; // ����� ��������� ��������� MSG ��� ��������� ���������
	WNDCLASSEX wc; // ������ ���������, ��� ��������� � ������ ������ WNDCLASSEX
	wc.cbSize = sizeof(wc); // ������ ��������� (� ������)
	wc.style = CS_HREDRAW | CS_VREDRAW; // ����� ������ ������
	wc.lpfnWndProc = WndProc; // ��������� �� ���������������� �������
	wc.lpszMenuName = NULL; // ��������� �� ��� ���� (� ��� ��� ���)
	wc.lpszClassName = szClassName; // ��������� �� ��� ������
	wc.cbWndExtra = NULL; // ����� ������������� ������ � ����� ���������
	wc.cbClsExtra = NULL; // ����� ������������� ������ ��� �������� ���������� ����������
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO); // ��������� �����������
	wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO); // ���������� ��������� ����������� (� ����)
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); // ���������� �������
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ���������� ����� ��� �������� ���� ����
	wc.hInstance = hInst; // ��������� �� ������, ���������� ��� ����, ������������ ��� ������
	if (!RegisterClassEx(&wc)){
		// � ������ ���������� ����������� ������:
		MessageBox(NULL, L"�� ���������� ���������������� �����!", L"������", MB_OK);
		return NULL; // ����������, �������������, ������� �� WinMain
	}
	// �������, ��������� ������:
	hMainWnd = CreateWindow(
		szClassName, // ��� ������
		L"����������� ������� ���������", // ��� ������ (�� ��� ������)
		WS_OVERLAPPEDWINDOW | WS_VSCROLL, // ������ ����������� ������
		CW_USEDEFAULT, // ������� ������ �� ��� �
		NULL, // ������� ������ �� ��� � (��� ������ � �, �� ������ �� �����)
		CW_USEDEFAULT, // ������ ������
		NULL, // ������ ������ (��� ������ � ������, �� ������ �� �����)
		(HWND)NULL, // ���������� ������������� ����
		NULL, // ���������� ����
		HINSTANCE(hInst), // ���������� ���������� ����������
		NULL); // ������ �� ������� �� WndProc
	if (!hMainWnd){
		// � ������ ������������� �������� ������ (�������� ��������� � ��):
		MessageBox(NULL, L"�� ���������� ������� ����!", L"������", MB_OK);
		return NULL;
	}
	ShowWindow(hMainWnd, nCmdShow); // ���������� ������
	UpdateWindow(hMainWnd); // ��������� ������
	while (GetMessage(&msg, NULL, NULL, NULL)){ // ��������� ��������� �� �������, ���������� ��-�����, ��
		TranslateMessage(&msg); // �������������� ���������
		DispatchMessage(&msg); // ������� ��������� ������� ��
	}
	return msg.wParam; // ���������� ��� ������ �� ����������
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC; // ������ ���������� ���������� ������ �� ������
	PAINTSTRUCT ps; // ���������, ���-��� ���������� � ���������� ������� (�������, ���� � ��)
	//COLORREF colorText = RGB(0, 0, 0); // ����� ���� ������
	switch (uMsg) {
		case WM_PAINT: // ���� ����� ����������, ��:

			CreateWindowEx(WS_EX_CLIENTEDGE, L"Edit", NULL, WS_CHILD | WS_VISIBLE | ES_RIGHT,
				150, 65, 200, 25, hWnd, (HMENU)10000, NULL, NULL);
			CreateWindowEx(WS_EX_CLIENTEDGE, L"Edit", NULL, WS_CHILD | WS_VISIBLE | ES_RIGHT,
				150, 115, 200, 25, hWnd, (HMENU)10000, NULL, NULL);
			CreateWindowEx(WS_EX_CLIENTEDGE, L"Edit", NULL, WS_CHILD | WS_VISIBLE | ES_RIGHT,
				150, 165, 200, 25, hWnd, (HMENU)10000, NULL, NULL);
			CreateWindowEx(WS_EX_CLIENTEDGE, L"Edit", NULL, WS_CHILD | WS_VISIBLE | ES_RIGHT,
				150, 215, 200, 25, hWnd, (HMENU)10000, NULL, NULL);
			CreateWindowEx(WS_EX_CLIENTEDGE, L"Edit", NULL, WS_CHILD | WS_VISIBLE | ES_RIGHT,
				150, 265, 200, 25, hWnd, (HMENU)10000, NULL, NULL);

			RECT rect; // ���-��, ������������ ������ ���������� �������
			HFONT hFont;
			hDC = BeginPaint(hWnd, &ps); // �������������� �������� ����������
			hFont = CreateFont(30, 0, 0, 0, FW_HEAVY, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
				CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
			SelectObject(hDC, hFont);
			//GetClientRect(hWnd, &rect); // �������� ������ � ������ ������� ��� ���������
			//SetTextColor(hDC, colorText); // ������������� ���� ������������ ����������
			SetRect(&rect, 15, 15, 700, 200);
			SetTextColor(hDC, RGB(147, 69, 107));
			DrawText(hDC, L"�������� ������ �������", -1, &rect, DT_NOCLIP);
			SetRect(&rect, 15, 60, 700, 200);
			DrawText(hDC, L"���", -1, &rect, DT_NOCLIP);
			SetRect(&rect, 15, 110, 700, 200);
			DrawText(hDC, L"�������", -1, &rect, DT_NOCLIP);
			SetRect(&rect, 15, 160, 700, 200);
			DrawText(hDC, L"��������", -1, &rect, DT_NOCLIP);
			SetRect(&rect, 15, 210, 700, 200);
			DrawText(hDC, L"�������", -1, &rect, DT_NOCLIP);
			SetRect(&rect, 15, 260, 700, 200);
			DrawText(hDC, L"�����", -1, &rect, DT_NOCLIP);
			//DrawText(hDC, mainMessage, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER); // ������ �����
			EndPaint(hWnd, &ps); // ����������� ��������
			break;
		case WM_DESTROY: // ���� ������ ���������, ��:
			PostQuitMessage(NULL); // ���������� WinMain() ��������� WM_QUIT
			break;
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam); // ���� ������� ������
	}
	return NULL; // ���������� ��������
}