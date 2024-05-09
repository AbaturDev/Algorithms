#include <iostream>
#include "vector.h"
#include <chrono>
using namespace chrono;
using namespace std;

int main()
{
    int x = 100000;

    Vector a;
    a.Upload(x);
    a.run_mergeSort();
    //a.display();
    //cout << endl;

    Vector b;
    b.Upload(x);
    b.run_quickSort();
    //b.display();
    //cout << endl;

    cout <<"Mean:   \t" << a.mean() <<"\t" <<b.mean() <<endl;
    cout <<"Median: \t" << a.median() <<"\t" << b.median() << endl;

    /*
    auto start = high_resolution_clock::now();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout << duration.count() << endl;
    */
    return 0;
}

