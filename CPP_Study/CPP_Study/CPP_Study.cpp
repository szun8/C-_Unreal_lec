#include <iostream>
using namespace std;

int main()
{
	// 연습문제

	// 별찍기)
	// 유저들이 어떤 정수를 입력하면,

	//1번)
		// n*n개의 별을 찍었으면 좋겠어요

	int input;
	cin >> input;

	for (int i = 0; i < input; i++) { // 줄
		for (int j = 0; j < input; j++) { // 별
			cout << "*";
		}
		cout << endl;
	}

	//2번)
		// 1개부터 시작해서 순차적으로 줄마다 증가하게 수정

	int input2;
	cin >> input2;

	for (int i = 0; i < input2; i++) {
		for (int j = 0; j < i+1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	//3번)
		// N개부터 시자해 줄마다 1개씩 줄어들기!

	int input3;
	cin >> input3;

	for (int i = 0; i < input3; i++) {
		for (int j = input3; j > i; j--) {
			cout << "*";
		}
		cout << endl;
	}

	// 구구단
		// 2단부터 9단까지


	for (int i = 2; i <= 9; i++) {
		cout << "[ " << i << "단 ]" << endl;
		for (int j = 1; j <= 9; j++) {
			cout << i << "*" << j << "=" << i * j << endl;
		}
		cout << endl;
	}
}	

