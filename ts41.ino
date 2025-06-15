// declarations of things

#include <Adafruit_TinyUSB.h>
#include <MIDI.h>

#define NOTECOUNT 128 // number of MIDI notes in channel
#define KEYCOUNT 126 // number of keyboard keys
#define MAPCOUNT 3 // number of keyboard mappings

#define OFFS -1 // shift the keyscan readouts by this many places backward
#define PULSEON 8 // pulse-on wait time in microseconds (reducing this lowers # of keys for bleed-over)
#define PULSEOFF 2 // pulse-off wait time in microseconds

#define READPIN 10
#define PULSEPIN 8
#define SHIFTPIN 7
#define STOREPIN 6
#define MODEPIN 9

#define DEVNAME "TS41 MIDI Keyboard"
#define MFRNAME "Tristan Bay"

#define MIDICH 1
#define MIDIVEL 64

struct Settings
{
  Settings();
  void changemapping(); // increment or wrap around current mapping
  short mappings[KEYCOUNT][MAPCOUNT]; // array of keyboard mappings; loaded in during setup
  short currmap; // index of current mapping to use
};

struct Keys
{
  Keys();
  int offset(int, int);
  void keyscan(); // scan all keys once
  void printkeys();
  unsigned short keybuf[KEYCOUNT]; // treated as arrays of bools for on/off (for de-bouncing)
};

struct ModeButton
{
  ModeButton();
  void update(Settings&); // includes what to do if pressed
  unsigned short modebuf; // treated as array of bools for on/off (for de-bouncing)
};

struct Notes
{
  Notes();
  void update(Keys&, Settings&); // update note buffer
  void printnotes(); // print notes to console
  short notebuf[NOTECOUNT]; // 1 if pressed, 0 if not
  short prevnote[NOTECOUNT]; // same as above but for previous scan
  short status[NOTECOUNT]; // 0 = no action, 1 = note on, -1 = note off
};