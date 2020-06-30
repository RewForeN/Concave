#pragma once

namespace Concave {

	class Application {

	public:
		Application(int width, int height, int pxwidth, int pxheight);
		virtual ~Application() = default;
		void Run();

	private:
		bool m_isRunning = true;

	};

	Application* CreateApplication();

}
