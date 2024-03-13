#include <stdio.h>
#include <stdlib.h>

void sort_even_before_odd(int *arr, int size)
{
	int arr1[size];
	int arr2[size];

	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			arr1[count1] = arr[i];
			count1++;
		}
		else
		{
			arr2[count2] = arr[i];
			count2++;
		}
	}

	//buble sort O(n^2)
	for(int i = 0; i < count1; i++)
	{
		for(int j = 0; j < count1-i-1; j++)
		{
			if(arr1[j] > arr1[j+1])
			{
				int temp = arr1[j];
				arr1[j] = arr1[j+1];
				arr1[j+1] = temp;
			}
		}
	}

	for(int i = 0; i < count2; i++)
	{
		for(int j = 0; j < count2-i-1; j++)
		{
			if(arr2[j] < arr2[j+1])
			{
				int temp = arr2[j];
				arr2[j] = arr2[j+1];
				arr2[j+1] = temp;
			}
		}
	}


	for(int i = 0; i < count1; i++)
	{
		arr[i] = arr1[i];
	}
	for(int i = 0; i < count2; i++)
	{
		arr[i+count1] = arr2[i];
	}
}

int main()
{
	int arr[] = {57, 24, 86, 12, 41, 93, 68, 35, 79, 5};
	int size = 10;
	sort_even_before_odd(arr, size);
	for(int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
