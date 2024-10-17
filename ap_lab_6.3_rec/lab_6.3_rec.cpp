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
    if (a[i] % 2 != 0) {
        minOdd = a[i];
        return i;
    }

    if (i < size - 1)
        return IFirst(a, size, minOdd, i + 1);
    else
        return -1;
}

int MinOdd(int* a, const int size, int minOdd, int i) {
    if (a[i] < minOdd && a[i] % 2 != 0)
        minOdd = a[i];

    if (i < size - 1)
        return MinOdd(a, size, minOdd, i + 1);
    else
        return minOdd;
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

    return 0;
}
