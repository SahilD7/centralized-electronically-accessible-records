#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);     
LiquidCrystal_I2C lcd(0X3F, 16, 2);
SoftwareSerial leg(0, 1);

 void printVolts()
{
  int sensorValue = analogRead(A0); //read the A0 pin value
  int voltage = ((sensorValue * (5.00 / 1023.00) * 2)/10)*100 ; //convert the value to a true voltage & battery percentage
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Scanner Ready");
  lcd.setCursor(0,1);
  lcd.print("Battery : ");
  lcd.print(voltage); //print the voltage to LCD
  lcd.print(" % ");
  if (voltage < 20) //set the voltage considered low battery here
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Scanner Ready");
    lcd.setCursor(0,1);
    lcd.print("Battery Low");
  }
}

void setup() 
{
  Serial.begin(9600);
  leg.begin(9600);
  SPI.begin();     
  mfrc522.PCD_Init();  
  lcd.backlight(); 
  lcd.clear();
  lcd.init();
  lcd.setCursor(0,0);
  lcd.print("Scanner Ready");
  //printVolts();

}
void loop() 
{
  printVolts();

  if (leg.available()) 
   Serial.write(leg.read()); 
 
 if (Serial.available()) 
   leg.write(Serial.read());

  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.print("Scanning...");
  
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    lcd.init();
    lcd.setCursor(0, 1);
     //lcd.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     //lcd.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
     
  }

lcd.begin(16, 2);
 content.toUpperCase();
  if (content.substring(1) == "49 11 C4 99") //Plz change to your cards UID
  {
   lcd.setCursor(0,0);
   lcd.print("ID : ");
   lcd.print(content.substring(1));
   Serial.println(content.substring(1));
   lcd.setCursor(0,1);
   lcd.print("Authorized");
    delay(4000);
   lcd.clear();
    setup();
  }

 else if (content.substring(1) == "E2 5A EF 60"){
  lcd.setCursor(0, 0);
  lcd.print("ID : ");
  lcd.print(content.substring(1));
  Serial.println(content.substring(1));
  lcd.setCursor(0,1);
    lcd.print("Authorized");
    delay(4000);
    lcd.clear();
      setup();
 }
 
 else if (content.substring(1) == "9D 3D 43 5B"){
  lcd.setCursor(0, 0);
  lcd.print("ID : ");
  lcd.print(content.substring(1));
  Serial.println(content.substring(1));
  lcd.setCursor(0,1);
    lcd.print("Authorized");
    delay(4000);
    lcd.clear();
      setup();
 }
 else   {
  lcd.setCursor(0, 0);
  lcd.print("ID : ");
  lcd.print(content.substring(1));
  Serial.println(content.substring(1));
  lcd.setCursor(0,1);
  lcd.print("Please Authorize the Card");
//  scroll();
  delay(4000);
    lcd.clear();
      setup();
      }
} 
