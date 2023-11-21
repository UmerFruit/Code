#include <iostream>
using namespace std;

class Heap {
    public:
        int arr[100];
        int size;

        Heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int val) {
            int index = ++size;
            arr[index] = val;

            while(index > 1) {
                int parent = index/2;

                if(arr[parent] < arr[index]) {
                    swap(arr[parent], arr[index]);
                    index = parent;
                } else {
                    return;
                }
            }   
        }

        // void deleteHeap() {
        //     if(size == 0) {
        //         cout << "Heap is empty!" << endl;
        //         return;
        //     }

        //     arr[1] = arr[size];
        //     size--;

        //     int i = 1;
        //     while(i < size) {
        //         int leftChild = 2*i;
        //         int rightChild = (2*i) + 1;

        //         if(leftChild < size && arr[i] < arr[leftChild]) {
        //             swap(arr[i], arr[leftChild]);
        //             i = leftChild;
        //         } else if(rightChild < size && arr[i] < arr[rightChild]) {
        //             swap(arr[i], arr[rightChild]);
        //             i = rightChild;
        //         } else {
        //             return;
        //         }
        //     }
        // }

        void deleteHeap() {
            if(size == 0) {
                cout << "Heap is empty!" << endl;
                return;
            }

            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i < size) {
                int leftChild = 2*i;
                int rightChild = (2*i) + 1;
                int largest = i;

                if(leftChild <= size && arr[largest] < arr[leftChild]) {
                    largest = leftChild;
                }
                
                if(rightChild <= size && arr[largest] < arr[rightChild]) {
                    largest = rightChild;
                }

                if(largest == i) {
                    return;
                } else {
                    swap(arr[i], arr[largest]);
                    i = largest;
                }
            }
        }

        void print() {
            cout << "Max Heap : ";
            for(int i=1; i<=size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
            
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
