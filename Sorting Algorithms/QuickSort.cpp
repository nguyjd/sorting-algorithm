#include <vector>

int partition(std::vector<unsigned long long>& arr, int beginningIndex, int endIndex)
{

	int pivotIndex = beginningIndex - 1;
	unsigned long long pivotValue = arr.at(endIndex);
	
	for (int i = beginningIndex; i < endIndex; i++)
	{

		if (arr.at(i) < pivotValue)
		{

			pivotIndex++;
			unsigned long long temp = arr.at(pivotIndex);
			arr.at(pivotIndex) = arr.at(i);
			arr.at(i) = temp;

		}

	}

	arr.at(endIndex) = arr.at(pivotIndex + 1);
	arr.at(pivotIndex + 1) = pivotValue;

	return pivotIndex;

}

void QuickSortDriver(std::vector<unsigned long long>& arr, int beginningIndex, int endIndex)
{
	
	if (beginningIndex < endIndex)
	{

		int pivotIndex = partition(arr, beginningIndex, endIndex);

		QuickSortDriver(arr, beginningIndex, pivotIndex);
		QuickSortDriver(arr, pivotIndex + 1, endIndex);

	}

}

void QuickSort(std::vector<unsigned long long>& arr)
{

	QuickSortDriver(arr, 0, arr.size() - 1);

}