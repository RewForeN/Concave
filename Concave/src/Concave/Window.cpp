
#include "pch.h"
#include "Window.h"


CONSOLE_FONT_INFOEX CreateConsoleFont(int w, int h) {

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = w;
	cfi.dwFontSize.Y = h;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");

	return cfi;

}

Concave::Window::Window(short width, short height, std::string title) {

	m_WindowWidth = width;
	m_WindowHeight = height;
	m_WriteRegion = {0, 0, width, height};
	m_ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD c = {width + 1, height + 1};

	SetConsoleActiveScreenBuffer(m_ConsoleHandle);
	SetConsoleWindowInfo(m_ConsoleHandle, TRUE, &m_WriteRegion);
	SetConsoleScreenBufferSize(m_ConsoleHandle, c);
	//SetConsoleScreenBufferSize(m_ConsoleHandle, {width + 1, height + 1});
	SetCurrentConsoleFontEx(m_ConsoleHandle, false, &CreateConsoleFont(15, 15));

	m_PixelBuffer = new CHAR_INFO[width * height];

	for (int i = 0; i < width * height; i++) {
		m_PixelBuffer[i].Char.UnicodeChar = 0x2588;
		m_PixelBuffer[i].Attributes = 0x0000;
	}

}

Concave::Window::~Window() {

	delete[] m_PixelBuffer;

}

void Concave::Window::OnUpdate() {

	WriteConsoleOutput(m_ConsoleHandle, m_PixelBuffer, {(short)m_WindowHeight, (short)m_WindowHeight}, {0, 0}, &m_WriteRegion);

}

void Concave::Window::SetTitle(LPCWSTR title) {

	SetConsoleTitle(title);

}

void Concave::Window::Clear(short color) {

	for (int i = 0; i < GetWidth() * GetHeight(); i++) {
		m_PixelBuffer[i].Attributes = color;
	}

}

void Concave::Window::Draw(int x, int y, short color) {

	m_PixelBuffer[y * GetWidth() + x].Attributes = color;

}

