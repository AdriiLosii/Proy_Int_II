int dist;
int strength;
int chequeo;
int i;
int uart[9];
const int HEADER=0x59;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println ("empiezo");
  Serial.println (" ");
  if (Serial1.available()) {
    if (Serial1.read()==HEADER) {
      uart[0]=HEADER;
      if (Serial1.read()==HEADER) {
        uart[1]=HEADER;
        for (i=2;i<9;i++) {
          uart[i]=Serial1.read();
        }

        chequeo=uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6]+uart[7];
        if(uart[8]==(chequeo&0xff)) {
          dist=uart[2]+uart[3]*256;//calculate distance value
          strength=uart[4]+uart[5]*256;//calculate signal strength value
          Serial.print("dist = ");
          Serial.print(dist);//output measure distance value of LiDAR
          Serial.print('\t');
          Serial.print("strength = ");
          Serial.print(strength);//output signal strength value
          //Serial.println("***************");
        }
      }
    }
  }

}