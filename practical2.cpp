#include<bits/stdc++.h>
using namespace std;

void swap(int &n1, int &n2){
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

int partition(vector<int>& array, int begin, int end) {
        int pivot = array[end];
        int i = begin - 1;
        for(int j = begin ; j <= end-1 ; j++) {
        if(array[j] <= pivot) {
            i++;
            swap(array[i] , array[j]);
        }
    }
    swap(array[i+1] , array[end]);
    return i+1;
}

void quickSort(vector<int>& array, int const begin, int const end)
{
    if(begin >= end) return;

    int pivotIndex = partition(array, begin, end);

    quickSort(array, begin, pivotIndex-1);
    quickSort(array, pivotIndex+1, end);
}

//Merges two sorted array
void mergeArray(vector<int>& array, const int first, const int mid, const int last){

    const int sizeA = mid - first + 1;
    const int sizeB = last - mid;
    int indexC = first;

    // create two temp arrays
    int* arrA = new int[sizeA];
    int* arrB = new int[sizeB]; 

    for(int i = 0 ; i < sizeA ; i++)
        arrA[i] = array[first + i];
    for(int i = 0 ; i < sizeB ; i++)
        arrB[i] = array[mid + 1 + i];

    int indexA, indexB;
    indexA = indexB = 0;   
    //Merge array[arrA .. arrB]
    while(indexA < sizeA && indexB < sizeB){
        if(arrA[indexA] <= arrB[indexB] || indexB == sizeB)
            array[indexC++] = arrA[indexA++];
        else  
            array[indexC++] = arrB[indexB++];
    }
    //add the remaining elements of arrA and arrB
    while(indexA < sizeA)
        array[indexC++] = arrA[indexA++];
    while(indexB < sizeB)
        array[indexC++] = arrB[indexB++];

    delete[] arrA;
    delete[] arrB;
}

//Divides array into 2 {Recursive}
void mergeSort(vector<int>& array, const int first, const int last){

    if(first >= last)
        return;

    int mid = first + (last - first)/2;

    mergeSort(array, first, mid);
    mergeSort(array, mid + 1, last);
    mergeArray(array, first, mid, last);
}

//Prints the array
void print(vector<int>& arr , int length, auto start, auto end){
    cout << "\n";
    for(int i = 0 ; i < length ; i++)
        cout << arr[i] << " ";

    cout << "\n~~Time analysis~~";
    cout << "\nIn nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns";
    cout << "\nIn microseconds : " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "µs";
    cout << "\nIn milliseconds : " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms";
    cout << "\n~~Time analysis~~";
}

int main(){

    vector<int> array;
    int size;

    cout << "Enter the size of array : ";
    cin >> size;

    cout << "Enter " << size << " elements : ";
    int temp;

    for(int i = 0 ; i < size ; i++){
        cin >> temp;
        array.push_back(temp);
    }

    int choice = 0;

    cout << "\n1] Merge sort\n2] Quick sort\n3] Exit \nEnter choice :";
    cin >> choice;
    auto start = chrono::steady_clock::now();

    switch(choice){
        case 1: {
            mergeSort(array, 0, size-1);
            auto end = chrono::steady_clock::now();
            print(array, size, start, end);
        }
			break;
        case 2: {
            quickSort(array, 0, size-1);
            auto end = chrono::steady_clock::now();
            print(array, size, start, end);
        }
			break;
        case 3: break;
        default: cout << "\nPlease enter a valid choice";
    }
}