// setup and loop

Keys ky;
Notes nt;
Settings st;
ModeButton md;

Adafruit_USBD_MIDI usbmidi;
MIDI_CREATE_INSTANCE(Adafruit_USBD_MIDI, usbmidi, MIDIusb);

void setup()
{
  pinMode(READPIN, INPUT);
  pinMode(PULSEPIN, OUTPUT);
  pinMode(SHIFTPIN, OUTPUT);
  pinMode(STOREPIN, OUTPUT);
  pinMode(MODEPIN, INPUT);
  ky = Keys();
  nt = Notes();
  st = Settings();
  md = ModeButton();
  TinyUSBDevice.setProductDescriptor(DEVNAME);
  TinyUSBDevice.setManufacturerDescriptor(MFRNAME);
  Serial.begin(9600);
  digitalWrite(PULSEPIN, LOW);
  digitalWrite(SHIFTPIN, LOW);
  digitalWrite(STOREPIN, LOW);
  MIDIusb.begin(MIDI_CHANNEL_OMNI);
  MIDIusb.turnThruOff();
}

void loop()
{
  md.update(st);
  ky.keyscan();
  // ky.printkeys();
  nt.update(ky, st);
  // nt.printnotes();
  for (int i = 0; i < NOTECOUNT; ++i) { // send MIDI messages
    switch (nt.status[i]) {
      case 1:
        MIDIusb.sendNoteOn(i, MIDIVEL, MIDICH);
        break;
      case -1:
        MIDIusb.sendNoteOff(i, MIDIVEL, MIDICH);
        break;
      default:
        break;
    }
  }
}