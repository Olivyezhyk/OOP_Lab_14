#include <iostream>
#include <list>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
using namespace std;

// --- Функція генерації випадкового числа ---
int RandomNumber() {
    return rand() % 100; // числа від 0 до 99
}

int main() {
    srand(static_cast<unsigned>(time(0))); // ініціалізація генератора випадкових чисел

    list<int> lst;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    // Заповнюємо список випадковими числами
    for (int i = 0; i < n; ++i)
        lst.push_back(RandomNumber());

    cout << "Original list: ";
    for (int val : lst)
        cout << val << " ";
    cout << endl;

    int key;
    cout << "Enter the value to duplicate: ";
    cin >> key;

    // Дублюємо елементи зі значенням key
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (*it == key)
            it = lst.insert(next(it), key); // вставляємо копію після поточного
    }

    cout << "Modified list: ";
    for (int val : lst)
        cout << val << " ";
    cout << endl;

    return 0;
}
