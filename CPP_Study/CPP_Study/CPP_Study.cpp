#include <iostream>
using namespace std;

// 오늘의 주제 : 반복문
/*
	데이터를 메모리에 할당하고 가공하고의 방법에 대해 알아봄
	가공한 데이터를 이용해서 무엇인가를 하고 싶다면?	
*/
int main()
{
	// while
	// if-else 굉장히 유용
	// 하지만 한번만 실행하는게 아니라, 특정조건까지 계속 반복해야 하는 상황
	// ex1) 게임을 끌 떄까지 계속 게임을 실행해라
	// ex2) 목적지에 도달할 때까지 계속 이동하라

	int count = 0;

	while (count < 5) {
		cout << "Hello World" << endl;
		count++;
	}

	do { // 무조건 한번은 괄호 안 내용 실행 후 조건식 판단
		cout << "Hello World" << endl;
		count++;
	} while (count < 5);

	// for
	// - 정해진 횟수를 원할 때
	
	for (int count2 = 0 ; count2 < 5 ; count2++) {
		cout << "Hello World" << endl;
	}

	// break; = 반복문에서 빠져나가주세요
	// continue; = 아래있는 명령문을 skip하고 반복 재실행

	int round = 1; 
	int hp = 100;
	int damage = 10;


	// 무한 루프 : 전투 시작
	while (true) {
		hp -= damage;
		if (hp < 0)
			hp = 0; //음 수체력을 0으로 보정

		// 시스템 메시지
		cout << "Round" << round << "몬스터체력" << hp << endl;

		if (hp == 0) {
			cout << "몬스터 처치!" << endl;
			break;
		}

		if (round == 5) {
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}

	// 1~10 사이의 홀수만 출력하기

	for (int i = 1; i <= 10; i++) {
		/*
		bool isEven = ((i % 2) == 0);
			1)	if(isEven == false)
					cout << i << endl;

			2)	if(isEven)
					continue; = 흐름 가로채서 다음 제어문 시작
		*/

		if(i % 2 == 1){
			cout << i << endl;
		}
	}
}	

