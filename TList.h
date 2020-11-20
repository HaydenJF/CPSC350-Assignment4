//implementation for TList
#include "TNode.h"

//header
template <class type>
class TList{
  private:
    TNode<type> *front;//Front of list node
    TNode<type> *back;//Back of list node
    unsigned int size;//Total size of list
  public:
    TList();//constructor
    ~TList();//destructor
    void insertFront(type d);//inserts node to front
    void insertBack(type d);//inserts node to back
    type removeFront();//removes front node
    type removeBack();//removes back node

    type getFront();//returns front node
    int find(type value);//finds if list has a object
    type deletePos(int pos);//deletes an object at a specific position

    void printList();//prints list of objects
    bool isEmpty();//tells if empty
    unsigned int getSize();//gives size

    type removeNode(type key);//removes node of object
};

//cpp
template <class type>
TList<type>::TList(){//constructor
  front = NULL;
  back = NULL;
  size = 0;
}

template <class type>
TList<type>::~TList(){//destructor
  while (front != NULL) {
    removeFront();
  }
}

template <class type>
void TList<type>::insertFront(type d) {//inserts node to front
  TNode<type> *node = new TNode<type>(d);
  if (size == 0) {
    back = node;
  } else {
    front->prev = node;
    node->next = front;
  }

  front = node;
  ++size;
}

template <class type>
void TList<type>::insertBack(type d) {//inserts node to back
  TNode<type> *node = new TNode<type>(d);
  if (size == 0) {
    front = node;
  } else {
    back->next = node;
    node ->prev = back;
  }

  back = node;
  ++size;
}

template <class type>
type TList<type>::removeFront(){//removes front node
  TNode<type> *node = front;
  if(front->next ==NULL){
    back = NULL;
  }
  else{
    front->next->prev = NULL;
  }
  front = front->next;
  --size;
  node->next = NULL;
  type temp = node->data;
  delete node;
  return temp;
}

template <class type>
type TList<type>::removeBack(){//removes back node
  TNode<type> *node = back;
  if(back->prev ==NULL){
    back = NULL;
  }
  else{
    back->prev->next = NULL;
  }
  back = back->prev;
  --size;
  node->prev = NULL;
  type temp = node->data;
  delete node;
  return temp;
}

template <class type>
type TList<type>::getFront(){//returns front node
  return front->data;
}


template <class type>
void TList<type>::printList(){//prints list of objects
  TNode<type> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;

  }
}

template <class type>
int TList<type>::find(type value) {//finds if list has a object
  int pos = -1;
  TNode<type> *curr = front;

  while (curr != NULL){
    ++pos;
    if (curr->data == value){
      return pos;
    }
    curr = curr->next;
  }
  return -1;
}

template <class type>
type TList<type>::deletePos(int pos) {//deletes an object at a specific position
  int p = 0;
  TNode<type> *curr = front;
  TNode<type> *prev = front;

  while(p != pos){
    prev = curr;
    curr = curr->next;
    p++;
  }

  prev->next = curr->next;
  curr->next = NULL;
  type temp = curr->data;
  size--;

  delete curr;
  delete prev;
  return temp;
}

template <class type>
bool TList<type>::isEmpty() {//tells if empty
  if (front == NULL && back == NULL){
    return true;
  }
  return false;
}

template <class type>
unsigned int TList<type>::getSize() {//gives size
  return size;
}

template <class type>
type TList<type>::removeNode(type key) {//removes node of object
  TNode<type> *curr = front;
  cout << "n" << endl;
  while(curr->data != key) {
    cout << "N2" << endl;
    if(curr == NULL) {
      cout << "welp" << endl;
      return '\0';
    }
    curr = curr->next;
  }
  if(curr==front){
    front = curr->next;
    front->prev = NULL;
  } else if(curr==back) {
    back = curr->prev;
    back->next = NULL;
  } else {
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
  }
  curr->next = NULL;
  curr->prev = NULL;

  type temp = curr->data;
  delete curr;
  size--;

  return temp;

}
