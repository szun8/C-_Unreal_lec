%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
   
   ; 쉬프트(shit)연산
   
   mov eax, 0x12345678
   PRINT_HEX 4, eax
   NEWLINE
   shl eax, 8 ;왼쪽으로 8칸 shift == 최상위 8bit는 분실이 된다는 의미
   PRINT_HEX 4, eax
   NEWLINE
   shr eax, 8 ;오른쪽으로 8칸 shift == 최하위 8bit 분실
   PRINT_HEX 4, eax
   NEWLINE
   ; 왜 ? 빠른 곱셈/나눗셈
   ; 게임서버에서 각각 캐릭터의 ObjectID를 만들어줄 때
   
   ; 논리(logical) 연산 => NOT AND OR XOR
   ; 조건 A , B
   ; not A : 0 이면 1, 1 이면 0
   ; A and B : 둘 다 참(1)이면 1출력, 하나라도 아니면 0출력
   ; A or B : 둘 중 하나라도 1이면 1출력, 둘 다 아니면 0출력
   ; A xor B : 둘 다 1이거나 0이면 0출력, 서로 다르면 1출력
   
   mov al, 0b10010101
   mov bl, 0b01111100
   
   and al, bl ; al and bl = 0b0001 0100 = 0x14
   PRINT_HEX 1, al
   NEWLINE
   
   not al ;0b1110 1011 = 0xeb
   PRINT_HEX 1, al
   NEWLINE
   
   ;응용사례: bitflag = 각 0과 1에 의미 부여
   
   mov al, 0b10010101 ;0x95
   mov bl, 0b01111100 ;0x7c
   
   NEWLINE
   PRINT_HEX 1, al
   NEWLINE
   
   xor al, bl ; 0b1110 1001 = 0xe9
   PRINT_HEX 1, al
   NEWLINE
   
   xor al, bl ; 0b1001 0101 = 0x95
   PRINT_HEX 1, al
   NEWLINE
   ; 동일한 값으로 xor 두번하면 자기 자신으로 되돌아오는 특성
   ; 암호학에서 유용 - 대칭키 암호 (value xor key)
   
   xor al, al ;자기끼리 연산하면, == mov al, 0
   PRINT_HEX 1, al ; 무조건 0 출력
   
    xor rax, rax ; return 0 과 같은 의미
    ret
    
    ; 초기화 된 데이터
    ;[변수이름] [크기] [초기값]
    ;[크기] db(1) dw(2) dd(4) dq(8)    
    
;section .data
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
    
section .bss
    num resb 1

