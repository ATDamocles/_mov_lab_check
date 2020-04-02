#include <iomanip>
#include <string>
#include <iostream>

using namespace std;
//#1 Checking function
float checkInt(string stringIn)
{
    while (cin.fail() || cin.eof() ||
        stringIn.find_first_not_of("-0123456789.") != string::npos) {
        cout << "Input error!" << endl;
        if (stringIn.find_first_not_of("-0123456789.") == string::npos) {
            cin.clear();
            cin.ignore(256, '\n');
        }
        getline(cin, stringIn);
    }
    //String into float
    string::size_type st;
    //Return floatOut;
    return stof(stringIn, &st);
}

//#1 Array, the less and the far
int main()
{
    string strInput;
    int iM = 0, iN = 0;
    int imin, jmin, imax, jmax;
    float iSml = 0, iBig = 0;
    bool test = true;
    cout << "================================ ++++++ ================================"<< endl
        <<"=== This program finds the smallest and biggest element in the array ==="<<endl;
    cout <<"Input a number of raws: ";  
    do {
        getline(cin, strInput);//Checking iM
        iM = (int)checkInt(strInput);
        if (iM < 0) {
            cout << "Input error!";
        }
    } while (iM < 0);  
    cout << "Input a number of columns: ";
    do {
        getline(cin, strInput);//Checking iN
        iN = (int)checkInt(strInput);
        if (iN < 0) {
            cout << "Input error!";
        }
    } while (iN < 0);   
    //#1 Initialzing dymanic array
    float **array = new float*[iM];
    for (int j = 0; j < iN; j++) {
        array[j] = new float[iN];
    }
    //#2 Array on the screen
    cout << "================================ Array =================================" << endl << endl;
    for (int i = 0; i < iM; i++)
    {
        for (int j = 0; j < iN; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            getline(cin, strInput);
            *(array[i] + j) = checkInt(strInput);
            // cin >> *(array[i] + j);
            //cout << setw(4) <<"A["<<i<<"]["<<j<<"]="<< array[i][j] <<" ";          
            //Check for the biggest one
            if (test == true) {
                iBig = array[i][j];//For biggest one
                imax = i;
                jmax = j;
                iSml = array[i][j];//For smallest one
                imin = i;
                jmin = j;
                test = false;
            }
            else {
                if (array[i][j] > iBig) {
                    iBig = array[i][j];
                    imax = i;
                    jmax = j;
                }
                else if(array[i][j] < iSml) {
                    iSml = array[i][j];
                    imin = i;
                    jmin = j;
                }
            }           
        }  
        cout << endl;
    }
    //#3 Question check and array deleting
    cout <<"The biggest one: " << "A[" << imax << "][" << jmax << "]=" << iBig
        << endl << "The smallest one: " << "A[" << imin << "][" << jmin << "]=" << iSml;
    for (int j = 0; j < iN; j++) {
        delete[] array[j];
    }
   delete[] array;
    return 0;
}

