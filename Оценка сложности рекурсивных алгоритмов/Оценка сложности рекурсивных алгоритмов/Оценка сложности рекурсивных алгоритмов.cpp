#include <iostream>
#include <vector>
#include <string>
using namespace std;

//ЗАДАНИЕ 1

// 1. Рекурсивная функция для вычисления НОД
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 2. Рекурсивная функция для вычисления числа Фибоначчи
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 3. Рекурсивная функция для переворота числа
int reverseNumber(int n, int reversed = 0) {
    if (n == 0) return reversed;
    return reverseNumber(n / 10, reversed * 10 + n % 10);
}

//ЗАДАНИЕ 2 

// 1. Вспомогательная функция для вывода представлений числа в виде суммы
void printPartitions(int m, int n, vector<int>& parts, int start) {
    if (m == 0 && n == 0) {
        for (int p : parts) cout << p << " ";
        cout << endl;
        return;
    }
    if (m == 0 || n == 0) return;

    for (int i = start; i <= n; i++) {
        parts.push_back(i);
        printPartitions(m - 1, n - i, parts, i);
        parts.pop_back();
    }
}

// Основная функция для вывода всех представлений
void printAllPartitions(int m, int n) {
    vector<int> parts;
    cout << "Представления " << n << " в виде суммы " << m << " слагаемых:" << endl;
    printPartitions(m, n, parts, 1);
    cout << endl;
}

// 2. Рекурсивная функция для вычисления двойного факториала
int doubleFactorial(int n) {
    if (n <= 1) return 1;
    return n * doubleFactorial(n - 2);
}

// 3. Рекурсивная функция для подсчета единиц в двоичном представлении
int countOnes(int n) {
    if (n == 0) return 0;
    return (n % 2) + countOnes(n / 2);
}

// 4. Функция сложения через прибавление единицы
int add(int a, int b) {
    if (b == 0) return a;
    return add(a + 1, b - 1);
}

// 5. Функция умножения через сложение
int multiply(int a, int b) {
    if (b == 0) return 0;
    return a + multiply(a, b - 1);
}

// 6. Проверка, является ли фрагмент строки палиндромом
bool isPalindrome(const string& s, int i, int j) {
    if (i >= j) return true;
    if (s[i] != s[j]) return false;
    return isPalindrome(s, i + 1, j - 1);
}

// 7. Подсчет количества цифр в числе
int countDigits(int n) {
    if (n == 0) return 0;
    return 1 + countDigits(n / 10);
}

int main() {
    setlocale(LC_ALL, "RU");

    cout << "=== ЗАДАНИЕ 1 ===" << endl;

    // Тест НОД
    cout << "1. НОД(48, 18) = " << gcd(48, 18) << endl;

    // Тест Фибоначчи
    cout << "2. 10-е число Фибоначчи = " << fibonacci(10) << endl;

    // Тест переворота числа
    cout << "3. Перевернутое число 12345 = " << reverseNumber(12345) << endl;

    cout << endl << "=== ЗАДАНИЕ 2 ===" << endl;

    // Тест представлений в виде суммы
    printAllPartitions(3, 5);

    // Тест двойного факториала
    cout << "2. 7!! = " << doubleFactorial(7) << endl;
    cout << "   8!! = " << doubleFactorial(8) << endl;

    // Тест подсчета единиц
    cout << "3. Количество единиц в двоичном представлении 13 (1101) = " << countOnes(13) << endl;

    // Тест сложения
    cout << "4. 7 + 5 = " << add(7, 5) << endl;

    // Тест умножения
    cout << "5. 6 * 4 = " << multiply(6, 4) << endl;

    // Тест палиндрома
    string testStr = "radar";
    int i = 0, j = testStr.length() - 1;
    cout << "6. Строка \"" << testStr << "\" палиндром? "
        << (isPalindrome(testStr, i, j) ? "Да" : "Нет") << endl;

    // Тест подсчета цифр
    cout << "7. Количество цифр в числе 123456 = " << countDigits(123456) << endl;

    return 0;
}