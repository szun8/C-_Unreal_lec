#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 (프로시저, 메소드, 루틴)
/*
input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다

< 형태 >
반환타입 함수이름([인자 타입 매개변수])
{
	함수내용
	return ~~;
}
*/
// Hello World를 콘솔에 출력하는 함수를 만들어보자!
// input / output : 없음
// 입력받을 타입이 없다 = void

void PrintHelloWorld() {
	cout << "Hello World" << endl;
	return; // return을 만나게 되면 함수를 빠져나간다
}

// 정수를 입력(함수)받아서, 콘솔에 출력하는 함수를 만들어보자
// input : int // output : X
void PrintNumber(int number) {
	cout << "넘겨주신 숫자는 "<< number <<" 입니다" << endl;
}

// 2를 곱하고 결과물을 뱉는 함수를 만들어보자
// input & output : int

int MultiplyBy2(int a) { // 인자가 있으면 반한을 해야함!
	int b = a * 2;
	return b;
}

// 두 숫자를 곱해서 결과물을 뱉는 함수 제작
// input :int, int & output : int
int MultiplyBy(int a, int b) {
	int c = a * b;
	return c;
}

// < 디버그 종류 >
// F5 = 실행하다가 break point에서만 멈추기
// F10 = 함수 단위로 큰 덩어리씩만 실행
// F11 = 한 줄씩 실행

// 스택프레임
// = (매개변수 + 반환 주소값(함수가 끝났을때 돌아갈 주소 저장) + 지역변수)
// 의 단위로 스택 프레임이 쌓이고 해제됨

int main()
{
	int result1 = MultiplyBy2(3);
	PrintNumber(result1);

	int result2 = MultiplyBy(3,5);
	PrintNumber(result2);
	PrintHelloWorld();
}	

