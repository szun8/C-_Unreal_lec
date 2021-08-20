#include <iostream>
#include <list>
using namespace std;

// 오늘의 주제 : list (연결 리스트)
// list 구현 = 면접 단골 문제 - 여러번 연습해도 좋을듯!
template<typename T>
class Node {
public:
	Node() : _next(nullptr), _prev(nullptr), _data(T()){}	// int를 넣어주면 0으로 밀어줄거임
	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value) {}
public:
	Node* _next;
	Node* _prev;
	T	  _data;
};

template<typename T>
class Iterator {
	// 단순하게 내가 어떤노드인지만 반환해주면 됨
public:
	// 자기 자신 class일때는 <T> 생략 가능 
	Iterator() : _node(nullptr) {}
	Iterator(Node<T>* node) : _node(node) {}

	// ++it
	Iterator& operator++() {
		_node = _node->_next;
		return *this;
	}
	// it++
	Iterator& operator++(int) {
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}
	
	// --it
	Iterator& operator--() {
		_node = _node->_prev;
		return *this;
	}
	// it--
	Iterator& operator--(int) {
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}

	T& operator*() {
		return _node->_data;
	}

	bool operator==(const Iterator& right) {
		return _node == right._node; //같으면 참 반환
	}
	
	bool operator!=(const Iterator& right) {
		return _node != right._node; //다르면 참 반환
	}

public:
	Node<T>* _node;
};


// [header] = 기본적으로 있고 데이터 추가될때마다 연결연결
template<typename T>
class List {
public:
	List() : _size(0){
		_header = new Node<T>();
		// 시작 더미노드는 자기 자신을 기본적으로 생성해 가리키는 걸로,
		_header->_next = _header;
		_header->_prev = _header;
	}
	~List() {
		while (_size > 0)
			pop_back();

		delete _header;
	}

	void push_back(const T& value) {
		AddNode(_header, value);
	}
	// [1] <-> [2] <-> [before] <-> [4] <-> [_header] <->
	// 	   !----- AddNode -----!
	// [1] <-> [2] <-> [after = node] <-> [before] <-> [4] <-> [_header] <->
	Node<T>* AddNode(Node<T>* before, const T& value) {
		Node<T>* node = new Node<T>(value);	// value값을 가진 노드를 일단 생성

		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;
		node->_prev = prevNode;

		node->_next = before;
		before->_prev = node;

		_size++;
		return node;
	}

	void pop_back() {
		RemoveNode(_header->_prev);
	}
	// [1] <-> [prevNode] - [node] - [nextNode] <-> [ _header ] <->
	// [1] <-> [prevNode] <-> [node->_next] <-> [ _header ] <->
	Node<T>* RemoveNode(Node<T>* node) {
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;
		--_size;

		return nextNode;
	}

	int size() { return _size; }
public:
	typedef Iterator<T> iterator;
	iterator begin() { return iterator(_header->_next); }
	iterator end() { return iterator(_header); }

	iterator insert(iterator it, const T& value) {
		return iterator(AddNode(it._node, value));
	}
	
	iterator erase(iterator it) {
		return iterator(RemoveNode(it._node));
	}

public:
	Node<T>* _header;
	int _size;
};
int main()
{ 
	List<int> li;
	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; ++i) {
		if (i == 5) {
			eraseIt = li.insert(li.end(), i);
		}
		else
			li.push_back(i);
	}

	li.pop_back();
	li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); ++it) {
		cout << (*it) << endl;
	}

	return 0;
}