#pragma once

#include <Windows.h>
#include "PixelBuffer.h"

#include <string>
#include <memory>

namespace Concave {

	class Window {

	public:
		Window(short width, short height, std::string title = "My Game");
		~Window();

		void OnUpdate();

		void SetTitle(LPCWSTR title);

		void Clear(short color = 0x0000);
		void Draw(int x, int y, short color = 0x000F);

		inline void* GetNativeWindow() { return &m_ConsoleHandle; }
		inline int GetWidth() { return m_WindowWidth; }
		inline int GetHeight() { return m_WindowHeight; }
		inline CHAR_INFO& GetPixelBuffer() { return *m_PixelBuffer; }

	private:
		HANDLE m_ConsoleHandle;

		int m_WindowWidth;
		int m_WindowHeight;
		SMALL_RECT m_WriteRegion;

		CHAR_INFO* m_PixelBuffer;

	};

}