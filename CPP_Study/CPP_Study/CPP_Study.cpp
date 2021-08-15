#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : vector

// Container : 데이터를 저장하는 객체 (자료구조 Data Structure)

// - vector의 동작 원리 (size/capacity)

// 반복자 iterator : 포인터와 유사한 개념, 컨테이너의 원소(데이터)를 가리키고, 다음/이전 원소로 이동 가능

int main()
{
	vector<int> v(10);
	v.reserve(1000); //중간 메모리 이사를 막기 위해 capacity 지정
	// int 대신!
	for (vector<int>::size_type i = 0; i < v.size(); i++) {
		v[i] = i;
	}

	/*vector<int>::iterator it;
	it = v.begin();
	cout << (*it) << endl;

	int* ptr;
	ptr = &v[0];
	cout << (*ptr) << endl;*/

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	// 유효한 범위 다음의 범위를 가리키는 end()! => 즉 원치않은 쓰레기 값을 가지고 있다

	// (!) 아주 미세한 성능 차 = ++it > it++(복사하는 과정이 있기 때문에)

	// 위에 보다 더 복잡해보이는데? 
	// 다른 컨테이너는 v[i]와 같은 index 접근이 안될수도 있음
	// iterator는 vector뿐 아니라, 다른 컨테이너에도 공동적으로 있는 개념
	// 그래서 뭐 list<int>::iterator it 처럼 보다 쉬운 코드호환이 가능함
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

	int* ptrBegin = &v[0]; // same mean = v.begin()._Ptr;
	int* ptrEnd = ptrBegin + 10; // same mean = v.end()._Ptr;
	for (int* ptr = ptrBegin; ptr != ptrEnd; ++ptr) {
		cout << *ptr << endl;
	}

	// const int*;  only read , 수정 X
	vector<int>::const_iterator cit1 = v.cbegin();

	// 역방향 이동 사용자도 있음 로꾸거~
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
		cout << *it << endl;
	}

	// vector = 동적 배열 = 동적으로 커지는 배열 = 배열
	// 원소가 하나의 메모리 블록에 연속하게 저장된다 !!! (중간에 빈 값이 있는것 용납 X)

	// 기초 지식이기에 면접 단골 문제라고 합니다
	// 	   그래서 이 부분을 모른다면 실력이 ㅎㅎ 여기까지~ 아는게 좋겠죠?
	// - 중간(BAD) 삽입/삭제 => 삽입/삭제한만큼 기존에 있던 데이터들의 위치를 수정해줘야하기 때문에 엄청난 나비효과를 불러옴
	// - 처음(BAD)/끝(GOOD) 삽입/삭제 => push_back()/pop_back()
	// - 임의 접근 Random Access => index 접근 : 지원하는 이유 : 모든 원소가 연속적으로 저장되어 있기에 가능한

	// but 중간 삽입 삭제가 불가능한 것은 아님
	// 그렇다면 각각의 반환값은 무엇일까?
	vector<int>::iterator insertIt = v.insert(v.begin() + 2, 5); //추가한 5의 주소
	vector<int>::iterator eraseIt1 = v.erase(v.begin() + 2);	// 삭제한 곳의 주소 (데이터가 앞으로 당겨짐 고려)
	vector<int>::iterator eraseIt2 = v.erase(v.begin() + 2, v.begin() + 4); // 삭제한 곳의 주소
	
	// 쭉- 스캔하면서 3이라는 데이터가 있으면 일괄 삭제
	for (vector<int>::iterator it = v.begin(); it != v.end();) {
		int data = *it;
		if (data == 3) {
			it = v.erase(it);
			// crash 발생 = iterator은 주소만 가진것이 아니라 소속하는 container에 대한 정보도 가지고 있어서
			// 그 자체를 삭제해주면 더이상 it는 무소속이 됨 -> 근데 건드리기에...
			// 그래서 삭제해주고 그 값을 다시 it에 넣고 갱신해서 소속 유지
			// 근데 이렇게 하면 땡겨진 새로운 값에서 ++it를 하니까 땡겨진 값은 조사도 안하고 넘어가게됨
			// 그걸 방지하기 위해 ++it을 아래와 같이 조정해줌
		}
		else {
			++it;
		}
	}
	
	
	return 0;
}