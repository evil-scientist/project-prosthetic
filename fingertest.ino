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
        
  /*Final Implementation in Python GUI */
  Serial.begin(9600); //added here for testing and debugging
  Serial.println("Type Finger number:");
  Serial.println("1 ==> Thumb ");
  Serial.println("2 ==> Index ");
  Serial.println("3 ==> Middle ");
  Serial.println("4 ==> Ring ");
  Serial.println("5 ==> Small ");
  Serial.println("6 ==> All Positions");


}
void loop() {
  if (Serial.available()) {
    int gesture = Serial.read();
    switch (gesture) {

      case '1':
        
        thumb();
        delay(500);       
        break;

      case '2':
        index();
        delay(500);
        break;

      case '3':
        middle();
        delay(500);
        break;

      case '4':
        ring();
        delay(500);
        break;

      case '5':
        small();
        delay(500);
        break;

      case '6':
        positions();
        delay(500);
        break;

      default:
        Serial.println("STOPPED");
        break;

    }
  }
}

void thumb() {
  Serial.println("THUMB");
  
  pos_thumb = analogRead(Pot_thumb);
  Serial.print("Relaxed: ");
  Serial.println(pos_thumb);
      
  while(pos_thumb>300){
  digitalWrite(Mplus_thumb, HIGH);
  digitalWrite(Mneg_thumb, LOW);
  pos_thumb = analogRead(Pot_thumb);
  }
  
  delay(2000);

  pos_thumb = analogRead(Pot_thumb);
  Serial.print("Closed: "); 
  Serial.println(pos_thumb);
  
  while(pos_thumb<800){
  digitalWrite(Mplus_thumb, HIGH);
  digitalWrite(Mneg_thumb, LOW);
  pos_thumb = analogRead(Pot_thumb);
  }

  digitalWrite(Mplus_thumb, LOW);
  digitalWrite(Mneg_thumb, LOW);

  pos_thumb = analogRead(Pot_thumb);
  Serial.print("Relaxed: "); 
  Serial.println(pos_thumb);
  
}

void index() {
  Serial.println("INDEX");
  
  pos_index = analogRead(Pot_index);
  Serial.print("Relaxed: ");
  Serial.println(pos_index);
      
  while(pos_index>300){
  digitalWrite(Mplus_index, HIGH);
  digitalWrite(Mneg_index, LOW);
  pos_index = analogRead(Pot_index);
  }
  
  delay(2000);

  pos_index = analogRead(Pot_index);
  Serial.print("Closed: "); 
  Serial.println(pos_index);
  
  while(pos_index<800){
  digitalWrite(Mplus_index, HIGH);
  digitalWrite(Mneg_index, LOW);
  pos_index = analogRead(Pot_index);
  }

  digitalWrite(Mplus_index, LOW);
  digitalWrite(Mneg_index, LOW);

  pos_index = analogRead(Pot_index);
  Serial.print("Relaxed: "); 
  Serial.println(pos_index);
  
}

void middle() {
  Serial.println("MIDDLE");
  
  pos_middle = analogRead(Pot_middle);
  Serial.print("Relaxed: ");
  Serial.println(pos_middle);
      
  while(pos_middle>300){
  digitalWrite(Mplus_middle, HIGH);
  digitalWrite(Mneg_middle, LOW);
  pos_middle = analogRead(Pot_middle);
  }
  
  delay(2000);

  pos_middle = analogRead(Pot_middle);
  Serial.print("Closed: ");
  Serial.println(pos_middle);
  
  while(pos_middle<800){
  digitalWrite(Mplus_middle, HIGH);
  digitalWrite(Mneg_middle, LOW);
  pos_middle = analogRead(Pot_middle);
  }

  digitalWrite(Mplus_middle, LOW);
  digitalWrite(Mneg_middle, LOW);
  
  pos_middle = analogRead(Pot_middle);
  Serial.print("Relaxed: "); 
  Serial.println(pos_middle);
  
}


void ring() {
  Serial.println("RING");
  
  pos_ring = analogRead(Pot_ring);
  Serial.print("Relaxed: ");
  Serial.println(pos_ring);
      
  while(pos_ring>300){
  digitalWrite(Mplus_ring, HIGH);
  digitalWrite(Mneg_ring, LOW);
  pos_ring = analogRead(Pot_ring);
  }
  
  delay(2000);

  pos_ring = analogRead(Pot_ring);
  Serial.print("Closed: ");
  Serial.println(pos_ring);
  
  while(pos_ring<800){
  digitalWrite(Mplus_ring, HIGH);
  digitalWrite(Mneg_ring, LOW);
  pos_ring = analogRead(Pot_ring);
  }
  digitalWrite(Mplus_ring, LOW);
  digitalWrite(Mneg_ring, LOW);
  
  pos_ring = analogRead(Pot_ring);
  Serial.print("Relaxed: ");
  Serial.println(pos_ring);
  
  
}


void small() {
  Serial.println("SMALL");
  
  pos_small = analogRead(Pot_small);
  Serial.print("Relaxed: "); 
  Serial.println(pos_small);
      
  while(pos_small>300){
  digitalWrite(Mplus_small, HIGH);
  digitalWrite(Mneg_small, LOW);
  pos_small = analogRead(Pot_small);
  }
  
  delay(2000);

  pos_small = analogRead(Pot_small);
  Serial.print("Closed: "); 
  Serial.println(pos_small);
  
  while(pos_small<800){
  digitalWrite(Mplus_small, HIGH);
  digitalWrite(Mneg_small, LOW);
  pos_small = analogRead(Pot_small);
  }
  digitalWrite(Mplus_small, LOW);
  digitalWrite(Mneg_small, LOW);
  
  pos_small = analogRead(Pot_small);
  Serial.print("Relaxed: ");
  Serial.println(pos_small);
  
 
}
void positions(){
    
    pos_small = analogRead(Pot_small);
    pos_ring = analogRead(Pot_ring);
    pos_middle = analogRead(Pot_middle);
    pos_index = analogRead(Pot_index);
    pos_thumb = analogRead(Pot_thumb);
    
    Serial.print("THUMB: ");
    Serial.println(pos_thumb);
    Serial.print("INDEX: ");
    Serial.println(pos_index);
    Serial.print("MIDDLE: ");
    Serial.println(pos_middle);
    Serial.print("RING: ");
    Serial.println(pos_ring);
    Serial.print("SMALL: ");
    Serial.println(pos_small);
    Serial.println();
}
