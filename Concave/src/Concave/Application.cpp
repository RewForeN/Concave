
#include "pch.h"
#include "Application.h"


Concave::Application::Application(int width, int height, int pxwidth, int pxheight) {

	m_Window = std::unique_ptr<Window>(new Window(width, height));

	OnCreate();

}

void Concave::Application::Run() {

	static std::chrono::steady_clock::time_point previousTime = std::chrono::steady_clock::now();
	static std::chrono::steady_clock::time_point currentTime;

	// Main loop
	while (m_isRunning) {

		currentTime = std::chrono::steady_clock::now();
		float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - previousTime).count() / 1000.0f;

		m_Window->OnUpdate();

		wchar_t s[256];
		swprintf_s(s, 256, L"My Game - FPS: %3.2f", 1000.0f / deltaTime);
		SetConsoleTitle(s);

		OnUpdate(deltaTime);

		previousTime = currentTime;

	}

}
