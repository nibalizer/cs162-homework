// CS 162
// Spencer Krum
// Assignment 3
// Karla Fant
// Winter 2014


#include <iostream>
#include "string.h"

using namespace std;
const bool debug = true;

struct schoolclass { // important not to try to call this 'class'
    char identifier[20];
    char name[50];
    char termyear[20];
    char comments[100];
    bool required;
    char grade;
};

int read_in_classes(schoolclass * classes, int current){
    strcpy(classes[current].identifier,"test");


    char response;
    if (current < 59) {
        return 'n';
    }
    cout << "cintinue? (y/n)" << endl;
    cin >> response;
    return response;


}

int mainmenu(){
    cout << "Pick one of the following: " << endl;
    cout << "1. Type class into program (insert)" << endl;
    cout << "2. Read bulk classes from file" << endl;
    cout << "3. Write classes to file" << endl;
    cout << "4. Display classes" << endl;
    cout << "5. Display classes from a specific term" << endl;
    cout << "What do you want to do? (1,2,3,4,5)" << endl;
    int response;
    cin >> response;
    return response;


}

int main() {

    schoolclass classes[60];

    //int num_classes = 0;
    //while (read_in_classes(classes, num_classes++) == 'y');
    int action = mainmenu();

    return 0;

}

