import serial

# Start serial
ser = serial.Serial(
    port = '/dev/ttyUSB0',
    baudrate = 9600,
    parity = serial.PARITY_NONE,
    stopbits = serial.STOPBITS_ONE,
    bytesize = serial.EIGHTBITS,
)

# Waiting for STM ready init
def wait_ready_init():
    while True:
        # Read data from STM32, non-blocking, every 0.1s
        c = ser.readline().decode('utf-8')
        print(clean_str(c)) if len(c) > 3 else "" # Clear the string

        # Check if alive
        if "STM-Ready" in c:
            ser.flush()
            return
        
# Waiting for STM next move
def wait_ready_next() -> bool:
    while True:
        # Read data from STM32, non-blocking, every 0.1s
        c = ser.readline().decode('utf-8')
        print(clean_str(c)) if len(c) > 3 else "" # Clear the string

        # Check if alive
        if "STM-NextMove" in c:
            ser.flush()
            return True
        elif "STM-Ready" in c:
            ser.flush()
            return True
        elif "STM-Invalid" in c:
            ser.flush()
            return False

def send_move(coordinates: str):
    ser.write(bytearray(coordinates.upper() + ".", 'utf-8'))

def send_game_over():
    ser.write(b"Python-End.")

def clean_str(s: str) -> str:
    return s.replace("STM-Ready\n","").replace("STM-NextMove\n","").replace("STM-Invalid\n","").replace("Python-End\n","")