// Copyright 2021 KarMashanova
#include "TimedDoor.h"

#include <iostream>
#include <string>

DoorTimerAdapter::DoorTimerAdapter(TimedDoor& door_) : door(door_) {}

TimedDoor::TimedDoor(int _t) {
  (*this).lock();
  (*this).iTimeout = _t;
  (*this).adapter = new DoorTimerAdapter(*this);
}

void DoorTimerAdapter::Timeout() { door.DoorTimeOut(); }

bool TimedDoor::isDoorOpened() { return opened; }
void TimedDoor::unlock() {
  opened = true;
  Timer n;
  n.tregister((*this).iTimeout, (*this).adapter);
}
void TimedDoor::lock() { opened = false; }
void TimedDoor::DoorTimeOut() { throw(std::string("close the door!")); }
void TimedDoor::throwState() {
  if (!isDoorOpened()) {
    throw(std::string("the door is closed!"));
  } else {
    throw(std::string("the door is opened!"));
  }
}
void Timer::sleep(int _t) {
  time_t beg = time(nullptr);
  while (time(nullptr) - beg < _t) {
    continue;
  }
}
void Timer::tregister(int c, TimerClient* client) {
  sleep(c);
  (*client).Timeout();
}