#include <iostream>
#include <vector>

using namespace std;

// 오늘의 주제 : smart pointer
// 간접적 포인터, 코드 안정성 유지
// 포인터를 알맞는 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)(생명주기 자동관리)
// shared_ptr, weak_ptr, unique_ptr
// shared_ptr, weak_ptr 는 서로 짝꿍~
// unique_ptr : 나만 이 포인터를 가지고 있음 -> 다른애한테 대입 X, 옮겨주고자한다면 move함수로 오른값 전달(일반적인 복사가 불허)

// reference count : 해당 포인터가 몇 명이나 참조하고 있나?
// 그래서 아무도 해당 객체를 참조하지 않을 때(count == 0?) 소멸가능

class Knight {
public:
	Knight() { cout << "Knight 생성" << endl; }
	~Knight() { cout << "Knight 소멸" << endl; }

	void Attack() {
		if (_target.expired() == false) { // 해당 포인터가 날라갔냐 확인, weak ptr 자체로는 타켓 그냥 사용불가
			shared_ptr<Knight> sptr = _target.lock();
			sptr->_hp -= _damage;
			cout << "HP : "<< sptr->_hp << endl;
		}
	}
public:
	int _hp = 100;
	int _damage = 10;
	weak_ptr<Knight> _target;// Knight* _target = nullptr;
};

class RefCountBlock {
public:
	int _refCount = 1;
	int _weakCount = 1;
};

template<typename T>
class SharedPtr {
public:
	SharedPtr() {}
	SharedPtr(T* ptr) : _ptr(ptr){
		if (_ptr != nullptr) {
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	// 복사 생성자
	SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block) {
		if (_ptr != nullptr) {
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	// 복사 대입 연산자
	void operator=(const SharedPtr& sptr) {
		_ptr = sptr._ptr;
		_block = sptr._block;
		if (_ptr != nullptr) {
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}
	~SharedPtr() {
		if (_ptr != nullptr) {
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;

			if (_block->_refCount == 0) {
				delete _ptr;
				// delete _block;  weak_ptr 사용시,
				cout << "delete Data"<< endl;
			}
		}
	}
public:
	T* _ptr = nullptr;
	RefCountBlock* _block = nullptr;
};
int main()
{ 
	//Knight* k1 = new Knight();
	//Knight* k2 = new Knight();
	//k1->_target = k2;	// target 지정

	//delete k2;
	//k1->Attack();		// k1의 target이 nulltpr이 되지는 않음, 쓰레기값이 출력됨, 댕글링 문제(useAfterFree)에서 자유로워짐

	//SharedPtr<Knight> k3(new Knight());
	//SharedPtr<Knight> k4 = k3; // 서로 같은 객체 가리키는 중

	//SharedPtr<Knight> k6;
	//{
	//	SharedPtr<Knight> k5(new Knight());
	//	k6 = k5;
	//	// 내부적으로 특정 조건을 만족하면 알아서 객체소멸
	//}

	shared_ptr<Knight> k1 = make_shared<Knight>();
	{
		shared_ptr<Knight> k2 = make_shared<Knight>();
		k1->_target = k2;
	}
	
	k1->Attack(); // 소멸되지 않았기에 정상적 출력
	// 주로 멀티쓰레드에서는 메모리 관리가 복잡해지기에 스마트 포인터를 활용 (거의 생포인터 사용 X)

	// 객체 서로가 서로를 가리키면 절대 각각이 소멸될일이 없음 (순환) -> 해당 부분 해결 = weak_ptr
	//		- 생명주기에서는 자유로워짐, 객체 소멸자체에는 관여를 하지 않기 때문

	unique_ptr<Knight> uptr = make_unique<Knight>();
	unique_ptr<Knight> uptr2 = std::move(uptr);

	return 0;
}