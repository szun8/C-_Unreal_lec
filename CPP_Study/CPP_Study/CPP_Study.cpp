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

unsigned char flag; // 부호를 없애야 >>를 하더라도 부호비트가 딸려오지 않음

// 데이터 하드코딩 지양

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 (변수를 상수화 한다고함)
// const를 붙였으면 초기값 반드시 지정

const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINVIBLE = 3;
// 보통 바꾸지 않는 값 설정 변수명은 대문자로 설정

// 전역 변수에 const를 지정하면 따로 컴파일러가 영역을 잡아서 처리하는게 아니라 바로 3처리
// 지역 변수에 const를 지정하면 전역과 다르게 스택영역을 잡아서 처리

// 전역 변수
// [데이터 영역]
// .data (초기값이 있는 경우)
int a = 2;
// .bss (초기값이 없는경우)
int b;
// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";

int main()
{
	// 지역 변수
	// [스택 영역]
	int c = 3;

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
	// 어셈블리어에서 까서 보여주는게 꽤나 이해하기 효과적이었음

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

#pragma region 비트 연산
// 언제 필요? : (사실 많이 X) 비트 단위의 조작이 필요할 때, 대표적으로 BitFlag
	// ~ bitwise not = 단일 숫자의 모든 비트를 대상으로, 0은 1/ 1은 0으로 뒤바꿈
	// & bitwise and = 두 숫자의 모든 비트 쌍을 대상으로 and를 한다
	// | bitwise or = 두 숫자의 모든 비트 쌍을 대상으로 or을 한다
	// ^ bitwise xor = 두 숫자의 모든 비트 쌍을 대상으로 xor을 한다

// << 비트 좌측 이동
	// - 비트열을 N만큼 왼쪽 이동
	// - 왼쪽의 넘치는 N개의 비트는 버림
	// - 새로 생성되는 N개의 비트는 0
	// - *2를 할 때 자주 보이는패턴

// >> 비트 우측 이동
	// - 비트열을 N만큼 오른쪽으로 이동
	// - 오른쪽의 넘치는 N개의 비트는 버림
	// - 왼쪽 생성되는 N개의 비트는 
	// 	   + 부호 비트가 존재할 겨우, 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
	// 	   + 아니면 0 (만약 부호 필요X면, unsigned 사용하는게 정신건강상 좋을듯,,,)

// 실습
	// 0b0000 [3.무적] [2.변이] [1.스턴] [0.공중부양]

	// 무적 상태로 만든다
	flag = (1 << INVINVIBLE); // 8로 컴파일 인식

	// 변이 상태를 추가 (무적 + 변이)
	flag |= (1 << POLYMORPH); // 위에서 설정한 무적상태를 유지하기 위해 bitwise or 사용 

	// 무적인지 확인하고 싶다? (다른 상태는 관심 없다고 가정)
	// bitmask : 내가 궁금한 것만 추출해서 확인시켜주는 좋은 기능
	bool invincible = ((flag & (1 << 3)) != 0); // (1<<3) : 이 부분이 bitmask

	// 무적이거나 스턴 상태인지 확인하고 싶다면?
	bool stunOrInvincivle1 = ((flag & (1 << 3)) | (flag & (1 << 1))) != 0; //me
	bool stunOrInvincivle2 = ((flag & 0b1010) != 0); //lesson

	bool mask = (1 << 3) | (1 << 1);
	bool stunOrInvincivle3 = ((flag & mask) != 0); //lesson
#pragma endregion
}	