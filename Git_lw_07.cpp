#include <iomanip>
#include <string>
#include <iostream>

using namespace std;
//#1 Checking function
int checkInt(string stringIn)
{
    while (cin.fail() || cin.eof() ||
        stringIn.find_first_not_of("0123456789") != string::npos) {
        cout << "Input error!" << endl;
        if (stringIn.find_first_not_of("0123456789") == string::npos) {
            cin.clear();
            cin.ignore(256, '\n');
        }
        getline(cin, stringIn);
    }
    //String into float
    string::size_type st;
    //Return floatOut;
    return stoi(stringIn, &st);
}

//#2 Main
int main()
{
    string strInput;
    int iN = 0;
    cout << "================================ ++++++ ================================" << endl
         << "=== This program finds array A*B, where arrays A and B are n*n  ===" << endl;
    cout << "Input a n: ";
    do {
        getline(cin, strInput);//Checking iN
        iN = (int)checkInt(strInput);
        if (iN <= 0) {
            cout << "Input error!";
        }
    } while (iN <= 0);

    //#1 Initialzing dymanic arrays
    int** A = new int* [iN];
    for (int j = 0; j < iN; j++) {
        A[j] = new int[iN];
    }
    int** B = new int* [iN];
    for (int j = 0; j < iN; j++) {
        B[j] = new int[iN];
    }
    //#2 Intilisating Arrays and output on the screen
    cout << "================================ Arrays =================================" << endl
        <<"Array A          Array B         Array A*B"<< endl;
    for (int i = 0; i < iN; i++)
    {
        for (int j = 0; j < iN; j++) {
            A[i][j] = rand() % 10;
            cout << "A[" << i << "][" << j << "] = " << A[i][j];
            B[i][j] = rand() % 10+iN;
            cout << "     B[" << i << "][" << j << "] = " << B[i][j];
            A[i][j] *= B[i][j];
            cout << "     A*B[" << i << "][" << j << "] = " << A[i][j] << endl;
        }
    }
    //#3 Question check and array deleting
    for (int j = 0; j < iN; j++) {
        delete[] A[j];
        delete[] B[j];
    }
    delete[] A;
    delete[] B;
    return 0;
}