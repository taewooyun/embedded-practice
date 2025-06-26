# [GPIO 제어 – 버튼 입력 + LED 토글] – STM32CubeIDE 실습 (STM32F103)

STM32 보드에서 버튼 입력을 감지하여 내장 LED를 토글하는 기본 디지털 GPIO 제어 실습입니다.

---

## ✅ 실습 목표

- GPIO 입력 설정 및 버튼 상태 감지
- GPIO 출력 설정으로 LED 토글
- Polling 기반 입력 처리 구조 이해

---

## 🗂️ 디렉토리 구조
```
2.gpio_control/
├── Core/
│ ├── Src/
│ │ └── main.c
│ └── Inc/
│ └── main.h
├── Drivers/
├── 2.gpio_control.ioc
├── README.md
```
---

## ⚙️ 빌드 및 업로드

1. STM32CubeIDE에서 `.ioc` 파일 열기
2. 핀 설정:
   - `PA5` → GPIO Output (LED)
   - `PC13` → GPIO Input (Button)
3. 보드 업로드 → 버튼 누르면 LED 토글 확인

---

## 📚 구성 흐름 요약

1. `HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)`  
   → 버튼 입력 상태 확인

2. `HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5)`  
   → LED 토글

3. `HAL_Delay(50)`  
   → 간단 디바운스 처리

---

## 🛠️ 개발 환경

- STM32CubeIDE v1.15 이상
- 보드: STM32F103C8T6 or NUCLEO-L073RZ
- UART 시리얼 모니터 (선택): TeraTerm, PuTTY 등

---

## 🐛 주요 이슈 & 해결

❗ **LED 너무 빨리 깜빡임**  
✅ `HAL_Delay(50)` 또는 이전 상태 저장 방식으로 디바운스 처리

