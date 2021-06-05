﻿#include <iostream>
using namespace std;

// 오늘의 주제 : TextRPG

enum PlayerType {
	PT_Knight=1,
	PT_Archer,	// 2
	PT_Mage		// 3
};

enum MonsterType {
	MT_Slime = 1,
	MT_Orc,	// 2
	MT_Skeleton	// 3
};

struct ObjectInfo { // 구조체
	short type;
	int hp;
	char attack;
	int defence;
	// 이론상 2+4+1+4 = 11bytes
	// 그러나 이 구조체의 크기는 11이 아닐수도 있음 
	// ---> 메모리영역에 padding 값을 같이 넣어줘서 컴퓨터가 계산하기 쉽게 정렬함 (나중에 더 이야기해볼거임.)
	// 실제로 까보면 short를 4byte로 잡고 있음
};

ObjectInfo playerInfo;
ObjectInfo monsterInfo;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	// 랜덤 시드 설정
	srand(time(0));

	EnterLobby();

	return 0;
}	

void EnterLobby() {
	while (1) {
		cout << "--------------------" << endl;
		cout << "로비에 입장했습니다!" << endl;
		cout << "--------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << "---------------------------" << endl;
		cout << "(1) 필드 입장 (2) 게임 종료" << endl;
		cout << "---------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1) {
			EnterField();
		}
		else {
			return;
		}
	}
}

void SelectPlayer() {
	while (1) {
		cout << "------------------" << endl;
		cout << "직업을 골라주세요!" << endl;
		cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
		cout << "> ";

		cin >> playerInfo.type; //input
		if (playerInfo.type == PT_Knight) {
			cout << "기사 생성중..." << endl;
			playerInfo.hp = 150;
			playerInfo.attack = 10;
			playerInfo.defence = 5;
			break;
		}
		else if (playerInfo.type == PT_Archer) {
			cout << "궁수 생성중..." << endl;
			playerInfo.hp = 100;
			playerInfo.attack = 15;
			playerInfo.defence = 3;
			break;

		}
		else if (playerInfo.type == PT_Mage) {
			cout << "법사 생성중..." << endl;
			playerInfo.hp = 80;
			playerInfo.attack = 25;
			playerInfo.defence = 0;
			break;

		}
		// 세 개도 아니라면 다시 반복문 돌아서 직업선택!
	}
}

void EnterField() {
	while (1) {
		cout << "--------------------" << endl;
		cout << "필드에 입장했습니다!" << endl;
		cout << "--------------------" << endl;

		cout << "[PLAYER] HP : " << playerInfo.hp << " / ATT : " << playerInfo.attack << " / DEF : " << playerInfo.defence << endl;
		CreateRandomMonster();

		cout << "--------------------" << endl;
		cout << "(1) 전투 (2) 도주" << endl;
		cout << "> ";

		int input;
		cin >> input;

		if (input == 1) {
			EnterBattle();
			if (playerInfo.hp == 0)
				return;
		}
		else
			return;
	}
}

void CreateRandomMonster() {
	// 1~3 랜덤 출력
	monsterInfo.type = 1 + (rand() % 3);

	switch (monsterInfo.type)
	{
	case MT_Slime:
		cout << " 슬라임 생성중...! (HP:15 / ATT:5 / DEF:0)" << endl;
		monsterInfo.hp = 15;
		monsterInfo.attack = 5;
		monsterInfo.defence = 0;
		break;
	case MT_Orc:
		cout << " 오크 생성중...! (HP:40 / ATT:10 / DEF:3)" << endl;
		monsterInfo.hp = 40;
		monsterInfo.attack = 10;
		monsterInfo.defence = 3;
		break;
	case MT_Skeleton:
		cout << " 스켈레톤 생성중...! (HP:80 / ATT:15 / DEF:5)" << endl;
		monsterInfo.hp = 80;
		monsterInfo.attack = 15;
		monsterInfo.defence = 5;
		break;
	}
}

void EnterBattle() {
	while (1) {
		int damage = playerInfo.attack - monsterInfo.defence;
		if (damage < 0)
			damage = 0;

		//선빵
		monsterInfo.hp -= damage;
		if (monsterInfo.hp < 0)
			monsterInfo.hp = 0;

		cout << "몬스터 남은 체력 : " << monsterInfo.hp << endl;
		if (monsterInfo.hp == 0) {
			cout << "몬스터를 처치했습니다!" << endl;
			return; // break;
		}
		
		damage = monsterInfo.attack - playerInfo.defence;
		if (damage < 0)
			damage = 0;

		// 반격
		playerInfo.hp -= damage;
		if (playerInfo.hp < 0)
			playerInfo.hp = 0;

		cout << "플레이어 남은 체력 : " << playerInfo.hp << endl;
		if (playerInfo.hp == 0) {
			cout << "당신은 사망했습니다... GAME OVER" << endl;
			return; // break;
		}
	}
}

