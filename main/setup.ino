void set_setup()
{
  Serial.begin(9600);
  Wire.begin();
  pinMode(PWMA, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(ECHO, INPUT);    // Define the ultrasonic echo input pin
  pinMode(TRIG, OUTPUT); // Define the ultrasonic trigger input pin
  pinMode(4, INPUT); //Sensor output(additional IR sesnor)
  pinMode(ECHO_2, INPUT);    // Define the ultrasonic echo input pin
  pinMode(TRIG_2, OUTPUT); // Define the ultrasonic trigger input pin
  pinMode(ECHO_3, INPUT);    // Define the ultrasonic echo input pin
  pinMode(TRIG_3, OUTPUT); // Define the ultrasonic trigger input pin
}
