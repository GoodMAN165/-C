#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <string>

using namespace std;

// 1. Функция для заполнения массива случайными числами
void fillRandom(vector<int>& arr, int minVal = 1, int maxVal = 100) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minVal, maxVal);

    for (int& num : arr) {
        num = dist(gen);
    }
}

// 2. Функция для вывода массива
void printArray(const vector<int>& arr, const string& message = "Массив:") {
    cout << message << " ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 3. Найти сумму элементов массива
int findSum(const vector<int>& arr) {
    return accumulate(arr.begin(), arr.end(), 0);
}

// 4. Найти максимальный элемент
int findMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// 5. Найти минимальный элемент
int findMin(const vector<int>& arr) {
    return *min_element(arr.begin(), arr.end());
}

// 6. Найти среднее арифметическое
double findAverage(const vector<int>& arr) {
    return static_cast<double>(findSum(arr)) / arr.size();
}

// 7. Поиск элемента в массиве
int findElement(const vector<int>& arr, int target) {
    auto it = find(arr.begin(), arr.end(), target);
    if (it != arr.end()) {
        return distance(arr.begin(), it);
    }
    return -1; // не найден
}

// 8. Сортировка массива (по возрастанию)
void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

// 9. Перевернуть массив
void reverseArray(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
}

// 10. Подсчет четных элементов
int countEven(const vector<int>& arr) {
    return count_if(arr.begin(), arr.end(), [](int x) { return x % 2 == 0; });
}

// 11. Подсчет нечетных элементов
int countOdd(const vector<int>& arr) {
    return count_if(arr.begin(), arr.end(), [](int x) { return x % 2 != 0; });
}

// 12. Удаление элемента по индексу
void removeElement(vector<int>& arr, int index) {
    if (index >= 0 && index < arr.size()) {
        arr.erase(arr.begin() + index);
    }
}

// 13. Вставка элемента
void insertElement(vector<int>& arr, int index, int value) {
    if (index >= 0 && index <= arr.size()) {
        arr.insert(arr.begin() + index, value);
    }
}

// 14. Поиск всех вхождений элемента
vector<int> findAllOccurrences(const vector<int>& arr, int target) {
    vector<int> indices;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            indices.push_back(i);
        }
    }
    return indices;
}

// 15. Замена всех вхождений элемента
void replaceAll(vector<int>& arr, int oldVal, int newVal) {
    replace(arr.begin(), arr.end(), oldVal, newVal);
}

int main() {
    setlocale(LC_ALL, "RU");

    const int SIZE = 10;
    vector<int> arr(SIZE);

    // Заполнение массива
    fillRandom(arr, 1, 50);
    printArray(arr, "Исходный массив:");

    // 1. Сумма элементов
    cout << "1. Сумма элементов: " << findSum(arr) << endl;

    // 2. Максимальный и минимальный элементы
    cout << "2. Максимальный элемент: " << findMax(arr) << endl;
    cout << "3. Минимальный элемент: " << findMin(arr) << endl;

    // 3. Среднее арифметическое
    cout << "4. Среднее арифметическое: " << findAverage(arr) << endl;

    // 4. Количество четных и нечетных
    cout << "5. Количество четных элементов: " << countEven(arr) << endl;
    cout << "6. Количество нечетных элементов: " << countOdd(arr) << endl;

    // 5. Поиск элемента
    int target = arr[3]; // берем элемент, который точно есть
    int index = findElement(arr, target);
    cout << "7. Элемент " << target << " найден на позиции: " << index << endl;

    // 6. Сортировка
    vector<int> sortedArr = arr;
    sortArray(sortedArr);
    printArray(sortedArr, "Отсортированный массив:");

    // 7. Перевернутый массив
    vector<int> reversedArr = arr;
    reverseArray(reversedArr);
    printArray(reversedArr, "Перевернутый массив:");

    // 8. Поиск всех вхождений
    target = arr[0];
    vector<int> occurrences = findAllOccurrences(arr, target);
    cout << "8. Элемент " << target << " встречается на позициях: ";
    for (int pos : occurrences) {
        cout << pos << " ";
    }
    cout << endl;

    // 9. Замена элементов
    vector<int> replacedArr = arr;
    replaceAll(replacedArr, target, 999);
    printArray(replacedArr, "Массив после замены " + to_string(target) + " на 999:");

    // 10. Вставка и удаление
    vector<int> modifiedArr = arr;
    insertElement(modifiedArr, 2, 777);
    printArray(modifiedArr, "После вставки 777 на позицию 2:");

    removeElement(modifiedArr, 2);
    printArray(modifiedArr, "После удаления элемента с позиции 2:");

    return 0;
}