#include <iostream>
using namespace std;

// 오늘의 주제 : 데이터 연산
// 데이터를 '가공'하는 방법에 대해서 !

// a[ 1 ] : a라는 이름의 바구니를 할당하고 안에 1을 넣는다
int a = 1;
int b = 2;


int main()
{
#pragma region 산술 연산
	// 산술 연산자

	//대입연산
	a = b; 
	// a에 b를 대입하고 b를 반환
	// -> b라는 바구니 안에 있는 값을, a라는 바구니 안에 복사
	a = (b = 3); // 괄호에서 3을 반환에서 a에 대입

	//사칙연산
	// 언제 필요? ex) 데미지 계산, 체력소모&힐, 카운터 1증가

	a += 3; //	a = a + 3;
	// 우선순위 생각 -> 괄호 사용
	
	// 증감연산자
	a = a + 1; //add eax, 1 -> inc eax
	a++; //후위
	++a; //전위
	a--;
	--a;

	b = a++; // 1) b=a, 2) a+1
	b = ++a; // 1) a+1 2) b=a

#pragma endregion

}	