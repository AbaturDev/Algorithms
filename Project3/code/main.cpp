#include <iostream>
#include <initializer_list>
#include "AdjacencyList.hpp"
#include "AdjacencyMatrix.hpp"
#include "Test.hpp"

using namespace std;

int main()
{
    cout<<"~~~10 Vert~~~~"<<endl;
    measureMartix(10, 11, 20);
    measureMartix(10, 23, 20);
    measureMartix(10, 34, 20);
    measureMartix(10, 45, 20);

    cout<<"~~~50 Vert~~~~"<<endl;
    measureMartix(50, 306, 20);
    measureMartix(50, 613, 20);
    measureMartix(50, 919, 20);
    measureMartix(50, 1225, 20);

    cout<<"~~~100 Vert~~~~"<<endl;
    measureMartix(100, 1238, 20);
    measureMartix(100, 2475, 20);
    measureMartix(100, 3713, 20);
    measureMartix(100, 4950, 20);

    cout<<"~~~500 Vert~~~~"<<endl;
    measureMartix(500, 31188, 20);
    measureMartix(500, 62375, 20);
    measureMartix(500, 93563, 20);
    measureMartix(500, 124750, 20);

    cout<<"~~~1000 Vert~~~~"<<endl;
    measureMartix(1000, 124875, 20);
    measureMartix(1000, 249750, 20);
    measureMartix(1000, 374625, 20);
    measureMartix(1000, 499500, 20);

    return 0;
}