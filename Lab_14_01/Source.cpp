#include <iostream>
#include <vector>
using namespace std;

// --- Підпрограма для створення масиву ---
void createArray(vector<int>& arr, int n) {
    arr.resize(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
}

// --- Підпрограма для виведення масиву ---
void printArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

// --- Підпрограма для знаходження найбільшого непарного елемента ---
int maxOddElement(const vector<int>& arr) {
    int maxOdd = -1; // Припустимо, що всі числа >=0, або можна використати INT_MIN
    bool found = false;

    for (int val : arr) {
        if (val % 2 != 0) { // якщо число непарне
            if (!found || val > maxOdd) {
                maxOdd = val;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No odd elements found in the array." << endl;
        return -1; // або будь-яке інше значення, що позначає відсутність непарних чисел
    }

    return maxOdd;
}

// --- Головна функція ---
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr;

    createArray(arr, n);      // Створення масиву
    cout << "Array elements: ";
    printArray(arr);          // Виведення масиву

    int maxOdd = maxOddElement(arr);  // Пошук найбільшого непарного елемента
    if (maxOdd != -1)
        cout << "The largest odd element is: " << maxOdd << endl;

    return 0;
}
