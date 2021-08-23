#include <iostream>
#include <vector>
#include <algorithm>
// (Q1) find
// (Q2) find_if
// (Q3) count_if, all_of, ant_of, none_of
// (Q4) for_each
// (Q5) remove, remove_if

using namespace std;

// 오늘의 주제 : 알고리즘

// 자료구조 [데이터를 저장하는 구조]
// 알고리즘 [데이터를 어떻게 사용할 것인가?]

int main()
{ 
	srand(static_cast<unsigned int>(time(nullptr)));
	vector<int> v;
	for (int i = 0; i < 100; ++i) {
		int num = rand() % 100;
		v.push_back(num);
	}
	
	// Q1. number라는 숫자가 벡터에 체크하는 기능 (bool or 첫등장 iterator)
	{
		int number = 50;
		bool found = false;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] == number) {
				found = true;
				break;
			}
		}

		vector<int>::iterator itFind = find(v.begin(), v.end(), number);
		if (itFind != v.end()) {
			found = true;
		}
	}

	// Q2. 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능
	{
		bool found = false;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] % 11 == 0) {
				found = true;
				break;
			}
		}

		struct CanDivideBy11
		{
			bool operator()(int n) { // 함수객체 사용
				return n % 11 == 0;
			}
		};

		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());
		if (itFind != v.end()) {
			found = true;
		}
	}

	// Q3. 홀수인 숫자의 개수?
	{
		int count1 = 0;
		for (int i = 0; i < v.size(); ++i) {
			if (v[i] % 2 == 1)
				++count1;
		}

		struct isOdd
		{
			bool operator()(int n) { // 함수객체 사용
				return n % 2 == 1;
			}
		};
		int count2 = count_if(v.begin(), v.end(), isOdd());

		bool b1 = all_of(v.begin(), v.end(), isOdd());	//모두가 조건에 만족?
		bool b2 = any_of(v.begin(), v.end(), isOdd());	//조건에 만족하는 데이터가 `하나라도` 있음?
		bool b3 = none_of(v.begin(), v.end(), isOdd());	//조건에 만족하는 데이터가 `하나도` 없음? == 모든 데이터가 홀수가 아닙니까?
	}

	// Q4. 벡터에 들어가 있는 모든 숫자들에 3을 곱해주세요!
	{
		for (int i = 0; i < v.size(); ++i) {
			v[i] *= 3;
		}

		struct MultiplyBy3 {
			void operator()(int& n) {
				n *= 3;
			}
		};
		// 모든 데이터를 스캔할 때 유용한 함수
		for_each(v.begin(), v.end(), MultiplyBy3());
	}

	// Q5. 홀수인 데이터 일괄 삭제
	{
		for (vector<int>::iterator it = v.begin(); it != v.end();) {
			if (*it % 2 == 1) {
				it = v.erase(it);
				// erase 사용시, iterator를 건드리니까 it에 다시 넣어주는 과정이 필요!!!
			}
			else
				++it;
		}

		v.clear();		
		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);
		// 1 4 3 5 8 2
		// remove(v.begin(), v.end(), 4);

		struct isOdd
		{
			bool operator()(int n) { // 함수객체 사용
				return n % 2 == 1;
			}
		};
		vector<int>::iterator it = remove_if(v.begin(), v.end(), isOdd());
		// 4 8 2 --------- 5 8 2 (???) => 삭제할 데이터보다는 남겨줘야할 데이터에 초점을 두고 함수가 동작함
		// 조건에 만족한 남겨줘야할 데이터만 위치로 옮겨주고 이후 필요없는 데이터의 첫 위치를 반환
		// 그냥 순서 재조정이지, 확실히 필요없는 데이터를 완전하게 삭제해주는 기능은 아님
		v.erase(it, v.end());
		// 그래서 위처럼 삭제해야함, 아래는 그냥 줄인 같은 의미의 코드
		v.erase(remove_if(v.begin(), v.end(), isOdd()), v.end());
	}
	return 0;
}