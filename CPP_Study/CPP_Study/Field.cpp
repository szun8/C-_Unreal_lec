#include "Field.h"
#include "Monster.h"
#include "Player.h"
#include <stdlib.h> // rand() = iostream���� ���ԵǾ��ֱ������� ���������� ���ԵǾ��ִ� ���̺귯��

Field::Field() : _monster(nullptr) {


}

// �Ҹ���
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
	{	// ��� ���� think -> �ڽ�Ŭ������ �θ� insert = o k !
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

		// �÷��̾� -> ���� ����
		_monster->OnAttacked(player);
		if (_monster->isDead()) {
			_monster->PrintInfo();
			delete _monster;
			_monster = nullptr;
			// mmonster�� �����ֱ�� field.h���� �����ϱ⿡ ���⼭ �ٷ� �Ҹ�!
			break;
		}

		// ���� -> �÷��̾� ����
		player->OnAttacked(_monster);
		if (player->isDead()) {
			player->PrintInfo();
			// player�� �����ֱ�� game.h���� �����ϰ� �ֱ⿡ game.h���� �Ҹ�!
			// �����ϰ� �ִ� ������ �Ҹ����ָ� ���� ����
			break;
		}
	}

}