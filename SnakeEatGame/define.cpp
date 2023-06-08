#include "head.h"
//��̬ȫ�ֱ���ȷ��ֻ��һ��Դ�ļ��г��֡���ֹ�ض���
string Foods::_foods = foodSign;  // ��̬��Ա�����Ķ���
string Obstacles::_obstacles = obstacleSign; // �ϰ���
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
		cout << "���������ѡ��" << endl;

		cin >> option;
		switch (option) {
		case 1:
			//������Ϸ
#if __DEBUG__
			cout << "��ʼ��Ϸ" << endl;
#endif
			startGame(map, snake);
			Menu();
			break;
		case 2:
			//��Ϸ����
#if __DEBUG__
			cout << "��Ϸ����" << endl;
#endif
			break;
		case 0:
			//�˳���Ϸ
#if __DEBUG__
			cout << "�˳���Ϸ" << endl;
#endif
			break;
		default:
			//�������
#if __DEBUG__
			cout << "�����������������" << endl;
#endif
			break;
		}
	} while (option);
}

void Menu() {
	system("cls");
	cout << "*********************************" << endl;
	cout << "****          ̰����         ****" << endl;
	cout << "****                         ****" << endl;
	cout << "****        1.��ʼ��Ϸ       ****" << endl;
	cout << "****        2.��Ϸ����       ****" << endl;
	cout << "****        0.�˳���Ϸ       ****" << endl;
	cout << "*********************************" << endl;

}
void InitGame(Map& map, Snake& snake) {
	map = Map();
	snake = Snake();
}
void UpdateMap() {
	//�ߵ�λ�� �� ʳ���λ��

}

void startShowGameRealTime(const Map& map, const Snake& snake, int gameWinTarget) {
	system("cls");
	//��ʾ�˵���Ŀ����Ϣ
	cout << "Ŀ��ʳ����Ŀ: " << GAME_WIN_TARGET << endl;
	cout << "Ŀ���ߵĳ���: " << gameWinTarget << endl;
	cout << "��ʼ�÷�: " << 0 << "    " << "��ǰ�÷�: " << snake.getSnakeScore() << endl;//
	cout << "��ʼ�ߵĳ���: " << START_SNAKE_LENGTH << "    " << "��ǰ�ߵĳ���: " <<  snake.getSnakeLength() << endl;
	cout << "��ǰ�ϰ��������: " << map.obstacleSize() << endl;
	cout << "��ǰ��ͼ��С: " << ROW << " X " << COL << endl;


	//��ʾ��ͼ����
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			//Χǽ ��ʱ�� '!' ��ʾ
			if (map.getXYOfElement(i, j) == MAP_FENCE_LEFT_RIGHT 
				|| map.getXYOfElement(i, j) == MAP_FENCE_UP_DOWN) {
				cout << map.getXYOfElement(i, j);
			}
			else if (map.isObstacle(i, j)) {
				cout << map.getXYOfObstacleSign(i, j);
			}
			//������ʾ�ߵ�λ�ã� Χǽ����
			else if (snake.isSnake(i, j)) {
				cout << snake.getXYOfElement(i, j);
			}
			//Ĭ����ʾ��ͼ
			else {
				cout << map.getXYOfElementMapOrFood(i, j);
			}
		}
		cout << endl;
	}
}
void showSnake(const Snake& snake) {
	// ��ȡ��׼������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < snake.getSnakeLength(); ++i) {
		Position pos = snake.getSnakePrevPos(i);
		// ���û����ַ���λ��
		COORD position = { pos._y, pos._x + 6 };

		// ����Ҫ���Ƶ��ַ�������
		char character = DEFAULT_MAP_SIGN;
		WORD attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

		// �����ַ�����
		SetConsoleTextAttribute(hConsole, attributes);

		// д���ַ���ָ��λ��
		DWORD charsWritten;
		WriteConsoleOutputCharacterA(hConsole, &character, 1, position, &charsWritten);
	}

	for (int i = 0; i < snake.getSnakeLength(); ++i) {
		Position pos = snake.getSnakePos(i);
		// ���û����ַ���λ��
		COORD position = { pos._y, pos._x + 6 };

		// ����Ҫ���Ƶ��ַ�������
		char character = i == 0 ? SNAKE_HEAD_SIGN : SNAKE_BODY_SIGN;
		WORD attributes = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_RED | BACKGROUND_RED | BACKGROUND_INTENSITY;

		// �����ַ�����
		SetConsoleTextAttribute(hConsole, attributes);

		// д���ַ���ָ��λ��
		DWORD charsWritten;
		WriteConsoleOutputCharacterA(hConsole, &character, 1, position, &charsWritten);
	}

	// �ָ�Ĭ�ϵ��ַ�����
	//SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

}
void showFood(const Map& map) {
	// ��ȡ��׼������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Position pos = map.getFood()._pos;
	// ���û����ַ���λ��
	COORD position = { pos._y, pos._x + 6};

	// ����Ҫ���Ƶ��ַ�������
	char character = map.getFood()._foodSign;
	WORD attributes = FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;

	// �����ַ�����
	SetConsoleTextAttribute(hConsole, attributes);

	// д���ַ���ָ��λ��
	DWORD charsWritten;
	WriteConsoleOutputCharacterA(hConsole, &character, 1, position, &charsWritten);

	// �ָ�Ĭ�ϵ��ַ�����
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
		cout << "��Ϸʤ���������ؿ�ʼ���棡" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '2':
		cout << "��Ϸʧ�ܣ�ʧ��ԭ��ײ��Χǽ�������ؿ�ʼ���棡" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '3':
		cout << "��Ϸʧ�ܣ�ʧ��ԭ��ײ�����������ؿ�ʼ���棡" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '4':
		cout << "��Ϸʧ�ܣ�ʧ��ԭ�򣺳�������Χ�������ؿ�ʼ���棡" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '5':
		cout << "��Ϸʧ�ܣ�ʧ��ԭ��ײ���ϰ�������ؿ�ʼ���棡" << endl;
		system("pause");
		//key = '0';
		return true;
		break;
	case '0':
		cout << "��Ϸ�˳��������ؿ�ʼ���棡" << endl;
		system("pause");
		return true;
	default:
#if __DEBUG__
		cout << "��Ϸ����" << endl;
#endif
		return false;
		break;
	}
}

void startGame(Map& map, Snake& snake) {
	// ������ʱ��
	// ���ȵõ���ʼ��Ϸʱ��ʱ�䣬��λ�Ǻ���
	// û33.4msˢ��һ�Σ�1sˢ��30�Σ�1s���ƶ�1�����
	//float baseTime = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
	//float runTime = baseTime;
	//float fixedTime = 10;

	char input;

	srand(time(0));
	int gameWinTarget = rand() % GAME_WIN_TARGET + START_SNAKE_LENGTH + 1;
	startShowGameRealTime(map, snake, gameWinTarget);
	//char input;


	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	// ��������ģʽ���������ü��������¼�
	DWORD mode;
	GetConsoleMode(hInput, &mode);
	SetConsoleMode(hInput, mode | ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	// �¼�������
	INPUT_RECORD events[128];
	DWORD count;


	do {
#if __DEBUG__
		cout << "��������Ĳ���(W / A / S / D)" << endl;
#endif
		//cin >> input;
		//��ʱ��
		//runTime += fixedTime;

		// ��ȡ�����¼�
		ReadConsoleInput(hInput, events, 128, &count);
		for (DWORD i = 0; i < count; i++) {
			//system("pause");
			if (events[i].EventType == KEY_EVENT && events[i].Event.KeyEvent.bKeyDown) {
				// ���¼��̰���
				int keyCode = events[i].Event.KeyEvent.wVirtualKeyCode;
				// �������¼����������keyCodeִ����Ӧ����
				switch (keyCode) {
				case 'W':
				case 'w':
					//��
#if __DEBUG__
					cout << "W" << endl;
#endif

					snake.MoveUp();
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);

					break;
				case 'S':
				case 's':
					//��
#if __DEBUG__
					cout << "S" << endl;
#endif
					snake.MoveDown();
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);
					break;
				case 'A':
				case 'a':
					//��
#if __DEBUG__
					cout << "A" << endl;
#endif
					snake.MoveLeft();
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);
					break;
				case 'D':
				case 'd':
					//��
#if __DEBUG__
					cout << "D" << endl;
#endif
					snake.MoveRight();
					ShowGameRealTime(map, snake, gameWinTarget);
					GameCollisionDetection(map, snake, input, gameWinTarget);
					break;
				case '0':
					//������Ϸ���� ԭ��-��Ϸ�˳�
					cout << "������Ϸ����" << endl;
					break;
				default:
#if __DEBUG__
					cout << "�����������������" << endl;
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
		//����ԭ�� ��Ϸʤ��  ��Ϸʧ��  ��Ϸ�˳�
		//
		if (GameEnd(input)) {
			break;
		}
		} while (true);

		InitGame(map, snake);
}
//ײǽ
bool isCollisionWithFence(const Position& posSnakeHead) {
	return	posSnakeHead._x == 0			||
			posSnakeHead._x == ROW - 1	||
			posSnakeHead._y == 0			||
			posSnakeHead._y == COL - 1;
}
//��ʳ��
bool isCollisionWithFood(const Position& posSnakeHead, const Position& posFood) {
	return posSnakeHead._x == posFood._x && posSnakeHead._y == posFood._y;
}

//ײ�ϰ���
bool isCollisionObstacle(const Position& posSnakeHead, const Map& map) {
	return map.isObstacle(posSnakeHead._x, posSnakeHead._y);
}

void GameCollisionDetection(Map& map, Snake& snake, char& input, int& gameWinTarget) {
	const Position& posSnakeHead = snake.getSnakeHead();
	const Position& posFood = map.getXYOfFood();
	//��Χǽ�Ƿ���ײ
	if (isCollisionWithFence(posSnakeHead)) {
#if __DEBUG__
		cout << "��Χǽ��ײ: " << "(" << posSnakeHead._x << "," << posSnakeHead._y << ")" << endl;

#endif
		//����Χǽ�� ��Ϸ����
		input = '2';
		return;
	}
#if __DEBUG__
	else {
		cout << "δ��Χǽ��ײ" << endl;
	}
#endif
	//��ʳ���Ƿ���ײ
	if (isCollisionWithFood(posSnakeHead, posFood)) {
#if __DEBUG__
		cout << "��ʳ����ײ: " << "(" << posSnakeHead._x << "," << posSnakeHead._y << ")" << endl;
#endif
		//�ߵ����峤�� + 1  & ��ʳ����ʧ����������ʳ������ڵ�ͼ�ϵ����λ��
		//
		snake.BodyPlusOne();
		snake.getSnakeScore() += 1;
		map.FoodPositionUpdate();
		if (snake.getSnakeLength() > MAX_SNAKE_LENGTH) {
			input = '4';//�߳��ȳ�����Χ
			return;
		}
		if (snake.getSnakeLength() == gameWinTarget) {
			input = '1';//��Ϸʤ��
			return;
		}
	}
#if __DEBUG__
	else {
		cout << "δ��ʳ����ײ" << endl;
	}
#endif
	//��������ײ
	if (snake.isCollisionWithSnakeBody()) {
#if __DEBUG__
		cout << "��ͷ��������ײ: " << "(" << posSnakeHead._x << "," << posSnakeHead._y << ")" << endl;
#endif
		input = '3';
		return;
	}
#if __DEBUG__
	else {
		cout << "δ��������ײ" << endl;
	}
#endif
	//���ϰ����Ƿ���ײ
	if (isCollisionObstacle(posSnakeHead, map)) {
#if __DEBUG__
		cout << "���ϰ�����ײ: " << "(" << posSnakeHead._x << "," << posSnakeHead._y << ")" << endl;
#endif
		//�����ϰ���� ��Ϸ����
		input = '5';
		return;
	}
#if __DEBUG__
	else {
		cout << "δ��Χǽ��ײ" << endl;
	}
#endif
}