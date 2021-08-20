#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 오늘의 주제 : deque = double-ended(양방향) queue 데크 = vector + list 특징
// [       ] 배열 형태의 저장이다보니 vector의 특정 + 일부 할당한 배열 영역이 다 차면, 
// [       ] 새롭게 다른 배열 영역을 생성 - 연속된게 아니니 list의 특징 (block단위)

int main()
{ 
	// 시퀀스 컨테이너 : 데이터가 삽입 순서대로 나열되는 형태
	// vector(동적배열) list(이중연결리스트) deque(!)
	
	// random access 지원 = 배열기반 동작
	// 다만 메모리 할당 정책이 다르다

	vector<int> v(3, 1);	// [1 1 1]
	deque<int> dq(3, 1);	// [ 3 3 ] [1 1 1 2] [ 2 ], int = 4byte, 앞뒤로 통을 늘림

	v.push_back(2);
	v.push_back(2);

	dq.push_back(2);
	dq.push_back(2);

	dq.push_front(3);
	dq.push_front(3);

	// - deque의 동작원리
	// - 중간 삽입/삭제 (BAD / BAD) => 삽입/삭제를 하면 vector의 특징과 마찬가지로 크기를 그만큼 조정해줘야함
	// 	   => 삭제하면, 빈만큼 앞으로 땡겨줘야함 / 삽입하면, 넣은만큼 앞이든 뒤든 밀어줘야함
	// - 처음/끝 삽입/삭제 (GOOD / GOOD) => 통에 다가 채워넣으면 되고, 통이 꽉찼으면 그냥 다른 통에 새로 넣으면됨
	
	deque<int>::iterator it;
	// - 임의접근 (GOOD) (약간 아파트처럼 각 데이터가 저장되어있어서 빠른거임)
	// _Size_type _Block = _Mycont->_Getblock(_Myoff); => 찾고자하는 offset이 들어있는 Block을 찾고
	// _Size_type _Off = _Myoff % _Block_size;	=> 나머지 연산을 통해 해당 Block에서 몇번째 offset에 있는지 찾고
	// return _Mycont->_Map[_Block][_Off];	=> 최종적으로 몇번째 Block에 몇번째 offset에 니가 원하는 데이터를 반환
	
	// 몇 블록, 몇 옾셋인지 알수있다는 것은, 중간에 비어있는 곳이 없다는 것을 의미
	// 따라서 중간 삽입/삭제가 BAD인 것!
	
	// 리스트같은 경우에는 모든 데이터들이 다 떨어져 주소로 연결되어있어서 임의접근이 어려웠던 것

	return 0;
}