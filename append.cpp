
#include <iostream>
#include "string.h"


using namespace std;

void append(char * string, char letter){

    int len = strlen(string);
    string[len] = letter;
}


int main() {
    
    char science[10] = "science";
    cout << science << endl;
    append(science, 'a') ;
    cout << science << endl;

    return 0;

}

