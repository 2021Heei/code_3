#include "head.h"
//静态全局变量确保只在一个源文件中出现。防止重定义
string Foods::_foods = foodSign;  // 静态成员变量的定义
string Obstacles::_obstacles = obstacleSign; // 障碍物
ostream& operator<<(ostream& out, const Position& pos) {
	out << "Position: " << " (" << pos._x << "," << pos._y << ")";
	return out;
}

ostream& operator<<(ostream& out, const Food& food) {
	out << "foodSign: " << food._foodSign << " " << food._pos;
	return out;
}
ostream& operator<<(ostream& out, const Obstacle& obstacle) {
	for (int i = 0; i < obstacle._obstacle.size(); ++i) {
		out << "obstacle: " << obstacle._obstacle[i]._sign << " " << obstacle._obstacle[i]._pos;
	}
	return out;
}
void Game(Map& map, Snake& snake) {
	int option;
	do {
		cout << "请输入你的选项" << endl;

		cin >> option;
		switch (option) {
		case 1:
			//进行游戏
#if __DEBUG__
			cout << "开始游戏" << endl;
#endif
			startGame(map, snake);
			Menu();
			break;
		case 2:
			//游戏设置
#if __DEBUG__
			cout << "游戏设置" << endl;
#endif
			break;
		case 0:
			//退出游戏
#if __DEBUG__
			cout << "退出游戏" << endl;
#endif
			break;
		default:
			//输入错误
#if __DEBUG__
			cout << "输入错误，请重新输入" << endl;
#endif
			break;
		}
	} while (option);
}

void Menu() {
	system("cls");
	cout << "*********************************" << endl;
	cout << "****          贪吃蛇         ****" << endl;
	cout << "****                         ****" << endl;
	cout << "****        1.开始游戏       ****" << endl;
	cout << "****        2.游戏设置       ****" << endl;
	cout << "****        0.退出游戏       ****" << endl;
	cout << "*********************************" << endl;

}
void InitGame(Map& map, Snake& snake) {
	map = Map();
	snake = Snake();
}
void UpdateMap() {
	//蛇的位置 和 食物的位置

}

void startShowGameRealTime(const Map& map, const Snake& snake, int gameWinTarget) {
	system("cls");
	//显示菜单和目标信息
	cout << "目标食物数目: " << GAME_WIN_TARGET << endl;
	cout << "目标蛇的长度: " << gameWinTarget << endl;
	cout << "初始得分: " << 0 << "    " << "当前得分: " << snake.getSnakeScore() << endl;//
	cout << "初始蛇的长度: " << START_SNAKE_LENGTH << "    " << "当前蛇的长度: " <<  snake.getSnakeLength() << endl;
	cout << "当前障碍物的数量: " << map.obstacleSize() << endl;
	cout << "当前地图大小: " << ROW << " X " << COL << endl;


	//显示地图和蛇
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			//围墙 暂时用 '!' 表示
			if (map.getXYOfElement(i, j) == MAP_FENCE_LEFT_RIGHT 
				|| map.getXYOfElement(i, j) == MAP_FENCE_UP_DOWN) {
				cout << map.getXYOfElement(i, j);
			}
			else if (map.isObstacle(i, j)) {
				cout << map.getXYOfObstacleSign(i, j);
			}
			//优先显示蛇的位置， 围墙除外
			else if (snake.isSnake(i, j)) {
				cout << snake.getXYOfElement(i, j);
			}
			//默认显示地图
			else {
				cout << map.getXYOfElementMapOrFood(i, j);
			}
		}
		cout << endl;
	}
}
void showSnake(const Snake& snake) {
	// 获取标准输出句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < snake.getSnakeLength(); ++i) {
		Position pos = snake.getSnakePrevPos(i);
		// 设置绘制字符的位置
		COORD position = { pos._y, pos._x + 6 };

		// 设置要绘制的字符和属性
		char character = DEFAULT_MAP_SIGN;
		WORD attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

		// 设置字符属性
		SetConsoleTextAttribute(hConsole, attributes);

		// 写入字符到指定位置
		DWORD charsWritten;
		WriteConsoleOutputCharacterA(hConsole, &character, 1, position, &charsWritten);
	}

	for (int i = 0; i < snake.getSnakeLength(); ++i) {
		Position pos = snake.getSnakePos(i);
		// 设置绘制字符的位置
		COORD position = { pos._y, pos._x + 6 };

		// 设置要绘制的字符和属性
		char character = i == 0 ? SNAKE_HEAD_SIGN : SNAKE_BODY_SIGN;
		WORD attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY;

		// 设置字符属性
		SetConsoleTextAttribute(hConsole, attributes);

		// 写入字符到指定位置
		DWORD charsWritten;
		WriteConsoleOutputCharacterA(hConsole, &character, 1, position, &charsWritten);
	}

	// 恢复默认的字符属性
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}
void showFood(const Map& map) {
	// 获取标准输出句柄
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Position pos = map.getFood()._pos;
	// 设置绘制字符的位置
	COORD position = { pos._y, pos._x + 6};

	// 设置要绘制的字符和属性
	char character = map.getFood()._foodSign;
	WORD attributes = FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;

	// 设置字符属性
	SetConsoleTextAttribute(hConsole, attributes);

	// 写入字符到指定位置
	DWORD charsWritten;
	WriteConsoleOutputCharacterA(hConsole, &character, 1, position, &charsWritten);

	// 恢复默认的字符属性
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}
void ShowGameRealTime(const Map& map, const Snake& snake, int gameWinTarget) {
	//system("cls");

	showSnake(snake);
	showFood(map);
}

bool GameEnd(char& key) {
	switch (key) {
	case '1':
		cout << "游戏胜利，将返回开始界面！" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '2':
		cout << "游戏失败！失败原因：撞上围墙，将返回开始界面！" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '3':
		cout << "游戏失败！失败原因：撞上自身，将返回开始界面！" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '4':
		cout << "游戏失败！失败原因：超出自身范围，将返回开始界面！" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '5':
		cout << "游戏失败！失败原因：撞上障碍物，将返回开始界面！" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '0':
		cout << "游戏退出，将返回开始界面！" << endl;
		system("pause");
		return true;
	default:
#if __DEBUG__
		cout << "游戏继续" << endl;
#endif
		return false;
		break;
	}
}

void startGame(Map& map, Snake& snake) {
	// 制作定时器
	// 首先得到开始游戏时的时间，单位是毫秒
	// 没33.4ms刷新一次，1s刷新30次；1s蛇移动1格或多格
	//float baseTime = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	//float runTime = baseTime;
	//float fixedTime = 10;

	char input;

	srand(time(0));
	int gameWinTarget = rand() % GAME_WIN_TARGET + START_SNAKE_LENGTH + 1;
	startShowGameRealTime(map, snake, gameWinTarget);
	//char input;


	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	// 设置输入模式，包括启用键盘输入事件
	DWORD mode;
	GetConsoleMode(hInput, &mode);
	SetConsoleMode(hInput, mode | ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	// 事件缓冲区
	INPUT_RECORD events[128];
	DWORD count;


	do {
#if __DEBUG__
		cout << "请输入你的操作(W / A / S / D)" << endl;
#endif
		//cin >> input;
		//定时器
		//runTime += fixedTime;

		// 读取输入事件
		ReadConsoleInput(hInput, events, 128, &count);
		for (DWORD i = 0; i < count; i++) {
			//system("pause");
			if (events[i].EventType == KEY_EVENT && events[i].Event.KeyEvent.bKeyDown) {
				// 按下键盘按键
				int keyCode = events[i].Event.KeyEvent.wVirtualKeyCode;
				// 处理按键事件，例如根据keyCode执行相应操作
				switch (keyCode) {
				case 'W':
				case 'w':
					//上
#if __DEBUG__
					cout << "W" << endl;
#endif

					snake.MoveUp();
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);

					break;
				case 'S':
				case 's':
					//下
#if __DEBUG__
					cout << "S" << endl;
#endif
					snake.MoveDown();
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);
					break;
				case 'A':
				case 'a':
					//左
#if __DEBUG__
					cout << "A" << endl;
#endif
					snake.MoveLeft();
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);
					break;
				case 'D':
				case 'd':
					//右
#if __DEBUG__
					cout << "D" << endl;
#endif
					snake.MoveRight();
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);
					break;
				case '0':
					//本局游戏结束 原因-游戏退出
					cout << "本局游戏结束" << endl;
					break;
				default:
#if __DEBUG__
					cout << "输入错误，请重新输入" << endl;
#endif
					snake.Move(snake.getDefaultMoveDirection());
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);
					break;
				}
			}
		}
		//debug
#if __DEBUG__
		cout << map.getFood() << endl;
		cout << "gameWinTarget: " << gameWinTarget << endl;
		cout << "snakeLength: " << snake.getSnakeLength() << endl;
		cout << "maxSnakeLength: " << MAX_SNAKE_LENGTH << endl;
		for (int i = 0; i < map.obstacleSize(); ++i) {
			cout << map.getIndexOfObstacle(i) << endl;
		}
		
#endif
		//结束原因 游戏胜利  游戏失败  游戏退出
		//
		if (GameEnd(input)) {
			break;
		}
		} while (true);

		InitGame(map, snake);
}
//撞墙
bool isCollisionWithFence(const Position& posSnakeHead) {
	return	posSnakeHead._x == 0			||
			posSnakeHead._x == ROW - 1	||
			posSnakeHead._y == 0			||
			posSnakeHead._y == COL - 1;
}
//吃食物
bool isCollisionWithFood(const Position& posSnakeHead, const Position& posFood) {
	return posSnakeHead._x == posFood._x && posSnakeHead._y == posFood._y;
}

//撞障碍物
bool isCollisionObstacle(const Position& posSnakeHead, const Map& map) {
	return map.isObstacle(posSnakeHead._x, posSnakeHead._y);
}

void GameCollisionDetection(Map& map, Snake& snake, char& input, int& gameWinTarget) {
	const Position& posSnakeHead = snake.getSnakeHead();
	const Position& posFood = map.getXYOfFood();
	//与围墙是否碰撞
	if (isCollisionWithFence(posSnakeHead)) {
#if __DEBUG__
		cout << "与围墙碰撞: " << "(" << posSnakeHead._x << "," << posSnakeHead._y << ")" << endl;

#endif
		//碰到围墙后 游戏结束
		input = '2';
		return;
	}
#if __DEBUG__
	else {
		cout << "未与围墙碰撞" << endl;
	}
#endif
	//与食物是否碰撞
	if (isCollisionWithFood(posSnakeHead, posFood)) {
#if __DEBUG__
		cout << "与食物碰撞: " << "(" << posSnakeHead._x << "," << posSnakeHead._y << ")" << endl;
#endif
		//蛇的身体长度 + 1  & 旧食物消失，随机种类的食物出现在地图上的随机位置
		//
		snake.BodyPlusOne();
		snake.getSnakeScore() += 1;
		map.FoodPositionUpdate();
		if (snake.getSnakeLength() > MAX_SNAKE_LENGTH) {
			input = '4';//蛇长度超出范围
			return;
		}
		if (snake.getSnakeLength() == gameWinTarget) {
			input = '1';//游戏胜利
			return;
		}
	}
#if __DEBUG__
	else {
		cout << "未与食物碰撞" << endl;
	}
#endif
	//与自身碰撞
	if (snake.isCollisionWithSnakeBody()) {
#if __DEBUG__
		cout << "蛇头与自身碰撞: " << "(" << posSnakeHead._x << "," << posSnakeHead._y << ")" << endl;
#endif
		input = '3';
		return;
	}
#if __DEBUG__
	else {
		cout << "未与自身碰撞" << endl;
	}
#endif
	//与障碍物是否碰撞
	if (isCollisionObstacle(posSnakeHead, map)) {
#if __DEBUG__
		cout << "与障碍物碰撞: " << "(" << posSnakeHead._x << "," << posSnakeHead._y << ")" << endl;
#endif
		//碰到障碍物后 游戏结束
		input = '5';
		return;
	}
#if __DEBUG__
	else {
		cout << "未与围墙碰撞" << endl;
	}
#endif
}