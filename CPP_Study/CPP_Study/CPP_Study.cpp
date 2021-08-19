#include <iostream>
#include <list>
using namespace std;

// 오늘의 주제 : list (연결 리스트)
// vector vs list 의 차이는 면접 단골 문제
// - list의 동작원리
//	ㅁ 종류
//		 1) 단일  [1]     -> [2]  ->    [3]->[4]...등
//		 2) 이중(양방향,STL)  [1]     <-> [2]  <->    [3]<->[4]...
//		 3) 연결	[1]     <-> [2]  <->    [3]<->[4] <-> [1]

// - 중간 삽입/삭제 (GOOD!)
//		li.insert(iter, k) / lt.erase(iter)
// - 처음 / 끝 - 삽입 / 삭제 (GOOD!)
//		li.push_front/back(k) / li.pop_front/back()
// - 임의 접근 = li[3] = 10; (NO!)
//		=> vector등과 같이 연속된 데이터가 아니기에 인덱스 접근 불가
//		=> list는 다음/전 주소만 가지고 있기 때문

class Node {	// Node(list 구성요소 하나)들의 모음 전체 = list
public:
	Node*  _next;	// node하나의 다음주소를 타고 가보면 다음 node의 값이 있으니 반환 자료형은 Node인 것!
	Node*  _prev;	
	int    _data;
	// Node [ data(4byte) _next(4 or 8)]-> Node [ data(4byte) _next(4 or 8)] -> ...
	// Node의 설계도를 완성하지 않아도 주소바구니이다보니까 통과됨.
	// 다음 Node는 지금 신경 X
};		

int main()
{ 
	list<int> li;

	// li.capacity(); 없음, 필요할때마다 노드 하나를 추가하는 느낌이기 때문

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();
	// itEnd node는 list의 제일 마지막 값을 가리키는게 아니라 그 다음 더미 노드 [ _Myhead : end() ] 를 가리킨다
	// (!) 더미 노드 = 우리가 넣어준 값이 X

	// list<int>::iterator itTest1 = --itBegin; => ERROR! 맨처음값에서는 뒤로 이동하면 CRASH, end인 더미노드로 가는 것 X
	// list<int>::iterator itTest3 = ++itEnd; => ERROR! 마찬가지로 맨뒷값에서는 앞으로 이동하면 CRASH, begin노드로 가는 것 X
	list<int>::iterator itTest2 = --itEnd; // 바로 전 데이터로 ! possible

	// 주소 이동 연산자 : ++ or -- 는 가능한데, 아래처럼 하는것은 불가능함.
	// list<int>::iterator itTest4 = itBegin + 10; => 연속적인 데이터연결이 아니기에 당연 비효율적, 인덱스 접근이 안되는 이유와 동일하게 불가능
	// 대충 안되는 것에는 이유가 있는 법 = 효율적이지도, 빠르지도 않음 (굳이?)

	// 근데 여기서 오잉? 하는 부분이 생김.
	// 중간삽입/삭제는 빠르다 <-> 중간 임의 접근은 느리다 = ??? 아이러니,,할 수 있어
	
	// 몇 번 인덱스에 있는 것을 삭제해줘 = 50번째의 주소를 가지고 있지 않음
	// 따라서, 50번까지의 주소로 하나씩 접근을 한 후 삭제 => 느림
	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; ++i)
		++it;
	li.erase(it);

	// 그러나 딱 50번째 데이터의 주소를 가지고 있다면, 하나씩 접근해줄 필요없이 그냥 해당주소로 뿅 이동해서 삭제가 가능함 => 빠름
	list<int>::iterator itRemember;
	for (int i = 0; i < 100; ++i) {
		if (i == 50) {
			itRemember = li.insert(li.end(), i); // 50번째 노드의 주소
		}
		else
			li.push_back(i);
	}
	// 중간 삽입/삭제가 GOOD인 이유
	// So, `주소 접근의 차이`라고 볼 수 있다.

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it) {
		cout << *it << endl;
	}

	li.insert(itBegin, 100);
	li.push_front(100);

	li.erase(li.begin());
	li.pop_front();

	li.remove(10);	// 내가 원하는 값 모두 삭제 !!!
	return 0;
}