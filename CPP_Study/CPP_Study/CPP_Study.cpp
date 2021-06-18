#include <iostream>
using namespace std;

// 오늘의 주제 : TextRPG2

// main
// - EnterLobby (PlayerInfo)
//	-- CreatePlayer
//	-- EnterGame (MonsterInfo)
//		--- CreateMonsters
//		--- EnterBattle

enum PlayerType {
	PT_knight=1,
	PT_Archer=2,
	PT_Mage=3
};

enum MonsterType {
	MT_Slime=1,
	MT_Orc=2,
	MT_Skeleton=3
};

struct StatInfo {
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerInfo);
void PrintStatInfo(const char* name, const StatInfo& info); // 복사보다 주소로 접근해 메모리 성능 고려
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterInfo[], int count);
bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo);

int main()
{
	srand((unsigned)time(nullptr));
	EnterLobby();
	return 0;
}

void EnterLobby() {
	while (true) {
		PrintMessage("로비에 입장했습니다");

		// PLAYER!  --- 얘의 정보가 EnterLobby함수 밖으로 나가는 일 X
		StatInfo playerInfo;
		CreatePlayer(&playerInfo);
		PrintStatInfo("Player", playerInfo); // ref로 사용중
		
		EnterGame(&playerInfo);
	}
}

void PrintMessage(const char* msg) {
	cout << "*************************" << endl;
	cout << msg << endl;
	cout << "*************************" << endl;
}

void CreatePlayer(StatInfo* playerInfo) {
	bool ready = false;
	while (ready==false) {
		// 올바른 값을 사용자가 입력해 플레이어를 생성했을 시,
		// 해당 while문 빠져나가자 !

		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 법사");
		cout << "> ";

		int input;
		cin >> input;

		switch (input)
		{
		case PT_knight:
			playerInfo->hp = 100;
			playerInfo->attack = 10;
			playerInfo->defence= 5;
			ready = true;
			break;
		case PT_Archer:
			playerInfo->hp = 80;
			playerInfo->attack = 15;
			playerInfo->defence = 3;
			ready = true;
			break;
		case PT_Mage:
			playerInfo->hp = 50;
			playerInfo->attack = 25;
			playerInfo->defence = 1;
			ready = true;
			break;
		}
	}
}

void PrintStatInfo(const char* name, const StatInfo& info) {
	cout << "*************************" << endl;
	cout << name << " : HP=" << info.hp << " ATT=" << info.attack << " DEF=" << info.defence << endl;
	cout << "*************************" << endl;
}

void EnterGame(StatInfo* playerInfo) {
	const int MONSTER_COUNT = 2;

	PrintMessage("게임에 입장했습니다");

	while (true) {
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);	// 몬스터 생성

		for (int i = 0; i < MONSTER_COUNT; i++) {
			PrintStatInfo("Monster", monsterInfo[i]);
		}

		PrintStatInfo("Player", *playerInfo);

		PrintMessage("[1] 전투 [2] 전투 [3] 도망");
		int input;
		cin >> input;

		if (input == 1 || input == 2) {
			int index = input - 1;
			bool victory = EnterBattle(playerInfo, &(monsterInfo[index]));
			// EnterGame에서 player정보를 포인터로 받고 있으니 그냥 적고,
			// monster의 정보는 배열이니 이름 그 자체로 포인터 = 그냥 적기!
			// 이지만 몬스터의 종류가 여러개이므로 원하는 index의 배열을 넣기
			// [+] index만 넘겨주면 함수 매개변수 설정상 주소를 넘겨줘야하기에 주소 처리 & 하기!

			if (victory == false)
				break;
		
		}
	}
}

void CreateMonsters(StatInfo monsterInfo[], int count) {
	for (int i = 0; i < count ; i++) {
		int randValue = (rand() % 3)+1; //1,2,3

		switch (randValue)
		{
		case MT_Slime:	// 1
			monsterInfo[i].hp = 30;
			monsterInfo[i].attack = 5;
			monsterInfo[i].defence = 1;
			break;
		case MT_Orc:	// 2
			monsterInfo[i].hp = 40;
			monsterInfo[i].attack = 8;
			monsterInfo[i].defence = 2;
			break;
		case MT_Skeleton:	// 3
			monsterInfo[i].hp = 50;
			monsterInfo[i].attack = 15;
			monsterInfo[i].defence = 1;
			break;
		}
	}
}

bool EnterBattle(StatInfo* playerInfo, StatInfo* monsterInfo) {
	while (true)
	{
		int damage = playerInfo->attack - monsterInfo->defence;
		if (damage < 0)
			damage = 0;

		monsterInfo->hp -= damage;
		if (monsterInfo->hp < 0)
			monsterInfo->hp = 0;

		PrintStatInfo("Monster", *monsterInfo);
		if (monsterInfo->hp == 0) {
			PrintMessage("몬스터를 처치헸습니다");
			return true;
		}

		damage = monsterInfo->attack - playerInfo->defence;
		if (damage < 0)
			damage = 0;

		playerInfo->hp -= damage;
		if (playerInfo->hp < 0)
			playerInfo->hp = 0;

		PrintStatInfo("Playerr", *playerInfo);
		if (playerInfo->hp == 0) {
			PrintMessage("GAME OVER");
			return false;
		}

	}
}