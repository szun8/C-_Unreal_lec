#pragma once

// 전방 선언 : 일단 얘가 등장'은' 할거야
class Player;	
class Field;

// is - a(포함)(!!!)
// has - a(상속)
class Game
{
public:
	// 구현은 .cpp에
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	// Player _player;
	// 	   #include "Player.h" 도 해줘야함 ---> player.h에서도 game.h를 선언해주면 순환하는 문제 발생(조심)
	// 위처럼 포인터가 아닌 객체를 선언해주면, only PLAYER의 정보만 가지게 된다
	// 직업에 따른 세부 객체 정보를 손실 가능 O
	// 객체 작업량도 그대로 복사되기에 용량 손실 가능 O
	// (걍 비-효율적임)

	// 포인터이기에 객체가 가리키는 '주소'만 담고 있는 주소 바구니
	Player* _player;
	Field* _field;
};

