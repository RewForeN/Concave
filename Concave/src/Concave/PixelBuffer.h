#pragma once

#include <Windows.h>

namespace Concave {

	class PixelBuffer {

	public:
		PixelBuffer(int width, int height);

		inline CHAR_INFO& GetBufferRaw() { return *m_Buffer; }
		inline int GetWidth() { return m_Width; }
		inline int GetHeight() { return m_Height; }

	private:
		CHAR_INFO* m_Buffer;
		int m_Width;
		int m_Height;

	};

}