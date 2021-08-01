#include <iostream>
using namespace std;

// 오늘의 주제 : 함수 포인터

int Add(int a, int b) {
	return a + b;
}

int Sub(int a, int b) {
	return a - b;
}

class Item {
public:
	Item() : _itemId(0), _rarity(0), _ownerId(0) {
	}

public:
	int _itemId;	// 아이템 구분 ID
	int _rarity;	// 희귀도
	int _ownerId;	// 소지자 ID
};

// 예를들어, 인벤토리에서 원하는 아이템을 찾고자할 때 기준에 따른 함수를 여러개 만들어버리면 굉장히 유지보수성 하락
// typedef 함수를 사용하면, 하나의 함수에 여러 기준 대입 가능 (각 기준마다 조건은 달라지는것만 생성해주면!)

typedef bool(ITEM_SELECTOR)(Item*, int);

Item* FindItem(Item items[],int itemCount, ITEM_SELECTOR* selector, int value) {	// = bool(*selector)(Item* item);
	for (int i = 0; i < itemCount; i++) {
		Item* item = &items[i];
		if (selector(item, value))
			return item;
	}
	return nullptr;
}

#pragma region SELECTOR
bool IsRareItem(Item* item, int value) {
	return item->_rarity >= value;
}

bool IsOwnerItem(Item* item, int ownerId) {
	return item->_rarity == ownerId;
}
#pragma endregion

int main()
{
	// pointer
	int a = 10;
	typedef int DATA;	// int -> DATA
	// 1) 포인터		*
	// 2) 변수 이름		ptr
	// 3) 데이터 타입	int(DATA)
	DATA* ptr = &a;

	// function
	// 함수(반환형-int, 매개변수 int 2개를 받는)를 타입정의해서 사용하고 싶다면?
	typedef int(FUNC_TYPE)(int , int ); // 형태

	// 같은 의미로 modern c++에서 아래와 같이 정의가능
	//using FUNC_TYPE = int(int a, int b);

	// 1) 포인터		*
	// 2) 변수 이름		fn
	// 3) 데이터 타입	함수 (인자는 int, int/ 반환은 int)
	FUNC_TYPE* fn;

	// 함수포인터
	fn = Add;
	// 이걸 왜 쓰냐 ?
	// 형태가 유사한 다른 함수를 적용하고 싶을때, (여러 함수중 하나를 골라서 호출하고 싶을때)
	// 하나하나 이름 바꿀필요 없이 fn이 가리키는 함수 주소만 바꾸면 더 간단히 사용할 수 있음 
	fn = Sub;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)(!!!)
	int result = fn(1, 2);	// = Add(1,2);, 기본문법
	cout << result << endl;
	
	int result2 = (*fn)(1, 2);	// 함수포인터는 *(접근 연산자) 붙어도 함수 주소!, 기본과 같은 의미
	cout << result2 << endl;

	Item items[10] = {};
	items[3]._rarity = 2;	// RARE
	Item* rareItem = FindItem(items, 10, IsRareItem, 2);	// 함수 그 자체는 주소로 반응한다고 위에 적었다
	return 0;
}