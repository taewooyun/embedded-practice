# Embedded System Practice

이 저장소는 임베디드 시스템의 전체 생태계를 구조화하여,  
각 계층(엣지 디바이스 → 데이터 브릿지 → 운용/제어 계층)에 해당하는 프로젝트를 직접 실습하고 기록한 학습용 레포입니다.  
QEMU 기반 펌웨어 개발부터 시작해, 실제 MCU 보드, RTOS, 통신 모듈, 제어 애플리케이션까지 실습 범위를 확장해나갑니다.

---

## 🧭 생태계 기반 학습 로드맵
```
[엣지 디바이스 계층]  
 ├─ QEMU UART 출력 ✅  
 ├─ Timer / GPIO 제어  
 ├─ RTOS Task 스케줄링  
 ├─ 센서 모듈 연동 (추후 보드 실습 예정)  
↓  
[데이터 브릿지 계층]  
 ├─ UART ↔ MQTT Bridge  
 ├─ Embedded Linux UART 통신 처리  
↓  
[운용/제어 계층]  
 ├─ Qt 기반 UART 로그 모니터 앱  
 ├─ Python 기반 자동화 테스트 도구
```
---

## 📁 디렉토리 구조
```
Embedded-Roadmap/  
├── edge/                    # 엣지 디바이스 계층 실습  
│  ├── uart_hello_qemu/  
│  ├── timer_blink_qemu/  
│  └── rtos_intro/  
│  
├── bridge/                  # 데이터 브릿지 계층 실습  
│  ├── serial_mqtt_bridge/  
│  └── embedded_linux_uart/  
│  
├── control/                 # 운용/제어 계층 실습  
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

## ✅ 실습 프로젝트 목록

### 📂 1. 엣지 디바이스 계층

| 프로젝트 | 설명 | 상태 |
|----------|------|------|
| [`uart_hello_qemu/`](./edge/uart_hello_qemu) | QEMU에서 UART 직접 초기화 및 출력 | ✅ 완료 |
| `timer_blink_qemu/` | QEMU에서 Timer delay 구현 | 🔜 예정 |
| `rtos_intro/` | FreeRTOS task 스케줄링 실습 | 🔜 예정 |

### 📂 2. 데이터 브릿지 계층

| 프로젝트 | 설명 | 상태 |
|----------|------|------|
| `serial_mqtt_bridge/` | UART → MQTT 변환 처리 | ⏳ 예정 |
| `embedded_linux_uart/` | Linux(Ubuntu, WSL) 기반 시리얼 수신 처리 | ⏳ 예정 |

### 📂 3. 운용/제어 계층

| 프로젝트 | 설명 | 상태 |
|----------|------|------|
| `qt_uart_monitor/` | Qt 기반 UART 로그 모니터 GUI 앱 | ⏳ 예정 |
| `python_uart_tester/` | UART 자동화 테스트 스크립트 | ⏳ 예정 |

---

## 🛠️ 공통 개발 환경

- OS: Ubuntu (WSL or native)
- Emulator: QEMU (`qemu-system-arm`)
- Toolchain: GCC ARM Embedded (`arm-none-eabi-gcc`)
- IDE: VSCode (또는 CLI 중심 개발)

---

## 🧾 커밋 메시지 규칙

### ✅ 포맷

```
[계층]/[프로젝트명]: [유형] [변경 내용]
```

### ✅ 예시

```
edge/uart_hello_qemu: feat UART 출력 초기화 코드 작성
bridge/serial_mqtt_bridge: docs README 작성
control/python_uart_tester: test 수신 파싱 테스트 추가
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

- 보드 없이 QEMU 환경에서 펌웨어 구조 실습
- ARM Cortex-M 기반 MCU의 부트 및 주변장치 제어 구조 이해
- 생태계 흐름에 맞춘 계층별 실습 구성으로 실전 대응력 강화
- RTOS, 통신, 제어 소프트웨어까지 자연스럽게 확장 가능

---

## ✍️ 작성자

- GitHub: [your-username]
- 목표: 방산 소프트웨어 개발자 / 임베디드 펌웨어 엔지니어
