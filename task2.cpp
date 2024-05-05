#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class DynamicArray {
private:
    int n;
    T* Bp;
    T* Tp;
public:
    DynamicArray(int size) {
        n = size;
        Bp = new T[size];
        Tp = Bp;

        srand(time(0));

        for (int i = 0; i < n; ++i) {
            Bp[i] = static_cast<T>(rand() % 2001 - 1000) / 10.0;
        }
    }

    ~DynamicArray() {
        delete[] Bp;
    }

    void print() {
        for (int i = 0; i < n; ++i) {
            cout << Bp[i] << "\t";
            if ((i + 1) % 5 == 0) {
                cout << "\n";
            }
        }
        cout << "\n";
    }

    T* findMaxPositive() {
        T* maxPtr = nullptr;
        for (int i = 0; i < n; ++i) {
            if (Bp[i] > 0 && (maxPtr == nullptr || Bp[i] > *maxPtr)) {
                maxPtr = &Bp[i];
            }
        }
        return maxPtr;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    DynamicArray<int> intArray(13);
    cout << "int array:\n";
    intArray.print();
    int* maxInt = intArray.findMaxPositive();
    if (maxInt) {
        cout << "Максимальный положительный элемент (int): " << *maxInt << "\n";
    } else {
        cout << "Не нашлось положительных элементов (int).\n";
    }

    DynamicArray<double> doubleArray(17);
    cout << "\ndouble array:\n";
    doubleArray.print();
    double* maxDouble = doubleArray.findMaxPositive();
    if (maxDouble) {
        cout << "Максимальный положительный элемент (double): " << *maxDouble << "\n";
    } else {
        cout << "Максимальный положительный элемент (double).\n";
    }

    return 0;
}
