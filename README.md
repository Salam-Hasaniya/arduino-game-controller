# **Arduino-Based Custom Game Controller**
An Arduino Micro-based custom game controller that emulates a keyboard and mouse, ensuring compatibility with all computer games.
![1Eknh0-RK4wRTbGUKDDLZt01VD7hhKkBJJKWWSqLp5SA](https://github.com/user-attachments/assets/8b53ea09-8106-48a9-b261-e5b97261dbe3)

## **Hardware Components**
- **Arduino Micro** – Microcontroller platform  
- **12 Push Buttons** – Mapped to keyboard/mouse functions  
- **2 Joysticks** – Simulates mouse movement and directional input  
- **Pull-down Resistors** – Stabilizes digital inputs  
- **3D-Printed Case** – Ensures durability and comfort  


## **Software & Libraries**
This project utilizes the following **Arduino libraries**:
```cpp
#include <Keyboard.h>
#include <Mouse.h>
```
- **Keyboard.h** – Enables button mapping to keyboard keys
- **Mouse.h** – Allows joystick movement to control the mouse cursor
  
## **Button Mapping**
| Button | Assigned Function   |
|--------|--------------------|
| Green  | Space (Jump)      |
| Red    | 'C' (Crouch)      |
| Blue   | 'T' (Action)      |
| Yellow | 'O' (Special)     |
| Up     | 'I' (Move Up)     |
| Down   | 'K' (Move Down)   |
| Left   | 'J' (Move Left)   |
| Right  | 'L' (Move Right)  |
| R2     | Right Mouse Click |
| L2     | Left Mouse Click  |

