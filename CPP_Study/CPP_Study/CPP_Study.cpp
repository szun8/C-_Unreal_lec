#include <iostream>
using namespace std;

// 오늘의 주제 : 로또 번호 생성기

void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Sort(int numbers[], int count) { // 0~5
	int j = 0;
	while (j < (count-1)) {
		for (int i = 0; i < count; i++) {
			if (i != count-1 && numbers[i] > numbers[i + 1]) {
				int temp = numbers[i + 1];
				numbers[i + 1] = numbers[i];
				numbers[i] = temp;
			}
		}
		j++;
	}
}

void Sort2(int numbers[], int count) { // 쌤 해답
	for (int i = 0; i < count; i++) {
		// i번째 값이 제일 좋은 후보라고
		int best = i;

		// 다른 후보와 비교를 통해 제일 좋은 후보 찾아나선다
		for (int j = i + 1; j < count; j++) {
			if (numbers[j] < numbers[best])
				best = j;
		}

		// 제일 좋은 후보와 교체하는 과정
		if(i!=best)
			Swap(numbers[i], numbers[best]);
	}
}

void ChooseLotto(int numbers[]) { // count 6가정

	srand((unsigned)time(0)); // 랜덤 시드 설정
	//TODO : 랜덤으로 1~45 사이의 숫자 6개를 골라주세요! (단 중복 X)

	// 1) 일단 6개의 영역에 숫자 넣기
	for (int i = 0; i < 6; i++) {
		numbers[i] = (rand() % 45) + 1; // 0~44
	}

	// 2) 숫자 중복 비교
	for (int i = 0; i< 6; i++) {
		int same = i;
		int another = 0 ;

		// 다른 후보와 비교를 통해 중복 후보를 찾아나선다
		for (int j = i + 1; j < 6; j++) {
			if (numbers[j] == numbers[same]) {
				numbers[j] = (rand() % 45) + 1;
			}
		}
	}
	// 3) 마지막 정렬
	Sort(numbers, 6);
}
int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);
	// a=2, b=1
	cout << "Swap 함수" << endl;
	cout << a << " " << b << endl;
	cout << "-----------------" << endl;

	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	cout << "정렬 함수" << endl;

	int numbers[6] = { 1,42,3,15,5,6 };
	Sort(numbers, sizeof(numbers) / sizeof(int)); 
	// 1 3 5 6 15 42
	for (int i = 0; i < 6; i++) {
		cout << numbers[i] << endl;
	}
	cout << "-----------------" << endl;

	// 3) 로또 번호 생성기
	cout << "로또 번호 생성기" << endl;
	ChooseLotto(numbers);
	for (int i = 0; i < 6; i++) {
		cout << numbers[i]<< " ";
	}

	return 0;
}