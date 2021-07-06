#include <iostream>
using namespace std;

// 오늘의 주제 : 생성자와 소멸자

// [생성자(Construcotr)와 소멸자(Destructor)]
// 클래스에 '소속'된 함수들을 멤버 함수라고 함
// 이 중에서 굉장히 특별한 함수 2종, 바로 [시작]과 [끝]을 알리는 함수들
// - 시작(탄생) -> 생성자 (여러 개 존재 가능)
// - 끝(소멸) -> 소멸자 (오직 1개만 존재)

// [암시적(Implicit) 생성자] - 기본이랑 복사 둘다 생긴다!
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐
// -> 그러나 우리가 명시적(Explicit)으로 아무 생성자 하나 만들면,
// 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어지지 않음!

// class는 일종의 설계도

class Knight {
public:
	// [1] 기본 생성자 (인자가 없음, 반환 타입 X)
	Knight(){
		cout << "Knight()기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	// [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
	// (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대한다)
	Knight(const Knight& knight) {
		// 같은 아이를 복사하고자 하니 const가 99.9% 붙는다고 보면됨
		_hp = knight._hp;
		_attack = knight._attack;
		_posY = knight._posY;
		_posX = knight._posX;
	}

	// [3] 기타 생성자 (위의 것 이외의 생성자)

	// 이 중에서 인자를 1개만 받는 [기타 생성자]를
	// [타입 변환 생성자]라고 부르기도 함

	// 명시적인 용도로만 사용하고 싶다면? => explicit
	explicit Knight(int hp) {
		cout << "Knight(int) 생성자 호출" << endl;

		_hp = hp;
		_attack = 10;
		_posY = 0;
		_posX = 0;
	}

	// 소멸자
	~Knight() {
		cout << "~Knight() 소멸자 호출"<< endl;
	}

	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die() {
		_hp = 0;
		cout << "Die" << endl;
	}

public:
	// 멤버 변수
	int _hp;
	int _attack;
	int _posY;
	int _posX;
};

void Knight::Move(int y, int x) {
	_posY = y;
	_posX = x;
	cout << "Move" << endl;
}

void Knight::Attack() {
	cout << "Attack : " << _attack << endl;
}

// Instantiate 객체를 만든다!
int main()
{
	Knight k1(100);	// 생성자
	k1._hp = 100;
	k1._attack = 10;
	k1._posY = 0;
	k1._posX = 0;

	// 복사 생성자 : 같은 애 만들고 싶어
	Knight k2(k1);	
	Knight k3 = k1;

	Knight k4;	// 생성자
	k4 = k1;	// 복사

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// 암시적 형변환 -> 컴파일러가 알아서 바꿔치지
	int num = 1;	// 정수
	float f = (float)num;	// 명시적 < 우리가 코드로 num을 float 바구니에 넣으라고 주문
	double d = num;			// 암시적 << 별말 안했는데 컴파일러가 알아서 처리하고 있음

	Knight k5;
	k5 = (Knight)1;	// (?) -> 타입변환 생성자 --> Knight(int) 생성자로 변환되어 호출

	return 0;
}


