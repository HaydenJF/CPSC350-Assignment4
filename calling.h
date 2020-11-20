//calling class header
#include "TQueue.h"
#include "window.h"

class calling{
  public:
    void call(string text);//gets file info
    void calculate();//calculates numbers needed
    void calcMean();//prints mean of student wait time
    void calcMedian();//prints median of student wait time
    void calcLongest();//prints longest student wait time
    void calcPlus10();//prints all students over 10 waiting
    void calcMeanWindow();//prints window mean idle time
    void calcMeanLongest();//prints longest window idle time
    void calcPlus5();////prints all windows over 5 idling
  private:
    int totalMeanS = 0;//total student wait time
    int numMeanS = 0;//total students waited
    int plus10 = 0;//students over 10 wait time
    int medianTotal = 0;//total students waited (for median)
    int longestWait = 0;//longest student wait
    TList<int> *medianList;//list of students with wait time
    window *array;//array of windows
    TQueue<student> *queue;//queue of students
    int arrayLength;//length of array of windows


};
