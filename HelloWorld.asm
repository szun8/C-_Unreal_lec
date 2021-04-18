%include "io64.inc"

section .text
global CMAIN
CMAIN:
    mov rbp, rsp; for correct debugging
   
   ; 분기문 (if)
   ; 특정 조건에 따라서 코드 흐름을 제어하는 것
   ; ex) 스킬 버튼 눌렀는가? - YES -> 스킬 사용
   ; ex) 제한 시간 내에 던전 입장 수락 버튼을 눌렀는가? YES -> 입장, NO -> 던전 취소
   
   ; 조건 -> 흐름
   
   ; CMP(컴페어 명령-두 피연산자를 비교) dst, src (dst가 기준)
   ; https://url.kr/c5brvt
   ; 비교를 한 결과물은 Flag Register 저장 (상태 저장)
   
   ; JMP [label] 시리즈
   ; 이걸 통해서 비교-저장된 상태에 맞춰 시리즈 작동시켜주면 되는
   ; JMP : 무조건 jump
   ; JE : JumpEquals 같으면 jump
   ; JNE : JumpNotEquals 크면 jump
   ; JG : JumpGreater 크면 jump
   ; JGE : JumpGreaterEquals 크거나 같으면 jump
   ; JL, JLE 등 많은 조건이 있음
   
   ; 두 숫자가 같으면 1, 아니면 0을 출력하는 프로그램
   
   mov rax, 10
   mov rbx, 20
   
   cmp rax, rbx
   je LABEL_EQUAL ;비교 결과물이 같으면 이 위치로 이동
   
   ; je에 의해 점프를 안했다면, 같지 않다는 의미로 0 입력후, LABEL_EQUAL_END로 이동
   mov rcx, 0
   jmp LABEL_EQUAL_END
   
LABEL_EQUAL: ;어셈블리어에서만 기능하는 위치 라벨
    mov rcx, 1
LABEL_EQUAL_END:
    PRINT_HEX 1,rcx
    NEWLINE
    
    ; 연습문제 : 어떤 숫자(1~100)가 짝수면 1, 홀수면 0을 출력하는 프로그램
    mov ax, 100
    mov bl, 2
    
    div bl ;100/2
    ; 나머지 ah가 0이면, 짝수/ 1이면, 홀수
    cmp ah, 0 ;짝수냐?
    je LABEL_EVEN ;짝수임.
    
    mov rcx, 0 ;홀수임.
    jmp LABEL_NEVEN
    
LABEL_EVEN:
    mov rcx, 1
    
LABEL_NEVEN:
    PRINT_HEX 1, rcx
    NEWLINE

    
   
   ;비교 결과 저장 내용 eflag register, cmp eflag 구글링^^
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

