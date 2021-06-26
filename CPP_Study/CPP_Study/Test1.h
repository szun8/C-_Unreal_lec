//#pragma once (컴파일러 최적화)
// = 헤더 가드
// : 같은 내용이 두번 이상 정의되지 않도록 막아주는 역할 수행

// #pragma once와 같은 내용 (수동적)
#ifndef _TEST1_H__	// 정의되지 않았다면
#define _TEST1_H__	// 여기서 정의를 해라

// 헤더 파일에 구현부를 적어도 좋지만,
// cpp파일에 재정의가 되어 중복 정의가 될수 있으니,
// 한쪽으로 모아주는 것이 좋다

// 헤더 파일은 거의 간단하게 선언부로 사용!
// 꼭 필요한 것만 include 하고 중첩현상 방지하자...

struct StatInfo {
	int hp;
	int attack;
	int defence;
};
void Test_1();

void Test_2();

void Test_3();

#endif
