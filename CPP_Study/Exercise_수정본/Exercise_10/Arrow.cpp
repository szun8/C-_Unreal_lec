#include "Arrow.h"
#include "Player.h"
#include <iostream>
using namespace std;

Arrow::Arrow( Player* target, int damage)
	: _target(target), _damage(damage)
{

}

Arrow::~Arrow()
{

}

void Arrow::AttackTarget()
{
	cout << "화살이 적을 피격합니다!" << endl;

	// 공격 대상이 있다면
	if (_target != nullptr)
	{
		// 데미지를 입힌다

		// 8번째에 죽고 9번째때 여기서 크래시
		// 즉,
		// 적(기사)이 직전에 죽어서 delete되었는데,
		// 여기서 nullptr된 값을 참조해버리니까
		// 크래시가 뜨는게 아닐까,,,?
		_target->AddHp(-_damage);
		_target->PrintInfo();
	}
}