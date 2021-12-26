# ImageProcessingBasedFireDetection
This project is made to accurately detect, classify, alert and extinguish fire in a buiding/room with 24x7 CCTV/Webcam survelliance and without using sensors.
This is our final year project for the session 2016-20; TMSL, Kolkata.

## Objective
To detect and classify fire flames wrt background using HAAR classifier in python3 and send the signal 24x7 to arduino uC for controlling peripherals used for the purpose of alerting and extinguishing the fire as and when required.

## Pre-requisites
1. Python3 setup in PC
2. Cascade GUI trainer installed in your PC (optional, as many readymade cascade gui trained xml files are available on internet)
3. Arduino Uno R3/Uno x1 & Arduino IDE
4. GSM module GSM900/850 x1
5. DC motor pump 12V x1
6. Breadboard x1
7. CCTV/Webcam 13MP (min. recommended)
8. Transistors BC547 x1
9. Resistor 1K x2 + POT 10K x1
10. Relay 5V x1
11. 16x2 LCD display x1
12. Buzzer x1

###### Dependencies [as on 10-10-2020]
1. OpenCV-python>=4.2.0.34
2. Pyserial>=3.4

## How To Use It?
1. First, after pre-requisites for environment setup are satisfied as stated above, connect everything according to given circuit diagram in repo.
2. Download this code package to a single folder locally.
3. Feed the controller_code.ino using Arduino IDE to your arduino uC through cable.
4. Download the dependencies and run detection_code.py file using IDLE.
5. Voila! Its ready for survelliance now.

## Future proposals [as on 10-10-2020]
N.A.

## Download Links
1. Arduino IDE: https://www.arduino.cc/en/software
2. Cascade Trainer GUI App (optional): http://amin-ahmadi.com/cascade-trainer-gui/
3. Python3: https://www.python.org/downloads/

## References
1. https://towardsdatascience.com/computer-vision-detecting-objects-using-haar-cascade-classifier-4585472829a9
2. https://medium.com/analytics-vidhya/haar-cascade-face-identification-aa4b8bc79478 
###### Version v1.0-beta
###### Next: v1.0
