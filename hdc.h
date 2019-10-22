#include <iostream>
#include <Windows.h>

struct resolution {
	float width = GetSystemMetrics(SM_CXSCREEN); //capsuling your screen width.
	float height = GetSystemMetrics(SM_CYSCREEN); //capsuling your screen height.
}res; //object of struct.

static struct key_strokes
{
	bool is_pressed; //keystroke structure's is_pressed boolean.
	DWORD start_time; //keystroke structure's start_time dword for compare with GetTickCount().
}
kPressingKey[256]; //255 is the vkTable limitation.

bool key_check(int Key, DWORD dwTimeOut) //its alternative for GetAsyncKeyState function. Simply it's checking keys with TickCount function.
{
	if (HIWORD(GetKeyState(Key))) //Key -> whatever virtual keycode you want.
	{
		if (!kPressingKey[Key].is_pressed || (kPressingKey[Key].start_time && (kPressingKey[Key].start_time + dwTimeOut) <= GetTickCount()))
		{
			kPressingKey[Key].is_pressed = TRUE;
			if (dwTimeOut > NULL)
				kPressingKey[Key].start_time = GetTickCount();
			return TRUE;
		}
	}
	else
		kPressingKey[Key].is_pressed = FALSE;
	return FALSE;
}

void DrawString(HDC hdc, HFONT font, int x, int y, COLORREF color, const  char* text) //draws string to HDC.
{
	SetTextAlign(hdc, TA_CENTER | TA_NOUPDATECP); //changes align to center.
	SetBkColor(hdc, RGB(0, 0, 0)); //sets 0 all values to get better opacity.
	SetBkMode(hdc, TRANSPARENT); //changes text background adaptive with window.
	SetTextColor(hdc, color); //changes text color default->black to your specific color.
	SelectObject(hdc, font); //handler object - font.
	TextOutA(hdc, x, y, text, strlen(text)); //output to handler.
	DeleteObject(font);
	DeleteObject(hdc);
}