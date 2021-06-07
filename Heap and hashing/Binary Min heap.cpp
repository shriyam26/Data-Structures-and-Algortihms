#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z;
}

class minHeap{
    int* harr;
    int capacity;
    int heapSize;
    
    public:
    minHeap(int capacity){
        heapSize = 0;
        capacity = capacity;
        harr = new int[capacity];
    }
    int parent(int ind){
        return (ind - 1)/2;
    }
    int left(int ind){
        return (2*ind + 1);
    }
    int right(int ind){
        return (2*ind + 2);
    }
    void printHeap();
    // to heapify a subtree with the root at given index
    void minHeapify(int ind);
    // Returns the minimum key (key at root) from min heap
    int getMin(){ return harr[0]; }
    // to extract the root which is the minimum element
    int extractMin();
    // Decreases(Repalces) key value of key at index ind to new_val
    void decreaseKey(int ind, int new_val);
    // Deletes a key stored at index ind
    void deleteKey(int ind);
    // Inserts a new key 'key'
    void insertKey(int key);
};

void minHeap::printHeap(){
    cout << "Heap is as follows:\n";
    for(int i = 0; i <heapSize; i++){
        cout << harr[i] << " ";
    }
    cout << endl;
}

void minHeap::insertKey(int val){ //O(logn)
    if(heapSize == capacity){
        cout << "Heap Overflow\n";
        return;
    }
    heapSize++;
    int ind = heapSize -1;
    harr[ind] = val;
    while(ind != 0 && harr[parent(ind)] > harr[ind]){
        swap(&harr[parent(ind)], &harr[ind]);
        ind = parent(ind);
    }
}

void minHeap::decreaseKey(int ind, int new_val){ //O(logn)
    harr[ind] = new_val;
    while(ind != 0 && harr[parent(ind)] > harr[ind]){
        swap(&harr[parent(ind)], &harr[ind]);
        ind = parent(ind);
    }
}

int minHeap::extractMin(){ //O(logn)
    if(heapSize <= 0){
        return INT_MAX;
    }
    if(heapSize == 1){
        heapSize--;
        return harr[0];
    }
    int min = harr[0];
    harr[0] = harr[heapSize - 1];
    heapSize--;
    minHeapify(0);
    return min;
}

void minHeap::deleteKey(int ind){ //O(logn)
    decreaseKey(ind, INT_MIN);
    extractMin();
}

void minHeap::minHeapify(int ind){
    int l = left(ind);
    int r = right(ind);
    int smallest = ind;
    if(l < heapSize && harr[l] < harr[smallest]) smallest = l;
    if(r < heapSize && harr[r] < harr[smallest]) smallest = r;
    if(ind != smallest){
        swap(&harr[ind], &harr[smallest]);
        minHeapify(smallest);
    }
}
int main()
{
    minHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.printHeap();
    h.deleteKey(1);
    h.printHeap();
    cout << endl;
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}