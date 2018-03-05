#! Python3
import time
import csv
import serial
from pylab import *
from appJar import gui

max_valid_read = 1023
reference_voltage = 5
update_interval = 5e-4

#for Linux 
ser = serial.Serial(port = '/dev/ttyACM1', baudrate = 115200)

#for Windows 
#ser = serial.Serial(port = 'COM9', baudrate = 115200)

time.sleep(2)
ser.flush()

ion()
t = arange(0,1,0.0005)
###<<< GUI CODE >>>###

#Main Menu Window
def mainPress(button):
    if button == 'Real Time':
        #app.stop()
        sig = emg()
        line, = plot(t, sig[0])
        ylim( (-1, 6) )
        sig_y = sig[0]
        annotate('Baseline',(t[0],sig_y[0]))
        starting_time = time.time()
        while (time.time()-starting_time<60):
            y = emg()
            line.set_ydata(y[0])
            #autoscale(enable=True, axis='both')
            draw()
            pause(0.000001)
        close()
        #print('RealTime Block Reached')
    else:
        close()
        app.showSubWindow('EMG Acquisition')

app = gui('EMG GUI', '400x200')
app.setBg('Orange')
app.setLabelFont(16,'Times')
font = 'Times 16 normal'

#Labels
app.addLabel('title1','EMG Signal Interface')
app.setLabelBg('title1','blue')
app.setLabelFg('title1','white')

#Buttons
app.addButtons(['Real Time','Acquisition'],mainPress)
app.setButtonFont(16,'Times')


#Acquisition Window        
def AcquisitionPress(button):
    if button == 'Cancel':
        app.hideSubWindow('EMG Acquisition')
    else:
        name = app.getEntry('Name')
        gesture = app.getEntry('Gesture')
        global file_name
        file_name = name + '_' + gesture + '.csv'
        print('File name to be saved as: ' + file_name)
        app.showSubWindow('Readings')

###<<< Acquisition Window >>>###
app.startSubWindow('EMG Acquisition', modal=True)
app.setBg('Orange')
app.setGeometry("400x200")
app.setFont(18)
app.addLabel('title2','    EMG Acquisition    ')
app.setLabelBg('title2','blue')
app.setLabelFg('title2','white')
#Label Entries
app.addLabelEntry('Name')
app.addLabelEntry('Gesture')
#Buttons
app.addButtons(['Enter','Cancel'],AcquisitionPress)
app.setButtonFont(16,'Times')
app.setFocus('Name')
app.stopSubWindow()
###<<<------------------->>>###

#Readings Window
def windowPress(button):
    if button == 'Start':
        print('Readings starting now: ')
        global values
        values = emg()
        plotting(values[1] ,values[0] )
        #print('Reached readings code')
        #app.hideSubWindow('Readings')
    else:
        filecreating(values[0],file_name)
        close()
        app.hideSubWindow('Readings')
    
###<<< Readings Window >>>###         
app.startSubWindow('Readings', modal=True)
app.setBg('Orange')
app.setGeometry("400x200")
app.setFont(18)
app.addLabel('promt','Click Start to begin taking readings')
app.setLabelFg('promt','white')
app.setLabelBg('promt','blue')
app.addMeter('Readings')
app.setMeterFill('Readings','red')        
app.addButtons(['Start','Finish'],windowPress)
app.stopSubWindow()
###<<<------------------->>>###

def plotting(x,y):
    plot(x,y)
    show()

def filecreating(output,file):
    print('csv function called')
    myfile = open(file,'w')
    with myfile:
        writer = csv.writer(myfile)
        writer.writerow(output)
    

def emg():
    #print('Readings starting now: ')
    ser.write(b'2')
    r = 0
    r_time = 0
    analog_reads = []
    analog_times = []
    while r <= max_valid_read:
        b1 = ord(ser.read(1))
        b2 = ord(ser.read(1))
        r = b1 + b2*256
        if(r <= max_valid_read):
           analog_reads.append((r*reference_voltage)/max_valid_read)
           analog_times.append(r_time)
           r_time = r_time + update_interval
    return analog_reads, analog_times   
        
#starting main GUI
app.go()


