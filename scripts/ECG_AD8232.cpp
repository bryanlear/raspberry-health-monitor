void setup()
{
    Serial.begin(9600);
    pinMode(10, INPUT); // LO+
    pinMode(11, INPUT); // LO-
}

void loop(){
    if ((digitalRead(10) == 1) || (digitalRead(11) == 1)){
        Serial.println(512);
    } else {
        Serial.println(analogRead(A0));
    }
    delay(5);
}