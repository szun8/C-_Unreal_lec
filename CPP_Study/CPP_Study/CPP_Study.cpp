#include <iostream>
using namespace std;

int main()
{
	srand(time(0)); // Seed값 설정해 랜덤값 랜덤으로 설정, rand()와 짝꿍!
	
	int mine;

	int wins=0;
	int total = 0;

	const int SCICCORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;


	do {
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl << ">" << endl;

		if (total == 0) {
			cout << "현재 승률 : 없음" << endl;
		}
		else {
			//확률을 구해준다
			int winPecentage = (wins * 100) / total; // 승률
			cout << "현재승률 : " << winPecentage << endl;
		}

		cin >> mine; // 사용자
		int value = 1 + (rand() % 3); // 0.1,2 사이의 값, 컴퓨터

		if (mine == SCICCORS) { // 가위
			if (value == SCICCORS)
				cout << "가위(님) vs 가위(컴퓨터) 비겼습니다!" << endl;
			else if (value == ROCK) {
				cout << "가위(님) vs 바위(컴퓨터) 졌습니다!" << endl;
				total++;
			}
		
			else {
				cout << "가위(님) vs 보(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
			}
		}

		else if (mine == ROCK) { // 바위
			if (value == SCICCORS) {
				cout << "바위(님) vs 가위(컴퓨터) 이겼습니다!" << endl;
				wins++;
				total++;
			}
			else if (value == ROCK)
				cout << "바위(님) vs 바위(컴퓨터) 비겼습니다!" << endl;
			else {
				cout << "바위(님) vs 보(컴퓨터) 졌습니다!" << endl;
				total++;
			}
				
		}

		else if (mine == PAPER) { // 보
			if (value == SCICCORS) {
				cout << "보(님) vs 가위(컴퓨터) 졌습니다!" << endl;
				total++;
			}
				
			else if (value == ROCK) {
				cout << "보(님) vs 바위(컴퓨터) 이겼습니다!" << endl;
				total++;
				wins++;
			}
				
			else
				cout << "보(님) vs 보(컴퓨터) 비겼습니다!" << endl;
		}

		else
			break;

		cout << endl;

	} while (mine < 4 && mine > 0);

	

}	

