#include"Pokerobo_Lab_Display_Handler.h"

GeomatryDisplayHandler displayHandler(LCD_PINS_ON_RIGHT);

JoystickHandler joystickHandler;
JoystickAction action;

ShootingTarget shootingtarget(&displayHandler);
PlaySpace playspace(&displayHandler, &shootingTarget, &playSpace);

void setup() {
  Serial.begin(57600);
  displayHandler.begin();
  joystickHandler.begin();
  gameBoard.begin();
}

void loop() {
  gameBoard.play(joystickHandler.input(&action));
  gameBoard.renderAndDelay(50);
}
)