// keys functions

Keys::Keys()
{
}

int Keys::offset(int x, int o)
{
  return (x + KEYCOUNT + o) % KEYCOUNT;
}

void Keys::keyscan()
{
  digitalWrite(PULSEPIN, HIGH);
  delayMicroseconds(PULSEOFF);
  for (int i = 0; i < KEYCOUNT; ++i) {
    digitalWrite(STOREPIN, LOW);
    digitalWrite(SHIFTPIN, HIGH);
    delayMicroseconds(PULSEON); // waiting more time here means more keys need to be pressed at once for bleed-over
    keybuf[offset(i, OFFS)] = (keybuf[offset(i, OFFS)] << 1) + (digitalRead(READPIN) ? 1 : 0);
    digitalWrite(STOREPIN, HIGH);
    digitalWrite(SHIFTPIN, LOW);
    if (i == 0)
      digitalWrite(PULSEPIN, LOW);
    delayMicroseconds(PULSEOFF);
  }
}