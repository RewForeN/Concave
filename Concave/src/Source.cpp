
#include "pch.h"
#include "Concave.h"

#include <vector>


class Demo : public Concave::Application {

public:
	Demo()
		: Application(40, 40, 10, 10) {

		snake[0].x = 10;
		snake[0].y = 10;

	}

	~Demo() {

	}

protected:
	void OnUpdate(float deltaTime) {

		static float timePassed = 0;
		timePassed += deltaTime;

		GetWindow().Clear();

		// Draw snake
		for (int i = 0; i < size; i++) {
			GetWindow().Draw(snake[i].x, snake[i].y);
		}

		// Draw apples
		if (hasApple)
			GetWindow().Draw(apple.x, apple.y, 0x632F);

		// Spawn apples
		if (!hasApple) {
			apple.x = rand() % 40;
			apple.y = rand() % 40;
			hasApple = true;
		}

		// Detect arrow keys
		if (GetAsyncKeyState(VK_UP) & 0x8000)
			direction = up;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			direction = down;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			direction = right;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			direction = left;

		// Move player in correct direction in 100ms intervals
		if (timePassed > 100) {
			switch (direction) {
			case up:
				Move(0, -1);
				break;
			case down:
				Move(0, 1);
				break;
			case left:
				Move(-1, 0);
				break;
			case right:
				Move(1, 0);
				break;
			}
			timePassed = 0;
		}

	}

	void Move(int x, int y) {

		// Move all parts of snake accordingly
		for (int i = size - 1; i >= 0; i--) {
			if (i != 0) {
				snake[i].x = snake[i - 1].x;
				snake[i].y = snake[i - 1].y;
			}
			else {
				snake[i].x += x;
				snake[i].y += y;
			}
		}

		// Eat apple
		if (snake[0].x == apple.x && snake[0].y == apple.y) {
			hasApple = false;
			size++;
		}

	}

private:
	struct coord {
		int x;
		int y;
	};
	std::vector<coord> snake = std::vector<coord>(100);
	int size = 1;

	coord apple;
	bool hasApple = false;

	enum dir {
		up,
		down,
		left,
		right
	};
	dir direction = right;

};

Concave::Application* Concave::CreateApplication() {

	return new Demo();

}
