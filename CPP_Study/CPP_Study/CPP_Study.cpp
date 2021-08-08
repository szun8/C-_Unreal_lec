#include <iostream>
using namespace std;

// 오늘의 주제 : 콜백 callback
// : 다시 호출하다? 역으로 호출하다?
// 함수 포인터 + 함수 객체 + 템플릿

// 어떤 상황이 일어나면 -> 이 기능 호출해줘

class Item {
public:

public:
	int _itemId = 0;
	int _rarity = 0;
	int _ownerId = 0;
};

class FindByOwnerId {
public:
	bool operator()(const Item* item) { // compare => const
		return (item->_ownerId == _ownerId);
	}
public:
	int _ownerId;
};

class FindByRarity {
public:
	bool operator()(const Item* item) { // compare => const
		return (item->_rarity >= _rarity);
	}
public:
	int _rarity;
};

// 마지막 매개변수로, 함수 포인터 = bool(*func)(const Item*) 을 넣거나
// 아래처럼 템플릿-함수객체(연산자 오버로딩)을 이용해 자유도 높은 기준 조건 생성가능 
template<typename T>
// T selector에 뭐를 넣을지에따라 functor가 알아서 맞는 기준 조건 호출!
Item* FindItem(Item items[], int itemCount, T selector) {
	for (int i = 0; i < itemCount; i++) {
		Item* item = &items[i];

		if(selector(item))	// class 마다 functor의 특징은 공통적으로 가짐
			return item;
	}
	return nullptr;
}
int main()
{
	Item items[10];
	items[3]._ownerId = 100;
	items[8]._rarity = 2;

	FindByOwnerId functor1;
	functor1._ownerId = 100;
	
	FindByRarity functor2;
	functor2._rarity = 1;

	Item* item1 = FindItem(items, 10, functor1); // -> FindByOwnerId
	Item* item2 = FindItem(items, 10, functor2); // -> FindByRarity
	return 0;
}