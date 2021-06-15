#include <iostream>
using namespace std;

// 오늘의 주제 : 다차원 배열

// 배열의 배열~

int main()
{
	// [4] [2] [3] [4] [1] << 0층
	// [1] [1] [5] [2] [2] << 1층

	int apartment2D[2][5] = { {4,2,3,4,1}, {1,1,5,2,2} };
	// 2차원 => 스택메몰는 1차원메모리로 나열된 상황

	for (int floor = 0; floor < 2; floor++) {
		for (int room = 0; room < 5; room++) {
			// apartment2D + (floor * 20) + 4 * room를 한 주소로 이동
			// 어셈블리어 : 먼저 어디 층에서 시작할 것인지에 대해 계산 및 이동
			int num = apartment2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}

	int apartment1D[10] = { 4,2,3,4,1,1,1,5,2,2 };

	for (int floor = 0; floor < 2; floor++) {
		for (int room = 0; room < 5; room++) {
			int index = (floor * 5) + room;
			// apartment1D + index(= (floor * 5) + room) * 4를 한 주소로 이동
			int num = apartment1D[index];
			cout << num << " ";
		}
		cout << endl;
	}

	// 1차원이랑 2차원이랑 어셈블리어에서는 약간의 계산 차이는 있지만 딱히 다른건 없음

	// 2차 배열은 언제 사용? 대표적으로 2D 로그라이크 맵
	int map[5][5] = {
		{1,1,1,1,1},
		{1,0,0,1,1},
		{0,0,0,0,1},
		{1,0,0,0,0},
		{1,1,1,1,1},

	};

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			int info = map[y][x];
			cout << info;
		}
		cout << endl;
	}

	return 0;
}