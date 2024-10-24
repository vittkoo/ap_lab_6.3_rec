#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i) {
    cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int IFirst(int* a, const int size, int& minOdd, int i) {
    if (i >= size) 
        return -1;
    if (a[i] % 2 != 0) {
        minOdd = a[i];
        return i;
    }
    return IFirst(a, size, minOdd, i + 1);
}

int MinOdd(int* a, const int size, int minOdd, int i) {
    if (i >= size) 
        return minOdd;
    if (a[i] % 2 != 0) {
        if (minOdd == -1 || a[i] < minOdd)
            minOdd = a[i];
    }
    return MinOdd(a, size, minOdd, i + 1);
}

template <typename T>
int IFirstTemplate(T* a, const int size, T& minOdd, int i) {
    if (i >= size) 
        return -1;
    if (a[i] % 2 != 0) {
        minOdd = a[i];
        return i;
    }
    return IFirstTemplate(a, size, minOdd, i + 1);
}


template <typename T>
int MinOddTemplate(T* a, const int size, int minOdd, int i) {
    if (i >= size) return minOdd;
    if (a[i] % 2 != 0) {
        if (minOdd == -1 || a[i] < minOdd)
            minOdd = a[i];
    }
    return MinOddTemplate(a, size, minOdd, i + 1);
}


int main() {
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

    int minOdd;
    int imin = IFirst(a, n, minOdd, 0);

    if (imin == -1)
        cerr << "There`s no odd elements!" << endl;
    else
        cout << "minOdd = " << MinOdd(a, n, minOdd, imin + 1) << endl;

    int minOddTemplate;
    int iminTemplate = IFirstTemplate(a, n, minOddTemplate, 0);

    if (iminTemplate == -1)
        cerr  << "There's no odd elements!" << endl;
    else
        cout << "minOddTemplate = " << MinOddTemplate(a, n, minOddTemplate, iminTemplate + 1) << endl;

    return 0;
}
