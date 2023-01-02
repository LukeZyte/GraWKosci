#include "Globals.h"

void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void boldFont() {
    static CONSOLE_FONT_INFOEX  font;
    font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &font);
    font.FontWeight = 700;
    font.dwFontSize.X = 24;
    font.dwFontSize.Y = 24;
    SetCurrentConsoleFontEx(hOut, NULL, &font);
}

void normalFont() {
    static CONSOLE_FONT_INFOEX  font;
    font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &font);
    font.FontWeight = 0;
    font.dwFontSize.X = 12;
    font.dwFontSize.Y = 12;
}