//implementation for window.cpp
#include "window.h"

//cpp
window::window(){//constructor
  s = student(0, 0);
  idleTime = 0;
}

window::~window(){}//destructor

bool window::needStudent(){//checks if window needs student
  if (s.workTime == 0){
    return true;
  }
  return false;
}

void window::changeStudent(student st){//change student in window
  s = st;
}
