#include <iostream>
using namespace std;

// 오늘의 주제 : 상속성

// 객체지향(OOP) <-> 절차지향
// - 상속성 (코드의 재사용성) (객체사이의 계층적인 관계)
// - 은닉성
// - 다형성

// class는 일종의 설계도
// 
// 메모리
// [[Player]]
// [ Knight ]

// 상속(Inheritance) ? 부모 -> 자식에게 물려주는 것

// 생성자(N)/소멸자(1)
// 생성자는 탄생을 기념해서 호툴되는 함수?
// - Knight를 생성하면 -> Player의 생성자? Knight의 생성자?
// -> 솔로몬의 선택 ! 그냥 둘 다 호출하자!

// 아래와 같이 묶기 가능 ---> 보다 편한
// GameObject
// - Creature
// -- Player, Monster, Npc, Pet

// - Projectile
// -- Arrow, Fireball

// - Env(채집물 등)

// Item
// - Weapon
// -- Sword, Bow
// - Armor
// -- Helmet, Boots, Armor 
// ...

class GameObject {	// 최최상위 객체
public:
	int _objectId;
};

class Player : public GameObject {	// 최상위 객체
public:
	Player() {
		_hp = 0;
		_attack = 0;
		_defence = 0;

		cout << "Player() 기본 생성자 호출" << endl;
	}

	Player(int hp) {
		_hp = hp;
		_attack = 0;
		_defence = 0;

		cout << "Player(int hp) 생성자 호출" << endl;
	}

	~Player() {
		cout << "~Player() 소멸자 호출" << endl;
	}
	void Move() { cout << "Player Move 호출" << endl; }
	void Attack() { cout << "Player Attack 호출" << endl; }
	void Die() { cout << "Player Die 호출" << endl; }

public:
	int _hp;
	int _attack;
	int _defence;
};

class Knight : public Player {
public:
	// 기본생성자가 아닌 기타생성자로 호출해도 선처리 영역의 생성자 호출은 기본과 달라지지 않음
	Knight() 
	/*
		선(먼저)처리 영역 -> Player 생성자 호출
	*/
	{
		_stamina = 100;
		cout << "Knight() 기본 생성자 호출" << endl;
	}

	Knight(int stamina) : Player(100) // <- 이렇게 하면 선처리 영역에서 호출되는 생성자를 지정해줄 수 있음
		/*
			선(먼저)처리 영역 -> Player(int hp) 생성자 호출
		*/
	{
		_stamina = stamina;
		cout << "Knight(int stamina) 생성자 호출" << endl;
	}

	~Knight() {
		cout << "~Knight() 소멸자 호출" << endl;
	}
	/*
		후(나중에)처리 영역 -> ~Player 소멸자 호출
	*/

	// 재정의 : 부모의 유산을 거부하고 새로운 이름으로 만든?
	void Move() { cout << "Knight Move 호출" << endl; }

public:
	int _stamina;
};

class Mage : public Player {
public:
	

public:
	int _mp;
};

int main()
{
	Knight k(1);
	k._hp = 100;
	k._defence = 5;
	k._attack = 10;
	//k._stamina = 50;

	//k.Move();			// 자식 ver
	//k.Player::Move();	// 부모 ver

	//k.Attack();
	//k.Die();

	return 0;
}