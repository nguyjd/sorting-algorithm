#include <vector>
#include <chrono>
#include <iostream>


void RadixSortDriver(std::vector<unsigned long long>& arr, int digits)
{

	for (int i = digits; i > 0; i--)
	{

		std::vector<std::vector<unsigned long long>> groups(10);
		std::vector<int> counters(10, 0);

		unsigned long long powerOfTen = 1;

		for (unsigned long long l = 1; l < i; l++)
		{

			powerOfTen = powerOfTen * 10;

		}

		for (int j = 0; j < arr.size(); j++)
		{
			int k;
			if (i > 1)
			{

				k = (arr.at(j) / powerOfTen) % (powerOfTen / 10);

			}
			else
			{

				k = arr.at(j) % 10;

			}

			groups.at(k).push_back(arr.at(j));
			counters.at(k)++;

		}

	}

}

void RadixSort(std::vector<unsigned long long>& arr)
{

	auto startDigitCount = std::chrono::steady_clock::now();

	int maxDigits = 0;
	for (int i = 0; i < arr.size(); i++)
	{

		int digitCount = 0;
		unsigned long long num = arr.at(i);

		// Count until no more digits.
		while (num != 0)
		{

			// Strip the least signifcant digit.
			num = num / 10;
			// Add one to the count.
			digitCount++;

		}

		if (digitCount > maxDigits)
		{

			maxDigits = digitCount;

		}

	}

	auto endDigitCount = std::chrono::steady_clock::now();


	auto startSort = std::chrono::steady_clock::now();

	RadixSortDriver(arr, maxDigits);

	auto endSort = std::chrono::steady_clock::now();

	auto runtimeDigitCount = std::chrono::duration_cast<std::chrono::milliseconds>(endDigitCount - startDigitCount).count();
	std::cout << "Radix Sort (Finding Max Digits): time taken in milliseconds " << runtimeDigitCount << " ms" << std::endl;
	auto runtimeSort = std::chrono::duration_cast<std::chrono::milliseconds>(endSort - startSort).count();
	std::cout << "Radix Sort (Sorting): time taken in milliseconds " << runtimeSort << " ms" << std::endl;
	auto runtimeOverall = std::chrono::duration_cast<std::chrono::milliseconds>(endSort - startDigitCount).count();
	std::cout << "Radix Sort (Overall): time taken in milliseconds " << runtimeOverall << " ms" << std::endl;

}