extern void leds_update();
extern void led_color(unsigned int num, unsigned int rgb);
extern void led_color(unsigned int num, unsigned char red, unsigned char green, unsigned char blue);
extern void led_channel(unsigned int num, unsigned int val);
#define OFF    0x000000
#define RED    0xFF0000
#define GREEN  0x00FF00
#define BLUE   0x0000FF
#define YELLOW 0xFFFF00
#define PINK   0xFF1088
#define ORANGE 0xE05800
#define WHITE  0xFFFFFF


void setup() {
  Serial1.begin(250000);
  usbMIDI.setHandleControlChange(OnControlChange);
}

elapsedMillis timeout;

void OnControlChange(byte channel, byte control, byte value) {
  led_channel(control, value*2);
//  Serial.println("got midi");
//  Serial.println(value);
}

void loop() {
  leds_update();
  usbMIDI.read(); // USB MIDI receive
}





