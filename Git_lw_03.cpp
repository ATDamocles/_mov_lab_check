#include <string>
#include <iostream>

using namespace std;

int main()
{
    string strInput;
    cout << "======================== ++++++ =====================" << endl
         << "=== This program finds '<<' and change into '>>'  ===" << endl;
    cout << "Input a string: ";
    getline(cin, strInput);    
    while (strstr(strInput.c_str(), "<<"))
    {
        strInput.replace(strInput.find("<<"), 2, ">>");
    }  
    cout << strInput;
    return 0;
}

