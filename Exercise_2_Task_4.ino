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
  {
    Serial.println("Button Pressed Printing Led 5 times");
    for (int i = 0; i < 5; i++)
    {
      ledCounterPrint(i);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(250);
      digitalWrite(LED_BUILTIN, LOW);
      delay(250);
    }
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(100);
}

void ledCounterPrint(int i)
{
  Serial.print("\tPrinting for the ");
  Serial.print(++i);
  Serial.println("th time");
}