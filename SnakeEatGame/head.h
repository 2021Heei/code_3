#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cassert>
#include <list>
#include <map>
#include <set>
#include <cstdbool>
#include <cstring>
#include <chrono>
#include <windows.h>
using namespace std;


#define __DEBUG__ 0		 		//����ģʽ�����������Ϣ
#define COL 16
#define ROW 16
#define START_SNAKE_LENGTH 2		// ��ʼ�ߵĳ��� ͷ + �� ==>  1 + 1 = 2
#define SNAKE_HEAD_SIGN 'x'		// �ߵ�ͷ���ű�ʾ
#define SNAKE_BODY_SIGN '*'		// �ߵ�������ű�ʾ
#define DEFAULT_MAP_SIGN '_'		// Ĭ�ϵ�ͼ���ű�ʾ
#define MAP_FENCE_LEFT_RIGHT '#'	// ��ͼΧǽ�����
#define MAP_FENCE_UP_DOWN '#'		// ��ͼΧǽ�Ϻ���
#define FOOD_TYPE 1				// ʳ������
#define MAX_OBSTACLE_NUMBER 3		// һ���ϰ�������
#define MAX_OBSTACLE_GROUP_NUMBER	3	// ����м����ϰ���
#define OBSTACLE_COLOR_SIZE			//�ϰ�����ɫ���ַ�����Ĵ�С
#define MAX_SNAKE_LENGTH (ROW-2)*(COL-2) // ��������󳤶�
#define GAME_WIN_TARGET	10		// �ߵĳ��ȴﵽ   ʱ��Ϸʤ����ÿ�ֿ�����һ����Χ���
#define MAX_GAME_SCORE 99999		// ��Ϸ�÷����ֵ���������ֵ���������� 

static char obstacleSign[] = "@$%&";	//�ϰ�����ű�ʾ
static char foodSign[] = "food";	// ʳ����ű�ʾ���Ե��ߵ����峤�� + 1
enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct Position {
	friend ostream& operator<<(ostream& out, const Position& pos);

	Position(int x = 0, int y = 0)
		:_x(x)
		,_y(y) {}

	/*bool operator<(const Position& pos) const {
		return _x < pos._x || _y < pos._y;
	}*/
	int _x;
	int _y;
};

static class Foods {
public:
	static char getFoodsElement() {
		int index = rand() % _foods.size();
		return _foods[index];
	}
	static string _foods;
};



struct Food {
	friend ostream& operator<<(ostream& out, const Food& food);

	Food(int x = 0, int y = 0) 
		:_pos(x, y){
		_foodSign = Foods::getFoodsElement();
	}

	Position _pos;
	char _foodSign;
};

class Func {
public:
	bool operator()(const Position& pos1, const Position& pos2) const{
		if (pos1._x < pos2._x)
			return true;
		else if (pos1._x > pos2._x)
			return false;
		else
			return pos1._y < pos2._y;
	}
};

//�����ϰ���ṹ��
struct ObstacleBase {
	ObstacleBase(int x = 0, int y = 0, int score = 1, char sign = obstacleSign[0], const char color[OBSTACLE_COLOR_SIZE] = "color") {
		_pos._x = x;
		_pos._y = y;
		_score = score;
		_sign = sign;
		strcpy(_color, color);
	}

	Position _pos;
	int _score;
	char _sign;
	char _color[OBSTACLE_COLOR_SIZE];
};
//һ���ϰ����ʼ��
static class Obstacles {
public:
	static void getObstaclesElement(vector<ObstacleBase>& _obstacle) {
		//һ���ϰ���ĸ���   ��ÿ���ϰ���ķ�������
		int obstacleNumber = rand() % MAX_OBSTACLE_NUMBER + 1;
		//һ�εõ��ϰ���Ԫ���±꣬Ȼ����뵽�ϰ���vector��
		for (int i = 0; i < obstacleNumber; ++i) {
			int index = rand() % _obstacles.size();
			_obstacle.push_back(ObstacleBase(0,0,1,_obstacles[index]));
		}
	}
	static string _obstacles;
};
//һ���ϰ���ṹ��
struct Obstacle {
	friend ostream& operator<<(ostream& out, const Obstacle& obstacle);

	Obstacle(int x = 0, int y = 0){
		//_pos.resize(_obstacle.size());
		Obstacles::getObstaclesElement(_obstacle);
	}

	/*vector<Position> _pos;
	vector<char> _obstacleSign;*/

	vector<ObstacleBase> _obstacle;
};

class Snake {
public:
	//��ʼ����ɫ
	Snake() 
		:_snakeLength(START_SNAKE_LENGTH)
		,_snakeScore(0) {
		_snake.resize(ROW);
		for (int i = 0; i < ROW; ++i) {
			_snake[i].resize(COL);
			for (int j = 0; j < COL; ++j) {
				_snake[i][j] = ' ';
			}
		}
		//��ʼ�����ߵĳ���Ϊ2��ͷ����Ϊ 1  '>'��ʾ�����峤Ϊ 1  '+' ��ʾ
		//��ʼ�ߵ�λ�����
		//�����ߵ�λ�� Ϊ 7 7 ������Ϊ 7 6
		_snake[7][7] = SNAKE_HEAD_SIGN;
		_snake[7][6] = SNAKE_BODY_SIGN;
		_pos.reserve((ROW - 1) * (COL - 1));
		_pos.push_back(Position(7, 7));
		_pos.push_back(Position(7, 6));
	}

	Snake(int lengths) 
		:_snakeLength(START_SNAKE_LENGTH){
		_snake.resize(ROW);
		for (int i = 0; i < ROW; ++i) {
			_snake[i].resize(COL);
			for (int j = 0; j < COL; ++j) {
				_snake[i][j] = ' ';
			}
		}
		//��ʼ�����ߵĳ���Ϊlengths��ͷ����Ϊ 1  '>'��ʾ�����峤Ϊ lengths - 1  '+' ��ʾ
		//��ʼ�ߵ�λ�����
		//�����ߵ�λ�� Ϊ 7 7 ������Ϊ 7 6

		if (lengths > 10) lengths = 10;
		//�ݹ�����ȷ��ͷ�������λ��
#if __DEBUG__
		cout << "�ݹ�ȷ����ʼ�ߵ�����λ��" << endl;
#endif
	}
	bool isSnake(int i, int j) const{
		if (_snake[i][j] == SNAKE_HEAD_SIGN || _snake[i][j] == SNAKE_BODY_SIGN) {
			return true;
		}
		else {
			return false;
		}
	}
	void show() {
		for (int i = 0; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				cout << _snake[i][j];
			}
		}
		cout << endl;
	}
	//�õ���ӦԪ��
	const char& getXYOfElement(int x, int y) const {
		return _snake[x][y];
	}
	const Position& getSnakeHead() const{
		return _pos[0];
	}
	char& getXYOfElement(int x, int y) {
		return _snake[x][y];
	}
	const int& getSnakeLength() const {
		return _snakeLength;
	}
	const Position& getSnakePos(int i) const {
		return _pos[i];
	}
	const Position& getSnakePrevPos(int i) const {
		return _prevPos[i];
	}
	void MoveUp() {
		//��
		Move(Direction::UP);

	}

	void MoveDown() {
		Move(Direction::DOWN);

	}

	void MoveLeft() {
		Move(Direction::LEFT);

	}

	void MoveRight() {
		Move(Direction::RIGHT);
	}

	void Move(Direction dir) {
		//��¼�����ߵ�λ����Ϣ�� ֮��ı�
		_prevPos = _pos;

		_snake[_pos[_snakeLength - 1]._x][_pos[_snakeLength - 1]._y] = DEFAULT_MAP_SIGN;
		//ת��Ϊ��һάλ������ĸ��£��ƶ�֮��βԪ������������Ԫ������������Ԫ�ظ��£������Ԫ�����ƶ��������
		for (int i = _pos.size() - 1; i > 0; --i) {
			_pos[i] = _pos[i - 1];
		}

		switch (dir) {
		case Direction::UP:
			--_pos[0]._x;
			break;
		case Direction::DOWN:
			++_pos[0]._x;
			break;
		case Direction::LEFT:
			--_pos[0]._y;
			break;
		case Direction::RIGHT:
			++_pos[0]._y;
			assert(_pos[0]._y < COL);
			break;
		}

		_snake[_pos[1]._x][_pos[1]._y] = SNAKE_BODY_SIGN;
		_snake[_pos[0]._x][_pos[0]._y] = SNAKE_HEAD_SIGN;
	}
	void BodyPlusOne() {
		//�ߵ����峤�� + 1  
		//ʳ���λ�ÿ���ˢ�³����������ڵ�λ���ϣ���ʱ�޷���ʾʳ����Ŷ��ߵĳ��� + 1
		//���ߵ����
		if (_prevPos.size() == 0) {
			//��һ�Σ���ʳ��ˢ�µ����ߵ����괦
			//��һ�Σ�û���ϴ��ߵļ�¼����Ҫ�Ƶ������Բ��õݹ�ʵ��Ѱ��
			//����Ϊ�˷��㣬���ճ�ʼ�ߵķ������ң�����ӵ���βҲ��ͬһ�У���x��������ͬ�ģ�y�������_pos�����һ��Ԫ���Ƶ�
			_pos.push_back(Position(7, 5));
		}
		else {
			//������ϴ��ߵļ�¼��ֱ�����ϴ��ߵļ�¼�����һ��Ԫ�ؼ���β����������ߵ�����β��Ҫ��ӵ����꣬�ұ�֤����Խ�磬��Ϊ����һ�εļ�¼��Խ���˻�����һ�α���������
			_pos.push_back(_prevPos[_prevPos.size() - 1]);
		}
		++_snakeLength;
		_snake[_pos[_snakeLength - 1]._x][_pos[_snakeLength - 1]._y] = DEFAULT_MAP_SIGN;
	}

	bool isCollisionWithSnakeBody() {
		//����ֻ�����ͷ�Ƿ�������������ͬ���ж��Ƿ���ײ
		//ʱ�临�Ӷ���O(n)��������Ϸ�Ľ��У��ߵĳ���Խ��Խ������ͷÿ����Ҫ�����岿�ֵļ�����ҲԽ��Խ��
		for (int i = 1; i < _pos.size(); ++i) {
			if (_pos[0]._x == _pos[i]._x && _pos[0]._y == _pos[i]._y) {
				return true;
			}
		}
		return false;
	}
	int& getSnakeScore() {
		return _snakeScore;
	}
	int getSnakeScore() const {
		return _snakeScore;
	}
	Direction getDefaultMoveDirection() {
		// ͨ����ͷ���ߵĲ��ӵ����λ���ж�Ĭ���ƶ�����
		// ˮƽ���� ��������ͬ�����������1��+1�������ƶ���-1�������ƶ�
		// ��ֱ���� ��������ͬ�����������1��+1�������ƶ���-1�������ƶ�
		int retX = _pos[0]._x - _pos[1]._x;
		if (retX == 1) {
			return Direction::DOWN;
		}
		else if (retX == -1){
			return Direction::UP;
		}
		int retY = _pos[0]._y - _pos[1]._y;
		if (retY == 1) {
			return Direction::RIGHT;
		}
		else {
			return Direction::LEFT;
		}
	}

private:
	int _snakeLength;
	int _snakeScore;
	vector<string> _snake;
	vector<Position> _pos;
	vector<Position> _prevPos;
};

class Map {
public:
	Map() {
		//16x16 ��ͼ �Ҵ��ڱ߽�Χǽ
		_map.resize(ROW);
		for (int i = 0; i < ROW; ++i) {
			_map[i].resize(COL);
			for (int j = 0; j < COL; ++j) {
				if (i == 0 || i == ROW - 1 || j == 0 || j == COL - 1) {
					_map[i][j] = MAP_FENCE_LEFT_RIGHT;
				}
				else {
					_map[i][j] = DEFAULT_MAP_SIGN;
				}
			}
		}

		FoodPositionUpdate();

		//�ϰ����ʼ��
		int obstacleGroupNumber = rand() % MAX_OBSTACLE_GROUP_NUMBER + 1;
		_obstacles.resize(obstacleGroupNumber);
		//vector ��Ϊlist���ã�����������Ҫ���ȫ������������ȥ�����ϰ�����Ӷ�Ӧ�����꣬������һ������ӵ����ϰ���ͷ����list����
		vector<Position> usePos;
		usePos.reserve(MAX_OBSTACLE_NUMBER * 4);
		for (int i = 0; i < obstacleGroupNumber; ++i) {
			for (int j = 0; j < _obstacles[i]._obstacle.size(); ++j) {
				usePos.clear();
				
				if (j == 0) {
					//����ʳ�Ҳ������
					int& x = _obstacles[i]._obstacle[j]._pos._x;
					int& y = _obstacles[i]._obstacle[j]._pos._y;
					do {
						x = rand() % (ROW - 2) + 1;
						y = rand() % (COL - 2) + 1;
					} while (isFood(x, y) 
						&& ((x == 7 && y == 7) || (x == 7 && y == 6)));
				}
				else {
					//�����µ��ϰ�������꣬��ԭ�ȵ��ϰ����Ƶ������ȷ��
					//����һ���ϰ�������ܣ����������ĸ�λ�ã����������ǣ�����Χǽ������ʳ������ϰ��������
					int& x = _obstacles[i]._obstacle[j]._pos._x;
					int& y = _obstacles[i]._obstacle[j]._pos._y;
					
					for (int k = 0; k < j; ++k) {
						int& px = _obstacles[i]._obstacle[k]._pos._x;
						int& py = _obstacles[i]._obstacle[k]._pos._y;
						//��
						if (!isFence(px - 1, py) && !isFood(px - 1, py)
							&& ((px - 1 != 7 && py != 7) && (px - 1 != 7 && py != 6)) ) {
							//�����ߵ��ж������޷����ߵı���snake�õ��ߵ�λ����Ϣ��������ʱʹ�ù̶������ж�
							usePos.push_back(Position(px - 1, py));
						}
						//��
						if (!isFence(px + 1, py) && !isFood(px + 1, py)
							&& ((px + 1 != 7 && py != 7) && (px + 1 != 7 && py != 6))) {
							//�����ߵ��ж������޷����ߵı���snake�õ��ߵ�λ����Ϣ��������ʱʹ�ù̶������ж�
							usePos.push_back(Position(px + 1, py));
						}
						//��
						if (!isFence(px, py - 1) && !isFood(px, py - 1)
							&& ((px != 7 && py - 1 != 7) && (px != 7 && py - 1 != 6))) {
							//�����ߵ��ж������޷����ߵı���snake�õ��ߵ�λ����Ϣ��������ʱʹ�ù̶������ж�
							usePos.push_back(Position(px, py - 1));
						}
						//��
						if (!isFence(px, py + 1) && !isFood(px, py + 1)
							&& ((px != 7 && py + 1!= 7) && (px != 7 && py + 1 != 6))) {
							//�����ߵ��ж������޷����ߵı���snake�õ��ߵ�λ����Ϣ��������ʱʹ�ù̶������ж�
							usePos.push_back(Position(px, py + 1));
						}
					}

					//�ڿ��������������һ����Ϊ���ϰ��������
					int index = rand() % usePos.size();
					x = usePos[index]._x;
					y = usePos[index]._y;

				}
				_obstaclesSearch[_obstacles[i]._obstacle[j]._pos] = _obstacles[i]._obstacle[j]._sign;
			}
		}
	}

	bool isFence(int x, int y) const {
		return x == 0 || x == ROW - 1 || y == 0 || y == COL - 1;
	}
	bool isFood(int x, int y) const {
		return x == _food._pos._x && y == _food._pos._y;
	}
	bool isObstacle(int x, int y) const {
		return _obstaclesSearch.find(Position(x, y)) != _obstaclesSearch.end();
	}
	void show() {
		for (int i = 0; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				if(i == _food._pos._x && j == _food._pos._y){
					cout << _food._foodSign;
				}
				else {
					cout << _map[i][j];
				}
			}
			cout << endl;
		}
	}
	//�õ���ӦԪ��
	const char& getXYOfElement(int x, int y) const{
		return _map[x][y];
	}

	char& getXYOfElement(int x, int y){
		return _map[x][y];
	}
	const Position& getXYOfFood() const {
		return _food._pos;
	}
	const Food& getFood() const {
		return _food;
	}
	const char& getXYOfElementMapOrFood(int x, int y) const{
		if (x == _food._pos._x && y == _food._pos._y) {
			return _food._foodSign;
		}
		else {
			return _map[x][y];
		}
	}
	const Obstacle& getIndexOfObstacle(int index) {
		assert(index >= 0 && index < _obstacles.size());
		return _obstacles[index];
	}
	const char& getXYOfObstacleSign(int x, int y) const {
		return _obstaclesSearch.find(Position(x, y))->second;
	}
	int obstacleSize() const {
		return _obstacles.size();
	}
	void FoodPositionUpdate() {
		srand(time(0));
		//��ʳ����ʧ����������ʳ������ڵ�ͼ�ϵ����λ��
		//ʳ���λ�ÿ���ˢ�³����������ڵ�λ���ϣ���ʱ�޷���ʾʳ����Ŷ��ߵĳ��� + 1
		//ʳ��λ��
		//Ŀ�� [1, ROW-2] �� [1, COL-2] ��Ϊ 1 �� ROW-1/COL-1����Χǽ
		//�������Ч�ʵ������ǰѷ��ϰ�������걣����һά�����У�Ȼ���������һά����������ʳ�����꣬������֤һ�ξͿ��Եõ�ʳ����Ч�����꣬�������ϰ���̫����������ϲ��ѭ����βŵõ�������俨
		do {
			_food._pos._x = rand() % (ROW - 2) + 1;
			_food._pos._y = rand() % (COL - 2) + 1;
		} while (isObstacle(_food._pos._x, _food._pos._y));
#if __DEBUG__
		cout << "food: " << _food._foodSign << "(" << _food._pos._x << "," << _food._pos._x << ")" << endl;
#endif
		//ʳ������
		_food._foodSign = Foods::getFoodsElement();
	}
private:
	vector<string> _map;
	Food _food;
	vector<Obstacle> _obstacles;
	map<Position, char, Func> _obstaclesSearch;
};

//��Ϸ��װ�����е��ö���Game�����ڣ�main�����ٵ���Game����
void Game(Map& map, Snake& snake);
void Menu();
void InitGame(Map& map, Snake& snake);
void UpdateMap();

void ShowGameRealTime(const Map& map, const Snake& snake, int gameWinTarget);


void startGame(Map& map, Snake& snake);

bool isCollisionWithFence(const Position& posSnakeHead);

bool isCollisionWithFood(const Position& posSnakeHead, const Position& posFood);

//��ײ���
void GameCollisionDetection(Map& map, Snake& snake, char& input, int& gameWinTarget);