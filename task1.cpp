#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;

const int N = 5;
const char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";

template<typename T>

void func(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 100) / 10.0;
    }
}

void func(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        char c = alphabet[(rand() % 26)];
//        cout << c << "\n";
        arr[i] = c;
    }
}

template<typename T>

int *func2(T arr[], int size) {
    T k;
    cout << "введите число: ";
    cin >> k;

    int *index_arr = new int[size];
    int cur_index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] <= k) {
            index_arr[cur_index] = i;
            cur_index += 1;
        }
    }

    while (cur_index < size) {
        index_arr[cur_index] = -1;
        cur_index += 1;
    }
    return index_arr;
}

int *func2(char *arr, int size) {
    char c;
    cout << "введите символ: ";
    cin >> c;

    int *index_arr = new int[size];
    int cur_index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] <= c) {
            index_arr[cur_index] = i;
            cur_index += 1;
        }
    }

    while (cur_index < size) {
        index_arr[cur_index] = -1;
        cur_index += 1;
    }
    return index_arr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    int arr_int[N];

    func(arr_int, N);

    cout << "int array\n";

    for (auto i: arr_int) {
        cout << i << "  ";
    }
    cout << "\n";

    int *result_int = func2(arr_int, N);

    cout << "индексы: ";
    for (int i = 0; (result_int[i] != -1 and i < N); i++) {
        cout << result_int[i] << " ";
    }

    cout << "\n\ndouble array\n";

    double arr2[N];

    func(arr2, N);

    for (auto i: arr2) {
        cout << i << "  ";
    }
    cout << "\n";

    int *result_double = func2(arr2, N);

    cout << "индексы: ";
    for (int i = 0; (result_double[i] != -1 and i < N); i++) {
        cout << result_double[i] << " ";
    }

    cout << "\n\nchar array\n";

    char *word = new char[N];

    func(word, N);

    for (int i = 0; i < N; i++) {
        cout << word[i] << "  ";
    }
    cout << "\n";

    int *result_char = func2(word, N);

    cout << "индексы: ";
    for (int i = 0; (result_char[i] != -1 and i < N); i++) {
        cout << result_char[i] << " ";
    }

    return 0;
}
