#include <iostream>
#include <vector>
using namespace std;

// 오늘의 주제 : vector
// 우리가 vector 기능을 구현해보는 게 오늘 내용

template<typename T>
class Iterator {
public:
	Iterator() : _ptr(nullptr) {

	}
	
	Iterator(T* _ptr) : _ptr(_ptr) {

	}

	Iterator& operator++() {	// 전위
		_ptr++;
		return *this;
	}
	 
	Iterator operator++(int) {  // 후위
		Iterator temp = *this;
		_ptr++;
		return temp;
	}
	
	Iterator& operator--() {	// 전위
		_ptr--;
		return *this;
	}
	 
	Iterator operator--(int) {  // 후위
		Iterator temp = *this;
		_ptr--;
		return temp;
	}
	
	Iterator operator+(const int count) { 
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count) {
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	bool operator==(const Iterator& right) {
		return _ptr == right._ptr;
	}
	
	bool operator!=(const Iterator& right) {
		return _ptr != right._ptr;
		// return !(*this == right);
	}

	T& operator*() {
		return *_ptr;
	}

public:
	T* _ptr;
};
template<typename T>
class Vector {
public:
	Vector() : _data(nullptr), _size(0), _capacity(0) {}
	~Vector() {
		if (_data)
			delete[] _data;
	}

	int size() { return _size; }
	int capacity() { return _capacity; }
	T& operator[] (const int pos) { return _data[pos]; }
	// & ref안해주면 참조는 되는데 값 변경은 안되기에 붙여주기~
	void clear() { _size = 0; }
	void push_back(const T& val) {
		if (_size == _capacity) {
			// 메모리 증설 작업
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)	newCapacity++;
			reserve(newCapacity);
		}

		// 이제부터 여유공간이있음!

		// 데이터 저장
		_data[_size] = val;
		// 데이터 개수 증가
		_size++;
	}

	void reserve(int capacity) {
		_capacity = capacity;
		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++) {
			newData[i] = _data[i];
		}

		// 새로 복사했으니, 기존에 있던 데이터를 날린다.
		if (_data) delete[] _data;
		// 교체
		_data = newData;
	}

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return begin() + _size; }

private:
	T* _data;
	int _size;
	int _capacity;
};

int main()
{
	vector<int> v;
	v.reserve(100);

	for (int i = 0; i < 100; i++) {
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	cout << "----------------------------" << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
		cout << (*it) << endl;
	}

	v.clear();

	
	return 0;
}