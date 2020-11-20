//implementation for window.h
#include "student.h"

//header
class window{
public:
  window();//constructor
  ~window();//destructor
  bool needStudent();//checks if window needs student
  void changeStudent(student st);//change student in window
  int idleTime;//time window has waited
  student s;//student a window holds

};
