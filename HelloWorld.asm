%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
   
    ; 함수 (procedure 프로시저, subroutine 서브루틴)
    ;call PRINT_MSG
    
    mov eax, 10
    mov ebx, 5
    call MAX
    PRINT_DEC 4, ecx
    NEWLINE
    
    xor rax, rax ; return 0 과 같은 의미
    ret
    
PRINT_MSG:
    PRINT_STRING msg
    NEWLINE
    ret
    
;ex) 두 값중 더 큰 값을 반환하는 mx
;근데 두 기ㅏㅄ을 어떻게 넘겨받지? 반환 어떻게?
;eax와 ebx 입력값을 ecx에 반환
MAX:
    cmp eax, ebx
    jg L1 ;eax가 크면 L1으로 이동
    mov ecx, ebx
    jmp L2
    
L1:
    mov ecx, eax
    
L2:
    ret
    
    ; 그런데 인자가 10개라면 어떻게 할까? a,b,c,d,,,
    ; eax, ebx에 이미 중요한 값이 있으면 어떻게 할까?
    ; [!] .data .bss 사용하면?
    ; 인자를 도대체 몇개를 할당해야 하지?
    
    ; 다른 메모리 구조가 필요하다
    ; - 꿈이 유효한 동안에는 그 꿈을 유지시켜야함 (유효범위의 개념이 있다)
    ; - 꿈이 끝나면 그 꿈을 부셔버려도 됨 (정리의 개념이 있다)
    ; - 꿈에서도 또 꿈을 꿀 수 있따는 것을 고려해야 함 (유동적으로 유효 범위가 확장 가능)
    
    ; [!] 스택(stack)이라는 메모리 영역을 사용
    ; 함수가 사용하는 일종의 메모장
    ; - 매개 변수 전달
    ; - 돌아갈 주소 관리
    
    ;===> To be continued...
    
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

