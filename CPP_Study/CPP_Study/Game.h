#pragma once

// ���� ���� : �ϴ� �갡 ����'��' �Ұž�
class Player;	
class Field;

// is - a(����)(!!!)
// has - a(���)
class Game
{
public:
	// ������ .cpp��
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	// Player _player;
	// 	   #include "Player.h" �� ������� ---> player.h������ game.h�� �������ָ� ��ȯ�ϴ� ���� �߻�(����)
	// ��ó�� �����Ͱ� �ƴ� ��ü�� �������ָ�, only PLAYER�� ������ ������ �ȴ�
	// ������ ���� ���� ��ü ������ �ս� ���� O
	// ��ü �۾����� �״�� ����Ǳ⿡ �뷮 �ս� ���� O
	// (�� ��-ȿ������)

	// �������̱⿡ ��ü�� ����Ű�� '�ּ�'�� ��� �ִ� �ּ� �ٱ���
	Player* _player;
	Field* _field;
};

