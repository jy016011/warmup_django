int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT); //적외선센서
  Serial.begin(9600);
  pinMode(2, OUTPUT); //초음파센서 Trig핀
  pinMode(3, INPUT); //초음파센서 Echo핀
}

void loop() {
  long duration, cm;
  digitalWrite(2, HIGH); //초음파 센서에 Trig신호 입력
  delayMicroseconds(10); //10us 정도 유지
  digitalWrite(2, LOW); //Tirg 신호 off

  duration = pulseIn(3, HIGH); //Echo pin: HIGH->LOW 간격을 측정
  cm = microsecondsToCentimeters(duration); //거리(cm)로 변환

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  val = digitalRead(7); //적외선 센서
  Serial.println(val);
  delay(1000);
  
}
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
} 

  

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
} 
