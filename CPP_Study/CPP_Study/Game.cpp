#include "Game.h"
#include "Player.h"
#include "Field.h"
#include <iostream>
using namespace std;
// name-space(이름-공간?)-여러 라이브러리를 쓰다보면, 이름이 겹치는 함수들이 존재 -> 그들을 구별해주기위해 별명을 지어준 느낌

//생성자
Game::Game() : _player(nullptr), _field(nullptr) {

}

//소멸자
Game::~Game() {
	if (_player != nullptr)
		delete _player;
	if (_field != nullptr)
		delete _field;
}

// 처음 초기화할 때 실행되는 함수
void Game::Init() {
	_field = new Field();
}

// 게임이 반복될 때마다 실행되는 함수
void Game::Update() {
	if (_player == nullptr) {
		CreatePlayer();
	}

	if (_player->isDead()) {
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}

	_field->Update(_player);
}

void Game::CreatePlayer() {
	while (_player == nullptr) {
		cout << "------------------------" << endl;
		cout << "--캐릭터를 생성하세요!--" << endl;
		cout << "1) 기사 2) 궁수 3) 법사" << endl;
		cout << "------------------------" << endl;

		cout << "> ";

		int input = 0;
		cin >> input;

		if (input == PT_Knight) {
			_player = new Knight();
		}
		else if (input == PT_Archer) {
			_player = new Archer();
		}
		else if (input == PT_Mage) {
			_player = new Mage();
		}
	}
}