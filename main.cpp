#include <iostream>
#include <Windows.h>
#include "hdc.h"

/* sources:
https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getdc
http://www.cplusplus.com/forum/windows/64772/
https://stackoverflow.com/questions/48644697/getting-a-hdc-in-c
https://cboard.cprogramming.com/cplusplus-programming/54491-hdc-newbie.html
*/

using namespace std;

bool function = false; //helps to get on-off statements of feature.

HDC hdc; //object of overlay.
HFONT Font; //object of overlay's font.
COLORREF textColor; //object of overlay's text color.
HWND hWnd = FindWindow(0, "Untitled - Notepad"); //you need to change here with your target application.;;

int main()
{
	while (true) //endless loop.
	{
		Sleep(1); //reduces-prevents high-cpu usage problem.
		hdc = GetDC(hWnd); //creating display handler with your app's hwnd.

		if (key_check(VK_F1, 0)) //if key pressed.
			function = !function; //if its true, it will be false - if its false, it will be true.

		if (function) // ->TRUE
			DrawString(hdc, Font, res.width / 8, res.height / 64, textColor = RGB(0, 255, 0), "Hello, Im Green."); //draws string to hdc with DrawString function.
		else
			DrawString(hdc, Font, res.width / 8, res.height / 64, textColor = RGB(255, 0, 0), "Hello, Im Red."); //draws string to hdc with DrawString function.

		DeleteObject(hdc); //helps to refresh overlay in loop.

		if (key_check(VK_F2, 0)) //if key pressed. -> dispose.
			break;
	}
	DeleteObject(hdc);
	return 0;
}
