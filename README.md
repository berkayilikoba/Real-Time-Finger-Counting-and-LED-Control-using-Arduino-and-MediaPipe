
# Real-Time Finger Counting and LED Control using Arduino, MediaPipe, and OpenCV

## Project Overview

This project detects finger count in real-time using **MediaPipe** and controls LEDs based on the detected count through **Arduino**. **OpenCV** is used for capturing and processing video frames, which are analyzed by MediaPipe for hand gesture recognition. The finger count is sent to an Arduino to control the LEDs interactively.

## Technologies Used

- **Python**
  - **OpenCV**: Used for capturing and processing video frames from the camera.
  - **MediaPipe**: Used for hand gesture recognition and finger count detection.
  - **Serial**: Used for communication between the Python script and Arduino.
  
- **Arduino**
  - Used to control LEDs based on the data received from the Python script.

## How It Works

1. **Hand Gesture Recognition**: The camera captures frames which are processed by OpenCV. MediaPipe analyzes these frames to detect hand landmarks and calculate the number of fingers raised.
2. **Finger Count Calculation**: The number of fingers raised is counted based on the hand landmarks detected by MediaPipe.
3. **LED Control**: The detected finger count is sent to the Arduino over a serial connection, which controls the LEDs by turning them on/off according to the number of fingers.

## Components

- **Camera**: Captures video frames for hand gesture recognition.
- **Arduino**: Controls the LEDs based on the received finger count.
- **LEDs**: Turn on/off based on the finger count detected by the system.

## Setup

### Requirements

- Python 3.x
- Arduino IDE
- Libraries:
  - `mediapipe`
  - `opencv-python`
  - `serial`
- Arduino with LEDs connected to pins 2 to 6.

### Installation

1. **Install Python Libraries**:

   ```bash
   pip install mediapipe opencv-python pyserial
   ```

2. **Arduino Setup**:  
   Upload the provided Arduino code to your Arduino board using the Arduino IDE. Ensure the LEDs are connected to the specified pins (2-6).

3. **Run the Python Script**:
   
   Connect your camera and Arduino. Run the Python script:

   ```bash
   python finger_counting_led_control.py
   ```

   Make sure your Arduino is connected to the specified COM port (e.g., `COM5`).

## Usage

- The system will display the number of fingers detected in real-time on the screen.
- The corresponding LEDs will light up based on the number of fingers raised.
- Press 'q' to exit the program.

## Troubleshooting

- Ensure your camera is properly connected and accessible by OpenCV.
- Double-check the serial connection between Python and Arduino.

## License

This project is open-source and available under the MIT License.
