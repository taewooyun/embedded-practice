# Embedded System Practice

이 저장소는 임베디드 시스템의 전체 생태계를 구조화하여,  
각 계층(엣지 디바이스 → 데이터 브릿지 → 운용/제어 계층)에 해당하는 프로젝트를 직접 실습하고 기록한 학습용 레포입니다.  
QEMU 기반 펌웨어 개발부터 시작해, 실제 MCU 보드, RTOS, 통신 모듈, 제어 애플리케이션까지 실습 범위를 확장해나갑니다.

---

## 🧭 생태계 기반 학습 로드맵
## 🧭 계층 구분

| 계층 | 설명 |
| --- | --- |
| **디바이스 계층(Device Layer)** | 센서, MCU, 주변장치 제어. RTOS 포함 |
| **통신 계층(Communication Layer)** | UART, MQTT, TCP/IP 등 상위 계층과의 데이터 교환 |
| **응용 계층(Application Layer)** | UI/제어 소프트웨어. 모니터링, 명령 송신 담당 |

---

## 📘 1. 디바이스 계층 실습 로드맵

| 챕터 | 주제 | 기술 키워드 | 실습 대상 |
| --- | --- | --- | --- |
| 1 | UART TX/RX | UART 레지스터, TXE, RXNE | QEMU, STM32 |
| 2 | GPIO 제어 | MODER, ODR, IDR | STM32 |
| 3 | SysTick 타이머 | 주기 인터럽트, 핸들러 | QEMU, STM32 |
| 4 | 외부 인터럽트 (EXTI) | NVIC, 핀 인터럽트 | STM32 |
| 5 | 타이머 기반 PWM | TIMx, CCR, ARR | 서보 모터, LED |
| 6 | ADC 센서 연동 | 온도센서, 전압 측정 | STM32 |
| 7 | I2C 통신 | MPU6050, OLED 등 | STM32 |
| 8 | SPI 통신 | 플래시, 디스플레이 | STM32 |
| 9 | RTOS 도입 | FreeRTOS Task, Semaphore | STM32 |
| 10 | Watchdog & Fault Handling | 시스템 복구, 무한루프 감지 | STM32 |

---

## 📗 2. 통신 계층 실습 로드맵

| 챕터 | 주제 | 기술 키워드 | 실습 대상 |
| --- | --- | --- | --- |
| 1 | UART ↔ PC | pyserial, minicom | PC + STM32 |
| 2 | UART ↔ MQTT | UART 파싱 + MQTT Publish | Python Bridge |
| 3 | MQTT 통신 | Mosquitto, QoS | ESP8266 or PC |
| 4 | MQTT ↔ MCU 명령 | MQTT → UART 명령어 변환 | Python, STM32 |
| 5 | TCP/IP 소켓 통신 | Socket 서버/클라이언트 | PC ↔ MCU or SBC |
| 6 | BLE 통신 | BLE 모듈(HM-10), AT 커맨드 | STM32 + 모듈 |
| 7 | CAN 통신 | CAN 트랜시버, 필터 설정 | STM32F103CAN |

---

## 📙 3. 응용 계층 실습 로드맵

| 챕터 | 주제 | 기술 키워드 | 실습 대상 |
| --- | --- | --- | --- |
| 1 | UART 터미널 기반 CLI | Python + UART 명령 UI | PC |
| 2 | MQTT 데이터 시각화 | Node-RED 대시보드 | PC |
| 3 | 간이 GUI (Python) | PyQt, Tkinter | PC |
| 4 | Qt 기반 제어 UI | QtWidgets, Signals | PC |
| 5 | 명령 입력 + 상태 모니터링 | QT or MFC + 프로토콜 설계 | PC ↔ MCU |
| 6 | 상태 이벤트 로깅 | SQLite, CSV 저장 | PC |
| 7 | 그래프 기반 센서 모니터링 | Realtime Chart (PyQt/Qt) | PC |
---

## 📁 디렉토리 구조
```
Embedded-Practice/  
├── device/                    # 디바이스 계층 실습  
│  ├── uart_hello_qemu/  
│  ├── timer_blink_qemu/  
│  └── rtos_intro/  
│  
├── communication/           # 통신 계층 실습  
│  ├── serial_mqtt_bridge/  
│  └── embedded_linux_uart/  
│  
├── application/             # 응용 계층 실습  
│  ├── qt_uart_monitor/  
│  └── python_uart_tester/  
│  
├── common/                  # 공통 문서 및 툴 정보  
│  └── toolchain.md
│  
├── .gitignore  
└── README.md  
```
---

## 🛠️ 공통 개발 환경

- OS: Ubuntu (WSL or native)
- Target Board: NUCLEO-F103RB
- MCU: STM32F103RB (ARM Cortex-M3)
- Emulator: QEMU (`qemu-system-arm`)
- Toolchain: GCC ARM Embedded (`arm-none-eabi-gcc`)
- IDE: VSCode (또는 CLI 중심 개발)

---

## 🧾 커밋 메시지 규칙

### ✅ 포맷

```
[계층]/[유형]: [변경 내용]
```

### ✅ 예시

```
device/feat: UART 출력 초기화 코드 작성
communication/test: 수신 파싱 테스트 추가
docs: README 수정
```

### ✅ 커밋 유형

| 유형 | 설명 |
|------|------|
| `feat` | 새로운 기능 추가 |
| `fix` | 버그 수정 |
| `refactor` | 코드 리팩토링 |
| `docs` | 문서 추가/수정 |
| `build` | 빌드 시스템 변경 |
| `test` | 테스트 코드 추가 |
| `chore` | 기타 작업 (정리, 설정 등)

---

## 🎯 학습 목적

- 펌웨어 구조 실습
- ARM Cortex-M 기반 MCU의 부트 및 주변장치 제어 구조 이해
- 생태계 흐름에 맞춘 계층별 실습 구성으로 실전 대응력 강화
- RTOS, 통신, 제어 소프트웨어까지 확장

---

## ✍️ 작성자

- GitHub: [taewooyun]
- 목표: 임베디드 시스템 개발
