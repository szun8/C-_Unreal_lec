#include <iostream>
using namespace std;

// 오늘의 주제 : 참조

// 원본 데이터를 수정하고자 하는데, 
// (주소 전달 방식인) 포인터로 매개변수를 넘겨주지 않는다면,
// (값 전달방식을 이용한다면,)
// 무조건 값복사라고 생각하고 원본 값은 조정되지 않는다

// 값을 읽기만을 원한다면, (예를들어 print)
// 값 전달 방식도 문제는 없

struct StatInfo {
	int hp;
	int attack;
	int defence;
};

void CreateMonster(StatInfo* info) {
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// 1) 값 전달 방식
void PrintInfoByCopy(StatInfo info) {
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;
}

// 2) 주소 전달 방식
void PrintInfoByPtr(StatInfo* info) {
	cout << "---------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "---------------------" << endl;
}

// StatInfo 구조체가 1000바이트짜리 큰 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는
// - (주소 전달) StatInfo*는 8바이트(CPU크기-64비트)
// - [!] (참조 전달) StatInfo*는 8바이트(CPU크기-64비트)

// 3) 참조 전달 방식
// 값 전달 처럼 편리하게 사용하고
// 주소 전달처럼 주소 값을 이용해 진퉁을 건드리는!
// 일석이조의 방식!

void PrintInfoByRef(StatInfo& info) {
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;
}

int main()
{
	// 4바이트 정수형 바구니를 사용
	// 앞으로 그 바구니 이름은 number
	// 그러니까 number에서 뭘 꺼내거나, 뭘 넣는다고 하면
	// 찰떡같이 알아듣고 해당 주소에 넣어주면 된다
	int number = 1;

	// * 
	// 주소를 담는 바구니
	// int 그 바구니를 따라가면 int 데이터(바구니)가 있음
	int* pointer = &number;
	// pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣는다
	*pointer = 2;

	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음
	// 실제로 실행해보면 포인터랑 100% 똑같다
	int& reference = number;

	// C++관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 reference라는 다른 이름을 지어줄게
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면,
	// 실제 number 바구니(진퉁에다가) 그 값을 꺼내거나 넣으면 됨!
	reference = 3;

	// 같다고 한다면 왜 굳이 참조를 사용하는가?
	// 참조 전달 때문!

	StatInfo info;
	CreateMonster(&info);

	PrintInfoByCopy(info);	// 값 전달
	PrintInfoByPtr(&info);	// 주소 전달
	PrintInfoByRef(info);	// 참조 전달

	return 0;
}