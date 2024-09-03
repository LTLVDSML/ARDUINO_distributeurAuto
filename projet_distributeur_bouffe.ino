//projet distributeur bouffe

#define in1          8
#define in2          9
#define in3          10
#define in4          11
#define inputLumiere A0

int intervalle      = 2;        // ms 
int delai           = 10;       // intervalle entre 2 actionnements
int compteurAction;             // compte le temps durant l'action de rotation
int tempsRotation   = 1000;     // temps de rotation lors de l'activation
int seuilHaut       = 1000;     // seuil de detection de la lumiere
int seuilBas        = 400;      // seuil de detection de l obscurite   


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(in1, OUTPUT);   //ORANGE
  pinMode(in2, OUTPUT);   //JAUNE
  pinMode(in3, OUTPUT);   //ROSE
  pinMode(in4, OUTPUT);   //BLEU

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  delay(60000);

  int lumiere = analogRead(inputLumiere);

  if(lumiere > seuilHaut)
  {
   rotationNegative(intervalle, tempsRotation, compteurAction);
  }

  if(lumiere < seuilBas)
  {
   rotationPositive(intervalle, tempsRotation, compteurAction);
  }

}


// FUNCTIONS /////////////////////////////////////////////////////////

void rotationNegative(int intervalle, int tempsRotation, int compteurAction){

while(compteurAction < tempsRotation)
  {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);

  delay(intervalle);

  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  delay(intervalle);

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

  delay(intervalle);

  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);

  delay(intervalle);

  compteurAction++;
  Serial.print(compteurAction);
}
}

//////////////////////////////////////////////////

void rotationPositive(int intervalle, int tempsRotation, int compteurAction){

while(compteurAction < tempsRotation)
  {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);

  delay(intervalle);

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

  delay(intervalle);

  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  delay(intervalle);

  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);

  delay(intervalle);

  compteurAction++;
  Serial.print(compteurAction);
}
}
