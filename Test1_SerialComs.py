
#This code sends data to the Arduino everytime the user inputs "1"
import serial
import json
import time
import keyboard

ser=serial.Serial('/dev/ttyACM0',115200,timeout=1.0)
#Function to send data

def send_data():
    data={
        "event": "EXCHANGE",
        "tray": "top",
        "mediaAmountInMl":15
        }
    message=json.dumps(data)
    ser.write(message.encode('utf-8'))
    print("Data sent",message)

#Main loop
print("TYpe 1 and press Enter to send data")
while True:
    try:
        user_input=input()
        if user_input=='1':
            send_data()
    except KeyboardInterrupt:
        print("Program exited.")
        break
        
ser.close()
