#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
SoftwareSerial mySerial(9,10); //(Rx,Tx)
int pump = 13;
int buzz = 11;
int res = 0;
int sms_count = 0;
unsigned long previous_time = 0; //In ms
const long interval = 30000; //In ms

void setup()
{
  pinMode(buzz, OUTPUT);
  pinMode(pump, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  res = Serial.read();
  if (res == 'p' ) // Fire detected
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" Fire Detected ");
    SetAlert();
    digitalWrite(buzz,HIGH);
    digitalWrite(pump, HIGH);
    delay(800);
  }
  if (res == 's' ) //No fire condition
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Capturing Video...");
    digitalWrite(buzz, LOW);
    unsigned long current_time = millis();
    if ((unsigned long)(current_time - previous_time) >= interval)
    {
      digitalWrite(pump, LOW);
      previous_time = current_time;
    }
    sms_count=0;
    delay(5);
  }
}

void SetAlert()
{
  while (sms_count < 3) //Number of SMS Alerts to be sent
  {
    SendTextMessage(); // Function to send AT Commands to GSM module
  }
  lcd.setCursor(0, 1);
  lcd.print("Fire Alert! SMS Sent!");
}

void SendTextMessage()
{
  mySerial.println("AT+CMGF=1");    //To send SMS in Text Mode
  delay(2000);
  mySerial.println("AT+CMGS=\"+9197909*****\"\r"); // change to the phone number you using
  delay(2000);
  mySerial.println("Fire in the ROOM!");//the content of the message
  delay(200);
  mySerial.println((char)26);//the stopping character
  delay(5000);
  mySerial.println("AT+CMGS=\"+919847xxxxxx\"\r"); // change to the phone number you using
  delay(2000);
  mySerial.println("Fire in NEW ROOM!");//the content of the message
  delay(200);
  mySerial.println((char)26);//the message stopping character
  delay(5000);
  sms_count++;
}
