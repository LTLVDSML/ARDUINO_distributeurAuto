//projet distributeur bouffe

#define in1 8
#define in2 9
#define in3 10
#define in4 11

int intervalle = 2; //ms
int compteur; // compte le temps entre chaque actionnement
int delai= 10; //intervalle entre 2 actionnement
int compteurAction; // compte le temps durant l'action de rotation
int tempsRotation = 3000; // temps de rotation lors de l'activation

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

  compteur++;
  delay(1000);
  Serial.print(compteur);

  if(compteur == delai)
  {
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
  compteur = 0;
  compteurAction = 0;
  }
}
