#include <iostream>
using namespace std;

// 상수인 건 알겠는데, 너무 따로따로 노는 느낌?
	// 하나의 세트인데?
const int SCICCORS = 1;
const int ROCK = 2;
const int PAPER = 3;
// 메모리를 조금이라도 잡을 가능성 O

enum ENUM_SRP { // ENUM 이름 설정 가능
		// 하나로 관리, 숫자 초기화를 안하면 첫 값은 0부터 시작
		// 그 다음 값들은 이전 값 + 1
	ENUM_SCISSORS = 5,
	ENUM_ROCK, // 6
	ENUM_PAPER // 7

	// 스택메모리에 영역을 차지 하지 않고 바로 그냥 사용 시, 해당되는 숫자로 떄려박아진다는 특징이 있음
	// 오직 가독성을 높이기 위해서만으로 사용!, 메모리 잡을 가능성 X
};
// #이 붙은 거 -> 전처리 지시문
// #include <iostream> 이라는 파일을 찾아서 해당 내용을 그냥 여기에 복붙!
// 디버그 단계 = 1) 전처리 2) 컴파일(통역) 3) 링크(파일단위 제작)

#define DEFINE_SCISSORS 1 // 이게 나오면 그냥 1이라는 값으로 대체해주세요
#define DEFINE_TEST cout << "Hello World" << endl;
// #define 은 그냥 코드 바꿔치기 개념이라고 알아두면 쉬울지도?
// 그래서 우선순위는 고려당하지 않고, 전처리 후 사라져버리는 개념이 되기에 디버깅 시 애매한 상황 발생

int main()
{
	DEFINE_TEST;

	srand(time(0)); // Seed값 설정해 랜덤값 랜덤으로 설정, rand()와 짝꿍!

	auto a = &SCICCORS; // 메모리에 올려져있지 않은 값을 메모리에 올려주는 역할을 하나? (아직 배우지 않은 것)
	
	int mine;

	int wins = 0;
	int total = 0;

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

