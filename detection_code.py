import cv2
import serial
import time


fire_cascade = cv2.CascadeClassifier('fire_detection.xml')
ser = serial.Serial('COM3',9600) #change COM port number on which your arduino is connected
cap = cv2.VideoCapture(0) #0 in case of inbuilt web cam and 1 if external cam is used
if cap.isOpened():
    while True:
        ret, img = cap.read()
        gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
        fire = fire_cascade.detectMultiScale(img, 1.2, 5)
        for (x,y,w,h) in fire:
            cv2.rectangle(img,(x,y),(x+w,y+h),(0,0,255),2)
            roi_gray = gray[y:y+h, x:x+w]
            roi_color = img[y:y+h, x:x+w]
            print('Fire is detected..!')
            ser.write('p'.encode())
            time.sleep(0.2)
        
        cv2.imshow('img',img)
        print('Continue Capturing Video...')
        ser.write('s'.encode())
    
        k = cv2.waitKey(30) & 0xff
        if k == 27:
           break

    cap.release()
    cv2.destroyAllWindows()

