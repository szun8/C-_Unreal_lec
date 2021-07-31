#pragma once
class Player
{
public:
	Player();
	Player(int hp);

	// 멤버 클래스의 소멸자까지 호출이 되어야함
	virtual ~Player();

	void PrintInfo();

	void AddHp(int value);
	bool IsDead();

	int GetAttackDamage();

	void OnDamaged(Player* attacker);

public:

	int _hp;
	int _maxHp;
	int _attack;
};

