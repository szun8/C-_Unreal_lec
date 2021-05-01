#include <iostream>
using namespace std;

// 프로그래밍을 단순하게 생각하면
// 적절한 데이터를 저장하고 가공하는 것
// 데이터 + 로직

// 그 중에서도 가장 빈번하게 사용되는 정수에 대해!

// 변수 선언 방법
// [타입] [이름];
// [타입] [이름] = [초기값];


// 0이 아닌 초기화 값이 있으면 .data 영역
int hp = 100;

// 초기값이 0이거나, 초기값이 없는 변수라면 .bss 영역

char a;     //1byte, signed(부호가 있는)이 생략되어 있는거임, -128 ~ 127
short b;    //2byte, -32,768 ~ 32,767
int c;      //4byte
__int64 d;  //8byte (long long)

unsigned char ua;     //1byte, signed(부호가 있는)이 생략되어 있는거임, 0 ~ 255
unsigned short ub;    //2byte, 0 ~ 65,536
unsigned int uc;      //4byte, 0 ~ 큰 값,,,
unsigned __int64 ud;  //8byte (long long)

// 참고) 이론적으로 양수만 존재할 수 있는 데이터 unsigned
// 무조건 unsigned를 사용할지 의견이 갈림
// - 레벨이 음수라는 것은 말이 안된다 -> 그럼 차라리 그 자리에서 프로그램을 크래시 내서 버그를 빨리 찾는게 낫다.
// - unsigned / signed 사이의 변환

int main()
{
    // 정수 오버플로우
    b = 32767;
    b = b + 1;
    cout << b << endl; // -32768, 범위 신경

    // 정수 언더플로우
    ub = 0;
    ub = ub - 1;
    cout << ub << endl; // 요상한 값 출력, 범위 신경

    cout << "체력이 " << hp << " 남았습니다" << endl;
}