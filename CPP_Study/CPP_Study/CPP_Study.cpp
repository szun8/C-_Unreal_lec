#include <iostream>
using namespace std;

// 오늘의 주제 : 다중 포인터

void SetMessage(const char* a) {
	a = "Bye";
}

void SetMessage(const char** a) {
	*a = "bye";
}

void SetMessage2(const char*& a) { // * + &
	a = "bye bye my blue";
}

int main()
{
	// 문자열 수정
	
	// .rdata Hello주소[H][e][l][l][o][\0]
	// .rdata Bye주소[B][y][e][\0]
	// msg[ Hello주소 ] << 8바이트
	const char* msg = "Hello";
	// main [매개변수][RET][지역변수(msg(Hello주소))] [매개변수(a(Hello주소 -> Bye주소))][RET][지역변수]

	SetMessage(msg);
	// cout << msg << endl;

	// Hello주소 [ Hello ] << 1바이트*6 == .rdata Hello주소[H][e][l][l][o][\0]
	// msg [ Hello주소 ] << 8바이트
	// pp[ &msg ] << 8바이트
	const char** pp = &msg;

	// main [매개변수][RET][지역변수(msg(Hello주소))] [매개변수(a(&msg))][RET][지역변수]
	SetMessage(&msg);
	cout << msg << endl;

	// [!] 포인터와 참조

	// main [매개변수][RET][지역변수(msg(Hello주소))] [매개변수(a(&msg))][RET][지역변수]
	SetMessage2(msg);

	return 0;
}