#include <Keyboard.h>
#include <Mouse.h>

// Pin Configuration
const int greenPin = 1;
const int redPin = 0;
const int bluePin = 17;
const int yellowPin = 16;
const int upPin = 12;
const int leftPin = 11;
const int downPin = 10;
const int rightPin = 9;
const int R2Pin = 8;
const int R1Pin = 7;
const int L2Pin = 4;
const int L1Pin = 3;

// Joystick Axes
const int xAxisLeft = A0;
const int yAxisLeft = A1;
const int xAxisRight = A4;
const int yAxisRight = A5;

// Button States
int greenState = 0, redState = 0, blueState = 0, yellowState = 0;
int upState = 0, leftState = 0, downState = 0, rightState = 0;
int R2State = 0, R1State = 0, L2State = 0, L1State = 0;

// Joystick Sensitivity Settings
const int range = 10;
const int center = range / 2;
const int threshold = 2;
const int responseDelay = 10; // Delay for input responsiveness

void setup() {
    // Set buttons as input
    pinMode(greenPin, INPUT);
    pinMode(redPin, INPUT);
    pinMode(bluePin, INPUT);
    pinMode(yellowPin, INPUT);
    pinMode(upPin, INPUT);
    pinMode(leftPin, INPUT);
    pinMode(downPin, INPUT);
    pinMode(rightPin, INPUT);
    pinMode(R1Pin, INPUT);
    pinMode(R2Pin, INPUT);
    pinMode(L1Pin, INPUT);
    pinMode(L2Pin, INPUT);

    // Initialize Keyboard and Mouse
    Keyboard.begin();
    Mouse.begin();
}

void loop() {
    updateButtonStates();
    activateButtons();
    processJoystick();
}

void updateButtonStates() {
    greenState = digitalRead(greenPin);
    redState = digitalRead(redPin);
    blueState = digitalRead(bluePin);
    yellowState = digitalRead(yellowPin);
    upState = digitalRead(upPin);
    leftState = digitalRead(leftPin);
    downState = digitalRead(downPin);
    rightState = digitalRead(rightPin);
    R2State = digitalRead(R2Pin);
    R1State = digitalRead(R1Pin);
    L2State = digitalRead(L2Pin);
    L1State = digitalRead(L1Pin);
}

void activateButtons() {
    activeKeyboardButton(greenState, ' ');
    activeKeyboardButton(redState, 'c');
    activeKeyboardButton(yellowState, 'o');
    activeKeyboardButton(blueState, 't');
    activeKeyboardButton(upState, 'i');
    activeKeyboardButton(leftState, 'j');
    activeKeyboardButton(downState, 'k');
    activeKeyboardButton(rightState, 'l');
    activeMouseButton(R2State, MOUSE_RIGHT);
    activeKeyboardButton(R1State, 'z');
    activeMouseButton(L2State, MOUSE_LEFT);
    activeKeyboardButton(L1State, 'x');
}

void activeKeyboardButton(int button, char key) {
    if (button == HIGH) {
        Keyboard.press(key);
    } else {
        Keyboard.release(key);
    }
}

void activeMouseButton(int button, uint8_t key) {
    if (button == HIGH) {
        Mouse.press(key);
    } else {
        Mouse.release(key);
    }
}

void processJoystick() {
    int xReadingLeft = readAxis(xAxisLeft);
    int yReadingLeft = readAxis(yAxisLeft);
    int xReadingRight = readAxis(xAxisRight);
    int yReadingRight = readAxis(yAxisRight);

    leftJoystick(xReadingLeft, yReadingLeft);
    Mouse.move(xReadingRight, -yReadingRight, 0);
}

int readAxis(int thisAxis) {
    int reading = analogRead(thisAxis);
    reading = map(reading, 0, 1023, 0, range);
    int distance = reading - center;
    if (abs(distance) < threshold) {
        distance = 0;
    }
    return distance;
}

void leftJoystick(int x, int y) {
    if (x > threshold) {
        Keyboard.press('a');
    } else if (x < -threshold) {
        Keyboard.press('d');
    } else {
        Keyboard.release('a');
        Keyboard.release('d');
    }

    if (y > threshold) {
        Keyboard.press('s');
    } else if (y < -threshold) {
        Keyboard.press('w');
    } else {
        Keyboard.release('s');
        Keyboard.release('w');
    }

    delay(responseDelay);
}
