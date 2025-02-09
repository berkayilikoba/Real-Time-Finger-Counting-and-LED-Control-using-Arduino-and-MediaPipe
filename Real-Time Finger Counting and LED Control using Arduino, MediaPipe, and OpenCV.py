import cv2 as cv  # Import OpenCV library for video capture and image processing
import mediapipe as mp  # Import MediaPipe library for hand tracking
import serial  # Import serial library for communication with Arduino
import time  # Import time library to add delays

# Initialize video capture to use the camera (index 1)
cap = cv.VideoCapture(1)

# Set up serial communication with the Arduino (COM5 port at 9600 baud rate)
arduino = serial.Serial(port='COM5', baudrate=9600, timeout=1)
time.sleep(2)  # Wait for 2 seconds to allow Arduino to initialize

# Initialize MediaPipe Hands module for hand tracking
mp_hands = mp.solutions.hands
mp_drawing = mp.solutions.drawing_utils  # Used to draw landmarks on the hand
hands = mp_hands.Hands(min_detection_confidence=0.5, min_tracking_confidence=0.5)

# Function to count the number of raised fingers
def count_fingers(hand_landmarks):
    # Finger tips for each finger (index, middle, ring, little)
    finger_tips = [8, 12, 16, 20]
    # Thumb tip is at index 4
    thumb_tip = 4
    counter = 0  # Initialize the counter for the fingers
    
    # Loop through each finger tip and check if it's raised
    for tip in finger_tips:
        # If the y-coordinate of the fingertip is above the joint, consider it raised
        if hand_landmarks.landmark[tip].y < hand_landmarks.landmark[tip - 2].y:
            counter += 1  # Increment counter for raised fingers
        
    # Check the thumb's position: if its x-coordinate is greater than the previous joint, count it as raised
    if hand_landmarks.landmark[thumb_tip].x > hand_landmarks.landmark[thumb_tip-1].x:
        counter += 1  # Increment counter for the thumb if raised
        
    return counter  # Return the total count of raised fingers

# Main loop to process the video frames
while cap.isOpened():
    _, frame = cap.read()  # Read a frame from the video capture
    rgb_frame = cv.cvtColor(frame, cv.COLOR_BGR2RGB)  # Convert the frame from BGR to RGB for MediaPipe
    
    # Process the frame for hand landmarks using MediaPipe
    results = hands.process(rgb_frame)
    
    # If hands are detected in the frame
    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            # Draw the landmarks and connections of the hand on the frame
            mp_drawing.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)
            
            # Get the number of raised fingers using the count_fingers function
            fingers = count_fingers(hand_landmarks)
            
            # Display the number of fingers on the screen
            cv.putText(frame, f'Number: {fingers}', (50, 50), cv.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            
            # Send the number of fingers via serial to Arduino, adding a newline character to mark the end
            arduino.write(f"{fingers}\n".encode())
            

    # Display the processed frame
    cv.imshow('Finger Counting', frame)

    # If 'q' is pressed, exit the loop
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close all OpenCV windows
cap.release()
cv.destroyAllWindows()
