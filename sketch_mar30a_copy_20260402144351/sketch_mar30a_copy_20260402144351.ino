int trigPin = 12;
int echoPin = 11;
int measureNum = 50;
float avMeas;
int i;
float bucket = 0;

long duracion;
float distancia;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  bucket = 0;

  for (i = 1; i <= measureNum; i = i + 1) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duracion = pulseIn(echoPin, HIGH);
    distancia = duracion * 0.0343 / 2;

    bucket = bucket + distancia;
  }

  avMeas = bucket / measureNum;
  Serial.println(avMeas);

  delay(200);
}