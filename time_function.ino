long previous_time_seconds_millis = 0;
int i = 0;
int repeat= 0;
int min;
int sec;

void setup() {
  Serial.begin(9600);
  }

int time(int minutes , int seconds)
{ 
   
   if(i == 0)
   {
    i = 1;
    min = minutes;
    sec = seconds;
   }
    long current_time_millis = millis();
     if(min >= 0 && sec >= 0)
       {
       if(current_time_millis - previous_time_seconds_millis == 1000)
           {
              previous_time_seconds_millis = current_time_millis;
              sec -=1 ;
           
                  if(sec == -1)
                      {
                         sec = 59;
                         min -= 1;
                       }
                   if(min>=0)
                   {
                       if(sec >= 10)
                           {
                              Serial.print("time left "); Serial.print(min); Serial.print(":"); Serial.println(sec);
                           }
                        else if(sec < 10)
                           {
                              Serial.print("time left "); Serial.print(min); Serial.print(":"); Serial.print("0"); Serial.println(sec);
                           }
                   }

                   else if(min == -1)
                   {
                        Serial.print("time over");
                   }
              }
       } 

}

void loop() 
{
 
    time(0,5); // time(enter start minutes , enter start seconds);


   
}
