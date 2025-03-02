#include "Balloon_Shooter_Lib.h"

DemoBalloon::DemoBalloon() {
  init();
}

DemoBalloon::DemoBalloon(int cx, int cy, int cr) {
  _x = cx; _y = cy; _r = cr;
}

void DemoBalloon::init() {
  _r = random(5, 10 + 1);
  _y = 63 + _r;
  _x = random(0, 128);
}

void DemoBalloon::set(GeometryDisplayHandler *displayHandler) {
  _pencil = displayHandler;
}

void DemoBalloon::check() {
  if (_y + _r >= 0) {
    _y = _y - 3;
  } else {
    _y = 63 + _r;
    _x = random(0, 128);
  }
}

void DemoBalloon::draw() {
  _pencil->drawCircle(_x, _y, _r);
}
