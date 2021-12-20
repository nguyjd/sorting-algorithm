#include <vector>

void InsertionSort(std::vector<unsigned long long>& arr)
{

	for (int i = 1; i < arr.size(); i++)
	{
		
		unsigned long long temp = arr.at(i);
		int index = i;

		while ((index > 0) && (arr.at(index - 1) > temp))
		{
			
			arr.at(index) = arr.at(index - 1);
			index--;

		}

		arr.at(index) = temp;

	}

}