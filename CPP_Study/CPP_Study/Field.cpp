#include "Field.h"
#include "Monster.h"
#include "Player.h"
#include <stdlib.h> // rand() = iostream에도 포함되어있긴하지만 직접적으로 포함되어있는 라이브러리

Field::Field() : _monster(nullptr) {


}

// 소멸자
Field::~Field() {
	if (_monster != nullptr)
		delete _monster;
}

void Field::Update(Player* player) {
	if (_monster == nullptr)
		CreateMonster();

	StartBattle(player);
}

void Field::CreateMonster() {
	int randValue = 1 + rand() % 3;

	switch (randValue)
	{	// 상속 관계 think -> 자식클래스를 부모에 insert = o k !
	case MT_SLIME:
		_monster = new Slime();
		break;
	case MT_ORC:
		_monster = new Orc();
		break;
	case MT_SKELETON:
		_monster = new Skeleton();
		break;
	}
}

void Field::StartBattle(Player* player) {
	while (true)
	{
		player->PrintInfo();
		_monster->PrintInfo();

		// 플레이어 -> 몬스터 공격
		_monster->OnAttacked(player);
		if (_monster->isDead()) {
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			// mmonster의 생명주기는 field.h에서 관리하기에 여기서 바로 소멸!
			break;
		}

		// 몬스터 -> 플레이어 공격
		player->OnAttacked(_monster);
		if (player->isDead()) {
			player->PrintInfo();
			// player의 생명주기는 game.h에서 관리하고 있기에 game.h에서 소멸!
			// 관리하고 있는 곳에서 소멸해주면 관리 용이
			break;
		}
	}

}