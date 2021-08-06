<H1>📚 C++ Study</H1>
<H6>by Inflearn 🌵</H6>

<H3> 목차 </H3>

* [객체지향](📍-객체지향)
* 동적할당
* 복사
* 타입변환
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
    ~~뭐 당연하다고 생각되는 부분일 수 있다...~~   
    
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
   
    
