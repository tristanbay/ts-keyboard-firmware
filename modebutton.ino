ModeButton::ModeButton()
{
  modebuf = 0;
}

void ModeButton::update(Settings& s)
{
  modebuf = (modebuf << 1) + (digitalRead(MODEPIN) ? 1 : 0);
  if ((((modebuf << 1) >> 1) ? 1 : 0) > (((modebuf >> 1) << 1) ? 1 : 0))
    s.changemapping();
}