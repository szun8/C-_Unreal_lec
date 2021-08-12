#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : vector

// STL (Standard Template Library)
// 프로그래밍할 때 필요한 자료구조/알고리즘들을
// 템플릿으로 제공하는 라이브러리

// Container : 데이터를 저장하는 객체 (자료구조 Data Structure)

// Array (배열) - 지정한 크기만큼만 사이즈 활용 가능하다는 단점 有
// 
// Vector (동적 배열) -> 배열을 '유동적으로' 사용한 것인가!?!?!?
// -> 1) (여유분을 두고) 메모리를 할당한다
//		-> Q1. 여유분은 얼만큼이 적당할까?
// -> 2) 할당해놨던 여유분까지 꽉 찼으면, 더 크게 메모리를 증설한다
// 		-> Q2. 증설을 얼만큼 해야할까?
//      -> Q3. 기존보다 더 크게 할 때, 기존의 데이터를 어떻게 처리할까?

// - vector의 동작 원리 (size/capacity)
// - 중간 삽입/삭제
// - 처음/끝 삽입/삭제
// - 임의 접근

int main()
{
	vector<int> v(1000, 0);	// resize말고 초기화 처음부터 사이즈할당 + 값 지정 가능
	vector<int> v2 = v;		// 복사도 가능!
	v.capacity();

	// size = 실제 사용 데이터개수 -> 당연 내가 넣은만큼 증가
	// size 크기도 초기 사용자 지정 가능
	v.resize(1000); // 다만, 그만큼 capacity도 증가

	// capacity = 여유분을 포함한 용량 개수
	//	-> A. 컴파일러에 따라 1.5(!) ~ 2배 만큼 여유분 증설
	// 근데 size == capacity 하면 안되냐?
	// 만약 그렇게 하다 배열 주소 뒤에 다른 메모리가 할당중이었다면,
	// 용량이 충분한 빈 주소로 가서 기존에 있던 데이터를 복사해주는 일이 발생
	// 너무 번거로움 (이사 비용이 여유분을 증설했을 경우보다 너무 많이 발생)
	// 1.5 ~ 2배씩 늘어나기에 일정 큰 용량을 capacity로 지정해줬다면, (1000,2000,4000...)
	// 안정과 여유가 생겨서 이사비용의 부담이 줄어들거임. (의 원리)

	// 근데 우리가 초반 용량을 정해줄수 있다면 capacity 초기 사용자 지정도 가능
	v.reserve(1000); // 처음 capacity 1000부터 시작
	
	for (int i = 0; i < 100; i++) {
		v.push_back(100);	// 할당한 사이즈 뒤에 !!추가!!로 넣는 것
		// v[i] = 100;			// index 접근
		cout << v.size() << " " << v.capacity() << endl;
	}

	// 근데 만약 데이터를 줄인다해도 capacity는 줄어들지 않음
	v.clear();
	cout << v.size() << " " << v.capacity() << endl;

	// capacity도 clear 하고싶다면, 임시벡터 만들어서 스왑해주기
	vector<int>().swap(v);	// Tip 이라고하네용 이런기능이 있다~ 정도!
	cout << v.size() << " " << v.capacity() << endl;

	// !--여러 기능들--! 
	v.front();		// 맨처음 있는 값 반환
	v.back();		// 맨뒤에 있는 값 반환
	v.pop_back();	// 맨뒤에 있는 값 삭제

	const int size = v.size();
	for (int i = 0; i < size; i++)
		cout << v[i] << endl;

	// Heap 영역 할당
	int* arr = new int[100];
	delete arr;
	arr = new int[1000];

	return 0;
}