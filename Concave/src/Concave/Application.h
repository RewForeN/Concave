#pragma once

#include "Window.h"

#include <memory>


namespace Concave {

	class Application {

	public:
		Application(int width, int height, int pxwidth, int pxheight);
		virtual ~Application() = default;

		void Run();

	protected:
		virtual void OnCreate() { }
		virtual void OnUpdate(float deltaTime) = 0;

		inline Window& GetWindow() { return *m_Window; }

	private:
		bool m_isRunning = true;
		std::unique_ptr<Window> m_Window;

	};

	Application* CreateApplication();

}
