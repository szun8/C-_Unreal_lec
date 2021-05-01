%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
   
    ; 스택 메모리, 스택 프레임
    
    ; 레지스터는 다양한 용도로 사용
    ; - a b c d 범용 레지스터
    ; - 포인터 레지스터 (포인터 = 위치를 가리키는~)
    ; -- ip (instruction Pointer) : 다음 수행 명령어의 위치
    ; -- sp (Stack Pointer) : 현재 스택 top 위치 (일종의 cursor)(실시간으로 내가 어딜 사용하고 있느냐)
    ; -- bp (Base Pointer) : 스택 상대주소 계산용 (여러 메모리들이 함수에 들어있으니 각각의 주소를 알기위해, sp는 계속 바뀌니까 bp가 알기 쉽게 배의 닻처럼 기억하 싶은 주소를 저장해주는 역할)
    
    ; 이전 단계에서 rax랑 rbx에 중요한 데이터가 저장 되어있었다면,
    push rax
    push rbx ; 중요한 두 데이터를 넣어서 임시 저장
    push 5
    push 2
    call MAX ;Stack에 돌아올 주소를 저장하기에 다시 여기로 리턴되어 올 수 있는 것
    PRINT_DEC 8, rax
    NEWLINE
    ; stack을 쓰고 깨끗이 복원을 안해주면 Crash가 날 수 있음
    add rsp, 16 ;옆 처럼 위치를 상위 원래 위치로 돌려주거나 pop을 두번 해서 비워주거나 해야함.
    pop rbx
    pop rax
    
MAX:
    push rbp
    mov rbp, rsp
    
    mov rax, [rbp+16] ;rbp+8 == return, 주소 접근
    mov rbx, [rbp+24]
    cmp rax, rbx
    jg L1 ;rax가 더 크면 밑으로 점프 아니면 밑으로 가서 rbx값 rax에 복사
    mov rax, rbx
L1:    
    pop rbp
    ret
    
    xor rax, rax ; return 0 과 같은 의미
    ret

    ; [!] 스택(stack)이라는 메모리 영역을 사용
    ; 함수가 사용하는 일종의 메모장
    ; - 매개 변수 전달
    ; - 돌아갈 주소 관리
    
    ; 초기화 된 데이터
    ;[변수이름] [크기] [초기값]
    ;[크기] db(1) dw(2) dd(4) dq(8)    
    
section .data
    msg db 'Hello World', 0x00
    
    ; 초기화 되지 않은 데이터
    ; [변수이름] [크기] [개수]
    ; [크기] resb(1) resw(2) resd(4) resq(8)

section .bss
    num resb 10

