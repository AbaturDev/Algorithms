#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <vector>
using namespace std;

struct Movie
{
	int index;
	string title;
	float rank;
};

class Vector 
{
private:
	vector<Movie> MovieVector;
	bool sorted;
	
public:
	/**
	 * Constructor
	 * @param s - set false for sorted variable  
	*/
	Vector(bool s = false);

	/**
	 * Method to upload date from the .csv file to the MovieVector 
	 * @param size - declares how many elements to upload
	*/
	void Upload(int size);

	/**
	 * Method to print all elements in the MovieVector 
	*/
	void display();

	/**
	 * Method to count mean of the elements ranking
	 * @return mean
	*/
	float mean();

	/**
	 * Method to find the median of the elements ranking
	 * @return median
	*/
	float median();

	/**
	 * Method to run merge sort algorithm
	 * Set sorted variable as a true
	*/
	void run_mergeSort();

	/**
	 * Method to run quicksort algorithm
	 * Set sorted variable as a true
	*/
	void run_quickSort();

	/**
	 * Method to run bucket sort algorithm
	 * Set sorted variable as a true
	*/
	void run_bucketSort();

private:
	//-------merge sort-------
	/**
	 * Method to merge two subbarrays(subbvectors)
	 * @param MV - vector to sort
	 * @param left - index of the leftmost element
	 * @param mid - index of the middle element
	 * @param right - index of the rightmost element
	*/
	void merge(vector<Movie>& MV, int left, int mid, int right);

	/**
	 * Recursive method to perform merge sort on vector
	 * @param MV - vector to sort
	 * @param left - index of the leftmost element
	 * @param right - index of the rightmost element
	*/
	void mergeSort(vector<Movie>& MV, int left, int right);

	//-------quicksort-------
	/**
	 * Method to partition the movie vector MV into intervals for the quicksort algorithm
	 * Chose pivot alaways as a middle element
	 * @param MV - vector to sort
	 * @param low - lowest index
	 * @param high - highst index
	 * @return index of the pivot
	*/
	int partiton(vector<Movie>& MV, int low, int high);

	/**
	 * Recursive method to perform quicksort on vector
	 * @param MV - vector to sort
	 * @param low - lowest index
	 * @param high - highst index
	*/
	void quickSort(vector<Movie>& MV, int low, int high);

	//-------bucket sort-------
	/**
	 * Method to perform bucket sort algorithm
	 * @param MV - vector to sort
	*/
	void bucketsort(vector<Movie>& MV);

	/**
	 * Method to get maximum rankking value of the vector MV
	 * @param MV - vector to serach for the value
	 * @return max rank value
	*/
	float getMax(vector<Movie>& MV);

	/**
	 * Method to get minimum rankking value of the vector MV
	 * @param MV - vector to serach for the value
	 * @return min rank value
	*/
	float getMin(vector<Movie>& MV);

	/**
	 * Insertion sort algorithm
	 * @param B - vector to sort
	*/
	void insertionsort(vector<Movie>& B);
};

#endif