
#include "olcConsoleGameEngine.h"

class Demo : public olcConsoleGameEngine {

public:
	Demo() { }

protected:
	virtual bool OnUserCreate() {

		return true;

	}

	virtual bool OnUserUpdate(float fElapsedTime) {

		for (int x = 0; x < m_nScreenWidth; x += 4) {
			for (int y = 0; y < m_nScreenHeight; y += 4) {
				Draw(x, y, L'#', rand() % 16);
			}
		}

		return true;

	}

};

int demo_main() {

	Demo game;
	game.ConstructConsole(400, 200, 2, 2);
	game.Start();

	return 1;

}