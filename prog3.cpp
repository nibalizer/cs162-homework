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
    char response;
    if (current >= 59) {
        return 'n';
    }
    cout << "Enter the course identifier: e.g. BIO442" << endl;
    char test[20];
    cin.ignore();
    cin.get(classes[current].identifier, 20);
    cout << "Enter the course name: e.g. Advanced Microbiology" << endl;
    cin.ignore();
    cin.get(classes[current].name, 50);
    cout << "Enter the course year and term: e.g. 2012W" << endl;
    cin.ignore();
    cin.get(classes[current].termyear, 20);
    cout << "Enter any comments on the course: e.g. This proffesor is hard " << endl;
    cin.ignore();
    cin.get(classes[current].comments, 100);
    cout << "Is this class required for your major? (y/n)" << endl;
    char required;
    cin >> required;
    if (required == 'y'){
        classes[current].required = true;}
    else { 
        classes[current].required = false;}
    cout << "What graded did you get in this class? e.g. A or 0 for no grade yet" << endl;
    cin >> classes[current].grade;


    cout << "continue entering classes (y/n)" << endl;
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
    cout << "6. Quit" << endl;
    cout << "What do you want to do? (1,2,3,4,5,6)" << endl;
    int response;
    cin >> response;
    return response;


}

int main() {

    schoolclass classes[60];

    int num_classes = 0;

    int action;
    int sel;
    while  (action < 6) {
        action = mainmenu();
        if (debug){ cout << action << endl; }
        switch (action) {
            case 1:
                while (read_in_classes(classes, num_classes++) == 'y');
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }
    }

    return 0;

}

