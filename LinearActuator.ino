#define Mplus_small 11
#define Mneg_small 10
#define Mplus_ring 9
#define Mneg_ring 8
#define Mplus_middle 7
#define Mneg_middle 6
#define Mplus_index 5
#define Mneg_index 4
#define Mplus_thumb 3
#define Mneg_thumb 2

#define Pot_small A0
#define Pot_ring A1
#define Pot_middle A2
#define Pot_index A3
#define Pot_thumb A4

int pos_small = 0;
int pos_ring = 0;
int pos_middle = 0;
int pos_index = 0;
int pos_thumb = 0;

void setup() {

  pinMode(Mplus_small, OUTPUT); // All M declared outputs
  pinMode(Mneg_small, OUTPUT);
  pinMode(Mplus_ring, OUTPUT);
  pinMode(Mneg_ring, OUTPUT);
  pinMode(Mplus_middle, OUTPUT);
  pinMode(Mneg_middle, OUTPUT);
  pinMode(Mplus_index, OUTPUT);
  pinMode(Mneg_index, OUTPUT);
  pinMode(Mplus_thumb, OUTPUT);
  pinMode(Mneg_thumb, OUTPUT);

  pinMode(Pot_small, INPUT); // All P declared inputs
  pinMode(Pot_ring, INPUT);
  pinMode(Pot_middle, INPUT);
  pinMode(Pot_index, INPUT);
  pinMode(Pot_thumb, INPUT);

  /*Final Implementation in Python GUI */
  Serial.begin(9600); //added here for testing and debugging
  Serial.println("Type gesture number:");
  Serial.println("1 ==> RELAX ");
  Serial.println("2 ==> FIST ");
  Serial.println("3 ==> POINT ");
  Serial.println("4 ==> PEACE ");
  Serial.println("5 ==> GRIP ");

}
void loop() {
  if (Serial.available()) {
    int gesture = Serial.read();
    switch (gesture) {

      case '1':
        relax();
        delay(500);
        break;

      case '2':
        fist();
        delay(500);
        break;

      case '3':
        point();
        delay(500);
        break;

      case '4':
        peace();
        delay(500);
        break;

      case '5':
        grip();
        delay(500);
        break;

      default:
        Serial.println("Only one of the valid options please");
        break;

    }
  }
}
/*
  int settingMinMax(){
    int smallMin,smallMax,ringMin,ringMax,middleMin,middleMax,indexMin,indexMax,thumbMin,thumbMax;

  }

  int checkPosition(){

    int positions[5] = 0;
    pos_small = analogRead(Pot_small);
    pos_ring = analogRead(Pot_ring);
    pos_middle = analogRead(Pot_middle);
    pos_index = analogRead(Pot_index);
    pos_thumb = analogRead(Pot_thumb);

    positions[0] = map(pos_small,smallMin,smallMax,90,0);
    positions[1] = map(pos_ring,ringMin,ringMax,90,0);
    positions[2] = map(pos_middle,middlelMin,middleMax,90,0);
    positions[3] = map(pos_index,indexMin,indexMax,90,0);
    positions[4] = map(pos_thumb,thumbMin,thumbMax,90,0);

    return positions;

    Serial.println(pos_small);
    Serial.println(pos_ring);
    Serial.println(pos_middle);
    Serial.println(pos_index);
    Serial.println(pos_thumb);

    }
*/

void relax() {
  //    checkPosition();

  digitalWrite(Mplus_small, HIGH);
  digitalWrite(Mneg_small, LOW);
  digitalWrite(Mplus_ring, HIGH);
  digitalWrite(Mneg_ring, LOW);
  digitalWrite(Mplus_middle, HIGH);
  digitalWrite(Mneg_middle, LOW);
  digitalWrite(Mplus_index, HIGH);
  digitalWrite(Mneg_index, LOW);
  digitalWrite(Mplus_thumb, HIGH);
  digitalWrite(Mneg_thumb, LOW);

  Serial.println("RELAX");
  delay(3000);

  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, LOW);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, LOW);
  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, LOW);
  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, LOW);
  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, LOW);

}

void fist() {

  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, HIGH);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, HIGH);
  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, HIGH);
  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, HIGH);
  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, HIGH);

  Serial.println("FIST");
  delay(4000);

  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, LOW);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, LOW);
  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, LOW);
  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, LOW);
  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, LOW);

}

void point() {
  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, HIGH);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, HIGH);
  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, HIGH);

  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, LOW);

  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, HIGH);

  Serial.println("POINT");
  delay(3500);

  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, LOW);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, LOW);
  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, LOW);
  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, LOW);
  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, LOW);

}

void peace() {
  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, HIGH);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, HIGH);

  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, LOW);
  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, LOW);

  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, HIGH);

  Serial.println("PEACE");
  delay(3500);

  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, LOW);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, LOW);
  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, LOW);
  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, LOW);
  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, LOW);

}

void grip() {

  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, HIGH);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, HIGH);
  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, HIGH);
  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, HIGH);
  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, HIGH);

  Serial.println("GRIP");
  delay(3500);

  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, LOW);
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, LOW);
  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, LOW);
  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, LOW);
  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, LOW);

}

