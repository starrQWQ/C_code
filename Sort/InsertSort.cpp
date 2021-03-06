#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

#include<iostream>

#define NUM 10

using T = int;
void print(T arr[], int nNum);
void swap(T *a, T *b);
long getSystemTime();
void InsertSort(T arr[], int nNum)
{
	T i = 0, j = 0;
	for (i = 1; i < nNum; ++i)
	{
		if (arr[i] < arr[i - 1])
		{
			T min = arr[i];
			for (j = i- 1; 
				j >= 0 && min < arr[j];
				--j)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = min;
		}

	}
}


int main()
{
	int arr[NUM] = { 0 };
	long t_start = 0, t_end = 0;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < NUM; ++i)
	{
		arr[i] = rand() % 100;
	}

	print(arr,NUM);
	t_start = getSystemTime();
	InsertSort(arr, NUM);
	t_end = getSystemTime();
	print(arr, NUM);
	std::cout << "time:" << t_end - t_start << std::endl;
	return 0;
}


void swap(T *a, T *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}



void print(T arr[], int nNum)
{
	for (int i = 0; i < NUM; ++i)
	{
		std::cout << arr[i];
		std::cout << ",";
	}
	std::cout << "\b\n" << std::endl;
}

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}
