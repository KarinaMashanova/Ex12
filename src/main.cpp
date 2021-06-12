// Copyright 2021 KarMashanova
#include <iostream>

#include "TimedDoor.h"

int main() {
  TimedDoor tDoor(5);
  try {
    tDoor.lock();
    tDoor.throwState();
  } catch (std::string message) {
    std::cout << message;
  }
}
