#include <iostream>
using namespace std;

// 오늘의 주제 : 데이터 연산
// 데이터를 '가공'하는 방법에 대해서 !

// a[ 1 ] : a라는 이름의 바구니를 할당하고 안에 1을 넣는다
int a = 1;
int b = 2;

bool isSame;
bool isDifferent;
bool isGreater;
bool isSmaller;

bool test;

int hp = 100;
bool isinvincible = true; //무적상태

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

#pragma region 비교 연산
	// 언제 필요? 
	// Ex)
	// 체력이 0이 되면 사망
	// 경험치가 100 이상이면 레벨업
	// 체력이 30% 이하이면 궁극기를 발동 (100 * hp /maxHp)

	// a == b : 둘의 값이 같냐?
	// 같으면 1, 다르면 0 반환
	isSame = (a == b);

	// a != b : 둘의 값이 다르냐?
	// 다르면 1, 같으면 0 반환
	isDifferent = (a != b);

	// a > b : a의 값이 b보다 큼?
	// a >= b : a의 값이 b보다 크거나 같은가?
	isGreater = (a > b);

	// a < b : a의 값이 b보다 작냐?
	// a <= b : a의 값이 b보다 작거나 같은가?
	isSmaller = (a < b);

#pragma endregion

#pragma region 논리 연산
	// 언제 필요? : 조건에 대한 논리적 사고가 필요 = 여러가지 조건을 보고 상황을 종합적으로 판단해야할 때
	// Ex)
	// 로그인시, 아이디와 비밀번호도 같아야함 (AND)
	// 길드 마스터 이거나 운영자 계정이면 길드 해산이 가능 (OR)

	// ! not
	// 0이면, 1 / 1이면 0 반환
	test = !isSame; // = isDifferent의 의미

	// && and
	// a && b -> 둘다 1이면 1, 그외 0
	test = (hp <= 0 && isinvincible == false); //죽음

	// || or
	// a || b -> 둘 중 하나라도 1이면 1, 둘다 0이면 0
	test = (hp > 0 || isinvincible == true); //살았음
	!(hp <= 0 && isinvincible == false); //위와 같은 의미

#pragma endregion
}	