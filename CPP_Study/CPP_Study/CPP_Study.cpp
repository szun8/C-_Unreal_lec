#include <iostream>
using namespace std;

// 오늘의 주제 : 연습 문제

// 문제1) 문자열 길이를 출력하는 함수
int StrLen(const char* str) {	// a == str

	int i = 0;

	while (str[i]!='\0') {
		i++;
	}
	return i;
}

// 문제2) 문자열 복사 함수
char* StrCpy(char* dest, char* src) { // dest=b, src=a
	/*
	int i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return dest;	// 뱉는게 dest자체이니 반환형을 void가 아니라 dest와 같이 char* 로 설정
	
	*/	


	// pointer. ver
	char* ret = dest;	// 주소 초기값 반환을 위해 시작위치 설정
	while (*src != '\0') {
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return ret;	// dest 초기값 뱉어주기
}

#pragma warning(disable: 4996)	// 해당 오류 그냥 넘어가줘

// 문제3) 문자열 덧붙이는 함수
char* StrCat(char* dest, char* src) {	// dest = a, src = b

	int a = 0;
	int b = 0;

	while (dest[a] != '\0')
		a++;

	// int len = StrLen(dest);
	// dest[len];

	while (src[b] != '\0') {
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return dest;
}

// 문제4) 두 문자열 비교 함수
int StrCmp(char* a, char* b) {
	// 먼저 각 글자 수 비교
	int count_a = 0;
	int count_b = 0;

	int count = 0;	// i

	while (a[count_a] != '\0')	// a글자수
		count_a++;

	while (b[count_b] != '\0')	// b글자수
		count_b++;

	if (count_a >= count_b) {
		count = count_a;
		count_a = 0;
		count_b = 0;
	}
		
	else {
		count = count_b; // count_b가 더 긴 경우
		count_a = 0;
		count_b = 0;
	}

	while (count != 0) {
		if (a[count_a] == b[count_b]) {
			count_a++;
			count_b++;
			count--;
		}
		else if (a[count_a] > b[count_b]) {
			return 1;
		}
		else if (a[count_a] < b[count_b]) {
			return -1;
		}
	}

	if (count_a == count_b)	// 완전히 둘이 같다면,
		return 0;

}

// 문제5) 문자열을 뒤집는 함수
char* ReverseStr(char* str) {
	int i = 0;
	while (str[i] != '\0')
		i++;	// 끝자리 수

	int count = i / 2;
	i--;

	char temp;
	for (int j = 0; j != count ; j++) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i--;
	}
	return str;
}

int main()
{
	const int BUF_SIZE = 100;

	char a[BUF_SIZE] = "HelloWorld";
	char b[BUF_SIZE] = "aa";

	//int len = StrLen(a);
	//cout << len;

	//StrCpy(b, a);	// return b;

	//StrCat(a, b);	// return a;

	//int value = StrCmp(a, b);
	//cout << value << endl;

	ReverseStr(a);
	cout << a << endl;

	return 0;
}
