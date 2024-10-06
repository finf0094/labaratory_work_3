#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Task 1: Напечатать все элементы массива, которые больше предыдущего.
void task1() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Task 2: Найти первую пару соседних элементов с одинаковым знаком.
void task2() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        if ((arr[i] > 0 && arr[i - 1] > 0) || (arr[i] < 0 && arr[i - 1] < 0)) {
            cout << arr[i - 1] << " " << arr[i] << endl;
            return;
        }
    }
}

// Task 3: Найти наименьший нечетный элемент в массиве.
void task3() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minOdd = 0;
    for (int x : arr) {
        if (x % 2 != 0 && (minOdd == 0 || x < minOdd)) {
            minOdd = x;
        }
    }
    cout << (minOdd == 0 ? 0 : minOdd) << endl;
}

// Task 4: Определить количество различных элементов в убывающем массиве.
void task4() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int uniqueCount = 0;
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueCount++;
        }
    }
    cout << uniqueCount << endl;
}

// Task 5: Поменять соседние элементы местами.
void task5() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i += 2) {
        swap(arr[i - 1], arr[i]);
    }
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// Task 6: Циклически сдвинуть элементы массива вправо.
void task6() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n > 1) {
        int last = arr.back();
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;
    }
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

// Task 7: Подсчитать количество пар одинаковых элементов.
void task7() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
    }
    cout << count << endl;
}

// Task 8: Напечатать элементы, которые встречаются в массиве только один раз.
void task8() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count == 1) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// Task 9: Проверить, угрожают ли друг другу ферзи на шахматной доске 8x8.
void task9() {
    vector<pair<int, int>> queens(8);
    cout << "Введите координаты 8 ферзей (строка и столбец от 1 до 8): " << endl;
    for (int i = 0; i < 8; i++) {
        cin >> queens[i].first >> queens[i].second;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            if (queens[i].first == queens[j].first || 
                queens[i].second == queens[j].second || 
                abs(queens[i].first - queens[j].first) == abs(queens[i].second - queens[j].second)) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

// Task 10: Определить, какие кегли остались стоять.
void task10() {
    int n, k;
    cout << "Введите количество кеглей и количество бросков: ";
    cin >> n >> k;
    vector<char> pins(n, 'I');
    cout << "Введите диапазоны, которые были сбиты (Ii и ri): " << endl;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        for (int j = l - 1; j < r; j++) {
            pins[j] = '.';
        }
    }
    for (char c : pins) {
        cout << c;
    }
    cout << endl;
}

// Main function to run all tasks
int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    task9();
    task10();
    return 0;
}
