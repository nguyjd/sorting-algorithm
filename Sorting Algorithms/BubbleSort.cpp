#include <vector>

void BubbleSort(std::vector<unsigned long long>& arr)
{

	bool inversion = true; 
	while (inversion)
	{ 
		inversion = false;
		for (int i = 0; i < (arr.size() - 1); i++)
		{ 
			if (arr.at(i) > arr.at(i + 1))
			{ 

				unsigned long long temp = arr.at(i);
				arr.at(i) = arr.at(i + 1);
				arr.at(i + 1) = temp;
				inversion = true;

			} 
		} 
	}

}