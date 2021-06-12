#include <iostream>
using namespace std;

// 오늘의 주제 : 포인터 vs 참조

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

StatInfo globalInfo;	

// 2) 주소 전달 방식
void PrintInfoByPtr(const StatInfo* const info) {
	// 포인터가 가지는 특성 상 만약의 경우를 대비해,
	if (info == nullptr)
		return;	// 아무값도 가지지 않는다면 종료해주는 조건문

	cout << "---------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "---------------------" << endl;

	// 별 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 바구니의 내용물인 주소를 바꿀 수 
			// info = &globalInfo; (X)
	// info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다!

	// 별 이전에 붙인다면?
	// const StatInfo* info
	// info가 가리키고 있는 바구니의 내용물을 바꿀 수 없음
	// '원격' 바구니의 내용물을 바꿀 수 없음
			// info->hp = 10000;  (X)

	// info [ 주소값 ]	--->   주소값 [ 데이터 ]
	}

// StatInfo 구조체가 1000바이트짜리 큰 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는
// - (주소 전달) StatInfo*는 8바이트(CPU크기-64비트)
// - [!] (참조 전달) StatInfo*는 8바이트(CPU크기-64비트)

// 3) 참조 전달 방식
// 값 전달 처럼 편리하게 사용하고
// 주소 전달처럼 주소 값을 이용해 진퉁을 건드리는!
// 일석이조의 방식!

void PrintInfoByRef(const StatInfo& info) { // 읽기 전용
	// const 넣으면 값 변경 불가!
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;
}

#define OUT	// 전처리를 사용해서 
// 바뀐다는 것을 명시적으로 나타내주는 기능 사용
void ChangeInfo(OUT StatInfo& info) {
	info.hp = 1000;
}

int main()
{
	StatInfo info;
	CreateMonster(&info);

	// 성능 : 똑같음
	// 편의성 : 참조 승! 

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다
	// 포인터는 주소를 넘기니 확실하게 원본을 넘긴다는 힌트를 줄수있는데.
	// 참조는 자연스럽게 모르고 지나칠 수 있음
	// 예) 마음대로 고친다면?
	// const를 사용해 맘대로 사용하는 부분 개선 가능 (안정성 도모)

	// 참고로 포인터도 const를 사용가능.
	// 단, * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라짐

	// 2) 초기화 여부
	// 침조 타입은 바구니의 2번째 이름 (별칭?)
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 그냥 어떤~ 주소라는 의미
	// -> 대상이 실존하지 않을 수도 있음.

	// 포인터에서 '없다'는 의미로?
	StatInfo* pointer = nullptr; // 0 or NULL
	// pointer = &info;
	PrintInfoByPtr(pointer);	// 주소 전달

	// 참조 타입은 이런 nullptr의 개념이 없다
	StatInfo& reference = info;
	PrintInfoByRef(reference);	// 참조 전달
	ChangeInfo(OUT info);	// 그냥 info만 있을 때는 바뀐다는 힌트가 없는데,
	// OUT을 같이 사용해서 바뀐다는 힌트를 부여해줌 (가독성 측면)

	// BONUS 1) 포인터로 사용하던걸 참조로 넘겨주려면?
	// pointer[  주소(&info)  ]		ref, info[  데이터  ]
	StatInfo& ref = *pointer; // 새 별칭 지칭해주면 됨
	PrintInfoByRef(ref); // *를 붙여주면 pointer가 가리키는 주소로 넘어가라!

	// BONUS 2) 참조로 사용하던걸 포인터로 넘겨주려면?
	// pointer[  주소(&info)  ]		reference, info[  데이터  ]
	StatInfo* ptr = &reference;
	PrintInfoByPtr(ptr);

	return 0;
}