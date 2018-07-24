#include<bits/stdc++.h>
#include <vector>
using namespace std;

class MinHeap
{
  private:
    vector<int> heap;
    int n;
    int heapSize;
 
  public:
    MinHeap(int n)
    {
      this->n = n;
      heapSize = 0;
    }
    
    int parent(int i)
    {
        return (i-1)/2;
    }
    
    int right(int i)
    {
        return 2*i+1;
    }
    
    int left(int i)
    {
        return 2*i+2;
    }
    
    int getMin()
    {
        return heap[0];
    }
    
    void swap(int a, int b)
    {
        int aux = a;
        a = b;
        b = aux;
    }
    
    
    void insertKey(int k)
    {
        if(heapSize==n)
        {
            cout << "heap overflow" << endl;
            return;
        }
        
        heapSize++;
        int i = heapSize-1;
        heap.push_back(k);
        
        while(i!=0 && heap[parent(i)]>heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void decreaseKey(int i, int newVal)
    {
        heap[i]=newVal;
        
        while(i!=0 && heap[parent(i)]>heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }
    
    void minHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        
        if(l<heapSize && heap[l]<heap[i])
            smallest = 1;
            
        if(r<heapSize && heap[r]<heap[smallest])
            smallest = r;
            
        if(smallest != 0)
        {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }
    
    int extractMin()
    {
        if(heapSize <= 0)
            return INT_MAX;
            
        if(heapSize == 1)
        {
            heapSize --;
            return heap[0];
        }
            
        int root = heap[0];
        heap[0] = heap[heapSize-1];
        heapSize--;
        minHeapify(0);
        
        return root;
    }
    
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }
    
    void printHeap()
    {
        for(int i = 0; i < heapSize; i++)
            cout << heap[i] << " ";
    }
  
};

int main()
{
    MinHeap m(11);
    m.insertKey(3);
    m.insertKey(2);
    m.insertKey(15);
    m.insertKey(5);
    m.insertKey(4);
    m.insertKey(45);
    m.printHeap();
    
}