#! Python3
import time
import serial
from appJar import gui

'''
max_valid_read = 1023
reference_voltage = 3.3
update_interval = 5e-4
''' 

ser = serial.Serial(port = '/dev/ttyACM0', baudrate = 9600)
#time.sleep(2)
ser.flush()


#Handling Events
def mainPress(button):
    if button == 'Cancel':
        app.stop()
    else:
        #gesture = app.getEntry('Gesture')
        print('The hand will move to gesture: ' + button)
        move(button)
	

app = gui('Hand Gesture GUI', '400x250')
app.setBg('Yellow')
app.setLabelFont(16,'Times')
font = 'Times 16 normal'

#Labels
app.addLabel('title','Gesture Control')
app.setLabelBg('title','red')
app.setLabelFg('title','white')
app.addLabel('text','Enter the gesture you want to perform:')

#Label Entries
#app.addLabelEntry('Gesture')

#Buttons
app.addButtons(['RELAX','FIST'],mainPress)
app.addButtons(['POINT','PEACE','GRIP'],mainPress)
#app.addButton('Cancel',mainPress)
app.setButtonFont(16,'Times')
#app.setFocus('Gesture')

def move(gesture):
    if (gesture == 'RELAX'):
        ser.write(b'1')
    if (gesture == 'FIST'):
        ser.write(b'2')
    if (gesture == 'POINT'):
        ser.write(b'3')
    if (gesture == 'PEACE'):
        ser.write(b'4')
    if (gesture == 'GRIP'):
        ser.write(b'5')
        
#starting main GUI
app.go()


