#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// вывод вектора
void printArray(vector<int>& arr) {
    int n = arr.size();

    cout << "Массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//вывод 2д вектора
void printArray(vector<vector<int>>& arr) {
    int n = arr.size();
    
    cout << "Массив: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//сумма 2д вектора
void sumaArray(vector<vector<int>>& arr) {
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum += arr[i][j];
        }
        cout << sum << endl;
    }
}

//НОД числа
int NOD(int& a, int& b) {
    int c = a % b;
    if (c != 0) {
        a = b;
        b = c;
        NOD(a, b);
    }
    else {
        return b;
    }
}

// Факторила числа
int Fact(int a) {
    static int b = 1;
    for (int i = 2; i <= a; i++) {
        b = b * i;
    }
    return b;
}

int main()
{
    setlocale(LC_ALL, "RU");
    
    // ЗАДАНИЕ 1 №3
    float k = 3.7;
    float g = 4.5;
    double c = 6.7;

    cout << (k + g + c) / 3 << endl;

    // ЗАДАНИЕ 2 №3
    int a;
    int b;
    cout << "Введите 2 натуральных числа: "; cin >> a >> b;

    cout << "НОК: " << (a * b) / NOD(a, b) << endl;
    
    // ЗАДАНИЕ 3
    int fact;
    cout << "Введите натуральное число, чтобы найти его факториал: "; cin >> fact;
    cout << Fact(fact) << endl;

    // ЗАДАНИЕ 4 
    vector<int> arr(8);

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 100 + 1;
    }
   
    printArray(arr);

    cout << "Макс. элемент массива: " << *max_element(arr.begin(), arr.end()) << endl;
    cout << "Мин. элемент массива: " << *min_element(arr.begin(), arr.end()) << endl;
    
    // ЗАДАНИЕ 5 №14
    vector<vector<int>> arr1(2, vector<int>(2));

    for (int i = 0; i < arr1.size(); i++) {
        for (int g = 0; g < arr1.size(); g++) {
            arr1[i][g] = rand() % 20 + 1;
        }
    }
    
    printArray(arr1);
    sumaArray(arr1);

    return 0;
}

