import serial
import time

PORTS = ['/dev/ttyACM0', '/dev/ttyACM1']
BAUD = 9600
BOUNDARY_COUNT = 4
TIMEOUT = 3

def establish_connection():
    print "Finding ports"
    # Connects to the Arduino
    usb = None
    # Finding which port the arduino is connected to
    for port in PORTS:
        print "Attempting port {}".format(port)
        usb = serial.Serial(port=port, baudrate=BAUD, timeout=TIMEOUT)
        time.sleep(2)
        if usb.readline():
            print "Attaching to device at '{}'...".format(port)
            break
        else:
            usb = None
    return usb

def get_boundaries(usb):
    # Sending acknowledgement to the Arduino
    usb.write('ack') # Value sent is unimportant
    # Capturing servo boundaries
    boundaries = []
    temp = usb.readline()
    while temp:
        temp = usb.readline()
        if ">" in temp:
            boundaries.append(temp)
    print "Connection established"
    return boundaries

if __name__ == '__main__':
    usb = establish_connection()
    boundaries = get_boundaries(usb)
    print boundaries
