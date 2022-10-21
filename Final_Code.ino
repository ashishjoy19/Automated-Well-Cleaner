#include <Stepper.h>
#define steps 100                           //Steps per revolution is set
  
                           //cutter
#define in1 6
#define in2 7

#define jet 4                             //jet

Stepper stepper(steps, 8, 9, 10, 11);       //stepper is the name
void setup() {
  
  
  //define the coil pins of the stepper motor
 
  stepper.setSpeed(50);                       //stepper speed is set

//For cutter
 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
 
 // digitalWrite(in1, LOW);
 // digitalWrite(in2, HIGH);

  
///For water jet
pinMode(jet, OUTPUT);
//pinMode(in1, OUTPUT);
//pinMode(in2, OUTPUT);
//digitalWrite(in1, LOW);
//digitalWrite(in2, HIGH);
///  
  Serial.begin(9600);
  
//digitalWrite(in1, LOW);
 // digitalWrite(in2, HIGH);
}

void loop() 
{
  Serial.println("Enter the action: ");
  while(Serial.available()==0)
  {
      
  }
  
  int action = Serial.parseInt();
  int step_size = 50; 
  Serial.print(action);
  
  if(action==1)                               //action 1 = Stepper Motor Up
  {
    
    stepper.step(step_size);
    
  }
  else if(action==2)                          //action 2 = Stepper Motor Down
  {
    stepper.step(-step_size);
  }
  if(action==3)                                //Action 3 = Cutter ON
  {
   // analogWrite(enA_cut, 220);
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  Serial.println("Cutter is ON");
  }
  else if(action==30)
  {
    digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  Serial.println(" Cutter is OFF");
  }
  else if(action=4)
  {
    digitalWrite(jet, HIGH);                  //Action 4 = Jet ON
    //digitalWrite(ena_jet,HIGH);
  }
  else if(action==5)
  {
    digitalWrite(jet,LOW);
  }
}
