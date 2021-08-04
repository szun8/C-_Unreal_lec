#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터

// typedef ? : 메모리에 올라가는 개념이 아님, 그냥 있다정도로 선언하기에 불과
// typedef 왼쪽 오른값 -> 오른쪽 (커스텀 타입 정의)

// 사실 타입정의값이 복잡해질수록 왼/오 로만 구분하기 어려워짐
// 정확히는 왼/오 기준이 아니라,
// [선언 문법]에서 typedef을 앞에다 붙이는 쪽

typedef int(*PFUNC)(int, int);	//어디에 포인터를 붙이는지 괄호로 정확하게 표기하기!
int Test(int a, int b) {

	cout << "Test" << endl;
	return a + b;
}

class Knight {
public:
	// 멤버함수
	int GetHp(int a , int b) {
		return _hp;
	}
public:
	int _hp = 100;
};

// 그렇다면 class의 멤버함수 포인터는 ?
typedef int(Knight::*PMEMFUNC)(int, int);
// Knight(Class)안에 포함된 멤버함수 포인터를 정의해줘

int main()
{
	// function
	// 함수(반환형-int, 매개변수 int 2개를 받는)를 타입정의해서 사용하고 싶다면?
	// 형태 : typedef int(FUNC_TYPE)(int , int ); 

	// 같은 의미로 modern c++에서 아래와 같이 정의가능
	// using FUNC_TYPE = int(int a, int b);

	// 1) 포인터		*
	// 2) 변수 이름		fn
	// 3) 데이터 타입	함수 (인자는 int, int/ 반환은 int)
	// => int (*fn)(int, int);

	PFUNC fn;
	fn = &Test;		// & 생략 가능 (C언어 호환성 때문)
	
	fn(1, 2);
	(*fn)(1, 2);
	// 위 문법으로 [전역 함수 / 정적(static) 함수]만 담을 수 있다 (호출 규약이 동일한 애들)
	// -> class 멤버 함수는 해당 문법 통과 X = 객체의 함수를 호출하는 것이기 때문에 그냥 함수를 호출하는 것과 태생이 다름
	
	Knight k1;
	k1.GetHp(1, 1);

	// 멤버함수포인터 사용법
	PMEMFUNC mfn;
	mfn = &Knight::GetHp;	// 얘는 &(주소)표시 붙여줘야 통과
	// 객체를 불러와야하기에 인스턴스를 같이 부여줘야하는 규약이 있음)
	(k1.*mfn)(3,4);

	Knight* k2 = new Knight();	// 동적할당
	(k2->*mfn)(3, 4);	// * . = -> / ((*k2).*mfn)(3, 5);와 같은 의미

	delete k2;
	return 0;
}