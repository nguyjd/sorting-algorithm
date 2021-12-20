#include <vector>
#include <algorithm>

void merge(std::vector<unsigned long long>& arr, std::vector<unsigned long long>& left, std::vector<unsigned long long>& right) {
	
	// Hold the index of the right and left index.
	int leftIndex = 0;
	int rightIndex = 0;

	// Loop through the enitre original array.
	for (int i = 0; i < arr.size(); i++)
	{

		// Test to see if element left in both arrays.
		if (leftIndex < left.size() && rightIndex < right.size())
		{

			// make comparison to see if inversion is needed.
			if ((left.at(leftIndex) <= right.at(rightIndex)))
			{

				// Set the value at the index of the main array.
				arr.at(i) = left.at(leftIndex);

				// Increment the index.
				leftIndex++;

			}
			else
			{

				// Set the value at the index of the main array.
				arr.at(i) = right.at(rightIndex);

				// Increment the index.
				rightIndex++;

			}

		} // Test to see if the left array has the remaining elements.
		else if (leftIndex < left.size())
		{

			// Set the value at the index of the main array.
			arr.at(i) = left.at(leftIndex);

			// Increment the index.
			leftIndex++;

		} // Test to see if the right array has the remaining elements.
		else if (rightIndex < right.size())
		{

			// Set the value at the index of the main array.
			arr.at(i) = right.at(rightIndex);

			// Increment the index.
			rightIndex++;

		}

	}

}

void MergeSort(std::vector<unsigned long long>& arr)
{

	// Base Case: When the array has a size of one. No inversion can be made.
	if (arr.size() <= 1)
	{

		return;

	}

	// Find the index of the midpoint main array.
	int midpoint = arr.size() / 2;

	// Two sub array to hold the split arrays.
	std::vector<unsigned long long> left(midpoint);
	std::vector<unsigned long long> right(arr.size() - midpoint);

	// Copy left half of the main array to the "left" array
	std::copy(arr.begin(), arr.begin() + midpoint, left.begin());

	// Copy right half of the main array to the "right" array
	std::copy(arr.begin() + midpoint, arr.end(), right.begin());

	MergeSort(left);
	MergeSort(right);
	merge(arr, left, right);

}