#include <vector>

void SelectionSort(std::vector<unsigned long long>& arr)
{

	for (int i = 0; i < arr.size() - 1; i++)
	{

		int index = i;
		for (int currentIndex = i + 1; currentIndex < arr.size(); currentIndex++)
		{

			if (arr.at(currentIndex) < arr.at(index))
			{

				index = currentIndex;

			}

		}

		if (index != i)
		{

			unsigned long long temp = arr.at(index);
			arr.at(index) = arr.at(i);
			arr.at(i) = temp;

		}


	}

}