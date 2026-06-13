import time
import board
from adafruit_ads1x15 import ADS1115, AnalogIn, ads1x15

i2c = board.I2C()
ads = ADS1115(i2c, address=0x48)
ads.gain = 1
ads.data_rate = 128

chan = AnalogIn(ads, ads1x15.Pin.A0)

while True:
    try:
        raw = chan.value
        voltage = raw * 4.096 / 32767
        print(f"raw={raw:6d} voltage={voltage:.4f} V")
        time.sleep(0.1)
    except OSError as e:
        print(f"I2C read failed: {e}")
        time.sleep(0.5)
