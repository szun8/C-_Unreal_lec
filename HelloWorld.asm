%include "io64.inc"

section .text
global CMAIN
CMAIN:
        mov rbp, rsp; for correct debugging
   
    ; 배열과 주소
    
    ; 배열 : 동일한 타입의 데이터 묶음
    ; - 배열을 구성하는 각 값을 배열 요소(element)
    ; - 배열의 위치를 가리키는 숫자를 인덱스(index)
    
    ; 주소
    ; [시작 주소 + 인덱스 +크기]
    
    mov rax, a
    ;연습문제 : a배열의 모든 데이터 출력해보기
    
    xor rbx, rbx ;rbx=0
    
LABEL_INDEX:
    PRINT_HEX 1, [a+rbx]
    NEWLINE
    add rbx, 1 ;inc rbx
    cmp rbx, 5
    jne LABEL_INDEX
    
    xor ecx, ecx
    
LABEL_INDEX2:  ;바이트 크기 고려해서 더해주기
    PRINT_HEX 1, [b+ecx]
    NEWLINE
    add ecx, 2
    cmp ecx, 10
    jne LABEL_INDEX2
    
    xor rax, rax ; return 0 과 같은 의미
    ret
    
    ; 초기화 된 데이터
    ;[변수이름] [크기] [초기값]
    ;[크기] db(1) dw(2) dd(4) dq(8)    
    
section .data
    msg db 'Hello World', 0x00
    a db 0x01, 0x02, 0x03, 0x04, 0x05 ; 5*1=5바이트
    ;a와 b가 연이어서 메모리가 잡혀있음
    ;memory 표시 : 0x01 0x00 =엔디안 처리=> 0x0001
    b times 5 dw 1 ; 2바이트 크기로 5개 만들고 1로 초기화 ; 5*2=10바이트
    
    map1 db '########', 0x00
    map2 db '#  ##  #', 0x00
    map3 db '#      #', 0x00
    map4 db '########', 0x00
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)

section .bss
    num resb 10

