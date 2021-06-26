#include <iostream>
using namespace std;
#include <iomanip>

// 오늘의 주제 : 연습 문제_달팽이

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

enum DIR {
	RIGHT=0,
	DOWN,
	LEFT,
	UP=4
};

bool CanGo(int y, int x) { // 유효범위 및 재방문 체크
	if (y < 0 || y >= N)
		return false;
	if (x < 0 || x >= N)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;	// 위 조건들이 다 아니라면, 가도 됨 (유효범위)
}

void SetBoard() {
	int dir = RIGHT;

	int num = 1;
	int y = 0;
	int x = 0;

	int dy[] = { 0,1,0,-1 };
	int dx[] = { 1,0,-1,0 };

	while (true) {
		board[y][x] = num;

		if (num == N * N)
			break;

		int nextY = y + dy[dir];
		int nextX = x + dx[dir];

		/*switch (dir)
		{
		case RIGHT:
			nextY = y;
			nextX = x + 1;
			break;
		case DOWN:
			nextY = y + 1;
			nextX = x;
			break;
		case LEFT:
			nextY = y;
			nextX = x - 1;
			break;
		case UP:
			nextY = y - 1;
			nextX = x;
			break;
		}*/	
		// 다음 좌표 찾아주는 스위치문

		if (CanGo(nextY, nextX)) {
			y = nextY;
			x = nextX;	// 한 칸 이동
			num++;
		}		// 만약 갈 수 없는 방향이라면,
		else {	// 방향 조정

			dir = (dir + 1) % 4;	// 0 1 2 3

			/*switch (dir)
			{
			case RIGHT:
				dir = DOWN;
				break;
			case DOWN:
				dir = LEFT;
				break;
			case LEFT:
				dir = UP;
				break;
			case UP:
				dir = RIGHT;
				break;
			}*/
		}
	}
}

int main()
{
	cin >> N;
	SetBoard();

	PrintBoard();
	return 0;
}
