#include "head.h"


int main() {
	srand(time(0));
	Map map;
	Snake snake;
	Menu();
	Game(map, snake);

	return 0;
}