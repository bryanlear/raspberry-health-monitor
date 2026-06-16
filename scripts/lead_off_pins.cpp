void setup()
{
    Serial.begin(9600);
    pinMode(10, INPUT);
    pinMode(11, INPUT);
}

void loop()
{
    Serial.print("LO+=");
    Serial.print(digitalRead(10));
    Serial.print(" LO-=");
    Serial.print(digitalRead(11));
    Serial.print(" A0=");
    Serial.println(analogRead(A0));
    delay(200);
}