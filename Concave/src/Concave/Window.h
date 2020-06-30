#pragma once

#include <Windows.h>
#include <string>

class Window {

public:
	Window();
	~Window() = default;

	void OnUpdate();

	unsigned int GetWidth();
	unsigned int GetHeight();

private:
	void Init();
	void Shutdown();

private:
	HANDLE m_windowHandle;

	std::string title;
	unsigned int width;
	unsigned int height;

};