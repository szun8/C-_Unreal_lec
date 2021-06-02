#include <iostream>
using namespace std;

// 오늘의 주제 : !!!호출 스택!!! = 내 지금 함수가 어떤 경로로 호출 되게 됐는지 경로 역탐색
// 어셈블리언어에서 보면 함수를 호출 스택에서 가리키는게 아니라 그 다음 주소를 가리켜주고 있음(어디로 갈지에 대한)
// 다만, c++언어에서는 부정확하게 나타내어질 수 있으니 그닥 크게 신경 X (호출 코드가 한 줄이 아니기에 착시현상이 있음)

// 함수 선언 <-> 구현부
void Func1();
void Func2(int, int); // 아직 매개변수를 사용하지 않으니, 굳이 이름 부여를 선언에서 안해도 되긴함.
void Func3(float a);

// 함수 구현
void Func1() {
	cout << "Func1" << endl;

	// push2
	// push 1
	// call Func2
	Func2(1,2);
}

void Func2(int a, int b) {
	cout << "Func2" << endl;

	Func3(10);
}

void Func3(float a) {
	cout << "Func3" << endl;

}

int main()
{
	cout << "main" << endl;
	Func1();
	return 0;
}	

