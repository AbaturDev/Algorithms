#include <iostream>
#include "vector.h"
#include <chrono>
using namespace chrono;
using namespace std;

int main()
{
    int x = 10000;

    Vector a;
    a.Upload(x);
    auto start = high_resolution_clock::now();
    a.run_bucketSort();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    cout <<"Mean:   \t" << a.mean() << endl;
    cout <<"Median: \t" << a.median() << endl;
    return 0;
}

