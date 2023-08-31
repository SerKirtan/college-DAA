#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int right , int parent) {
    int largest = parent;
    int leftChild = 2*parent + 1;
    int rightChild = 2*parent + 2;
    if(leftChild < right && arr[largest] < arr[leftChild])
        largest = leftChild;
    if(rightChild < right && arr[largest] < arr[rightChild])
        largest = rightChild;
    if(largest != parent) {
        swap(arr[parent] , arr[largest]);
        heapify(arr, right, largest);
    }
}

int main() {
    int size;
    vector<int> arr;
    cout << "Enter the size of array : ";
    cin >> size;
    cout << "Enter " << size << " elements : ";
    for(int i = 0; i < size ; i++) {
        int temp;
        cin >> temp;
        arr.emplace_back(temp);
    }
    auto start = chrono::steady_clock::now();
    for(int i = size/2 -1 ; i >= 0 ; i--)
        heapify(arr, size, i);
    
    for(int i = size - 1 ; i >= 0 ; i--) {
        swap(arr[0] , arr[i]);
        heapify(arr , i , 0);
    }
    auto end = chrono::steady_clock::now();

    for(int e : arr)
        cout << e << " ";

    cout << "\n~~Time analysis~~";
    cout << "\nIn nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns";
    cout << "\nIn microseconds : " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "µs";
    cout << "\n~~Time analysis~~";
}