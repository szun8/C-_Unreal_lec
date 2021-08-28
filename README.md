<H1>📚 C++ Study</H1>
<H6>by Inflearn 🌵</H6>

<H3> 목차 </H3>

* [객체지향](#-객체지향)
* 동적할당
* 복사
* 타입변환
* [Sequence Container](#-sequence-container)
* [연관 Container](#-연관-container) - [Map(multimap)](#-map) / [Set(multiset)](#-set)
* [Modern C++](#-modern-c)
* * *

<H2>📍 객체지향</H2>

* **Data Hinding 은닉성**    
  : _Encapsulation_ 캡슐화,  몰라도 되는 것을 깔끔히 숨기게 하는 목적, 안전도 생성
  
   * **접근지정자**     
   `public` 누구에게나 접근    
   `protected` 상속관계에 한해서만 접근 
      * 상속접근지정자     
      : 상속받는 class가 받은 부모class를 자신의 다음세대에게 어떻게 물려줄지
      ```C++
      class SuperCar : public Car {}
      ```   
        `private` 오직 자기자신만 접근 -> 접근이 필요하다면, 멤버함수 사용
        
  * **Polymorpism 다형성**   
    * `overloading` 함수 중복정의 (이름의 재사용, 인자의 형태에 따라)  
    
    ```C++
    int moveCar(int speed);
    int moveCar();
    ```
    
    * `overoverriding` 재정의 (부모함수를 자식에서 재정의)
    
    ```C++
    class Player {       // 부모
    public:
      int MovePlayer(Player* player){
        cout << "Player Move!" << endl;
      }
    }
    
    class Knight : pubic Player {    //자식
    public:
      int MovePlayer(Kinght* knight){
        cout << "Kinght Move!" << endl;
      }
    }
    
    Player p;
    MovePlayer(&p);   // "Player Move!"
    MoveKnight(&p);   // (1) - ERROR!
    
    Kngiht k;
    MovePlayer(&k);   // (2) - "Player Move!"
    MoveKnight(&k);   // "Kinght Move!"
    ```   
    상속관계에서는 부모-자식 class의 **포함관계** 를 생각해보는 것이 좋다   
    <s>뭐 당연하다고 생각되는 부분일 수 있다...</s>   
    
        + (1) 부모 -> 자식 X
        + (2) 자식 -> 부모 O   
        
    단, (2)의 경우 "Kinght Move!" 가 아니라 "Player Move!" 가 출력된다   
    이를 Knight로 출력하기 위해선, 아래 개념이 필요한데,   
    * `virtual` 가상함수   
    : `vftable`에 어디로 가야하는지에 대한 정보를 미리 저장해 원하는 것을 실행해준다   
       
    ```C++
    // class Player
    virtual int VMove(Player* player);   
    void MovePlayer(Player* player){
      player->VMove();
    }

    // class Knight
    virtual int VMove(Kinght* knight);   

    int main(){
      Kinght k;
      MovePlayer(&k);   // k의 VMove로 이동
    }
    ```   
       
    해당 개념을 `동적바인딩` 실행 시점에 결정    
     vs `정적바인딩` 컴파일시점에 어느 것을 불러올지 결정    
     
<H2>📍 Sequence Container</H2>
// vector iterator 비교는 `==` 연산자밖에 지원 안함! (일단 정리하기전에 까먹을까봐 메모해둠,,,)


<H2>📍 연관 Container</H2>
     
: 관계있는 값으로 `key` 와 `value` 를 묶어서 데이터를 저장하는 container 
        
 - 원하는 데이터를 빠르게 찾고자할 때 유용(아래의 단점 보완)
 - 기존 `vector` `list` 등은 선형자료구조로, 원하는 데이터를 찾는 과정이 고됐음.
 - 들어온 순서대로 저장을 하는 시퀀스container와 다르게 특정 규칙에 따라 데이터를 저장   
 - 종류 : `map` `multimap` `set` `multiset`      
    
<H3>🗺 Map</H3>

  : `node` 기반인 `균형이진트리`로 구성  
  ```C++
  #include <map>
  class Node{
    public:
      Node* _left;
      Node* _right;
      // Data
      int key, _value;
      pair<int,int> _data; // pair로 key, value 동시 선언 가능
  };
  int main(){
    map<int,int> m;
  ```
  👩🏻‍💻 **주요 함수**
  - `insert()`   
      key와 value동시 삽입 `make_pair(key,value)` `pair<int,int>(key,value)`   
      반환값 : `map.first` = 삽입 iterator / `map.second` = 삽입 성공여부
      
      ```C++
      pair<map<int,int>::iterator, bool> ok;
      ok = m.insert(1,100);
      ok = m.insert(1,200);   // key 중복시 무시처리(값 덮어쓰기 X), bool false 반환
      ```
      
      `[index]` 접근 및 데이터 삽입도 가능   
      
      📃 *없으면 추가, 있으면 수정.ver1* = `find()` 활용 : 없으면 `insert` / 있으면 `iterator의 second` 수정    
      📃 *없으면 추가, 있으면 수정.ver2* = `[index]` 활용 : 없으면 바로추가 / 있으면 바로수정
      
      ```C++
      m[5] = 500;
      ```
      그러나, index 기반 코드 사용'만'으로도 데이터 생성한다는 점 주의 (!!!)  
      
  - `erase()`
      key 나 범위로 삭제 위치 지정 가능   
      반환값 : `<unsigned int>`
      
      ```C++
      unsigned int count;
      count = m.erase(1); // count = 1
      count = m.erase(1); // count = 0, 이미 지운 데이터를 지우고자 할 때는 무시
      ```
  
  - `find()`   
      반환값 : 있으면 찾은 값의 `iterator` / 없으면 `end()`
      
      ```C++
      map<int,int>::iterator findIt = m.find(key);
      if(findIt != m.end()) // 찾는 값 있음
        cout<< "TRUE"<< endl;
      else                  // 찾는 값 없음
        cout<< "FALSE"<< endl;
      ```
      
    🗺 **map 순회**
    ```C++
    for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it){
        pair<const int, int>& p = (*it);
        int key = p.first;  // p 선언을 안해줬다면, it->first
        int value = p.second;
    }
    ```
    - sorting : 기본 key에 대한 `오름차순` 저장, `value`의 값으로 정렬을 하고자한다면, `map`에 대해 바로 sort는 안되고 `vector`나 다른 자료구조에 복사해서 사용   


 🔑 **multimap**
 : `map` 에서 중복 `key` 허용   
    
  👩🏻‍💻 **주요 함수**
  - `insert()` 

    ```C++
    multimap<int, int> mm;
    mm.insert(make_pair(1,100));
    mm.insert(make_pair(1,200));
    mm.insert(make_pair(1,300));
    mm.insert(make_pair(2,400));
    mm.insert(make_pair(2,500));
    ```
  - `erase()` `find()`

    ```C++
    unsigned int count = mm.erase(1); // key가 1인 데이터 다 삭제, count는 3
    // find()로 하나씩도 erase 가능
    multimap<int, int>::iterator itFind = mm.find(1); // 중복 key의 첫 iterator 반환
    if( itFind != mm.end() )
        mm.erase(itFind); // key = 1, value = 100인 데이터 삭제
        // ++연산자로 다음 iterator로도 접근해서 삭제 가능
    ```
  - `equal_range()` : 범위 반환 함수

    ```C++
    pair<multimap<int,int>::iterator, multimap<int,int>::iterator> itPair;  // start iterator, end iterator
    itPair = mm.equal_range(1);
    itPair.first == lower_bound(1);     // start iterator
    itPair.second == upper_bound(1);    // end iterator
    ```
    
 <H3>🔗 Set</H3>
 
 : `map` 과 달리 `key` 값 하나만 데이터에 저장하는 container
 - 하나의 값만을 저장한다는 특징 이외에는 `map` 과 거의 유사
 - 단, `[index]` 사용은 불가

🔑 **multiset**
 : `set` 에서 중복 `key` 허용  
    
<H2>📍 Modern C++</H2>

- **`auto`**    
 : 컴파일러가 알아서 자료형을 추론해주는 기능

  ```C++
  // type deduction
  int a = 1;
  auto a = 1; // 일종의 조커카드 느낌! 🃏
  ```
  🧨 warning - `const` 와 `&` 는 무시 , 가독성은 하락한다는 점 => 남용은 금지!
  ```C++
  int a = 1;
  const int cst = a;
  int& ref = a;
  auto teat1 = cst; // auto type = int
  auto test2 = ref; // auto type = int
  ```

- **`중괄호 초기화 { }`**   
: `=` 이나 `()` 로 초기화하던 기능에서, 추가적으로 생긴 초기화 기능 (초기화 문법의 일치화)   
  ```C++
  int a = 0;
  int b(0);
  int c {0};
  vector<int> v1 {1, 2, 3, 4};
  ```
  👍🏻 장점 - container와 잘어울리며, 축소변환방지 기능을 가지고 있다
  ```C++
  int x = 0;
  double y = x; // ERROR (X)
  double z {x}; // ERROR (O) ! → 실행되는 코드의 자료형을 꼼꼼히 check
  ```
  🧨 warning - `initializer_list` : 초기화 리스트
  ```C++
  class Knight{
    public:
      Knight(initializer_list<int> li) {}
      Knight(int a, int b) {} // 매개변수로 int인자를 두개 받는 생성자
  }
  int main(){
    Knight k1;    // 기본 생성자 호출
    Knight k2{};  // 기본 생성자 호출
    Knight k3{1, 2};  // Knight(initializer_list<int> li) 생성자 호출 = 우선순위가 제일 위에 있음, 조심!
    
    // 추가적으로 알면 좋은 것
    vector<int> v2(5, 2);   // [2, 2, 2 ,2, 2]
    vector<int> v3{5, 2};   // [5, 2]
  }
  ```
  
- **`nullptr`**   
: 주소를 `NULL`로 설정해주는 기능   
  🙄 이전에 사용하던 `NULL` `0`의 단점을 위해 생성
  
  ```C++
  void Test(int a) {cout << 'int' <<endl;}       // 정수
  void Test(void* ptr) {cout << 'ptr' <<endl;}   // 포인터
  int main(){
    Test(0);       // int
    Test(NULL);    // int => NULL값도 정의에서는 '0'으로 정의되어있음, 정수인식으로 포인터 접근 불가
    Test(nullptr); // ptr => 포인터 접근! 위와 같았던 오작동을 방지해준다 + 가독성 증가
  }
  ```
  
- **`using`**   
: 기존 `typedef`의 기능 대신 쓸수있는 새로운 별칭 문법   

  👀 `using` 🆚 `typedef`   
  + 기입 순서 상이 → 가독성(직관성) 상승   
    ```C++
    typedef int id1;
    using id2 = int;
    // 함수포인터
    typedef void(*myFunc1)();
    using myFunc2 = void(*)();
    ```   
  
  + `template` 사용 → `typedef` 에서는 바로 사용이 불가능했음   
  
    ```C++
    template<typename T>
    struct List1{              // 구조체를 통해 이차적으로 정의를 해야했음
      typedef std::list<T> type;
    }
    template<typename T>
    using List2 = std::list<T> // 바로 가능

    int main(){
     List1<int>::type li1;  // typedef
     List2<int> li2;        // using
    }
    ```
  
- **`enum class`**   
: 기존 `enum`의 기능에서 유효범위를 가진 새로운 열거형 `scoped enum`  

  ```C++
   enum Name1 { A, B, C};
   enum class Name2 { D, E, F};
   int main(){
      int A = 1;  // ERROR
      int D = 2;  // possible
   }
  ```
  + 이름 공간 관리(scoped)   
    : 기존 `enum` 에서 활용된 이름의 범위를 `전역`으로 인식해 다른 곳에서 사용이 불가했지만, `enum class`는 `지역`으로 인식해 다른 곳에서도 사용 가능!
  + 암묵적 변환 금지   
    : 기존 `enum`에서 정의된 이름들은 기본적으로 `정수`로 인식 → 비교가 가능했음   
    그러나 `enum class`는 정수로 인식을 하지 않기에 비교나 다른 변수에 넣는 것이 불가능하게 됨   
    <s>(뭐 굳이 강제적으로 casting 하면 100% 불가능은 아니긴 함)</s>
    
     ```C++
      if(A == 1) { return true; }
      if(D == 1) { return false; }
     ```
     
    추가적으로 `enum` `enum class`의 size는 `int`인 `4byte`로 되어있음 → 직접적 사이즈 변환 가능    
    
     ```C++
     enum Name1 : char { A, B, C};        // sizeof(Name1) = 1
     enum class Name2 : char { D, E, F};  // sizeof(Name2) = 1
     ```
___
<H6>보고 잘못되거나 이상한 부분은 comment 남겨주세요 😂</H6>
