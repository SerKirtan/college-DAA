#include<bits/stdc++.h>
using namespace std;

void iterativeFactorial(int num, int factorial = 1)
{
    for(int i = 2 ; i <= num ; i++) 
        factorial *= i;

    cout << "\nFactorial (iterartive) : " << factorial; 
}

void recursiveFactorial(int num , int factorial = 1)
{
    if(num == 1)
    {
        cout << "\n\nFactorial (recursive) : " << factorial; 
        return;
    }
    recursiveFactorial(num - 1 , factorial * num);
}

int main()
{
    int num;
    cout << "Enter number to find factorial : ";
    cin >> num;

    auto start = chrono::steady_clock::now();
    iterativeFactorial(num);
    auto end = chrono::steady_clock::now();
    cout << "\nTime analysis of iterative : " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << "ns";

    start = chrono::steady_clock::now();
    recursiveFactorial(num);
    end = chrono::steady_clock::now();

    cout << "\nTime analysis of recursive : " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << "ns";
}
