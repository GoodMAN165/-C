#include <iostream>
#include <vector>
using namespace std;

//Вывод массива
void printArray(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//Перестановка значений двух переменных
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Сортировка пузырьком
void bubbleSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1])

                swap(arr[j], arr[j + 1]);
        }
    }
}

//Сортировка выбором
void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        int min_idx = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        swap(arr[i], arr[min_idx]);
    }
}

//Сортировка вставками
void insertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");

    short userInput;
    int arrayLeng;

    cout << "Введите желаемую длинну массива: ";
    cin >> arrayLeng;

    vector<int> list(arrayLeng);

    for (int i = 0; i < arrayLeng; i++) {
        list[i] = rand() % 100 + 1;
    }

    printArray(list);

    cout << "\n\
    Выберит метод сортировки массива: \n\
    1 - Сортировка пузырьком \n\
    2 - Сортировка выбором \n\
    3 - Сортировка вставкой \n\n";
    cin >> userInput;

    switch (userInput) {
    case 1:
        bubbleSort(list);
        break;
    case 2:
        selectionSort(list);
        break;
    case 3:
        insertionSort(list);
        break;
    default:
        cout << "Ошибка!";
        break;
    }

    printArray(list);

    return 0;
}