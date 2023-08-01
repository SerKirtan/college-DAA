#include<bits/stdc++.h>
using namespace std;

void linearSearch(int arr[] , int size, int sElement, auto start)
{
    bool check = false;
    for(int i = 0 ; i < size ; i++)
    {
        if(arr[i] == sElement){
            cout << endl << sElement << " found at index " << i;
            check = true;
            break;
        }

    }
    if(!check)
        cout << "\nElement not in the array";
    auto end = chrono::steady_clock::now();
    cout << "\n~~Time analysis~~";
    cout << "\nIn nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns";
    cout << "\nIn microseconds : " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "µs";
    cout << "\n~~Time analysis~~";
}

void binarySearch(int arr[] , int low, int high, int sElement, auto start) 
{
    bool check = false;
    while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == sElement) // element found
    {
        check = true;
        cout << endl << sElement << " found at index " << mid;
        break;
    }

    if (arr[mid] < sElement) // go right if array element is smaller
      low = mid + 1;
    else                // go left if array element is larger
      high = mid - 1;
  }
    if(!check)
        cout << "\nElement not in the array";
    auto end = chrono::steady_clock::now();
    cout << "\n~~Time analysis~~";
    cout << "\nIn nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << "ns";
    cout << "\nIn microseconds : " << chrono::duration_cast<chrono::microseconds>(end - start).count() << "µs";
    cout << "\n~~Time analysis~~";
}

int main()
{
    int arr[] = {11, 21, 27, 30, 65, 71, 75, 89, 91 , 97};
    int size = sizeof(arr)/sizeof(int);

    cout << "Array elements :";
    for(int i = 0 ; i < size ; i++)
        cout << " " << arr[i];

    int searchElement;
    cout << "\nWhich element do you want to search in the array : ";
    cin >> searchElement;

    int ch = 0;
    cout << "\n1] Linear search\n2] Binary search\n3] Exit\nEnter choice : ";
    cin >> ch;

    auto start = chrono::steady_clock::now();
    switch(ch)
    {
    case 1:
        linearSearch(arr, size, searchElement, start);
        break;
    case 2:
        binarySearch(arr, 0, size-1, searchElement, start);
        break;
    case 3:
        break;
    default:
        cout << "\nInvalid input";
    }

}
