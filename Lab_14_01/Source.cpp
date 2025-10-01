#include <iostream>
#include <vector>
#include <algorithm> // для copy_if та max_element
#include <cstdlib>   // для rand, srand
#include <ctime>     // для time
using namespace std;

// --- Функція генерації випадкового числа ---
int RandomNumber() {
    return rand() % 100; // числа від 0 до 99
}

int main() {
    srand(static_cast<unsigned>(time(0))); // ініціалізація генератора випадкових чисел
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> vec(n);

    // Заповнюємо вектор випадковими числами
    generate(vec.begin(), vec.end(), RandomNumber);

    cout << "Array elements: ";
    for (int val : vec)
        cout << val << " ";
    cout << endl;

    // Відбираємо непарні елементи
    vector<int> oddElements;
    copy_if(vec.begin(), vec.end(), back_inserter(oddElements),
        [](int x) { return x % 2 != 0; });

    if (oddElements.empty()) {
        cout << "No odd elements found in the array." << endl;
    }
    else {
        int maxOdd = *max_element(oddElements.begin(), oddElements.end());
        cout << "The largest odd element is: " << maxOdd << endl;
    }

    return 0;
}
