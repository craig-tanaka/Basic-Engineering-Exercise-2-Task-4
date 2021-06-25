#define BAUDRATE 9600
#define BUTTON1_PIN 31

int buttonstate;
int ledLigthingCounter = 1;

void setup()
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  Serial.begin(BAUDRATE);
}

void loop()
{
  // put your main code here, to run repeatedly:
  buttonstate = digitalRead(BUTTON1_PIN);

  if (buttonstate == LOW)
    ledBlink(7, 200);
  else
    digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void ledCounterPrint(int i)
{
  Serial.print("\tPrinting for the ");
  Serial.print(++i);
  Serial.println("th time");
}

void ledBlink(int times, int duration){
  Serial.println("Button Pressed Lighting Led Requested Amount");
  for (int i = 0; i < times; i++)
  {
    ledCounterPrint(i);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(duration);
    digitalWrite(LED_BUILTIN, LOW);
    delay(duration);
  }
}