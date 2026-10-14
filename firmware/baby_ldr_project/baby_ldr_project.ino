
const int LDR_PIN = A0;
const int LED_PIN = 13;

unsigned long lastSample = 0;
const unsigned long SAMPLE_INTERVAL = 1000;

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    unsigned long now = millis();

    if (now - lastSample >= SAMPLE_INTERVAL) {
        lastSample = now;

        int adc = analogRead(LDR_PIN);
        bool ledOn = adc < 40;

        digitalWrite(LED_PIN, ledOn ? HIGH : LOW);

        Serial.print("ADC=");
        Serial.print(adc);
        Serial.print(" LED=");
        Serial.println(ledOn ? "ON" : "OFF");
    }
}
