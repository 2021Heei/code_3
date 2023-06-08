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


#define __DEBUG__ 0		 		//调试模式，输出更多信息
#define COL 16
#define ROW 16
#define START_SNAKE_LENGTH 2		// 初始蛇的长度 头 + 身 ==>  1 + 1 = 2
#define SNAKE_HEAD_SIGN 'x'		// 蛇的头符号表示
#define SNAKE_BODY_SIGN '*'		// 蛇的身体符号表示
#define DEFAULT_MAP_SIGN '_'		// 默认地图符号表示
#define MAP_FENCE_LEFT_RIGHT '#'	// 地图围墙左和右
#define MAP_FENCE_UP_DOWN '#'		// 地图围墙上和下
#define FOOD_TYPE 1				// 食物种类
#define MAX_OBSTACLE_NUMBER 3		// 一组障碍物数量
#define MAX_OBSTACLE_GROUP_NUMBER	3	// 最多有几组障碍物
#define OBSTACLE_COLOR_SIZE			//障碍物颜色的字符数组的大小
#define MAX_SNAKE_LENGTH (ROW-2)*(COL-2) // 理论蛇最大长度
#define GAME_WIN_TARGET	10		// 蛇的长度达到   时游戏胜利，每局可以在一定范围随机
#define MAX_GAME_SCORE 99999		// 游戏得分最大值，超过这个值将不再增加 

static char obstacleSign[] = "@$%&";	//障碍物符号表示
static char foodSign[] = "food";	// 食物符号表示，吃掉蛇的身体长度 + 1
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

//单个障碍物结构体
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
//一组障碍物初始化
static class Obstacles {
public:
	static void getObstaclesElement(vector<ObstacleBase>& _obstacle) {
		//一组障碍物的个数   ，每个障碍物的符号类型
		int obstacleNumber = rand() % MAX_OBSTACLE_NUMBER + 1;
		//一次得到障碍物元素下标，然后插入到障碍物vector中
		for (int i = 0; i < obstacleNumber; ++i) {
			int index = rand() % _obstacles.size();
			_obstacle.push_back(ObstacleBase(0,0,1,_obstacles[index]));
		}
	}
	static string _obstacles;
};
//一组障碍物结构体
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
	//初始化角色
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
		//初始设置蛇的长度为2，头长恒为 1  '>'表示，身体长为 1  '+' 表示
		//初始蛇的位置随机
		//设置蛇的位置 为 7 7 ，身体为 7 6
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
		//初始设置蛇的长度为lengths，头长恒为 1  '>'表示，身体长为 lengths - 1  '+' 表示
		//初始蛇的位置随机
		//设置蛇的位置 为 7 7 ，身体为 7 6

		if (lengths > 10) lengths = 10;
		//递归依次确定头和身体的位置
#if __DEBUG__
		cout << "递归确定初始蛇的身体位置" << endl;
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
	//得到对应元素
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
		//上
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
		//记录本次蛇的位置信息， 之后改变
		_prevPos = _pos;

		_snake[_pos[_snakeLength - 1]._x][_pos[_snakeLength - 1]._y] = DEFAULT_MAP_SIGN;
		//转化为对一维位置数组的更新，移动之后尾元素舍弃，其余元素依次由相邻元素更新，最后首元素由移动方向更新
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
		//蛇的身体长度 + 1  
		//食物的位置可以刷新出现在蛇所在的位置上？这时无法显示食物符号而蛇的长度 + 1
		//在蛇的最后
		if (_prevPos.size() == 0) {
			//第一次，且食物刷新到了蛇的坐标处
			//第一次，没有上次蛇的记录，需要推导，可以采用递归实现寻找
			//这里为了方便，按照初始蛇的方向向右，新添加的蛇尾也在同一行，即x坐标是相同的，y坐标就由_pos的最后一个元素推导
			_pos.push_back(Position(7, 5));
		}
		else {
			//如果有上次蛇的记录，直接找上次蛇的记录的最后一个元素即蛇尾的坐标就是蛇的新蛇尾需要添加的坐标，且保证不会越界，因为是上一次的记录，越界了会在上一次被检查出来。
			_pos.push_back(_prevPos[_prevPos.size() - 1]);
		}
		++_snakeLength;
		_snake[_pos[_snakeLength - 1]._x][_pos[_snakeLength - 1]._y] = DEFAULT_MAP_SIGN;
	}

	bool isCollisionWithSnakeBody() {
		//这里只检测蛇头是否与蛇身坐标相同来判断是否碰撞
		//时间复杂度是O(n)，随着游戏的进行，蛇的长度越来越长，蛇头每次需要与身体部分的检测次数也越来越多
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
		// 通过蛇头与蛇的脖子的相对位置判断默认移动方向
		// 水平方向 横坐标相同，纵坐标相差1，+1则向右移动，-1则向左移动
		// 竖直方向 纵坐标相同，横坐标相差1，+1则向下移动，-1则向上移动
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
		//16x16 地图 且存在边界围墙
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

		//障碍物初始化
		int obstacleGroupNumber = rand() % MAX_OBSTACLE_GROUP_NUMBER + 1;
		_obstacles.resize(obstacleGroupNumber);
		//vector 改为list更好，这样不再需要清空全部容器，而是去掉新障碍物添加对应的坐标，对于下一个待添加的新障碍物头插在list即可
		vector<Position> usePos;
		usePos.reserve(MAX_OBSTACLE_NUMBER * 4);
		for (int i = 0; i < obstacleGroupNumber; ++i) {
			for (int j = 0; j < _obstacles[i]._obstacle.size(); ++j) {
				usePos.clear();
				
				if (j == 0) {
					//不是食物，也不是蛇
					int& x = _obstacles[i]._obstacle[j]._pos._x;
					int& y = _obstacles[i]._obstacle[j]._pos._y;
					do {
						x = rand() % (ROW - 2) + 1;
						y = rand() % (COL - 2) + 1;
					} while (isFood(x, y) 
						&& ((x == 7 && y == 7) || (x == 7 && y == 6)));
				}
				else {
					//对于新的障碍物的坐标，由原先的障碍物推导并随机确定
					//对于一个障碍物的四周（上下左右四个位置）可用坐标是：不是围墙，不是食物，不是障碍物，不是蛇
					int& x = _obstacles[i]._obstacle[j]._pos._x;
					int& y = _obstacles[i]._obstacle[j]._pos._y;
					
					for (int k = 0; k < j; ++k) {
						int& px = _obstacles[i]._obstacle[k]._pos._x;
						int& py = _obstacles[i]._obstacle[k]._pos._y;
						//上
						if (!isFence(px - 1, py) && !isFood(px - 1, py)
							&& ((px - 1 != 7 && py != 7) && (px - 1 != 7 && py != 6)) ) {
							//这里蛇的判断由于无法由蛇的变量snake拿到蛇的位置信息，所以暂时使用固定坐标判断
							usePos.push_back(Position(px - 1, py));
						}
						//下
						if (!isFence(px + 1, py) && !isFood(px + 1, py)
							&& ((px + 1 != 7 && py != 7) && (px + 1 != 7 && py != 6))) {
							//这里蛇的判断由于无法由蛇的变量snake拿到蛇的位置信息，所以暂时使用固定坐标判断
							usePos.push_back(Position(px + 1, py));
						}
						//左
						if (!isFence(px, py - 1) && !isFood(px, py - 1)
							&& ((px != 7 && py - 1 != 7) && (px != 7 && py - 1 != 6))) {
							//这里蛇的判断由于无法由蛇的变量snake拿到蛇的位置信息，所以暂时使用固定坐标判断
							usePos.push_back(Position(px, py - 1));
						}
						//右
						if (!isFence(px, py + 1) && !isFood(px, py + 1)
							&& ((px != 7 && py + 1!= 7) && (px != 7 && py + 1 != 6))) {
							//这里蛇的判断由于无法由蛇的变量snake拿到蛇的位置信息，所以暂时使用固定坐标判断
							usePos.push_back(Position(px, py + 1));
						}
					}

					//在可用坐标里随机找一个作为新障碍物的坐标
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
	//得到对应元素
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
		//旧食物消失，随机种类的食物出现在地图上的随机位置
		//食物的位置可以刷新出现在蛇所在的位置上？这时无法显示食物符号而蛇的长度 + 1
		//食物位置
		//目标 [1, ROW-2] 和 [1, COL-2] 因为 1 和 ROW-1/COL-1处是围墙
		//这里更有效率的做法是把非障碍物的坐标保存在一维数组中，然后在随机在一维数组中生成食物坐标，这样保证一次就可以得到食物有效的坐标，避免了障碍物太多或者运气较差导致循环多次才得到，程序变卡
		do {
			_food._pos._x = rand() % (ROW - 2) + 1;
			_food._pos._y = rand() % (COL - 2) + 1;
		} while (isObstacle(_food._pos._x, _food._pos._y));
#if __DEBUG__
		cout << "food: " << _food._foodSign << "(" << _food._pos._x << "," << _food._pos._x << ")" << endl;
#endif
		//食物种类
		_food._foodSign = Foods::getFoodsElement();
	}
private:
	vector<string> _map;
	Food _food;
	vector<Obstacle> _obstacles;
	map<Position, char, Func> _obstaclesSearch;
};

//游戏封装，所有调用都在Game函数内，main函数再调用Game函数
void Game(Map& map, Snake& snake);
void Menu();
void InitGame(Map& map, Snake& snake);
void UpdateMap();

void ShowGameRealTime(const Map& map, const Snake& snake, int gameWinTarget);


void startGame(Map& map, Snake& snake);

bool isCollisionWithFence(const Position& posSnakeHead);

bool isCollisionWithFood(const Position& posSnakeHead, const Position& posFood);

//碰撞检测
void GameCollisionDetection(Map& map, Snake& snake, char& input, int& gameWinTarget);