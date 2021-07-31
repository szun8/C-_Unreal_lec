#pragma once
class Player
{
public:
	Player();
	Player(int hp);

	// ��� Ŭ������ �Ҹ��ڱ��� ȣ���� �Ǿ����
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

