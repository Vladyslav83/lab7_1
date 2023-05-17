#include <iostream>
#include <cstring>

template<typename T>
void findMaxValues(const T* arr, int size, T& maxValue, int& count)
{
    if (size <= 0)
    {
        std::cout << "Error: Invalid array size." << std::endl;
        return;
    }

    maxValue = arr[0];
    count = 1;

    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
            count = 1;
        }
        else if (arr[i] == maxValue)
        {
            count++;
        }
    }
}

// Specialization for char*
template<>
void findMaxValues(const char* const* arr, int size, const char*& maxValue, int& count)
{
    if (size <= 0)
    {
        std::cout << "Error: Invalid array size." << std::endl;
        return;
    }

    maxValue = arr[0];
    count = 1;

    for (int i = 1; i < size; ++i)
    {
        if (std::strcmp(arr[i], maxValue) > 0)
        {
            maxValue = arr[i];
            count = 1;
        }
        else if (std::strcmp(arr[i], maxValue) == 0)
        {
            count++;
        }
    }
}

int main()
{
    int intArray[] = { 3, 1, 5, 2, 5, 5 };
    int intMaxValue;
    int intMaxCount;

    findMaxValues(intArray, sizeof(intArray) / sizeof(int), intMaxValue, intMaxCount);
    std::cout << "Max value: " << intMaxValue << std::endl;
    std::cout << "Count: " << intMaxCount << std::endl;

    const char* stringArray[] = { "apple", "banana", "cherry", "banana", "banana" };
    const char* stringMaxValue;
    int stringMaxCount;

    findMaxValues(stringArray, sizeof(stringArray) / sizeof(const char*), stringMaxValue, stringMaxCount);
    std::cout << "Max value: " << stringMaxValue << std::endl;
    std::cout << "Count: " << stringMaxCount << std::endl;

    return 0;
}
