// settings functions (and hard-coded presets)

Settings::Settings()
{
  short mpre[MAPCOUNT][KEYCOUNT] = { // temp array for key mappings (layout formatted in mirror image of keyboard)
    { // 12edo harmonic table (major thirds up/right)
        3,  2,  1,
      7,  6,  5,  4,
        10, 9,  8,
          13, 12, 11,
        17, 16, 15, 14,
          20, 19, 18,
        24, 23, 22, 21,
          27, 26, 25,
        31, 30, 29, 28,
          34, 33, 32,
            37, 36, 35,
          41, 40, 39, 38,
            44, 43, 42,
          48, 47, 46, 45,
            51, 50, 49,
              54, 53, 52,
            58, 57, 56, 55,
              61, 60, 59,
            65, 64, 63, 62,
              68, 67, 66,
            72, 71, 70, 69,
              75, 74, 73,
                78, 77, 76,
              82, 81, 80, 79,
                85, 84, 83,
              89, 88, 87, 86,
                92, 91, 90,
                  95, 94, 93,
                99, 98, 97, 96,
                  102,101,100,
                106,105,104,103,
                  109,108,107,
                113,112,111,110,
                  116,115,114,
                    119,118,117,
                  123,122,121,120,
                    126,125,124
    },
    { // 12edo harmonic table (major thirds down/right)
        0,  0,  0,
      1,  2,  3,  4,
        5,  6,  7,
          9,  10, 11,
        12, 13, 14, 15,
          16, 17, 18,
        19, 20, 21, 22,
          23, 24, 25,
        26, 27, 28, 29,
          30, 31, 32,
            34, 35, 36,
          37, 38, 39, 40,
            41, 42, 43,
          44, 45, 46, 47,
            48, 49, 50,
              52, 53, 54,
            55, 56, 57, 58,
              59, 60, 61,
            62, 63, 64, 65,
              66, 67, 68,
            69, 70, 71, 72,
              73, 74, 75,
                77, 78, 79,
              80, 81, 82, 83,
                84, 85, 86,
              87, 88, 89, 90,
                91, 92, 93,
                  95, 96, 97,
                98, 99, 100,101,
                  102,103,104,
                105,106,107,108,
                  109,110,111,
                112,113,114,115,
                  116,117,118,
                    120,121,122,
                  123,124,125,126,
                    127,127,127
    },
    { // 12edo bosanquet
        50, 50, 50,
      51, 51, 51, 51,
        52, 52, 52,
          53, 53, 53,
        54, 54, 54, 54,
          55, 55, 55,
        56, 56, 56, 56,
          57, 57, 57,
        58, 58, 58, 58,
          59, 59, 59,
            60, 60, 60,
          61, 61, 61, 61,
            62, 62, 62,
          63, 63, 63, 63,
            64, 64, 64,
              65, 65, 65,
            66, 66, 66, 66,
              67, 67, 67,
            68, 68, 68, 68,
              69, 69, 69,
            70, 70, 70, 70,
              71, 71, 71,
                72, 72, 72,
              73, 73, 73, 73,
                74, 74, 74,
              75, 75, 75, 75,
                76, 76, 76,
                  77, 77, 77,
                78, 78, 78, 78,
                  79, 79, 79,
                80, 80, 80, 80,
                  81, 81, 81,
                82, 82, 82, 82,
                  83, 83, 83,
                    84, 84, 84,
                  85, 85, 85, 85,
                    86, 86, 86
    }
  };
  for (int i = 0; i < MAPCOUNT; ++i) // move to struct-wide array
    for (int j = 0; j < KEYCOUNT; ++j)
      mappings[j][i] = mpre[i][j];
  uint8_t cpre[MAPCOUNT][PIXCHCOUNT] = {
    { 255, 127, 63 }, // 12edo harmonic table (major thirds up/right)
    { 127, 255, 191 }, // 12edo harmonic table (major thirds down/right)
    { 223, 159, 255 }, // 12edo bosanquet
  };
  for (int i = 0; i < MAPCOUNT; ++i) // move to struct-wide array
    for (int j = 0; j < PIXCHCOUNT; ++j)
      colors[j][i] = cpre[i][j];
  currmap = 0; // default mapping index
}

void Settings::updatepixcolor()
{
  pix.setPixelColor(0, st.colors[0][currmap], st.colors[1][currmap], st.colors[2][currmap]);
  pix.show();
}

void Settings::changemapping()
{
  currmap = (currmap + 1) % MAPCOUNT;
  updatepixcolor();
}