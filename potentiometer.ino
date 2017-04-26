# potentiometer
//controlling an RGB LED with a potentiometer 

const int kPot = A1;
int val = 0;

int redPin = 9;
int greenPin = 11;
int bluePin = 10;
void setup()
{
  Serial.begin(9600);
  pinMode( redPin, OUTPUT );
  pinMode( greenPin, OUTPUT );
  pinMode( bluePin, OUTPUT );
}
 
void loop()
{
  val = analogRead( kPot );
  Serial.println(val);
  if( val < 100 )
  {
    setColor( 255, 0, 0 );
  }
  if( val >= 100 and val <300)
  {
      setColor( 255, 255, 0 );

  }
  if( val > 300 )
  {
    setColor( 0, 255, 0 );
  }
}
void setColor(int red, int green, int blue)
{  
  analogWrite( redPin, 255 - red );
  analogWrite( greenPin, 255 - green );
  analogWrite( bluePin, 255 - blue );
}
