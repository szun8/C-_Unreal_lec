#pragma once
class Monster; // ���漱��
class Player;

class Field	// ��ۿ�۰Ÿ��� �ο���
{
public:
	Field();
	~Field();

	void Update(Player* player);
	void CreateMonster();

	void StartBattle(Player* player);
private:
	Monster* _monster;
	// �������̱⿡ ������ ��ü���� ���赵�� �ʿ���� -> ���漱������ ����
};

