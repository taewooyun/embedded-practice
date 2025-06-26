# UART Tick + LED Toggle – STM32CubeIDE 실습 (Nucleo-F103RB)

이 프로젝트는 STM32 Nucleo-F103RB 보드를 사용하여 **UART를 통한 tick 메시지 출력**과  
**PA5(GPIO)를 이용한 LED 토글**을 1초 간격으로 반복하는 실습입니다.

STM32CubeIDE를 기반으로 **SystemClock 설정, GPIO 초기화, UART 전송**을 수행하며,  
실제 하드웨어 작동을 통해 MCU 초기화 흐름을 익히는 것이 목표입니다.

---

## ✅ 실습 목표

- STM32 HAL을 통한 시스템 클럭 설정 흐름 이해
- UART2 (PA2, PA3) 전송 설정 및 시리얼 출력 확인
- GPIO (PA5) 출력 설정 및 LED 토글 구현
- `HAL_Delay()` 기반의 주기적 작업 흐름 구현
- CubeMX 및 CubeIDE 기본 사용법 익히기

---

## 🗂️ 디렉토리 구조
```
2.uart_gpio_led/
├── Core/
├── Drivers/
├── Debug/ # (Git 무시 대상)
├── .gitignore
├── .project
├── .mxproject
├── 2.uart_gpio_led.ioc
├── STM32F103RBTX_FLASH.ld
└── README.md
```
---

## ⚙️ 빌드 및 업로드

🛠️ STM32CubeIDE 내부에서:

1. **Build (Ctrl + B)**  
2. **Run → Debug 또는 Run 버튼 클릭**  
3. PlatformIO 또는 외부 시리얼툴로 COM 포트 열기

📟 시리얼 설정: `115200 8-N-1`  

**출력 예시:**
```
tick
tick
tick
```
💡 LED(PA5, LD2)는 1초 간격으로 깜빡입니다.

---

## 📚 구성 흐름 요약

1. **SystemClock_Config()**  
    → 기본 HSI 클럭을 사용하여 SYSCLK, AHB, APB 클럭 분주 설정

2. **MX_USART2_UART_Init()**  
    → `PA2`, `PA3`를 사용한 UART2 설정 (115200bps)

3. **MX_GPIO_Init()**  
    → `PA5`를 Push-Pull 출력으로 설정 (LD2 제어용)

4. **main() 루프**  
    → `"tick\r\n"` 메시지 전송  
    → PA5 핀 토글  
    → 1초 대기 반복

---

## 🛠️ 개발 환경

- STM32CubeIDE 1.18.x  
- STM32 Nucleo-F103RB 보드  
- arm-none-eabi-gcc (CubeIDE 내장)  
- 시리얼 모니터: PlatformIO

---

## 🐛 주요 이슈 & 해결

❗ `tick`이 한 번만 출력되고 루프가 돌지 않음  
✅ 해결: SystemClock_Config()에서 HSI 설정 누락 또는 SysTick 설정 오류

❗ LED 토글은 되는데 UART 출력이 안 보임  
✅ 해결: UART2 TX/RX 핀 설정이 잘못되었거나 시리얼 모니터 포트/속도 불일치

❗ 보드에 업로드는 되었지만 반응 없음  
✅ 해결: .ioc 설정을 초기화하거나 코드에 `HAL_Init()` 누락 여부 확인