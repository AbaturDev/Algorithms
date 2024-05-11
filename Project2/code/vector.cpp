#include "vector.h"
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>

Vector::Vector(bool s) : sorted(s)
{
}

void Vector::Upload(int size)
{
	if (size <= 0)
	{
		return;
	}

	ifstream File;
	File.open("projekt2_dane.csv");
	if (File.is_open())
	{
		string line;
		bool firstLine = true;

		while (getline(File, line) && MovieVector.size() < size)
		{
			if (firstLine == true)
			{
				firstLine = false;
				continue;
			}

			stringstream ss(line);
			string index_str, movie, rank_str;
			
			getline(ss, index_str, ',');
			getline(ss, movie, ',');
			while (movie.front() == '"')
			{
				string temp;
				if (movie.back() == '"')
				{
					break;
				}
				getline(ss, temp, ',');
				movie = movie + "," + temp;
			}

			getline(ss, rank_str, ',');

			if (rank_str.empty())
			{
				continue;
			}

			Movie tempMovie;

			tempMovie.index = stoi(index_str);
			tempMovie.title = movie;
			tempMovie.rank = stof(rank_str);

			MovieVector.push_back(tempMovie);
		}
		File.close();
	}
}

void Vector::display()
{
	for (int i = 0; i < MovieVector.size(); i++)
	{
		cout << MovieVector.at(i).index << " " << MovieVector.at(i).title << " " << MovieVector.at(i).rank << endl;
	}
}

void Vector::mergeSort(vector<Movie>& MV, int left, int right)
{
	if (left >= right) return;

	int mid = left + (right - left) / 2;
	mergeSort(MV, left, mid);
	mergeSort(MV, mid + 1, right);
	merge(MV, left, mid, right);
}


void Vector::merge(vector<Movie>& MV, int left, int mid, int right)
{
	int size1 = mid - left + 1;
	int size2 = right - mid;

	vector<Movie> L(size1);
	vector<Movie> R(size2);

	for (int i = 0; i < size1; i++) {
		L[i] = MV[left + i];
	}

	for (int j = 0; j < size2; j++) {
		R[j] = MV[mid + 1 + j];
	}
	int i = 0;
	int j = 0;
	int k = left;

	while (i < size1 && j < size2) {
		if (L[i].rank <= R[j].rank)
		{
			MV[k] = L[i];
			i++;
		}
		else {
			MV[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < size1) {
		MV[k] = L[i];
		i++;
		k++;
	}

	while (j < size2) {
		MV[k] = R[j];
		j++;
		k++;
	}
}

void Vector::run_mergeSort()
{
	mergeSort(MovieVector, 0, MovieVector.size() - 1);

	sorted = true;
}

float Vector::mean()
{
	float sum = 0;
	for (int i = 0; i < MovieVector.size(); i++)
	{
		sum += MovieVector.at(i).rank;
	}
	return sum / MovieVector.size();
}

float Vector::median()
{
	if(sorted == false)
	{
		throw runtime_error("Unsorted data!");
	}
	
	if (MovieVector.size() % 2 == 0)
	{
		float median = (MovieVector.at(MovieVector.size() / 2).rank + MovieVector.at((MovieVector.size() / 2)-1).rank)/2;
		return median;
	}
	else
	{
		return MovieVector.at(MovieVector.size() / 2).rank;
	}
}

int Vector::partiton(vector<Movie>& MV, int low, int high)
{
	Movie pivot = MV[(low+high)/2];
	
	int i = low;
	int j = high;

	while (i < j)
	{
		while (MV[i].rank < pivot.rank)
		{
			i++;
		}
		while (MV[j].rank > pivot.rank)
		{
			j--;
		}
		if (i < j)
		{
			swap(MV[i], MV[j]);
			i++;
			j--;
		}
	}
	return j;
}

void Vector::quickSort(vector<Movie>& MV, int low, int high)
{
	if (low >= high)
	{
		return;
	}
	int j = partiton(MV, low, high);
	quickSort(MV, low, j);
	quickSort(MV, j+1, high);
}

void Vector::run_quickSort()
{
	quickSort(MovieVector, 0, MovieVector.size() - 1);

	sorted = true;
}

float Vector::getMax(vector<Movie>& MV)
{
	float max = 0;
	for(int i = 0; i < MV.size(); i++)
	{
		if(max < MV.at(i).rank)
		{
			max = MV.at(i).rank;
		}
	}
	return max;
}

float Vector::getMin(vector<Movie>& MV)
{
	float min = MV.at(0).rank;
	for(int i = 0; i < MV.size(); i++)
	{
		if(min > MV.at(i).rank)
		{
			min = MV.at(i).rank;
		}
	}
	return min;
}

void Vector::insertionsort(vector<Movie>& B)
{
	for(int i = 0; i<B.size(); i++)
	{
		Movie temp = B[i];
		int j = i - 1;
		while(j >= 0 && temp.rank < B.at(j).rank)
		{
			B[j+1] = B[j];
			j--;
		}
		B[j+1] = temp;
	}
}

void Vector::bucketsort(vector<Movie>& MV)
{
	float max = getMax(MV);
	float min = getMin(MV);
	int bucket =  max - min + 1;
	int j = 0;

	vector<Movie> B[bucket];

	for(int i = 0; i < MV.size(); i++)
	{
		j = MV.at(i).rank - min;
		B[j].push_back(MV[i]);
	}
	
	for(int i = 0; i<bucket; i++)
	{
		insertionsort(B[i]);
	}

	int index = 0;
	for(int i = 0; i < bucket; i++)
	{
		for(int j = 0; j < B[i].size(); j++)
		{
			MV[index] = B[i][j];
			index++;
		}
	} 
}

void Vector::run_bucketSort()
{
	bucketsort(MovieVector);

	sorted = true;
}