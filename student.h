//implementation for student.h
#include <iostream>

using namespace std;

//header
class student{
  public:
    student(int s, int w);//constructor with info
    student();//default
    ~student();//destructor
    void setWaitTime(int w);//reset wait time
    int waitTime;//time been waiting
    int workTime;//amount of time working
    int startTime;//time student wants to start
};
