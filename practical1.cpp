#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int length)
{
    for(int i = 0 ; i < length-1 ; i++)
        for(int j = 1; j < length-i ; j++)
            if(arr[j-1]> arr[j]) swap(arr[j-1] , arr[j]);

}

void insertionSort(vector<int>& arr , int length){
    for(int i = 1; i < length ; i++){
        int temp = arr[i];
        int j=i-1;

        while(j >= 0){
            if(arr[j] > temp)
                arr[j+1] = arr[j];
            else
                break;
            j--;
        }
        arr[j+1] = temp;
    }
}

void selectionSort(vector<int>& arr , int length){
    for(int i = 0 ; i < length-1 ; i++){
        int min = i;

        for(int j = i+1 ; j < length ; j++){
            if(arr[j] < arr[min]) min = j; 
        }

        if(min != i)
            swap(arr[i],arr[min]);
    }
}

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

int main()
{
    vector<int> arr;
    int size , temp;
    cout << "\nEnter number of elements you want to sort : ";
    cin >> size;

    for(int i = 0 ; i < size ; i++){
        cin >> temp;
        arr.push_back(temp);
    }

    int ch = 0;
    cout << "\n1] Bubble sort\n2] Indertion sort\n3] Selection Sort\n4] Exit\nEnter choice :";
    cin >> ch;
    auto start = chrono::steady_clock::now();
    switch(ch){
        case 1: {
            bubbleSort(arr, size);
            auto end = chrono::steady_clock::now();
            print(arr, size, start, end);
            break;
        }
        case 2: {
            insertionSort(arr, size);
            auto end = chrono::steady_clock::now();
            print(arr, size, start, end);
            break;
         }   
        case 3: {
            selectionSort(arr, size);
            auto end = chrono::steady_clock::now();
            print(arr, size, start, end);
            break;
        }
        case 4:
            break;
        default:
            cout << "Error : Invalid choice. \n";
            break;
    }
}
