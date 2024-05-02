#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

const int MAX_SIZE = 1024 * 1024 * 100; // 100 MB

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void WriteToFile(int data[], long long size, const string& filename)
{
    ofstream file(filename);
    for (long long i = 0; i < size; i++)
    {
        file << data[i] << " ";
    }
    file.close();
}

int main()
{
    srand(time(0));

    const string inputFilename = "large_file.txt";
    const string outputFilename = "sorted_large_file.txt";
    const int fileSizeGB = 2;
    const long long numIntegers = (1024LL * 1024LL  * fileSizeGB) / sizeof(int);

    // Создаем временные файлы

    const int numFiles = numIntegers / MAX_SIZE + (numIntegers % MAX_SIZE != 0); // Вычисляем количество временных файлов
    for (int i = 0; i < numFiles; ++i) {
        ofstream tempFile("temp_" + to_string(i) + ".txt");
        if (!tempFile.is_open()) {
            cerr << "Error: Unable to create temp file: " << "temp_" + to_string(i) + ".txt" << endl;
            return 1;
        }

        long long remainingIntegers = min(numIntegers - i * MAX_SIZE, (long long)MAX_SIZE); // Оставшееся количество целых чисел для записи
        for (long long j = 0; j < remainingIntegers; j++)
        {
            int num = rand();
            tempFile << num << " ";
        }

        tempFile.close();
    }

    for (int i = 0; i < numFiles; ++i) // Сортируем каждый временный файл
    {
        ifstream tempFile("temp_" + to_string(i) + ".txt");
        if (!tempFile.is_open()) {
            cerr << "Error: Unable to open temp file for reading: " << "temp_" + to_string(i) + ".txt" << endl;
            return 1;
        }

        int* data = new int[MAX_SIZE];
        long long index = 0;
        int num;
        while (tempFile >> num && index < MAX_SIZE)
        {
            data[index++] = num;
        }
        tempFile.close();

        if (index == 0)
        {
            cerr << "Error: No data read from temp file: " << "temp_" + to_string(i) + ".txt" << endl;
            delete[] data;
            return 1;
        }

        quickSort(data, 0, index - 1);

        WriteToFile(data, index, "sorted_temp_" + to_string(i) + ".txt");

        delete[] data;
    }

    ofstream outputFile(outputFilename); // Объединяем отсортированные файлы
    for (int i = 0; i < numFiles; ++i)
    {
        ifstream sortedTempFile("sorted_temp_" + to_string(i) + ".txt");
        if (!sortedTempFile.is_open())
        {
            cerr << "Error: Unable to open sorted temp file for reading: " << "sorted_temp_" + to_string(i) + ".txt" << endl;
            return 1;
        }

        int num;
        while (sortedTempFile >> num)
        {
            outputFile << num << " ";
        }

        sortedTempFile.close();
    }
    outputFile.close();

    for (int i = 0; i < numFiles; ++i) // Удаляем временные файлы
    {
        if (remove(("temp_" + to_string(i) + ".txt").c_str()) != 0)
        {
            cerr << "Error: Unable to delete temp file: " << "temp_" + to_string(i) + ".txt" << endl;
        }
        if (remove(("sorted_temp_" + to_string(i) + ".txt").c_str()) != 0)
        {
            cerr << "Error: Unable to delete sorted temp file: " << "sorted_temp_" + to_string(i) + ".txt" << endl;
        }
    }

    cout << "Sorting and merging complete. Result saved in " << outputFilename << endl;

    return 0;
}
