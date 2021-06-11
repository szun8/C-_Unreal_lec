#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 실습

// 포인터로 구조체를 넘길 때(monster) vs 그냥 반환값으로 복사해서 넘겨줄 때(player)
// 따라서, 포인터를 넘겨줄 때는 실제 원본을 대상으로 작업하기에 훨씬 더 빨리 됨 (효율 上)

struct StatInfo {
	int hp;			// offset +0
	int attack;		// +4
	int defence;	// +8
};

void EnterLobby();
StatInfo CreatePlayer();
void CreateMonster(StatInfo* info);
// 플레이어 승리 시 true, 아니면 false
bool StartBattle(StatInfo* player, StatInfo* monster);

int main()
{
	EnterLobby();
	
	return 0;
}

void EnterLobby() {
	cout << "로비에 입장했습니다" << endl;

	StatInfo player;
	// [매개변수][RET][지역변수(임시 저장소인 temp(100, 10, 2), player(b,b,b))] [매개변수(&temp)][RET][지역변수(ret(100, 10, 2))]
	player = CreatePlayer();
	// player = temp

	StatInfo monster;
	// [매개변수][RET][지역변수(monster(b,b,b))] [매개변수(&monster)][RET][지역변수()]
	// ->를 통해 지역변수 monster의 변수들을 접근, 조정
	CreateMonster(&monster); // 몬스터 구조체 넘겨주기

	// 번외편1)
	// 구조체끼리 복사할 때 무슨 일이 벌어질까?
	// player = monster;
	// 한줄이라도 빠른걸 의미 X

	bool victory = StartBattle(&player, &monster);

	if (victory)
		cout << "승리!" << endl;
	else
		cout << "패배!" << endl;

}

StatInfo CreatePlayer() {
	StatInfo ret; // 반환값
	cout << "플레이어 생성" << endl;

	ret.hp = 100;
	ret.attack = 10;
	ret.defence = 2;

	return ret;
}

void CreateMonster(StatInfo* info) {
	cout << "몬스터 생성" << endl;

	info->hp = 40;
	info->attack = 8;
	info->defence = 1;

}

bool StartBattle(StatInfo* player, StatInfo* monster) {
	while (true) {		// damage 변수는 그냥 계산용도 = 재사용 가능
		// 둘 중하나 죽을 때까지 무한정 반복!!
		int damage = player->attack - monster->defence;
		if (damage < 0)
			damage = 0;

		monster->hp -= damage;
		if (monster->hp < 0)
			monster->hp = 0;

		cout << "몬스터 HP : " << monster->hp << endl;

		if (monster->hp == 0) // 몬스터 죽음
			return true;

		damage = monster->attack - player->defence;
		if (damage < 0)
			damage = 0;

		cout << "플레이어 HP : " << player->hp << endl;

		player->hp -= damage;
		if (player->hp < 0)
			player->hp = 0;

		if (player->hp == 0) // 플레이어 죽음
			return true;

	}
}