# TS Keyboard Firmware
This is the official repository for the firmware for the TS41 isomorphic/microtonal MIDI keyboard, powered by the Adafruit KB2040 microcontroller.  

![The TS41 MIDI Keyboard](https://raw.githubusercontent.com/tristanbay/ts-keyboard-firmware/refs/heads/main/ts41_pic.jpg)

## Customizing layout presets
To change the keyboard's layout presets, make your own layout by following the instructions below or copy and paste one from [layouts.txt](https://github.com/tristanbay/ts-keyboard-firmware/blob/main/layouts.txt) into the definition of `mpre` in the `Settings::Settings()` function in the [settings.ino](https://github.com/tristanbay/ts-keyboard-firmware/blob/main/settings.ino) file. If there are more or fewer total layouts given in the function than before, change the value of the `MAPCOUNT` macro in [ts41.ino](https://github.com/tristanbay/ts-keyboard-firmware/blob/main/ts41.ino) to however many layouts there are now.  

To create your own layout, make a list of comma-separated MIDI note values where the position of the number in the list corresponds to the index of the physical key.

## Customizing preset colors
Similar to customizing the layouts, colors for each preset can be customized by changing the entries in the definition of `cpre` in the `Settings::Settings()` function in **settings.ino**. The first position of each sub-array should not be changed (it should stay as `0`) since this refers to the index of the NeoPixel being lit up and there is only one. The second, third, and fourth positions are the amounts of red, green, and blue, respectively, from a range of 0 to 255, and these are the values you want to change.  

The stock firmware has 4 layouts. In order, they are:
- 41 notes per octave (in orange)
- 31 notes per octave (in off-white)
- 22 notes per octave (in emerald green)
- 19 notes per octave (in indigo)

## Uploading the firmware to the keyboard
1. Download Arduino IDE v2.
    - If installing as a Flatpak, follow [these instructions](https://github.com/flathub/cc.arduino.IDE2/blob/master/README.md) to make sure USB permissions are set up properly.
2. Download either the .zip or .tar.gz file from the latest release on the right-hand side of this page (which contains the firmware code), unzip it, rename it as "ts41", and place it in the Arduino sketchbook folder.
    - On Linux, the sketchbook folder will probably be in the home directory by default, but it may vary on other operating systems. You can find out where it is by opening the Arduino IDE and going to **File > Preferences > Settings > Sketchbook location**.
3. Open the Arduino IDE. On the left side of the window near the top, click the folder icon and select the project named "ts41" from the menu.
4. In the Library Manager, install "Adafruit TinyUSB Library" by *Adafruit*.
5. Install the "arduino-pico" board package by following [these instructions](https://github.com/earlephilhower/arduino-pico#installing-via-arduino-boards-manager), including the OS-specific notes if they apply to your system.
6. Select the "Adafruit KB2040" board option from the drop-down menu near the top of the IDE window (just to the right of the three circular buttons).
7. In the top menu bar, under **Tools > USB Stack**, select the "Adafruit TinyUSB" option.
8. Plug the keyboard into the computer if not already plugged in.
9. Press the circular "Upload" button near the board drop-down menu (the one with the arrow) **or** press Ctrl-U (or Cmd-U on Mac) to compile and upload the firmware to the microcontroller.
