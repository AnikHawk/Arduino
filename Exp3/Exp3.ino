const int tonePin = 9;
#define OCTAVE_OFFSET 0

// These values can also be found as constants in the Tone library (Tone.h)
int notes[] = { 0,//a a#  b    c    c#   d    d#   e    f    f*   g    g#
                262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494,
                523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988,
                1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
                2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951
              };

//char *song = "The Simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
//char *song = "Indiana:d=4,o=5,b=250:e,8p,8f,8g,8p,1c6,8p.,d,8p,8e,1f,p.,g,8p,8a,8b,8p,1f6,p,a,8p,8b,2c6,2d6,2e6,e,8p,8f,8g,8p,1c6,p,d6,8p,8e6,1f.6,g,8p,8g,e.6,8p,d6,8p,8g,e.6,8p,d6,8p,8g,f.6,8p,e6,8p,8d6,2c6";
//char *song = "TakeOnMe:d=4,o=4,b=160:8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5,8f#5,8e5,8f#5,8f#5,8f#5,8d5,8p,8b,8p,8e5,8p,8e5,8p,8e5,8g#5,8g#5,8a5,8b5,8a5,8a5,8a5,8e5,8p,8d5,8p,8f#5,8p,8f#5,8p,8f#5,8e5,8e5";
//char *song = "Entertainer:d=4,o=5,b=140:8d,8d#,8e,c6,8e,c6,8e,2c.6,8c6,8d6,8d#6,8e6,8c6,8d6,e6,8b,d6,2c6,p,8d,8d#,8e,c6,8e,c6,8e,2c.6,8p,8a,8g,8f#,8a,8c6,e6,8d6,8c6,8a,2d6";
//char *song = "20thCenFox:d=16,o=5,b=140:b,8p,b,b,2b,p,c6,32p,b,32p,c6,32p,b,32p,c6,32p,b,8p,b,b,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,b,32p,g#,32p,a,32p,b,8p,b,b,2b,4p,8e,8g#,8b,1c#6,8f#,8a,8c#6,1e6,8a,8c#6,8e6,1e6,8b,8g#,8a,2b";
//char *song = "Bond:d=4,o=5,b=80:32p,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d#6,16d#6,16c#6,32d#6,32d#6,16d#6,8d#6,16c#6,16c#6,16c#6,16c#6,32e6,32e6,16e6,8e6,16d#6,16d6,16c#6,16c#7,c.7,16g#6,16f#6,g#.6";
//char *song = "StarWars:d=4,o=5,b=45:32p,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#.6,32f#,32f#,32f#,8b.,8f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32c#6,8b.6,16f#.6,32e6,32d#6,32e6,8c#6";
//char *song = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";
//char *song = "Ajnabi:d=4,o=5,b=200:8c#6,8b,8a,8g#,f#.,c#.6,c#6,8c#.6,b,16b,8c#6,d6,c#6,2b.,8c#6,8b,16g#.,8f#,e,f#,8g#.,16f#,2e,2f#,g#,8f#,e.,16g#.,a.,g#,16f#,16g#,1f#.,16g#,8a.,g#,f#.,c#.6,c#6,8c#.6,b,8b,16c#.6,d6,c#6,2b.,8c#6,8b,16g#.,8f#,e,f#,8g#.,16f#.,e.,f#.,8g#.,8f#,8e.,c#,a,g#,16f#.,16g#.,2f#.,a4";
//char *song = "Ajeeb:d=16,o=6,b=130:a,p,8g,p,a,p,8g,p,e,p,8d,p,c,p,4e,2p,a,p,8g,p,a,p,8g,p,e,p,8d,p,c,p,4d,2p,e,p,8d,p,e,p,8d,p,c,p,8b5,p,a5,p,8b5,p,2a5,8p,a,p,8g,p,a,p,8g,p,e,p,d,p,c,p,a5,p,2c,8p,a,p,8g,p,a,p,8g,p,e,p,8d,p,c,p,4e,2p,a,p,8g,p,a,p,8g,p,e,p,8d,p,c,p,4d,2p,e,p,8d,p,e,p,8d,p,c,p,8b5,p,a5,p,8b5";
//char *song = "Barbiegirl:d=4,o=5,b=125:8g#,8e,8g#,8c#6,a,p,8f#,8d#,8f#,8b,g#,8f#,8e,p,8e,8c#,f#,c#,p,8f#,8e,g#,f#";
//char *song = "KahoNaa.:d=4,o=6,b=140:f,32p,8e,d,e,16p,8f,8f,8e,d,e,16p,f,32p,8e,d,e,8e,8g,f,8e,2d,p,8b5,b5,c,d.,8b5,c.,8b5,a.5,8b5,b5,c,d,e,2c.";
//char *song = "ItsMyLif:d=4,o=5,b=125:d#,g,2g.,8d#,d#,d,c,a#.4,p,8p,8a#4,8g,8g,8g,8g,a#,d#,d#,2g,p,8d#,8d#,8d#,8d#,d#,8d,c.,8a#4,2a.4,2p,d#,g,2g.,8c,8d#,8d#,8d#,8d#,d#,d,c,2a#4,8p,8a#4,8g,8g,8g,8g,a#,g#,g,8f,d#.,p,8d#,8d#,8d#,8d#,d#,8d,c.,8a#4,2a#.4,p,d#,p,d,p,c";
//char *song = "MyHeartW:d=16,o=5,b=100:2d6,2e6,4a,2a6,4g6,8f#6,2e6,4f#6,4g6,2f#6,4e6,4d6,4c#6,2d6,4c#6,1b,1a,1d6,2e6,4a,2a6,4g6,8f#6,2e6,4f#6,4g6,2f#6,4e6,4d6,4c#6,2d6,4c#6,4c#6,2d6,4e6,2f#6,2e6,1d6";
//char *song = "JingleBe:d=8,o=6,b=125:g5,e,d,c,2g5,g5,e,d,c,2a5,a5,f,e,d,b5,g5,b5,d,g.,16g,f,d,2e,g5,e,d,c,2g5,16f#5,g5,e,d,c,2a5,a5,f,e,d,g,16g,16f#,16g,16f#,16g,16g#,a.,16g,e,d,4c,4g,e,e,e.,16d#,e,e,e.,16d#,e,g,c.,16d,2e,f,f,f.,16f,f,e,e,16e,16e,e,d,d,e,2d";
//char *song = "DragonDr:d=4,o=5,b=100:8g,8g,16p,8f,16p,16g,16f,a#,16p,8g,8g,16p,8f,16p,8g,p,8p,8g,8g,16p,8f,16p,16g,16f,16g,a#,16p,8g,8g,16p,8f,16p,8g";
//char *song = "Dragonba:d=4,o=6,b=56:16f7,16f7,16d#7,32c7,4f7,32f7,32f7,16f7,16d#7,32c7,4f7,32a#6,32a#6,32a#6,32a#6,16a#6,16g#6,32a#6,32a#6,32a#6,32a#6,16a#6,16g#6,2c7,16c7,16d#7,8f7,8f7,8f7,16d#7,16c7,16d#7,16c7,16d#7,32d#7,8f.7,16c7,16d#7,4f7,16g#7,16g7,16f7,8d#.7,16g#7,16g7,8f7,8d#7,2f7";
//char *song = "Friends1:d=8,o=5,b=90:b,16b,16a,16g,f,f,16g,a,4g,b,16b,16a,16g,f,f,16g,a,4g,4,6d,g,a,c6,b,a,g.,16g,d,g,a,2a,16d,g,a,c6,b,a,g.,16c6,b,a,g,2d6,16c6,c6,c6,c6,b,a,g.,16a,b,4b,16g,16a,16b,16c6,c6,c6,c6,c6,b,a,g,g.,16d,16g,16a,b,4a,4g,d,6,c6,4b,16a,g,b.,a";
//char *song = "MissionI:d=4,o=5,b=112:8d#.,8d#.,8d#.,8d#.,8f#,16g#,16f#,8d#.,8d#.,8d#.,8d#,16d#,8c#,8d,8d#.,8d#.,8d#.,8d#.,8f#,16g#,16f#,8d#.,8d#.,8d#.,8d#,16d#,8c#,8d,8d#,16p,8d#,16p,8d#,16p,8d#,16p,16f#,16p,16g#,16p,8d#,16p,8d#,16p,8d#,16p,8d#,16p,16c#,16p,16d,16p,16d#,16p,16c#,16d#,16p,16c#,16d#,16p,16c#,16d#,16p,16f#,16p,16g#,16f#,16d#,16p,16c#,16d#,16p,16c#,16d#,16p,16c#,16d#,16p,8c#,8d,16a#,16g,2d#,32p,16a#,16g,2d,32p,16a#,16g,2c#,16p,16a#,16c";
//char *song = "InTheEnd:d=4,o=6,b=200:d.5,32p,a.5,32p,a.5,32p,f.5,32p,e.5,32p,e.5,32p,e.5,32p,e.5,32p,8e.5,8f.5,d.5,32p,a.5,32p,a.5,32p,f.5,32p,e.5,32p,e.5,32p,e.5,32p,8e.5,8f.5,d.5,32p,a.5,32p,a.5,32p,f.5,32p,e.5,32p,e.5,32p,e.5,32p,8e.5,8f.5,d.5";
//char *song = "Aerials:d=4,o=5,b=90:8d#.,8d.,2c,8p,8f.,8d#.,2d,8p,8d#.,8f.,8g.,8g#.,8g,8f,8d#.,8d.,2c,8p,8d#.,8d.,2c,8p,8f.,8d#.,2d,8p,8d#.,8f.,8g.,8g#.,8g,8f,8d#.,8d.,2c";
//char *song = "Phantom:d=4,o=5,b=140:c,f,c,d#.,8c#,2c#,a#4,d#,8a#4,2c,c,f,c,d#.,8c#,2c#,a#4,d#.,8a#4,2c,p,c,f,g#,c.6,8a#,2a#,a#,d#.6,8a#,2c6,p,c6,2f.6,8d#6,8c#6,8c6,8a#,8g#,8g,8f,2e,c#,c#.,8c,2c";
char *song = "Titanic:d=8,o=6,b=125:e,f#,2g#,16f#,16g#,16f#,e,f#,2b,32c#7,32b,a,g#,4e,2c#,2b5,d#,f#,f#,2g#,16a,16g#,16f#,16e,4f#,2b,g#,b,2c#7,2b,2f#";
//char *song = "";
//char *song = "";
//char *song = "";


void setup(void) {
  Serial.begin(9600);
}
#define isdigit(n) (n >= '0' && n <= '9')
void play_rtttl(char *p)
{
  int default_dur = 4;
  int default_oct = 6;
  int bpm = 63;
  int num;
  int wholenote;
  int duration;
  int note;
  int scale;

  while (*p != ':') p++;  p++;    // ignore name // skip ':'

  // get default duration
  if (*p == 'd') {
    p++; p++;              // skip "d="
    num = 0;
    while (isdigit(*p)) {
      num = (num * 10) + (*p++ - '0');
    }
    if (num > 0) default_dur = num;
    p++;                   // skip comma
  }

  // get default octave
  if (*p == 'o')
  {
    p++; p++;              // skip "o="
    num = *p++ - '0';
    if (num >= 3 && num <= 7) default_oct = num;
    p++;                   // skip comma
  }

  // get BPM
  if (*p == 'b') {
    p++; p++;              // skip "b="
    num = 0;
    while (isdigit(*p)) {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;                   // skip colon
  }


  // BPM usually expresses the number of quarter notes per minute
  wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)

  // note loop
  while (*p)
  {
    // first, get note duration, if available
    num = 0;
    while (isdigit(*p)) {
      num = (num * 10) + (*p++ - '0');
    }

    if (num) duration = wholenote / num;
    else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

    // now get the note
    note = 0;

    switch (*p)
    {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    p++;
    // now, get optional '#' sharp
    if (*p == '#') {
      note++;
      p++;
    }

    // now, get optional '.' dotted note
    if (*p == '.') {
      duration += duration / 2;
      p++;
    }

    // now, get scale/octave
    if (isdigit(*p)) {
      scale = *p - '0';
      p++;
    }
    else scale = default_oct;
    if (*p == ',') p++;       // skip comma for next note (or we may be at the end)
    if (note) {
      tone(tonePin, notes[(scale - 4) * 12 + note]);  //octave 4,5,6,7 allowed
      delay(duration);
      noTone(tonePin);
    }
    else delay(duration);
  }
}


void loop(void)
{
  play_rtttl(song);
  delay(10);
  while(1);
}
