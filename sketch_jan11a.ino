#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
SoftwareSerial BTserial(10, 9);
void setup() {
  BTserial.begin(9600);
  lcd.begin(16, 2);
}
void loop() {
int f=0;
  int v=0;
  float vv;

  while(1){   
  v=analogRead(A0);
  vv=2*v*(5.0/1024.0);
  lcd.setCursor(0,0);
  lcd.print("V: ");
  if(vv>1.4){
    lcd.print(vv);
      f++;
      break;
    }
    else lcd.print("?");   
 }
  int a=0;
  float aa;
 while(1){
  a=analogRead(A1);
  aa=a*(5.0/1024.0)-2.5;
  aa*=10;
  lcd.setCursor(8,0);
  lcd.print("A: ");
  if(aa>.9){
    lcd.print(aa);
      f++; break;    }
      else lcd.print("?");
 
  }

  if(f==2){
    lcd.setCursor(0,1);
    lcd.print("P: ");
  lcd.print(vv*aa);
  lcd.setCursor(8,1);
    lcd.print("E: ");
  lcd.print(vv*(millis()/1000));
  }
  BTserial.print(vv); 
BTserial.print("V ,");
BTserial.print(aa);
BTserial.print("A ,");
BTserial.print(vv*aa);
BTserial.print("W ,");
BTserial.print(vv*(millis()/1000));
BTserial.print("WH ;");
delay(10000);
lcd.clear();
  delay(1000);
}

  
