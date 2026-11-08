# Steps
1. Creating new project
2. Starting MCC and go to Pin Package View
3. Enabling RD10 as GPIO output. This is used for lightning on-board LED
4. Enabling RD13 as GPIO input. This is used to generating the interrupt by pressing on-board SW.
5. Go to Pins tab
6. Enabling Weak Pullup in RD13 (SW). See detail in Curiosity Nano User Guide 5.2. Mechanical Switch
7. Also select options in Interrupt on Change. Any is selected in this repository so that both rising and falling edge will generate interrupt.
8. Register your interrupt handler with IO_SW_SetInterruptHandler(intr) defined in pins.c
