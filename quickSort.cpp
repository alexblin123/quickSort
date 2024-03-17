#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

static void quickSort(int* arr, int startIndex, int endIndex) {

    if (startIndex < endIndex) {
        int leftIndex = startIndex, rightIndex = endIndex;
        int pivotElem = arr[(leftIndex + rightIndex) / 2];

        do {
            while (arr[leftIndex] < pivotElem) leftIndex++;
            while (arr[rightIndex] > pivotElem) rightIndex--;

            if (leftIndex <= rightIndex) {
                int tmp = arr[leftIndex];
                arr[leftIndex++] = arr[rightIndex];
                arr[rightIndex--] = tmp;
            }

        } while (leftIndex < rightIndex);
        quickSort(arr, startIndex, rightIndex);
        quickSort(arr, leftIndex, endIndex);
    }
    return;
}

int main() {

    srand(time(0));
    system("chcp 1251 > Null");

    const int SIZE = 25;

    int arr[SIZE]{};

    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 26 - 10;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    auto start = high_resolution_clock::now(); // засекаем время перед сортировкой

    quickSort(arr, 0, SIZE - 1);

    auto stop = high_resolution_clock::now(); // засекаем время после сортировки
    auto duration = duration_cast<microseconds>(stop - start); // вычисляем время выполнения

    cout << endl << "Массив после сортировки: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << endl << "Время выполнения программы (в микросекундах): " << duration.count() << endl; 

    return 0;

}
