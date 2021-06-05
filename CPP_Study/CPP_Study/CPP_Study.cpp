#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 마무리

// 1. 오버로딩 (중복정의 : 함수 이름의 재사용)
// - 매개변수 갯수 상이
// - 매개변수 타입 상이 (순서가 다른걸 포함)

int Add(int a, int b) {
	return a + b;
}

float Add(float a, float b) {
	return a + b;
}
// 어디로 갈 지 애매하지 않으면 문제 X

// 2. 기본인자값 (디폴트 매개변수)
// 항상 마지막 끝 쪽에 와야함.
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0, int castleId = 0) {

}

// 3. 스택 오버플로우 : 스택 메모리 고갈

int Factorial(int n) { // 재귀함수 호출
	if (n <= 1)
		return 1;

	return n * Factorial(n - 1);
}

int main()
{
	float result = Add(1.5f, 2.1f);
	cout << result << endl; // 3.6

	SetPlayerInfo(100, 40, 10);
	// castleId를 설정하고자 할때는 guildId도 C++에서는 설정해줘야함 ---> C#은 castleId:1 이렇게 다로 설정가능

	// 5! = 5*4*3*2*1
	int result2 = Factorial(5000000);
	cout << result2 << endl; // 3.6

	return 0;
}	

