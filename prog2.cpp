// Spencer Krum
// CS 162
// Sat Feb 15, 2014
// Program #2
// Karla Fant


#include <iostream>
#include "string.h"

using namespace std;
const bool debug = false;

void append(char * string, char letter){
    //function to add a letter to a string

    int len = strlen(string);
    string[len] = letter;
    string[len+1] = '\0';
}

int capitalize( char firstletter){
    return toupper(firstletter); //really pointless function to fulfil requirement to pass by value
}

void capitalize_sentences(char * paragraph)
{

    for (int i = 0; i < strlen(paragraph) ; i++)
    {
        //cout << paragraph[i] << endl;
        if (paragraph[i] == '.' && paragraph[i+1] == ' '){
            if (debug) {
                cout << "Found capital candidate: " << paragraph[i+2] << endl;
            }
            paragraph[i+2] = toupper(paragraph[i+2]);

        }
        if (paragraph[i] == '.' && paragraph[i+1] == ' ' && paragraph[i+2] == ' '){
            if (debug) {
                cout << "Found capital candidate: " << paragraph[i+3] << endl;
            }
            paragraph[i+3] = toupper(paragraph[i+3]);

        }
    }

}

void two_spaces_between_sentences(char * paragraph_start, char * paragraph_end)
{

    for (int i = 0; i < strlen(paragraph_start) ; i++)
        //fake strcpy
    {
        if ( paragraph_start[i+1] == '\0' ) {

            if (debug) {
                cout << "I + 1 is not a thing"  << paragraph_start[i+1] << endl;
            }

            append(paragraph_end, paragraph_start[i]);    //extend paragraph_end by a letter
            break;
        }

        if (paragraph_start[i] == '.' && paragraph_start[i+1] == ' ' && paragraph_start[i+2] != ' '){
            // we are in a sentence barrier

            if (debug) {
                cout << "Found Sentence Barrier: " << paragraph_start[i] << paragraph_start[i+1] << endl;
            }

            append(paragraph_end, paragraph_start[i]);    //extend paragraph_end by a letter

            append(paragraph_end, paragraph_start[i+1]);  //extend paragraph_end by a letter
            append(paragraph_end, ' ');                   //extend paragraph_end by a space
            i++;     // increment i for the work we're doing in here
            
        }
        else {
            // We are not in a sentence barrier
            
            //append(paragraph_end, paragraph_start[i]);    //extend paragraph_end by a letter
            append(paragraph_end, paragraph_start[i]);    //extend paragraph_end by a letter
            //paragraph_end[i] = paragraph_start[i];

        }

    }
}

void enter_word_replace(char * paragraph){
    char continuing;
    do {
        char replacant[20];
        char replacement[20];

        cout << "Enter word to replace: " << endl;
        cin >> replacant;
        cout << "Enter word to replace with: " << endl;
        cin >> replacement;

        cout << "Replacing " << replacant << " with " << replacement << endl;
        char * instance = strstr(paragraph, replacant); //find the begining of the target word
        while ( instance) {
            strncpy(instance, replacement, strlen(replacement)); //replace the word
            instance = strstr(paragraph, replacant); //Set pointer to next instance
        }
        cout << "Do you want to correct another word? (y/n)" << endl;
        cin >> continuing;
    } 
    while (continuing == 'y');
 
}




int main(){
    char paragraph_start[300];
    char paragraph_end[600];
    

    cout << "Enter paragraph" << endl;
    cin.get(paragraph_start, 300);
    if (debug) {
        cout << paragraph_start << endl;
    }

    capitalize_sentences(paragraph_start);
    paragraph_start[0] = capitalize(paragraph_start[0]); //first letter in caps

    two_spaces_between_sentences(paragraph_start, paragraph_end);


    enter_word_replace(paragraph_end);


    cout << "Final State:" << endl;
    cout << paragraph_end << endl;
    return 0;
}
