#include <iostream>
using namespace std;

// 오늘의 주제 : 객체 지향의 시작

// 데이터 + 가공(로직, 동작)

// 객체지향 = 객체
// 객체란? 모든 obj, 플레이어/ 몬스터/ GameRoom

// 객체지향 프로그래밍

// 절차(procedural)지향 프로그래밍
// - procedure = 함수

// Knight를 설계해보자
// - 속성(데이터): hp, attack, position(x, y)
// - 기능(동작): Move, Attack, Die

struct A {

};
// 거의 C++에서는 구조체랑 클래스 차이 그닥 없음
// class는 일종의 설계도
class Knight {
public:
	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die() {
		hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
	int hp;
	int attack;
	int posY;
	int posX;
};

void Knight::Move(int y, int x) {
	posY = y;
	posX = x;
	cout << "Move" << endl;
}

void Knight::Attack() {
	cout << "Attack : " << attack << endl;
}

// Instantiate 객체를 만든다!
int main()
{
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posY = 0;
	k1.posX = 0;

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posY = 1;
	k2.posX = 1;

	return 0;
}


