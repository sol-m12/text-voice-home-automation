//voice/text controlled home automation
//Department of Electronics and Communication Enginnering
// Micro Electronics And Circuits
///SEC -3
//YEAR-2016
//   Name                          ID
//1, Solomon Mehabaw ........     UGR/25389/14

String voice;
const int relay_1=2;//Connect relay1 to pin 2( pin 2 of arduino to relay 1 using #define relay_1 2)
const int relay_2=3;//Connect relay2 to pin 3( pin 3 of arduino to relay 2 using #define relay_2 3)
const int relay_3=4;//Connect relay3 to pin 4( pin 4 of arduino to relay 3 using #define relay_3 4)
void setup() 
{
   // put your setup code here, to run once:
   Serial.begin(9600);//Set rate for communicating with phone
   pinMode(relay_1,OUTPUT);
   pinMode(relay_2,OUTPUT);
   pinMode(relay_3,OUTPUT);
  
}

void loop() 
{
   // put your main code here, to run repeatedly:
   //Check if there is an available byte to read
   while (Serial.available())
       {
         //to make stable
         delay(3);
         char x=Serial.read();
         voice=voice+x;
       }
    if(voice.length()>0)
       {
         Serial.println(voice);
         if(voice=="turn on first light")
          {
             digitalWrite(relay_1,HIGH);
          }
         else if (voice=="turn off first light")
          {
              digitalWrite(relay_1,LOW);
          }
         else if (voice=="turn on second light")
          {
             digitalWrite(relay_2,HIGH);
          }
         else if (voice=="turn off second light")
          {
              digitalWrite(relay_2,LOW);
          }
         else if (voice=="turn on fan")
          {
             digitalWrite(relay_3,HIGH);
          }
  
         else if (voice=="turn off fan")
          {
             digitalWrite(relay_3,LOW);
          }
         else if (voice=="turn on all")
          {
             turn_all();
          }
         else if (voice=="turn off all")
           {  
              turn_off();
           }
  voice="";
  
         }

}

void turn_all()
   {
     digitalWrite(relay_1,HIGH);
     digitalWrite(relay_2,HIGH);
     digitalWrite(relay_3,HIGH);
   }
void turn_off()
   {
      digitalWrite(relay_1,LOW);
      digitalWrite(relay_2,LOW);
      digitalWrite(relay_3,LOW);
   }
