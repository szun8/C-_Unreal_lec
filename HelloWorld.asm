%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
    ;write your code here
    
    ;mov eax, 0x1234
    ;mov rbx, 0x12345678
    ;mov cl, 0xff
    
    ;mov al, 0x00 ;1byte만 사용
    
    ;메모리(실행) <-사용-> 레지스터(저) : 서로 핑퐁(?)
    
    ;mov rax, a
    ;-> rax에 a값을 가지는게 아니라 a의 주소값을 가지게됨
    ; 각자 주소값 접근
    ;mov rax, [a] ;
    ;-> rax의 크기만큼 a의 값을 복사(a크기 != rax크기)
    ;mov al, [a]
    ;-> a의 크기만큼 할당
    
    ;mov [a], byte 0x55
    ;mov [a], word 0x6666
    ;mov [a], cl
    
    xor rax, rax
    ret
    
    ;변수의 선언 및 사용
    ;변수 = 데이터를 저장하는 바구니 [ ]-메모리를 요청하는
    ; -> 초기 바구니 사용 선언 == 이름, 크기 지정
    
    ; 초기화 된 데이터
    ;[변수이름] [크기] [초기값]
    ;[크기] db(1) dw(2) dd(4) dq(8)    
    
section .data
    msg db 'Hello World', 0x00 ;=null (문자끝표시)
    
    a db 0x11 
    ;b dw 0x2222
    c dd 0x33333333
    d dq 0x4444444444444444
    
    b dd 0x12345678 
    ;거꾸로 저장 = Little-Endian : 캐스팅(데이터 추출)유리
    ;그대로 저장 = Big-Endian : 숫자 비교 유리
    ;local과 server에 저장하는 방식이 다를수있으니 웬만하면 서버로 보낼때 따르는 방식 하나를 지정할 것
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
    
section .bss
    e resb 10

