#include <iostream>
#include "Player.h"
using namespace std;

// 오늘의 주제 : 전방선언

int main()
{
	// Player는 몇 byte?
	// int 2ro = 2 * 4 = 8byte
	Player p1;	// 지역변수 (Stack)

	Player* p2 = new Player; // 동적할당 (Heap)

	p1._target = p2;	// player에 다른 player 연결

	return 0;
}