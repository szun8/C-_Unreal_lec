#include <iostream>
#include <vector>

using namespace std;

// 오늘의 주제 : lambda 람다 표현식 (익명함수)
// 사용 : [캡쳐](인자값){구협부}
// 람다 = 함수 객체를 빠르게 만드는 문법 (새로운 기능이 들어간 것은 아님)

enum class ItemType {
	None,
	Armor,
	weapon,
	Jewelry,
	consumable
};

enum class Rarity {
	Common,
	Rare,
	Unique
};

class Item {
public:
	int _itemid = 0;
	Rarity _rarity = Rarity::Common;
	ItemType _type = ItemType::None;

public:
	Item(){}
	Item(int itemid, Rarity rarity, ItemType type) : _itemid(itemid), _rarity(rarity), _type(type) {}

};

int main()
{ 
	vector<Item> v;
	// push_back : 기본적으로 오른 값을 받아주고 있다 (&&) / 저번 주 복습정도,,,
	v.push_back(Item(1, Rarity::Common, ItemType::weapon));
	v.push_back(Item(2, Rarity::Common, ItemType::Armor));
	v.push_back(Item(3, Rarity::Rare, ItemType::Jewelry));
	v.push_back(Item(4, Rarity::Unique, ItemType::weapon));

	struct IsUniqueItem
	{
		bool operator()(Item& item) {
			return item._rarity == Rarity::Unique;
		}
	};
	
	struct FindItemByItemId
	{
		// 함수객체를 이용하게 되면,
		// 원하는 특정 데이터도 넣어서 하나의 함수만 호출하는 것이 아니라
		// 여러 함수를 호출시킬 수 있음
		// -> 람다로도 가능

		FindItemByItemId(int itemid) : _itemid(itemid) {}

		bool operator()(Item& item) {
			return item._itemid == _itemid;
		}

		int _itemid;
	};

	struct FindItem {

		FindItem(int itemid, Rarity rarity, ItemType type) : _itemid(itemid), _rarity(rarity), _type(type) {}

		bool operator()(Item& item) {
			return item._itemid == _itemid && item._rarity == _rarity && item._type == _type;
		}

		int _itemid;
		Rarity _rarity;
		ItemType _type;
	};
	int itemid = 4;
	Rarity rarity = Rarity::Unique;
	ItemType type = ItemType::weapon;

	// 자동 추론, 원하는 타입이 있을경우 위처럼 변경 가능
	auto IsUniqueLambda = [](Item& item) -> int { return item._rarity == Rarity::Unique; };

	// Closure 클로져 : 람다에 의해 만들어진 실행시점 객체
	// 조건 이름 설정안하고 그냥 바로 때려넣기도 가능!
	// [ ] = Capture 캡쳐 : 함수 객체 내부에 변수를 저장하는 개념과 유사
	//		- 새로 변수를 내부에서 선언해주는게 아니라 외부에 선언되어있는 변수를 가져올 수 있음
	//		- 사진을 찰칵 [캡쳐]하듯.. 이종의스냅샷을 찍는다고 이해
	// 기본 캡쳐 모드 : 값(복사) 방식(=) / 참조방식(&) (위에서 만든 함수객체와 완전히 똑같은 기능 수행)

	// (!) 모든 변수를 한번에 캡쳐모드를 지정하는 일은 지양 -> 어떤 값이 내부적으로 복사 혹 참조가 됐는지 모름
	// 하나하나 지정해줘서 가독성도 높이고, 뭐가 복사 혹 참조가 됐는지 알 수 있음
	// 참조(주소) 값을 사용한다는 의미 : 내가 사용하는 동안 해당 참조값이 유효해야함 -> 건드리면 안되기에 더욱더 조심해야함
	// 물론 갑복사도 조심해야함 , 소멸된 (delete) 객체라면, 이상한 메모리를 건드릴수 있음.

	// capture 1) 값 방식 (=)
	auto findByItemIdLambda1 = [=](Item& item) { return item._itemid == itemid; };
	// 값을 이후에 바꿔도 그전에 실행됐다면, 바뀐값으로 실행되지 않음, 그 자체로 복사
	
	// capture 2) 참조 방식 (&) : 말 그대로 변수의 주소를 가져오는 느낌,모든 변수에 &가 붙어있다고 생각
	// 이후에 값을 바꿔줘도 주소 인식이라 바뀐 값으로 식 진행
	auto findByItemIdLambda2 = [&](Item& item) { return item._itemid == itemid; };

	// 변수마다 캡쳐 모드를 지정해서 사용 가능 : 값 방식(name), 참조 방식(&name)
	auto findByItem = [=, &type](Item& item) {
		return item._itemid == itemid && item._rarity == rarity && item._type == type;
	};

	auto findit1 = std::find_if(v.begin(), v.end(), IsUniqueLambda);
	auto findit2 = std::find_if(v.begin(), v.end(), FindItemByItemId(itemid));

	if (findit1 != v.end())  cout << "아이템 ID : " << findit1->_itemid << endl;
	if (findit2 != v.end())  cout << "아이템 ID : " << findit2->_itemid << endl;

	return 0;
}