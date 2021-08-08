#include <iostream>
using namespace std;

// 오늘의 주제 : 템플릿 기초

// 템플릿 : 함수나 클래스를 찍어내는 틀
// 1) 함수 템플릿
// 2) 클래스 템플릿
//-----------------------------------------------------

#pragma region 함수 템플릿
template<typename T>
// template<class T> 도 같은 의미로 가능하다!
// type별로 아래 함수를 재사용하는 것이 아니라,
// type별로 함수를 새로 만들어 주는 것
void Print(T a) {
	cout << a << endl;
}

// 아래와 같이 type을 두개 받아서
// 꼭 굳이 동일한 type의 매개변수를 받지 않아도 됨을 설명
template<typename T1, typename T2>
void Print(T1 a, T2 b) {
	cout << a << " " << b << endl;
}

template<typename T>
T Add(T a, T b) {
	return a + b;
}

class Knight {
public:

public:
	int _hp = 100;
};

// 우리가 특수하게 만든 class의 내용도 출력하고자 할 때,
// 
// 연산자 오버로딩 (전역함수.ver)
// cout -> ctrl + f12 = 어디서 정의됐는지 알수 있음
ostream& operator<< (ostream& os, const Knight& k) {
	os << k._hp;
	return os;
}

// 템플릿 특수화
template<>
void Print(Knight a) {
	cout << "!Knight!" << endl;
	cout << a._hp << endl;
}
#pragma endregion

#pragma region 클래스 템플릿

// typename '?'를 붙이면 '조커카드' (어떤 타입도 나 넣을 수 있음)
// 근데 무조건 typename을 붙여야 하는 것은 아님
template<typename Type, int SIZE=10>
// 디폴트 매개변수도 가능!
class RandomBox {
public:
	Type GetRandomData() {
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	Type _data[SIZE];
};

// 템플릿 특수화
template<int SIZE>
// 근데 특수화에선 디폴트 매개변수가 안된댕
// +)
// 특수화 시에는 기본 클래스 템플릿과 다르다는 것을 구분해주기 우해서
// 원하는 타입을 아래처럼 클래스 이름 옆 대괄호에 정의해준다
class RandomBox<double, SIZE> {
public:
	double GetRandomData() {
		cout << "RandomBox Double" << endl;
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	double _data[SIZE];
};
#pragma endregion


int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	// 알아서 type을 컴파일러가 추론해서 템플릿에 넣어주는 것
	Print<int>(50);
	// 대신 대괄호로 적어서 명시적으로 우리가 정해줄수도 있다.
	Print(50.5f);
	Print(50.0);
	Print("Hello World");
	
	Print("Hello World",100);

	Add(1, 2);
	Add<float>(1.11f, 2.22f);

	Knight k1;
	Print(k1);

	// --------------------------------------

	RandomBox<int,10> rb1;

	for (int i = 0; i < 10; i++) {
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;

	RandomBox<double, 20> rb2;

	for (int i = 0; i < 20; i++) {
		rb2._data[i] = i + 0.5;
	}
	int value2 = rb2.GetRandomData();
	cout << value2 << endl;

	// rb1 = rb2; => 결론적으로 같지 않게 인식
	// 비슷한 유형의 랜덤박스로 보일지라도 템플릿 인자로 받을때
	// 서로 다른 수가 있다면 개와 고양이 처럼
	// 완전히 다른 클래스 유형으로 인식함
	return 0;
}