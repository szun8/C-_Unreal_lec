%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
   ; 반목문(while, for)
   ; 특정 조건을 만족할때까지 반복해서 실행
   
   ;ex) Hello World 10번 출력?
   
   mov ecx, 10
   
LABEL_LOOP:
    PRINT_STRING msg
    NEWLINE
    dec ecx ;sub ecx, 1과 동일
    cmp ecx, 0
    jne LABEL_LOOP
    
    ;연습문제 : 1~100까지의 합을 구하는 프로그램
    
    mov rax, 0
    mov rbx, 1
    
LABEL_PLUS:
    add rax, rbx ;
    add rbx, 1
    cmp rbx, 101
    jne LABEL_PLUS
    
    PRINT_DEC 1, rax
    NEWLINE
    
    ;강의 풀이(1,1~100)
    mov eax, 100 ; 최종 목적지
    xor ebx, ebx ; mov ebx, 0 / ebx: 결과물
    xor ecx, ecx
    
LABEL_SUM:
    inc ecx ; add ecx, 1과 동일
    add ebx, ecx ; ebx = ebx + ecx
    cmp ecx, eax
    jne LABEL_SUM
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    ;강의 풀이(2,100~1)
    mov eax, 100
    xor ebx, ebx ; mov ebx, 0 / ebx: 결과물
    xor ecx, ecx
    
LABEL_SUM2:
    add ebx, ecx ; ebx = ebx + ecx
    dec eax
    cmp eax, 0
    jne LABEL_SUM2
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    ; loop [라벨]
    ; - ecx에 반복 횟수
    ; - loop 할때마다 ecx 1 감소 0이면 빠져나감 아니면 라벨로 이동
   
    mov ecx, 100
    xor ebx, ebx ; mov ebx, 0 / ebx: 결과물
LABEL_LOOP_SUM:
    add ebx, ecx
    loop LABEL_LOOP_SUM ; ecx를 1줄이는 기능이 내부에 있다고 보면되고 0되면 루프 탈출
    
    PRINT_DEC 4, ebx
    NEWLINE
    
    xor rax, rax ; return 0 과 같은 의미
    ret
    
    ; 초기화 된 데이터
    ;[변수이름] [크기] [초기값]
    ;[크기] db(1) dw(2) dd(4) dq(8)    
    
section .data
    msg db 'Hello World', 0x00
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)
    
section .bss
    num resb 1

