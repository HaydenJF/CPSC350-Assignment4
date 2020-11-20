//implementation for student.cpp
#include "student.h"

//cpp
student::student(int s, int w){//constructor with info
  waitTime = 0;
  workTime = w;
  startTime = s;
}

student::student(){//default
  waitTime = 0;
}

student::~student(){}//destructor

void student::setWaitTime(int t){//reset wait time
  waitTime = t;
}
