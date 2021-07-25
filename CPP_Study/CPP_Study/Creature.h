#pragma once

enum CreatureType {
	CT_PLAYER=0,
	CT_MONSTER=1
};
class Creature
{
public:
	Creature(int creatureType) 
		: _creatureType(creatureType), _hp(0), _attack(0), _defence(0) {

	}

	virtual ~Creature() {

	}

	virtual void PrintInfo() = 0;	// 순수가상함수 - 인터페이스만 적용, 자식 클래스들은 다 재정의 필요

	// player-monster가 서로 치고박는거니까 field보단 creature에 관련 함수 생성
	void OnAttacked(Creature* attacker);
	bool isDead() { return _hp <= 0; }

protected:
	int _creatureType;
	int _hp;
	int _attack;
	int _defence;
};

