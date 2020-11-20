//implementation for TNode
#include <iostream>

using namespace std;

//header
template <class type>
class TNode{
  public:
    TNode();//Node Constructor
    TNode(type d);//Node Constructor with value
    ~TNode();//Node destructor
    type data;//value (can be anything)
    TNode *next;//node after
    TNode *prev;//node before
};

//cpp
template <class type>
TNode<type>::TNode(){}//Node Constructor

template <class type>
TNode<type>::TNode(type d) {//Node Constructor with value
  data = d;
  next = NULL;
  prev = NULL;
}

template <class type>
TNode<type>::~TNode(){//Node destructor
  delete next;
  delete prev;
}
