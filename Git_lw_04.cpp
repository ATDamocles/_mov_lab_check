#include <iostream>
#include <list>

using namespace std;

struct input
{
    const char family[30];
    const char city[10];
    int physic;
    int mathe;
    int liter;
};

int main() {
    int iabit = 0;
    list<string> lineout;
    //List of abiturients
    struct input arr[5] = { 
        {"OLeksii0","Poltawa",5,5,5},
        {"OLeksii1","Minsk",5,5,5},
        {"OLeksii2","Minsk",2,3,1},
        {"OLeksii3","Minsk",5,4,4},
        {"OLeksii4","Poltawa",5,5,5}
    };
    //List Checking
    for (int i = 0; i < 5; i++) {
        //In Minsk
        if (!strcmp(arr[i].city, "Minsk")) {
            //Medium grade = 4
            if((arr[i].liter + arr[i].mathe + arr[i].physic) / 3 >= 4){
                //Number of abiturients add 1
                iabit++;
                //Add a Family to list
                lineout.push_back(arr[i].family);
            }           
        }       
    }
    //Output number of abiturients
    cout << "Number of abiturients: " << iabit << endl; 
    //Output abiturients ia alphabet order
    lineout.sort();
    cout << "Sorted Last name in alphabet order: " << endl;
    for (list<string>::iterator it = lineout.begin(); it != lineout.end(); ++it) {
        //Output list in sorted order
        cout << *it <<endl;
    }     
    return 0;
}

