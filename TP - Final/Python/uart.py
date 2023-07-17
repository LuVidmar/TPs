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
        c = ser.read_until(b"STM-Ready.").decode('utf-8')
        print(c.replace("STM-Ready.", "")) # Clear the string

        # Check if alive
        if "STM-Ready." in c:
            ser.flush()
            return
        
# Waiting for STM next move
def wait_ready_next():
    while True:
        # Read data from STM32, non-blocking, every 0.1s
        c = ser.read_until(b"STM-NextMove.").decode('utf-8')
        print(c.replace("STM-NextMove.", "").replace("STM-Ready.", "")) # Clear the string

        # Check if alive
        if "STM-NextMove." in c:
            ser.flush()
            return

def send_move(coordinates: str):
    ser.write(bytearray(coordinates.upper() + ".", 'utf-8'))

def send_game_over():
    ser.write(b"Python-End.")