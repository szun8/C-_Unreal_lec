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

// - 중간 삽입/삭제
// - 처음/ 끝 삽입/삭제
// - 임의 접근 = li[3] = 10; 불가

class Node {	// Node(list 구성요소 하나)들의 모음 전체 = list
public:
	Node*  _next;	// node하나의 다음주소를 타고 가보면 다음 node의 값이 있으니 반환 자료형은 Node인 것!
	int    _data;
	// Node [ data(4byte) _next(4 or 8)]-> Node [ data(4byte) _next(4 or 8)] -> ...
	// Node의 설계도를 완성하지 않아도 주소바구니 이다보니까 통과됨.
	// 다음 Node는 지금 신경 X
};		

int main()
{ 
	list<int> li;

	for (int i = 0; i<100; ++i) {
		li.push_back(i);
	}
	li.push_front(10); // 앞에서 삽입 가능
	// li.capacity(); 없음

	list<int>::iterator itBegin = li.begin();
	list<int>::iterator itEnd = li.end();

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