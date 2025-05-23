// heap.cpp
// Michelle Salome

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);

  int i = vdata.size() - 1;

  while(i > 0){
    int parent = (i - 1) / 2;
    if(vdata[i] < vdata[parent]){
      std::swap(vdata[i], vdata[parent]);
      i = parent;
    } else{
      break;
    }
  }
}

void Heap::heapMin(int i){
  int left = 2*i + 1;
  int right = 2*i + 2;
  int smallest = i;

  if(left < vdata.size() && vdata[left] < vdata[smallest]){
    smallest = left;
  }

  if(right < vdata.size() && vdata[right] < vdata[smallest]){
    smallest = right;
  }

  if(smallest != i){
    std::swap(vdata[i], vdata[smallest]);

    heapMin(smallest);
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(vdata.empty()){
    return;
  }

  vdata[0] = vdata.back();
  vdata.pop_back();

  heapMin(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  if(vdata.empty()){
    return;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    