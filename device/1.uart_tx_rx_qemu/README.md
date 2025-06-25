# QEMU UART Echo – Cortex-M3 Bare-metal 실습

이 프로젝트는 QEMU 에뮬레이터에서 ARM Cortex-M3 아키텍처(LM3S6965EVB 보드)를 기반으로 **UART 송수신 (에코)** 기능을 실습하는 예제입니다.  
실물 보드 없이 UART 레지스터 구조, 벡터 테이블, 초기화 흐름 등을 이해하는 것을 목표로 합니다.

---

## ✅ 실습 목표

- ARM Cortex-M3 아키텍처 초기 부팅 흐름 이해
- MMIO 방식으로 UART 송수신 구현
- QEMU를 통한 UART ↔ 콘솔 I/O 테스트
- startup, linker, main 구성 요소의 역할 이해

---

## 🗂️ 디렉토리 구조
```
uart_echo_qemu/
├── Makefile
├── linker.ld
├── qemu_run.sh
├── startup.s
├── main.c
└── README.md
```
---

## ⚙️ 빌드 및 실행

```bash
make clean
make
```
빌드 성공 시 main.elf 생성됨

▶️ 실행 방법 (QEMU)
```bash
./qemu_run.sh
```
(내부 명령: qemu-system-arm -M lm3s6965evb -nographic -serial mon:stdio -kernel main.elf)

🔍 예상 출력:
```css
UART Echo Ready
[a 입력 시]
a
```
종료 방법: Ctrl + A → X

## 📚 구성 흐름 요약
1. startup.s

    → 초기 스택 설정 및 Reset_Handler 정의

    → main()으로 분기
1. main.c

    → uart_print()로 안내 메시지 출력

    → uart_receive()로 입력
    
    → uart_send()로 echo 출력
1. UART 레지스터

    → UART0_DR (0x4000C000): 데이터 송수신

    → UART0_FR (0x4000C018): 송수신 상태 (TXFF, RXFE 등)
1. linker.ld

    → .isr_vector, .text, .data, .bss 등 섹션의 메모리 배치 설정

    → RAM/FLASH 영역 크기 정의

### 🛠️ 개발 환경
QEMU 8.x 이상 (qemu-system-arm)

ARM GCC 툴체인 (arm-none-eabi-gcc)

make (GNU Make)

VSCode + WSL (Ubuntu)

### 🐛 주요 오류 & 해결
❗ 오류 메시지
```bash
Timer with period zero, disabling
qemu: fatal: Lockup: can't escalate 3 to HardFault (current priority -1)
```
✅ 해결 방법

- startup.s에서 .type Reset_Handler, %function 명시 필요

- Reset_Handler의 .text 섹션 선언 누락 시 QEMU 실행 오류 발생

- -serial mon:stdio 옵션 누락 시 UART 출력이 콘솔에 보이지 않음