---

# Traffic Light Control System on STM32

This repository contains a **traffic light control application** designed for an intersection with adjustable timing in both **automatic** and **manual** modes using mechanical buttons with software debouncing (covering **red**, **amber**, and **green** phases). The system is developed on an **STM32F103C6** microcontroller, simulated using **Proteus**, and implements a **Finite State Machine (FSM)** to manage various modes.

## Table of Contents
1. [Project Overview](#project-overview)  
2. [Features](#features)  
3. [Hardware Requirements](#hardware-requirements)  
4. [Software Requirements](#software-requirements)  
5. [Project Structure](#project-structure)  
6. [Mode Descriptions](#mode-descriptions)  
7. [How to Build and Run](#how-to-build-and-run)  
8. [Future Improvements](#future-improvements)  

---

## 1. Project Overview

This project simulates a **traffic light system** at a crossroads with the following characteristics:

- **12 LEDs** (4 red, 4 amber, 4 green) corresponding to two directions of traffic.
- **4 seven-segment displays** (two per road) to show countdown time and mode number.
- **3 buttons**:
  1. **Mode Selection**: Cycles through 4 modes  
  2. **Time Increase**: Increments the time duration in modification modes
  3. **Time Set**: Confirms and stores the chosen time.

An **FSM (Finite State Machine)** is used to manage the modes, transitions, and LED blinking behavior. The design also includes software-based button debouncing and a flexible timer configuration to ensure stable performance.

### Main Goals

1. **Normal Traffic Light Operation** (Mode 1).  
2. **On-the-Fly Modification** of Red, Amber and Green Durations (Modes 2, 3, 4).  
3. **Stable Timer and Debouncing**: Changing timer interrupt intervals without affecting the main application logic.

---

## 2. Features

- **Operating Modes (4 total)**:
  1. **Normal Mode**: Standard traffic light sequence  
  2. **Modify Red Duration**  
  3. **Modify Amber Duration**  
  4. **Modify Green Duration**  

- **Real-Time Display** on 7-segment LEDs showing:
  - Current countdown time for each color.
  - Current mode indication during editing.

- **Blinking LEDs** in modification modes (2 Hz) to indicate the active editing state and also which color is being edited.

- **Button Debouncing** using software debouncing method for all 3 push buttons to ensure stable input readings.

- **Adjustable Timer Interrupt** (10 ms default) that can be configured to 1 ms or 100 ms without impacting the overall system behavior.

---

## 3. Hardware Requirements

- **STM32 Microcontroller** (e.g., STM32F103C8T6 or similar)  
- **12 LEDs**: 4 red, 4 amber, 4 green  
- **4 Seven-Segment Displays** (common anode or cathode, depending on your design)  
- **3 Push Buttons** for:
  1. Mode Selection: to select modes
  2. Time Increase: to modify the time for each color LED on the fly
  3. Time Set: to set the chosen value

- **Resistors** for LEDs and buttons (as required)  
- **Power Supply**: 5V or 3.3V, depending on the board and LED configurations  

---

## 4. Software Requirements

- **STM32CubeIDE**. Since I have not run and tested the source code on other tools such as **TrueSTUDIO** / **Keil uVision** (any STM32-supported IDE), I recommend using **STM32CubeIDE** to run this project..
- **STM32CubeProgrammer** (optional) to load the hex file (source code) onto your board.
- **Proteus** (for schematic and simulation)  

Ensure your development environment is configured for STM32 microcontrollers.

---

## 5. Project Structure

```
.
├── Source code/
│   ├── .settings                          # Project preferences
│   ├── Button/                            # Button testing functions
│   │   ├── proteus                        # Proteus simulation files
│   │   └── stm32                          # STM32 source code for button testing
│   └── Traffic_light_system_stm32f103c6
│       ├── proteus                        # Proteus simulation files
│       └── stm32                          # Main STM32 source code
│           ├── Core/
│           │   └── Inc/                   # Header files
|               ├── button.h
│               ├── fsm_automatic.h
|               ├── fsm_manual.h
|               ├── global.h
|               ├── led_7_seg.h
|               ├── led_states.h
│               ├── main.h
│               ├── software_timer.h
│           │       └── ...
│           └── Src/                       # Source files
|               ├── button.c               # Button reading and debouncing logic
│               ├── fsm_automatic.c        # Finite State Machine for Normal Mode (Mode 1) 
|               ├── fsm_manual.c           # Finite State Machine for Four Operating Mode (Mode 1-4)
|               ├── global.c               # Global variables and timing settings
|               ├── led_7_seg.c            # Seven-segment display handling
|               ├── led_states.c         
│               ├── main.c                 # Main loop integrating 2 FSM and display logic
│               ├── software_timer.c       # Timer configuration and interrupt              
│               └── ...
|        
├── .gitignore
├── README.md                            # You're reading this file
└── ...

```

### Notable Files

- **main.c**: Initializes hardware, put fsm logic and display seven_segment logic in main loop.  
- **fsm.c / fsm.h**: Contains the FSM logic for mode control.  
- **button.c / button.h**: Button reading (press, hold) and software debouncing.  
- **seven_segment.c / seven_segment.h**: Functions to display mode and time on the 7-segment.  
- **timer.c / timer.h**: Timer setup for periodic interrupts (default 10 ms).

---

## 6. Mode Descriptions

1. **Mode 1 - Normal Mode**  
   - Traffic lights operate normally with fixed durations for Red, Amber, and Green. 
   - 7-segment displays show the remaining time for the current LED color in each direction.

2. **Mode 2 - Modify Red LEDs**  
   - Red LEDs blink at **2 Hz** to indicate we are editing their time duration.  
   - Use the **second button** to increase the time (1–99 seconds).  
   - Press the **third button** to confirm and save the new time.  
   - The 7-segment displays show the **mode number** and the **current time** for Red.

3. **Mode 3 - Modify Amber LEDs**  
   - Similar behavior to Mode 2, but for the Amber LED duration.

4. **Mode 4 - Modify Green LEDs**  
   - Similar behavior to Mode 2, but for the Green LED duration.

Press the **first button** at any time to cycle through modes (1 → 2 → 3 → 4 → 1 → ...). Initially, the system runs with 5 seconds for Red, 3 seconds for Amber, and 2 seconds for Green. After that, when it returns to mode 1, the system runs with the new setting time or the same time if the user does not modify anything.

---

## 7. How to Build and Run

1. **Clone the Repository**  
   ```bash
   git clone https://github.com/NgqvngVinh/Traffic-light-STM32F103C6.git
   cd Traffic-light-STM32F103C6
   ```

2. **Open Project** in your preferred STM32 IDE (recommend: **STM32CubeIDE**).

3. **Check Pin Assignments**  
   - Ensure the pin assignments in the .ioc file (`Lab3_fsm_traffic_light.ioc` or `main.c`) match your actual hardware connections (LEDs, 7-segment displays, buttons).

4. **Build the Project**  
   - Compile the code and generate the `.hex` file (you must go to Navigate to C/C++Build, select Settings, MCU Post build outputs, and check to the Intel Hex file).

5. **Proteus Simulation** (Optional)  
   - Open the **Proteus schematic file** (`.pdsprj`).  
   - Load the compiled firmware (hex file) into the virtual MCU.  
   - Run the simulation to verify functionality before testing on real hardware.

6. **Verify Operation**  
   - Upon reset, the system starts in **Mode 1 (Normal)**.  
   - Press **Button 1** to cycle modes.  
   - In Modes 2–4, use **Button 2** to increment time, then press **Button 3** to set it.

---

## 8. Future Improvements

- **Add More Intersection Directions**: Extend the system to handle more than two directions (e.g., a 4-way intersection).
- **Implement Advanced Traffic Management**: For instance, dynamic timing based on traffic density.

---

**Thank you for checking out this project!**  
If you have any questions or suggestions, feel free to open an issue or submit a pull request.
