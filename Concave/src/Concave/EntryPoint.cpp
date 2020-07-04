
#include "pch.h"
#include "Concave.h"

extern Concave::Application* Concave::CreateApplication();

int main() {

	auto app = Concave::CreateApplication();
	app->Run();
	delete app;

	return 1;

}
