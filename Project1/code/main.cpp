#include <iostream>
#include "array.h"
#include <chrono>
using namespace chrono;
using namespace std;

int main()
{
    Array<int> a;
    //adding elements
    for (int i = 0; i < 1000; i++)
    {
        int random = rand() % 10;
        a.add(i, random);
    }
    a.shuffle();    //shuffling array

    //sorting
    auto start1 = high_resolution_clock::now();
    a.sort();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1);
    cout << "Time for sorting: " << duration1.count() << endl;

    //getting message
    auto start2 = high_resolution_clock::now();
    a.getMessage();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);
    cout << "Time for getting message: " << duration2.count() << endl;
    
    return 0;
}