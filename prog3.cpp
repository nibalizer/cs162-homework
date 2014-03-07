// CS 162
// Spencer Krum
// Assignment 3
// Karla Fant
// Winter 2014


/*
 *
 * algorithm
 *
 * instatiate a static array of 60 schoolclass structs
 *
 * We will loop around printing a menu and reading a response
 *   case statement on the response  for one of six options
 *   each case calls the function correspondng to that case
 *
 *
 * read in classes from user
 *
 *   increase num_classes
 *   ask user for all info for a class
 *   put info into class struct in array
 *   ask if repeat
 *
 * read in classes from file
 *
 *  open file
 *  read in elements into struct
 *  append struct to array
 *  increment num_classes
 *  repeart until end of file
 *
 * write classes to file
 *
 *  write out entire array, separating fields with commas and structs with
 *  newlines
 *
 * display classes
 *
 *  iterate through array, printing eache element of each struct
 *
 *
 * display classes matching term
 *  
 *  same as display classes, but check if term/year match user input
 *
 *
 *
 */

#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;
const bool debug = false;

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

void display_classes(schoolclass * classes, int num_classes){

    for (int i = 0; i<num_classes; i++){
        cout << "Id: " << classes[i].identifier << endl;
        cout << "Name: " << classes[i].name << endl;
        cout << "Year/Term: " << classes[i].termyear << endl;
        cout << "Comments: " << classes[i].comments << endl;
        if (classes[i].required ) { 
            cout << "Required: " << "YES" << endl;
        } else {
            cout << "Required: " << "NO" << endl;
        }
        cout << "Grade: " << classes[i].grade << endl;

    }

}

void write_classes_to_file(schoolclass * classes, int num_classes){

    ofstream classes_db;
    classes_db.open("classes_db.csv");

    for (int i = 0; i<num_classes; i++){
        classes_db << classes[i].identifier << ',';
        classes_db << classes[i].name << ',';
        classes_db << classes[i].termyear << ',';
        classes_db << classes[i].comments << ',';
        if (classes[i].required ) { 
            classes_db << "y" << ',';
        } else {
            classes_db << "n" << ',';
        }
        classes_db << classes[i].grade << '\n'; //final entry, close with a newline

    }

}

void read_in_classes_from_file(schoolclass * classes, int &num_classes){

    if (debug) {
        cout << "reading in file" << endl;
    }
    
    ifstream classes_db;
    classes_db.open("classes_db.csv");

    while (!classes_db.eof()){

        int current = num_classes++;

        classes_db.get(classes[current].identifier, 20, ',');
        if (debug) {
            cout << classes[current].identifier << endl;
        }
        classes_db.ignore();
        classes_db.get(classes[current].name, 50, ',');
        classes_db.ignore();
        classes_db.get(classes[current].termyear, 20, ',');
        classes_db.ignore();
        classes_db.get(classes[current].comments, 100, ',');
        classes_db.ignore();
        char required;
        classes_db >> required;
        if (required == 'y'){
            classes[current].required = true;}
        else { 
            classes[current].required = false;}
        classes_db.ignore();
        classes_db >> classes[current].grade;
        classes_db.ignore(10,'\n');
    }
    num_classes--;


}

void display_classes_with_filter(schoolclass * classes, int num_classes){

    char filter[20];

    cout << "What term?" << endl;
    cin.ignore();
    cin.get(filter,20);


    for (int i = 0; i<num_classes; i++){
        if ( ! strcmp(filter, classes[i].termyear)) {  //strcmp doesn't do what you would think
            cout << "Id: " << classes[i].identifier << endl;
            cout << "Name: " << classes[i].name << endl;
            cout << "Year/Term: " << classes[i].termyear << endl;
            cout << "Comments: " << classes[i].comments << endl;
            if (classes[i].required ) { 
                cout << "Required: " << "YES" << endl;
            } else {
                cout << "Required: " << "NO" << endl;
            }
            cout << "Grade: " << classes[i].grade << endl;
        }

    }

     


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
                read_in_classes_from_file(classes, num_classes);
                break;
            case 3:
                write_classes_to_file(classes, num_classes);
                break;
            case 4:
                display_classes(classes, num_classes);
                break;
            case 5:
                display_classes_with_filter(classes, num_classes);
                break;
            default:
                break;
        }
    }

    return 0;

}

