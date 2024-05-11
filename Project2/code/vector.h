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
	
public:

	void Upload(int size);
	void display();
	float mean();
	float median();
	void run_mergeSort();
	void run_quickSort();
	void run_bucketSort();

private:
	//merge sort
	void merge(vector<Movie>& MV, int left, int mid, int right);
	void mergeSort(vector<Movie>& MV, int left, int right);

	//quicksort
	int partiton(vector<Movie>& MV, int low, int high);
	void quickSort(vector<Movie>& MV, int l, int h);

	//bucket sort
	void bucketsort(vector<Movie>& MV);
	float getMax(vector<Movie>& MV);
	float getMin(vector<Movie>& MV);
	void insertionsort(vector<Movie>& B);
};

#endif