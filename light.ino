//declare the light sensor equal to its pins to we can collect the data from it
//ex: int lightValue = A0;

//declare a LED in case we need some test.
int led = D7;

//in this situation, because i dont have any light sensor so i will declare a varieble to simulate the analog light value.
float si_value;
void setup()
{   
    //setup the simulating value to simulate the light analog value which is normally 10
    si_value = 10; 
    
    //if i have a decent light sensor, i will setup the light sensor as INPUT.
    //pinMode(lightValue, INPUT);
    pinMode(led, OUTPUT);
}
void loop(){
    //this is the simulation code
    if (si_value < 100)
    {
        si_value = si_value +1;
        delay(1000);
        
        if (si_value > 30){
            digitalWrite(led, HIGH);
            Particle.publish("light", "on");
            
        } else 
        {
            Particle.publish("light", "off");
            }
        }
        
    
    
    
    else 
    {
        while (si_value >10){
            si_value = si_value -1;
            delay(1000);
            if (si_value > 30){
            digitalWrite(led, HIGH);
            Particle.publish("light", "on");
            }
            else {
                Particle.publish("light", "off");
            }
        }   
     
    }
    
    
    //the real code would be
   
    // 
    //{ if (analogRead(lightValue)  >= 30)
        //Particle.publish("light", "on");
        
        //while (analogRead(lightValue) > 30){}
        
        
    //} else {
    //  //Particle.publish("light", "off");}
    //
}
   