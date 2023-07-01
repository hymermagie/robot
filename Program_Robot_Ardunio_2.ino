//Senzor ULTRASONIC
#define trigPin 7
#define echoPin 6


 int buzzer = 11;

//A
int motor1pin1 = 2;
int motor1pin2 = 3;
//B
int motor2pin1 = 4;
int motor2pin2 = 5;


int pinTuratieA=9;
int pinTuratieB=10;


void setup() {
 
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(buzzer, OUTPUT); 
  pinMode(pinTuratieA, OUTPUT); 
  pinMode(pinTuratieB, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
     digitalWrite(buzzer,HIGH);
     Serial.begin(9600);










stanga();
delay(1000);
stopm();
dreapta();
delay(1000);
stopm();
inainte();
delay(1000);
stopm();
inapoi();
delay(1000);
stopm();
  
}



void loop()

{  int distance;
  
   
   distance=senzor_ULTRASONIC();
    if(distance<50)
    {stopm();
      digitalWrite(buzzer,LOW);
      delay(500);
      digitalWrite(buzzer,HIGH);
      delay(700);
     dreapta();
     delay(350);
     stopm();}
     else
       inainte();
       delay(500);


int x=Serial.read();

if(Serial.read()=='1')  //cand bluetooth da comanda 1, masina se misca in fata
{  distance=senzor_ULTRASONIC();
    if(distance>20)
      {inainte();
       delay(1000);
       stopm();}
       else
       {stopm();
        Serial.print("Exista obiect in fata, introduceti alta comanda");}}


if(Serial.read()=='2')  //cand bluetooth da comanda 2, masina se misca in spate
{  inapoi();
   delay(1000);
   stopm();
}

if(Serial.read()=='3')  //cand bluetooth da comanda 3, masina se misca la stanga
{  stanga();
   delay(1000);
   stopm();
    distance=senzor_ULTRASONIC();
    if(distance<20)
       Serial.print("Exista obiect in fata, introduceti alta comanda");}

if(Serial.read()=='4')  //cand bluetooth da comanda 4, masina se misca la dreapta
{  dreapta();
   delay(1000);
   stopm();
    distance=senzor_ULTRASONIC();
    if(distance<20)
       Serial.print("Exista obiect in fata, introduceti alta comanda");}   




  if(Serial.read()=='5')  //cand bluetooth da comanda 5, se opreste
    stopm();


if(Serial.read()=='6')  //mod automat
{  distance=senzor_ULTRASONIC();
   if(distance<20)
    {stopm();
    dreapta();
     delay(1000);
     stopm();}
     else
       inainte();}



 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
}
 

int senzor_ULTRASONIC()
{long durata,distanta;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 durata = pulseIn(echoPin, HIGH);
 distanta = (durata / 2) / 29.1;
 return distanta;}


 void inainte()
{digitalWrite(motor1pin1, LOW);
 digitalWrite(motor1pin2, HIGH);
 analogWrite(pinTuratieA, 180);
 digitalWrite(motor2pin1, HIGH);
 digitalWrite(motor2pin2, LOW);
 analogWrite(pinTuratieB, 180);}
            
           
void stopm()
{analogWrite(pinTuratieA, 0);
 analogWrite(pinTuratieB, 0);
 digitalWrite(motor2pin1, LOW);
 digitalWrite(motor2pin2, LOW);
 digitalWrite(motor1pin1, LOW);
 digitalWrite(motor1pin2, LOW);
 }


void inapoi()
{digitalWrite(motor1pin1, HIGH);
 digitalWrite(motor1pin2, LOW);
 analogWrite(pinTuratieB, 180);
 digitalWrite(motor2pin1, LOW);
 digitalWrite(motor2pin2, HIGH);
 analogWrite(pinTuratieA, 180);}


void dreapta()
{digitalWrite(motor1pin1, LOW);
 digitalWrite(motor1pin2, HIGH);
 analogWrite(pinTuratieA, 180);}


void stanga()
{digitalWrite(motor2pin1, HIGH);
 digitalWrite(motor2pin2, LOW);
 analogWrite(pinTuratieB, 180);}
