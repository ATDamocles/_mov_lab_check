#include <iostream>

using namespace std;

template < typename T >
//#1 Bubble sort
void bubblesort(T* arr)
{
    int arrsize = sizeof(arr)+1;  
    for (int i = 0; i < arrsize - 1; i++) {
        for (int j = 0; j < arrsize - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < arrsize; i++) {
        cout << arr[i] <<' ';
    }

}

//#2 Main
int main()
{
    int array1[5] = {5, 6, 123, 7, 1};
    char array2[5] = { 'a', 'c', 'e', 'd', 'b' };
    double array3[5] = { 0.1, 0.05, 1.24, 1.25, 1.23 };

    cout << "=== INT ===" << endl;
    bubblesort(array1);
    cout << endl <<"=== CHAR ===" << endl;
    bubblesort(array2);
    cout << endl << "=== DOUBLE ===" << endl;
    bubblesort(array3);

    return 0;
}
