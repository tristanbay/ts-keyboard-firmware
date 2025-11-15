# TS Keyboard Firmware
This is the official repository for the firmware for the TS41 isomorphic/microtonal MIDI keyboard, powered by the Adafruit KB2040 microcontroller.

![The TS41 MIDI Keyboard](https://raw.githubusercontent.com/tristanbay/ts-keyboard-firmware/refs/heads/main/ts41_pic.jpg)

## Customizing layouts
To change the keyboard's layout presets, make your own layout by following the instructions below or copy and paste one from [layouts.txt](https://github.com/tristanbay/ts-keyboard-firmware/blob/main/layouts.txt) into the definition of `mpre` in the `Settings::Settings()` function in the [settings.ino](https://github.com/tristanbay/ts-keyboard-firmware/blob/main/settings.ino) file. If there are more or fewer total layouts given in the function than before, change the value of the `MAPCOUNT` macro in [ts41.ino](https://github.com/tristanbay/ts-keyboard-firmware/blob/main/ts41.ino) to however many layouts there are now.

To create your own layout, make a list of comma-separated MIDI note values where the position of the number in the list corresponds to the index of the physical key.

## Customizing colors
Similar to customizing the layouts, colors for each preset can be customized by changing the entries in the definition of `cpre` in the `Settings::Settings()` function in **settings.ino**. The first position of each sub-array should not be changed (it should stay as `0`) since this refers to the index of the NeoPixel being lit up and there is only one. The second, third, and fourth positions are the amounts of red, green, and blue, respectively, from a range of 0 to 255, and these are the values you want to change.

## How to upload the firmware to the KB2040
1. Download Arduino IDE v2 and open the application.
    - If installing as a Flatpak, follow [these instructions](https://github.com/flathub/cc.arduino.IDE2/blob/master/README.md) to make sure USB permissions are set up properly.
2. In the Library Manager, install "Adafruit TinyUSB Library" by *Adafruit*.
3. Install the "arduino-pico" board package by following [these instructions](https://github.com/earlephilhower/arduino-pico#installing-via-arduino-boards-manager), including the OS-specific notes if they apply to your system.
4. Select the "Adafruit KB2040" board option from the drop-down menu near the top of the IDE window (just to the right of the three circular buttons).
5. In the top menu bar, under **Tools > USB Stack**, select the "Adafruit TinyUSB" option.
6. Plug the keyboard into the computer if not already plugged in.
7. Press the circular "Upload" button near the board drop-down menu (the one with the arrow) **or** press Ctrl-U (or Cmd-U on Mac) to compile and upload the firmware to the microcontroller.
