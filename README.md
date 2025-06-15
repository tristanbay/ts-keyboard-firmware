# TS Keyboard Firmware
This is the official repository for the firmware for the TS41 isomorphic/microtonal MIDI keyboard, powered by the Adafruit KB2040 microcontroller.

## How to upload to the KB2040
1. Download Arduino IDE v2 and open the application.
2. In the Library Manager, install "Adafruit TinyUSB Library" by *Adafruit*.
3. Install the "arduino-pico" board package by following [these instructions](https://github.com/earlephilhower/arduino-pico#installing-via-arduino-boards-manager), including the OS-specific notes if they apply to your system.
4. With the USB port facing away from you, hold down the button on the left-hand side of the microcontroller while plugging it into the computer.
5. Select the "Adafruit KB2040" board option from the drop-down menu near the top of the IDE window (just to the right of the three circular buttons).
6. Press the circular "Upload" button near the board drop-down menu (the one with the arrow) **or** press Ctrl-U (or Cmd-U on Mac) to compile and upload the firmware to the microcontroller.
