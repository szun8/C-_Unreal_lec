#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 객체(Functor) = [함수처럼 동작]하는 객체
// !!!!! () 연산자 오버로딩

// 함수포인터의 단점
// 1) 완전히 동일한 시그니처(반환, 매개변수 타입, 수 등)만 호환이 가능했음
// 2) 상태를 가질 수 없다.

class Functor {
public:
	void operator() () {
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator() (int num) {
		cout << "Functor Test" << endl;
		_value += num;
		cout << _value << endl;
		return true;
	}

private:
	int _value = 0;
};
class MoveTask {
public:
	void operator() () {
		// TODO
		cout << "해당 좌표로 플레이어 이동" << endl;
	}

public:
	int _playerId;
	int _posX;
	int _posY;
};

int main()
{
	Functor functor;

	functor();	// ()연산자 오버로딩으로 가능해짐
	bool ret = functor(3);

	// MMO에서 함수객체를 사용하는 예시
	// 클라이언트 <-> 서버
	// 서버 : 클라가 보내준 네트워크 패킷을 받아서 처리
	// ex) 클라 : 나 (5,0) 좌표로 이동시켜줘!
	// 만약에 이런 요청들이 많이 몰린다면?

	MoveTask task;
	// 일단 요청 주문서를 만들어놓긴 함
	task._playerId = 100;
	task._posX = 5;
	task._posY = 0;

	// 나중에 여유가 될때 일감을 실행한다
	task();
	// => functor를 만들어주는 시점과 실행하는 시점을 분리할 수 있다는 굉장히 큰 장점 소유
	// commandPattern 이라는 용어로 부르게 될거랍니다,,,
	return 0;
}