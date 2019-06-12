#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pin1=7;
int pin2=8;
int pin3=9;
int pin4=10;
int dt=900;
int stepcount=4;
int rev=0;
int rev2=0;
int i=0;
int c=4;
int stepc=9;
int nstep=0;
int tstep;
int btn1=A0;
int btn2=A1;
int btn3=A2;
int snr1=0;
int snr2=0;
int snr3=0;
float mmv=0;

void setup() {
  // put your setup code here, to run once:
pinMode(pin1,OUTPUT);
pinMode(pin2,OUTPUT);
pinMode(pin3,OUTPUT);
pinMode(pin4,OUTPUT);
Serial.begin(9600);
lcd.begin(16, 2);
lcd.print("UITM P.G 2018!!");
}

//Main code
void loop() {

snr1=analogRead(btn1);
snr2=analogRead(btn3);
snr3=analogRead(btn2);

if (snr1>1000)
  {
    nstep=1;
    rev2=1;
  }

  else if (snr3>1000)
  {
    nstep=-1;
    rev2=1;
  }
  else if(snr2>1000)
  {
   tstep=0;
   rev2=1;  
    lcd.clear();
 lcd.setCursor(0, 0);
lcd.print("step: ");
lcd.print(nstep);
lcd.setCursor(0, 1);
lcd.print("post: ");
mmv=tstep*0.001953;
lcd.print(mmv);
lcd.print("mm");
  }

if (Serial.available() > 0) {
                // read the incoming byte:
                rev = Serial.parseInt();
                nstep=rev*512;//No. of steps per revolution       
                rev2=1;
        }

if(rev2==1){

  if(nstep>0){
    if(c<8)
    {
     stepc++;
     c++;
     }
      else{
        c=1;
        stepc=1;
         }
  nstep--;  
  tstep--;
  }
 

  else if(nstep==0)
  {
      stepc=9;

   i=0;
   c=4;
   rev2=0; 
}

else {
if(c>1)
{
 stepc--;
 c--;
 }
  else{
    c=8;
    stepc=8;
     }
nstep++;
tstep++;  
}

lcd.clear();
lcd.setCursor(0, 0);
lcd.print("step: ");
lcd.print(nstep);
lcd.setCursor(0, 1);
lcd.print("post: ");
mmv=tstep*0.001953;
lcd.print(mmv);
lcd.print("mm");
}

else{
Serial.println("pls insert new value");
Serial.print(snr1);

}

//Condition for stepc
switch(stepc){

case 1:
digitalWrite(pin1,HIGH);
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin4,LOW);
delayMicroseconds(dt);
break;

case 2:
//1100
digitalWrite(pin1,HIGH);
digitalWrite(pin2,HIGH);
digitalWrite(pin3,LOW);
digitalWrite(pin4,LOW);
delayMicroseconds(dt);
break;
case 3:
//0100
digitalWrite(pin1,LOW);
digitalWrite(pin2,HIGH);
digitalWrite(pin3,LOW);
digitalWrite(pin4,LOW);
delayMicroseconds(dt);
break;
case 4:
//0110
digitalWrite(pin1,LOW);
digitalWrite(pin2,HIGH);
digitalWrite(pin3,HIGH);
digitalWrite(pin4,LOW);
delayMicroseconds(dt);
break;
case 5:
//0010
digitalWrite(pin1,LOW);
digitalWrite(pin2,LOW);
digitalWrite(pin3,HIGH);
digitalWrite(pin4,LOW);
delayMicroseconds(dt);
break;
case 6:
//0011
digitalWrite(pin1,LOW);
digitalWrite(pin2,LOW);
digitalWrite(pin3,HIGH);
digitalWrite(pin4,HIGH);
delayMicroseconds(dt);
break;
case 7:
//0001
digitalWrite(pin1,LOW);
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin4,HIGH);
delayMicroseconds(dt);
break;
case 8:
//1001
digitalWrite(pin1,HIGH);
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin4,HIGH);
delayMicroseconds(dt);
break;
case 9:
//1001
digitalWrite(pin1,LOW);
digitalWrite(pin2,LOW);
digitalWrite(pin3,LOW);
digitalWrite(pin4,LOW);
delayMicroseconds(dt);
break;
}
}
