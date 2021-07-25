#pragma once
class Monster; // 전방선언
class Player;

class Field	// 우글우글거리는 싸움장
{
public:
	Field();
	~Field();

	void Update(Player* player);
	void CreateMonster();

	void StartBattle(Player* player);
private:
	Monster* _monster;
	// 포인터이기에 몬스터의 구체적인 설계도는 필요없음 -> 전방선언으로 충족
};

