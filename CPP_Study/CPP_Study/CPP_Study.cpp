#include <iostream>
using namespace std;

// 오늘의 주제 : 배열

struct StatInfo {
	int hp=0xAAAAAAAA;
	int attack=0xBBBBBBBB;
	int defence=0xDDDDDDDD;
};

int main()
{
	// TYPE 이름[개수];

	// 배열의 크기는 상수여야 함 (VC 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음
	int a = 10;
	int b = a;

	// 그런데 배열은 [이름] 조금 다르게 동작
	// StatInfo players[10];
	// players = monsters;

	// 그럼 배열의 이름은 뭐지?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작 위치를 가리키는 TYPE(StatInfo)* 포인터
	auto WhoAmI = monsters; // auto = 타입 추론해 자료형 자동 지정

	// StatInfo(주소)[ (100, 10, 1) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ]...
	// monster_0[ 주소 ]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈!
	// StatInfo[ (100, 10, 1) ] StatInfo[ (200, 20, 2) ] StatInfo[ ] StatInfo[ ] StatInfo[ ]...
	// monster_1[ 주소 ]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능
	// StatInfo[ (100, 10, 1) ] StatInfo[ (200, 20, 2) ] StatInfo[ (300, 30, 3) ] StatInfo[ ] StatInfo[ ]...
	// monster_2[ 주소 ]
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이거는 위에와 완전 다른 의미
	// tmep[ 내용물 ]
	StatInfo temp; // 데이터 그 자체를 조작, 주소 조작 X
	temp = *(monsters + 2);
	temp.hp = 400;
	temp.attack = 40;
	temp.defence = 4;

	// 이를 조금 더 자동화 한다!
	for (int i = 0; i < 10; i++) {
		StatInfo& monster = *(monsters + i);
		monster.hp = (i + 1) * 100;
		monster.attack = (i + 1) * 10;
		monster.defence = (i + 1);
	}

	// 인덱스
	// *(monsters + i) = monster[i]
	for (int i = 0; i < 10; i++) {
		monsters[i].hp = (i + 1) * 100;
		monsters[i].attack = (i + 1) * 10;
		monsters[i].defence = (i + 1);
	}

	// 배열 초기화 문법 
	int numbers[5] = {}; // 다 0으로 초기화
	int numbers1[10] = { 1,2,3,4,5 }; // 초기화 하지 않은 부분은 0으로 초기화
	int numbers2[] = { 1, 2, 3, 4, 11, 24, 124, 14, 1 }; // 데이터 개수만큼의 크기에 해당하는 배열로 만들어줌
	char helloStr[] = "Hello";

	return 0;
}