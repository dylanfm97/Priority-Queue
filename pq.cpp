#include <iostream>
#include <vector>

#include "pq.h"

PriorityQueue::PriorityQueue(std::vector<node> S)
  :mHeap(S)
{  

  for(int i = S.size()-1; i >= 0; i--){
    siftdown(mHeap[i], i);
  }

}


void PriorityQueue::printqueue(){
  for(int i = 0; i < mHeap.size(); i++){
    std::cout << "key: " << mHeap[i].key << " value: " << mHeap[i].value 
	      << " position: " << mHeap[i].position << std::endl;
  }
}

void PriorityQueue::changevalue(int i, int value){
  mHeap[i].value = value;
}

int PriorityQueue::minchild(int i){
  //return the index of the smallest child of heap(i)
  if(2*i+1 >= mHeap.size()){//if the index is more than halfway through the array
    return 0; //no children
  }
  else{ //otherwise, if the index is in the first half of the array
    if(2*i+2 >= mHeap.size()){
      return 2*i+1; //there is only 1 child, so return it
    }
    else{//if there is more than 1 child
      if(mHeap[2*i+1].value < mHeap[2*i+2].value){
	  return 2*i+1;
	}
	else{
	  return 2*i+2;
	}     
    }
  }
}

void PriorityQueue::siftdown(node x, int i){
  int c = minchild(i);
  while(c != 0 && mHeap[c].value < x.value){
    node temp = mHeap[i];
    mHeap[i] = mHeap[c]; 
    mHeap[i].position = i;
    mHeap[c] = temp; 
    mHeap[c].position = c;
    i = c;
    c = minchild(i);
  }
  mHeap[i] = x;
  mHeap[i].position = i;
}

void PriorityQueue::bubbleup(node x, int i) {
  int p = i >> 1;
  while(i != 0 && mHeap[p].value > x.value){
    node temp = mHeap[i];
    mHeap[i] = mHeap[p]; 
    mHeap[i].position = i;
    mHeap[p] = temp;
    mHeap[p].position = p;

    i = p;
    p = i >> 1;
  }
}

node* PriorityQueue::deletemin() {
  if(mHeap.size() == 0){
    return 0;
  }
  else{
    node x = mHeap[0];
    siftdown(mHeap[mHeap.size() - 1], 0);
    mHeap.pop_back();
    return &x;
  }
}

void PriorityQueue::decreasekey(node x){
  bubbleup(x, x.position);
}

node PriorityQueue::getnode(int i){
  return mHeap[i];
  
}

int PriorityQueue::size(){
  return mHeap.size();
}

    
    
  
  
	
