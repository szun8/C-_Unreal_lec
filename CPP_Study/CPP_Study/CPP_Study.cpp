#include <iostream>
using namespace std;

// 오늘의 주제 : 지역 변수와 '값' 전달 (call by value)

// 전역 변수 - 일부러 올려주지 않는 이상, 데이터 영역에 메모리 업로드
// 참고) 초기화 여부, const 등 .rodata/ .data/ .bss
int globalValue = 0;

void Test() {
	cout << "전역 변수의 값은 : " << globalValue << endl; // 성공
}

void IncreaseHp(int hp) {
	hp += 1;
}

// [매개변수][RET][지역변수] ---넘겨줄때 지역변수를 매개변수에 '복사'해서'값'만 넘겨주게됨--> [매개변수][RET][지역변수]
int main()
{
	int hp = 1;

	cout << "Increase 호출 전 :" << hp << endl;
	IncreaseHp(hp);
	cout << "Increase 호출 후 :" << hp << endl;


	cout << "전역 변수의 값은 : " << globalValue << endl; // 성공
	globalValue++;

	Test();

	// 지역 변수 : 함수 내부에 만든 변수 - 스택 영역에 메모리 업로드, 함수끼리 변수 공유 불가
	int localValue = 1;

	return 0;
}	

