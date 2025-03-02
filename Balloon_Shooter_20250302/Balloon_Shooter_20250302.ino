#include "Balloon_Shooter_Lib.h"

#define CONCURRENT_BALLOONS_TOTAL     10

GeometryDisplayHandler dh;

int numOfBalls = CONCURRENT_BALLOONS_TOTAL;

DemoBalloon* balls[CONCURRENT_BALLOONS_TOTAL] = { 0 };

void setup() {
  randomSeed(analogRead(A3));
  dh.begin();
  numOfBalls = random(3, CONCURRENT_BALLOONS_TOTAL + 1);
  for(int k=0; k<numOfBalls; k++) {
    balls[k] = new DemoBalloon();
    balls[k]->set(&dh);
  }
}

void loop() {
  for(int i=0; i<numOfBalls; i++) {
    balls[i]->check();
  }

  dh.firstPage();
  do {
    for(int i=0; i<numOfBalls; i++) {
      balls[i]->draw();
    }
  } while(dh.nextPage());

  delay(50);
}
