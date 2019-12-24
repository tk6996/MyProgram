import serial.tools.list_ports
def serialSetup(port):
    
    return s
for i in list(serial.tools.list_ports.comports()) :
    if str(i).split(' ',1)[0] == "COM16":
        s = serial.Serial("COM16",115200,serial.EIGHTBITS,serial.PARITY_NONE,serial.STOPBITS_ONE)
        while True :
            print(s.read())
        