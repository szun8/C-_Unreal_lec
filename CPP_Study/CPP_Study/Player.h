#pragma once
//#include "Monster.h"
//class Monster; -> 여기에 전방 선언을 하거나

class Player {
public:

public:
	int _hp;
	int _attack;

	// Monster _target;
	// 포인터가 아닌 형태로 인스턴스를 가지고 있으면 player의 종속적인 관계로 있기에 monster설계도 내부를 다 알아야 함
	// total 20byte
	
	class Monster* _target2;
	// 여기서 바로 class 선언 해줘도됨
	// 포인터 형태의 인스턴스는 반환형이 무엇이던 주소를 담고 있는 바구니이기에 4(8)바이트만 차지
	// 당장 어느정도의 의존성 해방 -> 다만, 내부의 인자/함수들을 건드리고자할 때는 헤더 선언 필요
	// total 12byte

	// + player끼리 싸운다고 해서 player를 player 내부에 넣고자할 때는,
	// Player player는 설계도 전체를 요하는데 아직 작업중인 class이다 보니까 에러 O
	Player* _target; 
	// 얘는 전방 선언만 해줘도 되는 포인터 선언이라 가능!

	// 얘가 몇 바이트냐? -> 이걸로 설계도를 생각해서 class를 완성시키고 애매한 부분을 잡아줄수있음

};