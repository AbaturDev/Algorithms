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

private:
	void merge(vector<Movie>& MV, int left, int mid, int right);
	void mergeSort(vector<Movie>& MV, int left, int right);

	int partiton(vector<Movie>& MV, int low, int high);
	void quickSort(vector<Movie>& MV, int l, int h);
};

#endif