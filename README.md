
## Hardware
 Component | Module / Model | Purpose |
|---|---|---|
| Raspberry Pi 5 | Raspberry Pi 5 | Runs sensor-reading scripts, processes signals, controls feedback outputs, etc |
| Heartbeat sensor | KY-039 | Detects pulse changes in light transmission via fingertip or any tip |
| Temperature and humidity sensor | KY-015 / DHT11 | Measures temperature and humidity |
| Digital temperature sensor | KY-001 / DS18B20 | Measures temperature using digital 1-Wire interface |
| 3-color RGB LED | KY-016 | Color-based status |
| Passive buzzer | KY-006 | Pulse tones |
| ADC module | ADS1115 | Converts KY-039 analog signal into digital | 

## Initial Fritzing breadboard diagram for the prototype:

![draft_first_diagram](diagrams/sketch_bb.png)

```
WIRING:

KY-039 SIG → ADS1115 A0
ADS1115 (Analog-to-Digital) SDA → GPIO2 / physical pin 3
ADS1115 SCL → GPIO3 / physical pin 5

KY-015 S → GPIO17 / physical pin 11
KY-001 S → GPIO4 / physical pin 7
KY-006 S → GPIO18 / physical pin 12

KY-016 R → GPIO22 / physical pin 15
KY-016 G → GPIO23 / physical pin 16
KY-016 B → GPIO24 / physical pin 18
KY-016 - → GND
```