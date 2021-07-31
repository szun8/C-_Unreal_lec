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
	cout << "ȭ���� ���� �ǰ��մϴ�!" << endl;

	// ���� ����� �ִٸ�
	if (_target != nullptr)
	{
		// �������� ������

		// 8��°�� �װ� 9��°�� ���⼭ ũ����
		// ��,
		// ��(���)�� ������ �׾ delete�Ǿ��µ�,
		// ���⼭ nullptr�� ���� �����ع����ϱ�
		// ũ���ð� �ߴ°� �ƴұ�,,,?
		_target->AddHp(-_damage);
		_target->PrintInfo();
	}
}