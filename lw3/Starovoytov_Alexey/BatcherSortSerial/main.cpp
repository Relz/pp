#include <iostream>
#include <omp.h>
#include <vector>

void batcherSort(std::vector<char> & array)
{
	size_t arraySize = array.size();
	for (size_t p = 1; p < arraySize; p += p)
	{
		for (size_t k = p; k > 0; k /= 2)
		{
			for (size_t j = k % p; j + k < arraySize; j += (k + k))
			{
				for (size_t i = 0; i < arraySize - j - k; ++i)
				{
					if ((j + i) / (p + p) == (j + i + k) / (p + p))
					{
						if (array[j + i + k] < array[j + i])
						{
							std::swap(array[j + i], array[j + i + k]);
						}
					}
				}
			}
		}
	}
}

void PrintCharactersOut(std::vector<char> const & characters)
{
	for (char character : characters)
	{
		std::cout << character << " ";
	}
}

int main()
{
	std::vector<char> characters {'D', 'A', 'B', 'Z', 'F', 'C', 'A', 'B', 'X', 'Z', 'Y'};

	batcherSort(characters);
	PrintCharactersOut(characters);

	return EXIT_SUCCESS;
}
