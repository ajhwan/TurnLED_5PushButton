const int buttonPin = 2;
const int ledPin = 10;
int ledState = LOW;
bool buttonState = LOW;

int pressed = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  if (digitalRead(buttonPin)== HIGH && buttonState == LOW)
  {
    pressed++;
    buttonState = HIGH;
  }
  else if (digitalRead(buttonPin)== LOW && buttonState == HIGH)
  {
    buttonState = LOW;
  }
  if (pressed == 5)
  {
    digitalWrite(ledPin,HIGH);
  }
}

bool debounceButton(bool state)
{
  bool stateNow = digitalRead(buttonPin);
  if (state != stateNow)
  {
    delay(20);
    stateNow = digitalRead(buttonPin);
  }
  return stateNow;
}
