
#include "pch.h"
#include "PixelBuffer.h"


Concave::PixelBuffer::PixelBuffer(int width, int height) {

	m_Width = width;
	m_Height = height;
	m_Buffer = new CHAR_INFO[width * height];

	for (int i = 0; i < width * height; i++) {
		m_Buffer[i].Char.UnicodeChar = 0x2588;
		m_Buffer[i].Attributes = 0x000F;
	}

}
