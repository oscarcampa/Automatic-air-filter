# Automatic-air-filter
Code combination of components for autonomous air filter

%%%%%% CODE FOR VOLTAGE SENSOR ! %%%%%%%%%%%%% 
% TWO TYPE OF VOLTAGE SENSOR CODE 
% FOR OP AMP VOLTAGE SENSOR 
// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

% CODE FOR VOLTAGE REGULAR SENSOR 
% void setup () {
  // put your setup code here to run once: 
  Serial.begin (9600) ; 
}
  void loop() {

    // put your main code here, to run repeatidly 
    int adc = analogRead(A0) ; 

    Serial.println(adc) ; 
    
  }
  %%%%%%%% CODE FOR CURRENT SENSOR %%%%%%%%%
  void setup () {
  // put your setup code here to run once: 
  Serial.begin (9600) ; 
}
  void loop() {

    // put your main code here, to run repeatidly 
    int adc = analogRead(A0) ; 

    Serial.println(adc) ; 
    
  }
  
%%%%%%%%% CODE FOR TEMPERATURE SENSOR %%%%%%%%%%%%%
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  baselineTemp = 40;
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
   fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");
  
   if (celsius < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp && celsius < baselineTemp + 10) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp + 10 && celsius < baselineTemp + 20) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp + 20 && celsius < baselineTemp + 30) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  if (celsius >= baselineTemp + 30) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1000); 
}


%%%%%%%% END OF CODE FOR TEMP VOLT AND CURRENT %%%%%%%%%%
