// C++ program for implementation of Heap Sort
/*
Heap Sort Algorithm for sorting in increasing order: 
1. Build a max heap from the input data. 
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree. 
3. Repeat step 2 while the size of the heap is greater than 1.

How to build the heap? 
Heapify procedure can be applied to a node only if its children nodes are heapified. So the heapification must be performed in the bottom-up order.
bottom up approach means when we insert a new element we insert it at last index and then move updwards by heapification.
Similarly top down approach means when we remove an element we remove the top element and then we heapify reducing the sixe of the tree.
*/

//Time complexity to build a heap is O(n). Actually by looking at the algorithm it would look like the time complexity should be O(nlogn) since heapify takes
//O(logn) time and build heap makes O(n) such calls. But actually Heapify takes O(h) time where h is the height of the noe, so it takes different time for //each node. So on calculatingtime taken for each node adn then adding it together we get O(n) time complexity for build heap
#include <bits/stdc++.h>
using namespace std;

//min heap sorts array in descending order and max heap in increasing order.
void maxHeapify(int arr[], int n, int i){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l < n && arr[largest] < arr[l]) largest = l;
    if(r < n && arr[largest] < arr[r]) largest = r;
    if(largest != i){
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}
    
void buildMaxHeap(int arr[], int n){ 
    for(int i = n/2-1; i>=0; i--){
        maxHeapify(arr, n, i);
    }
}

void heapSort(int arr[], int n){
    buildMaxHeap(arr, n);
    for(int i = n-1; i >=0 ; i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}