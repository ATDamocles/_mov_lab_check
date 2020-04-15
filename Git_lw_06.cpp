#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<int> iarray{ 1, 15, -34, 46, -134, 0 };
    fstream f1;
    int temp = 0;
    cout << "==================== File =====================" << endl
         << "= Input numbers in File 1, then from F1 to F2 =" << endl
         << "= Numbers need to be bigger than 0 in file F2 =" << endl
         << "=== Numbers in F1: 1, 15, -34, 46, -134, 0 ====" << endl;
    //Add numbers in file F1 from vector
    f1.open("F1.txt", ios::out);
    for (int i = 0; i < (int)iarray.size(); i++) {
        f1 << iarray[i] << ' ';
    }   
    iarray.clear();//Clear an array
    f1.close();
    //Add numbers from vector >0 in file F2, after reading them from F1 to vector
    f1.open("F1.txt", ios::in);
    while (!f1.eof()) {
        f1 >> temp;
        iarray.push_back(temp);
    }
    f1.close();
    cout << "Output: ";
    f1.open("F2.txt", ios::out);
    for (int i = 0; i < (int)iarray.size(); i++) {
        if (iarray[i]>0) {
            f1 << iarray[i] << ' ';
            cout << iarray[i] << ' ';
        }       
    }
    f1.close();
    return 0;
}
