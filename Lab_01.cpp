#include <iostream>
#include <string>

using namespace std;

//#1 Recursive factorial function
long factorial(long number)
{
    return number == 0 ? 1 : number * factorial(number - 1);
   // return (number == 1 || number == 0) ? 1 : factorial(number - 1) * number;
}

//#2 Checking function
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
    //String into integer
    string::size_type st;
    //int intOut = stoi(stringIn, &st);
    //return intOut;
    return stoi(stringIn, &st);
}

//#3 Main function
int main()
{   
    string strInput;
    int  iN, iM;
    cout << "========== Calculation of the combination number ==========" << endl
         << "================= C = n! / (m! * (n - m)!) =================" << endl
        << "Input M number: ";//Checking iM
    getline(cin, strInput);
    iM = checkInt(strInput);
    cout << "Input N number: ";//Checking iN
    do {
        getline(cin, strInput);
        iN = checkInt(strInput);
    } while (iN <= iM);
    unsigned long iC = factorial(iN) / (factorial(iM) * factorial(iN - iM));
    cout << "Calculation result: C = " << iC;
    return 0;
}
