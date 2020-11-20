//calling class cpp file
#include "calling.h"
#include <fstream>

void calling::call(string text){//gets file info
  ifstream file(text);
  bool badFile = false;
  if (file.is_open()) {
    string tempLine;
    queue = new TQueue<student>();
    int lines = 1;

    bool time = false;
    int numTime = 0;
    bool size = false;
    int numSize = 0;


    while (getline(file, tempLine)) {
      try {
        if (lines == 1) {
          arrayLength = stoi(tempLine);
          array = new window[arrayLength];
          time = true;
        } else if (time == true){
          time = false;
          numTime = stoi(tempLine);
          size = true;
        } else if (size == true){
          size = false;
          numSize = stoi(tempLine);
        } else if (numSize > 0){
          numSize--;
          queue->insert(student(numTime, stoi(tempLine)));
          if (numSize == 0){
            time = true;
          }
        }
        lines++;
      } catch(const invalid_argument i){
        cout << "Bad File" << endl;
        badFile = true;
      }
    }
    if (!badFile){
      calculate();
    }
  }
}

void calling::calculate(){//calculates numbers needed
  int time = 0;
  medianList = new TList<int>();
  while (!queue->isEmpty()){
      for (int i = 0; i < arrayLength; ++i){
        if (!queue->isEmpty()){
          if (array[i].needStudent()){
            if (queue->peek().startTime <= time){
              if (queue->peek().startTime < time){
                int wait = time - queue->peek().startTime;
                queue->peek().setWaitTime(wait);
                totalMeanS += wait;
                numMeanS++;
                medianList->insertFront(wait);
                medianTotal++;
                if (wait > longestWait){
                  longestWait = wait;
                }
                if (wait > 10){
                  plus10++;
                }
              }
              array[i].s = queue->remove();
              i = 0;
            }
          }
        }
      }
      for (int i = 0; i < arrayLength; ++i){
        if (!queue->isEmpty()){
          if (array[i].needStudent()){
            array[i].idleTime++;
          } else {
            array[i].s.workTime--;
          }
        }
      }
      time++;
  }
  calcMean();
  calcMedian();
  calcLongest();
  calcPlus10();
  calcMeanWindow();
  calcMeanLongest();
  calcPlus5();
}

void calling::calcMean(){//prints mean of student wait time
  double r = 0;
  if (numMeanS != 0){
    r = (double)(totalMeanS)/ (double)(numMeanS);
  }
  cout << "1. The mean student wait time : " << r << endl;
}

void calling::calcMedian(){//prints median of student wait time
  double r = 0;
  if (numMeanS != 0){
    if (medianTotal % 2 == 1){
      for (int i = 0; i < medianTotal/2; ++i){
        medianList->removeFront();
      }
      r = medianList->removeFront();
    } else {
      for (int i = 0; i < (medianTotal/2)-1; ++i){
        medianList->removeFront();
      }
      r = medianList->removeFront();
      r += medianList->removeFront();
      r /= 2;
    }
  }
  cout << "2. The median student wait time : " << r << endl;
}

void calling::calcLongest(){//prints longest student wait time
  int r = longestWait;
  cout << "3. The longest student wait time : " << r << endl;
}

void calling::calcPlus10(){//prints student waiting over 10 min
  int r = plus10;
  cout << "4. The number of students waiting over 10 minutes: " << r << endl;
}

void calling::calcMeanWindow(){//prints mean window idling time
  int r = 0;
  for (int i = 0; i < arrayLength; i++){
    r += array[i].idleTime;
  }
  r /= arrayLength;
  cout << "5. The mean window idle time: " << r << endl;
}

void calling::calcMeanLongest(){//prints longest window idling time
  int r = 0;
  for (int i = 0; i < arrayLength; i++){
    if (array[i].idleTime > r){
      r = array[i].idleTime;
    }
  }
  cout << "6. The longest window idle time: " << r << endl;
}

void calling::calcPlus5(){//prints windows over 5 minutes of idling
  int r = 0;
  for (int i = 0; i < arrayLength; i++){
    if (array[i].idleTime > 5){
      r++;
    }
  }
  cout << "7. Number of windows idle for over 5 minutes: " << r << endl;
}
