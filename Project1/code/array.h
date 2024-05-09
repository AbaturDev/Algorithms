#pragma once
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

template <class T>
struct Packet{
    T data;
    int number;
};

template <class T>
class Array{
private:
    Packet<T>* array;
    int capacity;
    int size;

public:
    Array(int capacity = 5);
    /*
    * Constructor - creats array, set size and capacity
    * @param capacity - default capacity of an array
    */

    ~Array();
    /*
    * Destructor - delete array, unlock memory
    */

    int getSize();
    /*
    * Method to get size of array
    * @retrun size
    */

    int getCapacity();
    /*
    * Method to get cacpacity of array
    * @return capcaity
    */

    void display();
    /*
    * Method to print elements of array
    */

    void add(int n, T value);
    /*
    * Method to add packet at the end of array
    * @param n - number of packet
    * @param value - value of element in the packet
    */

    string getMessage();
    /*
    * Method to convert array to one string message
    * @return string, concatenated message
    */

    void sort();
    /*
    * Method to call the mergSort method with proper arguments
    */

    void shuffle();
    /*
    * Method to shuffle the array
    */


private:
    void mergeSort(Packet<T>* arr, int left, int right);
    /*
    * Recursive method to perform merge sort on an array
    * @param arr - array to sort
    * @param left - index of leftmost element of the array
    * @param right - index of rightmost element of the array
    */


    void merge(Packet<T>* arr, int left, int mid, int right);
    /*
    * Method to merge two subbarrays
    * @param arr - array to sort
    * @param left - index of leftmost element of the array
    * @param mid - index of the middle element
    * @param right - index of the rightmost element of the array
    */

    void realloc(); 
    /*
    * Method to realloc memory when capacity is full
    * Method increas capacity 2 times and copy array to new array
    */

    bool isUsed(int n);
    /*
    * Method to check if number of packet is already used
    * @return True - is used
    * @return False - is not used
    */

    bool isEmpty();
    /*
    * Method to check if array is empty
    * @return True - array is empty, 
    * @return False -  is not empty
    */
};

template <class T>
ostream& operator<<(ostream& os, const Packet<T>& packet);
/*
* Overloaded stream insertion operator to print the data of a Packet object
* Function to facilitate the use of the getMessage method
* @param os - the output stream
* @param packet - the Packet object to print
* @return ostream& - the output stream
*/


//------------Code implementation------------------------

template <class T>
ostream& operator<<(ostream& os, const Packet<T>& packet) 
{
    os << packet.data;
    return os;
}

template <class T>
Array<T>::Array(int capacity)
{
    array = new Packet<T>[capacity];
    this->capacity = capacity;
    size = 0;
}

template <class T>
Array<T>::~Array()
{
    delete [] array;    
}

template <class T>
bool Array<T>::isEmpty()
{
    if(size == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

template <class T>
int Array<T>::getSize()
{
    return size;
}

template <class T>
int Array<T>::getCapacity()
{
    return capacity;
}

template <class T>
void Array<T>::add(int n,T value)
{
    if(size==capacity)
    {
        realloc();
    }
    if(isUsed(n)==true)
    {
        cout<<"Number of packet is already used"<<endl;
    }
    else
    {
        array[size].number = n; 
        array[size].data = value;
        size++;
    }
}

template <class T>
void Array<T>::realloc()
{
    capacity = capacity * 2;
    Packet<T> *newArray = new Packet<T>[capacity];
    for(int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }
    delete [] array;
    array = newArray;
}

template <class T>
void Array<T>::display()
{
    cout<<"Capacity: "<<getCapacity()<<endl;
    cout<<"Size: "<<getSize()<<endl;
    if(isEmpty()==true)
    {
        cout<<"Array is empty"<<endl;
    }
    else
    {
        cout<<"Elements of array"<<endl;
        for(int i=0; i<size; i++)
            {
                cout << array[i].data<<" ";
            }
        cout<<endl;
    }
}

template <class T>
bool Array<T>::isUsed(int n)
{
    for(int i=0; i<size; i++)
    {
        if(n==array[i].number)
        {
            return true;
        }
    }
    return false;
}

template <class T>
string Array<T>::getMessage()
{
    ostringstream convert;
    if(isEmpty()==true)
    {
        return "";
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            convert << array[i];
        }
        string message = convert.str();
        return message;
    }
}

template <class T>
void Array<T>::shuffle()
{
    Packet<T> temp;
    int random = 0;

    for(int i=0; i<size; i++)
    {
        random = rand() % size;

        temp = array[i];
        array[i] =  array[random];
        array[random]=temp;
    }
}

template <class T>
void Array<T>::mergeSort(Packet<T>* arr, int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

template <class T>
void Array<T>::merge(Packet<T>* arr, int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;

    Packet<T>* leftArray = new Packet<T>[size1];
    Packet<T>* rightArray = new Packet<T>[size2];

    for (int i = 0; i < size1; i++) {
        leftArray[i] = arr[left + i];
    }

    for (int j = 0; j < size2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;

    while (i < size1 && j < size2) {
        if (leftArray[i].number <= rightArray[j].number)
        {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < size2){
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;

}

template <class T>
void Array<T>::sort()
{
    mergeSort(array, 0, size - 1);
}

#endif