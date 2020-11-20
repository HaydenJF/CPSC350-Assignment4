#include "ListNode.h"

ListNode::ListNode(){}

ListNode::ListNode(int d) {
  data = d;
  next = NULL;
}

ListNode::~ListNode(){
  delete next; //Look up just in case
}
