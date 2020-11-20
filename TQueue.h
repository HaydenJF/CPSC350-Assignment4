//implementation for TQueue
#include "TList.h"

//header
template <class type>
class TQueue{
  public:
    TQueue(); //constructor
    ~TQueue(); //destructor


    void insert(type d); //insert new object in back
    type remove(); //remove object in front


    type peek(); //look at front object
    bool isEmpty();//check if empty
    unsigned int getSize();//gives size

  private:
    TList<type> *myTQueue;
    int numElements;
    int i = 0;
};

//cpp
template <class type>
TQueue<type>::TQueue(){//constructor
  myTQueue = new TList<type>();
  numElements = 0;
}

template <class type>
TQueue<type>::~TQueue<type>(){//destructor
  delete myTQueue;
}

template <class type>
void TQueue<type>::insert(type d){//insert new object in back
  myTQueue->insertBack(d);
  ++numElements;
}

template <class type>
type TQueue<type>::remove(){//remove object in front
  if (!isEmpty()){
    numElements--;
    return myTQueue->removeFront();
  }
}

template <class type>
type TQueue<type>::peek(){//look at front object
  if (!isEmpty()){
    return myTQueue->getFront();
  }
}

template <class type>
bool TQueue<type>::isEmpty(){//check if empty
  return (numElements == 0);
}

template <class type>
unsigned int TQueue<type>::getSize(){//gives size
  return numElements;
}
