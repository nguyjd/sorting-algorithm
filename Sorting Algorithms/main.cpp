#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <time.h>

void BubbleSort(std::vector<unsigned long long>& arr);
void SelectionSort(std::vector<unsigned long long>& arr);
void InsertionSort(std::vector<unsigned long long>& arr);
void MergeSort(std::vector<unsigned long long>& arr);
void QuickSort(std::vector<unsigned long long>& arr);
void RadixSort(std::vector<unsigned long long>& arr);

void compare(std::vector<unsigned long long>& correctArray, std::vector<unsigned long long>& myArray)
{ 

	std::cout << "Comparing the two vector." << std::endl;

	bool sameVector = true;

	for (int i = 0; i < correctArray.size(); i++)
	{

		if (correctArray.at(i) != myArray.at(i))
		{

			sameVector = false;
			break;

		}

	}

	if (sameVector)
	{

		std::cout << "The two vector are the same." << std::endl;

	}
	else
	{

		std::cout << "The two vector are not the same." << std::endl;

	}

}

int main()
{

	const int SIZE = 10000000000;


	std::cout << "Generating unsigned long long numbers." << std::endl;
	std::vector<unsigned long long> randomULLong;
	std::default_random_engine generatorULL;
	generatorULL.seed(time(0));
	std::uniform_int_distribution<unsigned long long> distributionULL(0, ULLONG_MAX);
	for (int i = 0; i < SIZE; i++)
	{ 
		
		randomULLong.push_back(distributionULL(generatorULL));
	
	}
	std::cout << "Finished generating unsigned long long numbers." << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Generating int numbers." << std::endl;
	std::vector<unsigned long long> randomInt;
	std::default_random_engine generatorInt;
	generatorInt.seed(time(0));
	std::uniform_int_distribution<unsigned long long> distributionInt(0, INT_MAX);
	for (int i = 0; i < SIZE; i++)
	{

		randomInt.push_back(distributionInt(generatorInt));

	}
	std::cout << "Finished generating int numbers." << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Creating the vectors." << std::endl;
	std::vector<unsigned long long> BubbleSortArrULL(SIZE), SelectionSortArrULL(SIZE), InsertionSortArrULL(SIZE), MergeSortArrULL(SIZE), QuickSortArrULL(SIZE), RadixSortArrULL(SIZE);
	std::vector<unsigned long long> BubbleSortArrInt(SIZE), SelectionSortArrInt(SIZE), InsertionSortArrInt(SIZE), MergeSortArrInt(SIZE), QuickSortArrInt(SIZE), RadixSortArrInt(SIZE);

	std::cout << "Copying the random number to the vectors." << std::endl;
	std::copy(randomULLong.begin(), randomULLong.end(), BubbleSortArrULL.begin());
	std::copy(randomULLong.begin(), randomULLong.end(), SelectionSortArrULL.begin());
	std::copy(randomULLong.begin(), randomULLong.end(), InsertionSortArrULL.begin());
	std::copy(randomULLong.begin(), randomULLong.end(), MergeSortArrULL.begin());
	std::copy(randomULLong.begin(), randomULLong.end(), QuickSortArrULL.begin());
	std::copy(randomULLong.begin(), randomULLong.end(), RadixSortArrULL.begin());

	std::copy(randomInt.begin(), randomInt.end(), BubbleSortArrInt.begin());
	std::copy(randomInt.begin(), randomInt.end(), SelectionSortArrInt.begin());
	std::copy(randomInt.begin(), randomInt.end(), InsertionSortArrInt.begin());
	std::copy(randomInt.begin(), randomInt.end(), MergeSortArrInt.begin());
	std::copy(randomInt.begin(), randomInt.end(), QuickSortArrInt.begin());
	std::copy(randomInt.begin(), randomInt.end(), RadixSortArrInt.begin());
	std::cout << "Finished copying the random number to the vectors." << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Sorting the random vectors." << std::endl;
	std::sort(randomULLong.begin(), randomULLong.end());
	std::sort(randomInt.begin(), randomInt.end());
	std::cout << "Finished sorting the random vectors." << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Starting Timing Test for unsigned long long numbers." << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	if (20000 >= SIZE)
	{
	
		std::cout << "Starting Bubble Sort." << std::endl;
		compare(randomULLong, BubbleSortArrULL);
		auto start = std::chrono::steady_clock::now();
		BubbleSort(BubbleSortArrULL);
		auto end = std::chrono::steady_clock::now();
		auto runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		std::cout << "Bubble Sort: time taken in milliseconds " << runtime << " ms" << std::endl;
		compare(randomULLong, BubbleSortArrULL);

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Starting Selection Sort." << std::endl;
		compare(randomULLong, SelectionSortArrULL);
		start = std::chrono::steady_clock::now();
		SelectionSort(SelectionSortArrULL);
		end = std::chrono::steady_clock::now();
		runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		std::cout << "Selection Sort: time taken in milliseconds " << runtime << " ms" << std::endl;
		compare(randomULLong, SelectionSortArrULL);

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Starting Insertion Sort." << std::endl;
		compare(randomULLong, InsertionSortArrULL);
		start = std::chrono::steady_clock::now();
		InsertionSort(InsertionSortArrULL);
		end = std::chrono::steady_clock::now();
		runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		std::cout << "Insertion Sort: time taken in milliseconds " << runtime << " ms" << std::endl;
		compare(randomULLong, InsertionSortArrULL);

		std::cout << std::endl;
		std::cout << std::endl;


	}
	else
	{

		std::cout << "Skipping Bubble Sort. (SIZE > 20000)" << std::endl;
		std::cout << "Skipping Selection Sort. (SIZE > 20000)" << std::endl;
		std::cout << "Skipping Insertion Sort. (SIZE > 20000)" << std::endl;

		std::cout << std::endl;
		std::cout << std::endl;

	}

	std::cout << "Starting Merge Sort." << std::endl;
	compare(randomULLong, MergeSortArrULL);
	auto start = std::chrono::steady_clock::now();
	MergeSort(MergeSortArrULL);
	auto end = std::chrono::steady_clock::now();
	auto runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "Merge Sort: time taken in milliseconds " << runtime << " ms" << std::endl;
	compare(randomULLong, MergeSortArrULL);
	
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Starting Quick Sort." << std::endl;
	compare(randomULLong, QuickSortArrULL);
	start = std::chrono::steady_clock::now();
	QuickSort(QuickSortArrULL);
	end = std::chrono::steady_clock::now();
	runtime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << "Quick Sort: time taken in milliseconds " << runtime << " ms" << std::endl;
	compare(randomULLong, QuickSortArrULL);

	std::cout << std::endl;
	std::cout << std::endl;

	/*
	std::cout << "Starting Radix Sort." << std::endl;
	compare(randomULLong, RadixSortArrULL);
	RadixSort(RadixSortArrULL);
	compare(randomULLong, RadixSortArrULL);

	std::cout << std::endl;
	std::cout << std::endl;
	*/

	std::cout << "Ending Timing Test for unsigned long long numbers." << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;

}