
#include "Concave.h"

class Demo : public Concave::Application {

public:
	Demo()
		: Application(80, 80, 8, 8)	{

	}

	~Demo() {

	}

};

Concave::Application* Concave::CreateApplication() {

	return new Demo();

}