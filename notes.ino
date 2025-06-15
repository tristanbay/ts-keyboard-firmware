// notes functions

Notes::Notes()
{
}

void Notes::update(Keys& k, Settings& s)
{
  for (int i = 0; i < NOTECOUNT; ++i) {
    prevnote[i] = notebuf[i]; // set prev note values to old current note values
    notebuf[i] = 0; // then zero out current note values
  }
  for (int i = 0; i < KEYCOUNT; ++i)
    notebuf[s.mappings[i][s.currmap]] += k.keybuf[i] ? 1 : 0; // add each pressed key to total
  for (int i = 0; i < NOTECOUNT; ++i) {
    notebuf[i] = notebuf[i] > 1 ? 1 : notebuf[i]; // clip total to 0 or 1
    status[i] = notebuf[i] - prevnote[i];
  }
}

void Notes::printnotes() // test function
{
  for (int i = 0; i < NOTECOUNT; ++i) {
    switch (status[i]) {
      case 1:
        Serial.print(i);
        Serial.print(": ON\n");
        break;
      case -1:
        Serial.print(i);
        Serial.print(": OFF\n");
        break;
      default:
        break;
    }
  }
}