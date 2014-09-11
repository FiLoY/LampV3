#define LED_PINY 6
#define LED_PINR 10
#define LED_PING 11

String message;


void setup()
{
  pinMode(LED_PINY,OUTPUT);
  pinMode(LED_PINR,OUTPUT);
  pinMode(LED_PING,OUTPUT);

  Serial.begin(9600);
  Serial.println(" HI ");

}

void loop()
{  
  while (Serial.available()) {
    char incomingChar = Serial.read();
  
    if (incomingChar >= '0' && incomingChar <= '9') {
      message += incomingChar;

    } else if (incomingChar == 'y') {
      Serial.println("yellow Lamp");
      analogWrite(LED_PINY, message.toInt());
      message = "";
    } else if (incomingChar == 'r') {
      Serial.println("red Lamp");
      analogWrite(LED_PINR, message.toInt());
      message = "";
    } else if (incomingChar == 'g') {
      Serial.println("green Lamp");
      analogWrite(LED_PING, message.toInt());
      message = "";
    } else {
      Serial.println("Error Lamp"); 
      message = "";
    } 
  }  
}
