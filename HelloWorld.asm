%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
   
    GET_DEC 1, al ;10진수로 input
    GET_DEC 1, num
    
    ;PRINT_DEC 1, al
    ;NEWLINE
    ;PRINT_DEC 1, num
    
    ;add a, b (a = a + b)
    ;a는 레지스터 or 메모리
    ;b는 레지스터 or 메모리 or 상수
    ; 단! a, b 모두 메모리는 X
    
    ;빼기 연산 == 더하기 연산
    ;sub a, b (a= a-b)
    
    add al, 1; 레지스터 + 상수
    PRINT_DEC 1, al ; 1+1=2
    NEWLINE
    
    add al, [num] ; 레지스터 + 메모리
    ;그냥 num은 주소값 복사 -> 값 복사 대괄호 필수
    PRINT_DEC 1, al ; 2+2=4
    NEWLINE
    
    mov bl, 3 ; 레지스터 + 레지스터
    add al, bl
    PRINT_DEC 1, al ; 4+3=7
    NEWLINE
    
    add [num], byte 1 ; 메모리 + 상수
    PRINT_DEC 1, [num] ;1+2=3
    NEWLINE
    
    add [num], al ; 메모리 + 레지스터
    PRINT_DEC 1, [num] ;3+7=10
    NEWLINE
    
    ; 곱하기 연산
    ; mul reg
    ; - mul bl => al * bl 
    ; -- 연산 결과를 ax에 저장
    ; - mul bx => ax* bx
    ; -- 연산 결과는 dx(상위 16비트) ax(하위16비트)에 저장
    
    ; 예) 5*8 ?
    mov ax, 0
    mov al, 5
    mov bl, 8
    mul bl
    PRINT_DEC 2,ax
    NEWLINE
    
    ; 나누기 연산 (1바이트 나누기)
    ; div teg
    ; - div bl => ax / bl
    ; -- 연산결과는 al(몫) ah(나머지)
    
    ;예) 100/3 ?
    mov ax, 100
    mov bl, 3
    div bl
    PRINT_DEC 1,al
    NEWLINE
    mov al, ah ;ah 값 al에 복사해서 출력
    PRINT_DEC 1,al

    xor rax, rax
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

