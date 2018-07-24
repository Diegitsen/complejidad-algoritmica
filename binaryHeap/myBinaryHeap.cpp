#include <bits/stdc++.h>
using namespace std;

class maxHeap
{
  private:
  int n;
  vector<int> heap;
  
  //bubbles
  void bubbleUp()
  {
      int child = heap.size()-1;
      int parent = getParent(child);
      
      while(heap[child]>heap[parent] && child >= 0 && parent >= 0) // (se rompe la regla del heap? && existe el hijo? && existe el padre?)
      {
          swap(child, parent);
      }
  }
  
  void bubbleDown()
  {
      int parent = 0; 
      
      while(1) 
      {
          int left = getLeftChild(parent);
          int right = getRightChild(parent);
          int length = heap.size();
          int aux = parent;
          
          
          if(left < length && heap[left]>heap[aux]) // (el nodo izq es hijo del padre? && se rompe la regla del heap?)
            aux = left;
        
          if(right < length && heap[right]>heap[aux]) // (el nodo der es hijo del padre? && se rompe la regla del heap?)
            aux = right;
          
          if(aux != parent) // hubo algun cambio entre el aux y el nodo der o izq?
          {
             swap(aux, parent);
             parent=aux;
          }
          
          else 
            break;
      }
  }
  
  void swap(int child, int parent)
  {
      int aux;
      aux = heap[child];
      heap[child]=heap[parent];
      heap[parent]=aux;
  }
  
  int getParent(int child)
  {
      if(child %2==0)
        return (child/2)-1;
    
      else 
        return child/2;
  }
  
  int getLeftChild(int parent)
  {
      return 2*parent+1;
  }
  
  int getRightChild(int parent)
  {
      return 2*parent+2;
  }
  
  public:
  
  maxHeap(int n)
  {
    this->n = n;    
  }
  
  void insert(int value)
  {
      heap.push_back(value);
      bubbleUp();
  }
  
  int remove()
  {
      int child = heap.size()-1;
      swap(child, 0);
      
      int value = heap.back();
      heap.pop_back();
      
      bubbleDown();
      
      return value;
  }
  
  int getSize()
  {
      return heap.size();
  }
  
  void printHeap()
  {
      
    for(int i = 0; i < heap.size(); i++)
        cout << heap[i] <<" ";
    
  }
};

int main()
{
    maxHeap heap(4);

    heap.insert(-1);
    heap.insert(99);
    heap.insert(-2);
    heap.insert(15);
   
    while(heap.getSize()>0)
    {
        cout << heap.remove() << " ";
    }
    
    return 0;
    
    
     
}









/*
swap(child, parent);
        child = parent;
          parent = getParent(child);

*/





