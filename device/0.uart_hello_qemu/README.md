# QEMU UART Hello – Cortex-M3 Bare-metal 실습

이 프로젝트는 QEMU 에뮬레이터에서 ARM Cortex-M3 아키텍처를 기반으로 UART 메시지를 출력하는 실습 예제입니다.  
임베디드 시스템의 기본 구조, 초기화 코드, MMIO 방식 UART 송신 로직을 경험하는 것이 목적입니다.

---

## ✅ 실습 목표

- ARM Cortex-M3 아키텍처 이해
- UART를 통한 문자열 출력
- QEMU 가상 보드를 활용한 실습 환경 구성
- startup, linker, main, uart 모듈의 구성 흐름 파악

---

## 🗂️ 디렉토리 구조
```
uart_hello_qemu/
├── Makefile
├── linker/
│ └── linker.ld
├── src/
│ ├── main.c
│ ├── uart.c
│ └── startup.s
├── include/
│ └── uart.h
├── build/
└── README.md
```
---

## ⚙️ 빌드 및 실행

```bash
make clean
make
```
빌드가 성공하면 build/cm3.elf 파일이 생성됩니다.

▶️ 실행 방법 (QEMU)
```bash
qemu-system-arm -M lm3s6965evb -nographic -kernel build/cm3.elf
```
🔍 예상 출력
```
Timer with period zero, disabling
Hello from QEMU UART!
```
종료 방법: Ctrl + A -> X 

## 📚 구성 흐름 요약
1. startup.s → 스택 초기화 + main() 진입

1. main.c → uart_init(), uart_puts() 호출

1. uart.c → UART 레지스터 제어하여 출력

1. linker.ld → 섹션 위치 및 메모리 배치 정의

1. QEMU가 UART 출력을 에뮬레이션하여 콘솔에 문자열 출력

## 🛠️ 개발 환경
- QEMU (qemu-system-arm)

- ARM 툴체인 (arm-none-eabi-gcc)

- VSCode + WSL

- make (GNU Make)