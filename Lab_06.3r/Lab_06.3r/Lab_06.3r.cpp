#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


void Create(int* a, const int size, const int Low, const int High, int i)
{
    if (i < size)
    {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}


void Print(int* a, const int size, int i)
{
    if (i < size)
    {
        cout << "a[" << setw(1) << i << "] = " << setw(4) << a[i] << endl;
        Print(a, size, i + 1);
    }
}


int FirstOdd(int* a, const int size, int i)
{
    if (i >= size) return -1; 

    if (a[i] % 2 != 0) 
        return i;

    return FirstOdd(a, size, i + 1);
}


int MinOdd(int* a, const int size, int i, int minOdd)
{
    if (i >= size) return minOdd; 

    if (a[i] % 2 != 0 && a[i] < minOdd)
        minOdd = a[i];

    return MinOdd(a, size, i + 1, minOdd);
}

int main()
{
    srand((unsigned)time(NULL)); 
    const int n = 10;
    int a[n];
    int Low = -10;
    int High = 10;

    Create(a, n, Low, High, 0);
    Print(a, n, 0);

  
    int firstOddIndex = FirstOdd(a, n, 0);

    if (firstOddIndex == -1)
    {
        cerr << "No Odd" << endl;
    }
    else
    {
      
        int minOdd = MinOdd(a, n, firstOddIndex + 1, a[firstOddIndex]);
        cout << "MinOdd:  " << minOdd << endl;
    }

    return 0;
}
