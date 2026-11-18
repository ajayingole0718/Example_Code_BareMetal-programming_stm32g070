# STM32 Embedded Systems – Practical Projects & Examples

A collection of Embedded C programming examples, STM32 microcontroller projects, peripheral drivers, and FreeRTOS-based applications developed for learning, experimentation, and practical embedded software development.

This repository contains hands-on projects using STM32 microcontrollers, including GPIO, PWM, ADC, SPI, I2C, UART, and Real-Time Operating System (RTOS) concepts.

## Repository Overview

The repository is organized into individual project directories.

### Projects

| No. | Project | Description |
|---|---|---|
| 1 | `1_test_Software` | STM32 embedded software testing and development |
| 2 | `FreeRTOS_Queue` | FreeRTOS queue-based inter-task communication |
| 3 | `FreeRTOS_Software_RTOS_API` | FreeRTOS API implementation and practice |
| 4 | `I2C_LCD_Display` | LCD interfacing using the I2C protocol |
| 5 | `Led_control_using_PWM_ACT` | LED control using PWM |
| 6 | `Led_control_using_PWM_GPT` | PWM-based LED control and experiments |
| 7 | `SPI_ADXL_Project` | ADXL345 accelerometer interfacing using SPI |
| 8 | `one_khz_pulse` | 1 kHz pulse generation using STM32 timer/GPIO |

## Technologies & Concepts

- Embedded C programming
- STM32 microcontrollers
- ARM Cortex-M architecture
- CMSIS and register-level programming
- GPIO configuration and control
- Timer and interrupt programming
- PWM generation
- ADC interfacing
- SPI communication
- I2C communication
- LCD interfacing
- FreeRTOS
- Task creation and scheduling
- Queues and synchronization
- Inter-task communication

## Development Environment

| Tool | Usage |
|---|---|
| STM32CubeIDE | Embedded software development |
| STM32CubeMX | Peripheral configuration |
| Git | Version control |
| GitHub | Source code management |
| C Language | Embedded programming |

## Hardware Platform

Projects are developed and tested using STM32 development boards and microcontrollers.

The repository includes STM32G0 and STM32F4-related development examples.

Actual hardware requirements depend on the individual project.

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/YOUR_USERNAME/Example_Code_stm32g0andStm32f4.git
```

### 2. Open STM32CubeIDE

1. Launch STM32CubeIDE.
2. Select your workspace.
3. Import the required project directory.
4. Check the MCU configuration and build settings.
5. Build the project.
6. Connect the target STM32 board.
7. Flash and debug the firmware.

### 3. Explore individual projects

Each project has its own source code and configuration files. Open the required project directory to explore its implementation.

## Repository Structure

```text
Example_Code_stm32g0andStm32f4/
│
├── 1_test_Software/
│
├── FreeRTOS_Queue/
│
├── FreeRTOS_Software_RTOS_API/
│
├── I2C_LCD_Display/
│
├── Led_control_using_PWM_ACT/
│
├── Led_control_using_PWM_GPT/
│
├── SPI_ADXL_Project/
│
├── one_khz_pulse/
│
└── README.md
```

## Learning Objectives

The main objectives of this repository are:

- Develop strong Embedded C programming skills.
- Understand STM32 peripheral programming.
- Practice hardware-level register configuration.
- Understand interrupt handling and timer operations.
- Gain practical experience with FreeRTOS.
- Implement communication protocols.
- Develop reusable embedded software modules.
- Improve debugging and firmware development skills.

## Future Improvements

More projects and implementations will be added, including:

- UART communication and DMA
- ADC with hardware timer triggering
- FreeRTOS synchronization mechanisms
- Advanced embedded system applications
  
**Embedded Software / Firmware Development**

Interested in Embedded C, STM32 microcontrollers, ARM Cortex-M architecture, FreeRTOS, peripheral drivers, and IoT firmware development.

## Contributions

This repository is primarily maintained as a practical embedded systems development and learning collection.

Suggestions, improvements, and technical discussions are welcome.

---

