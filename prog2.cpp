// Spencer Krum
// CS 162
// Sat Feb 15, 2014
// Program #2
// Karla Fant
//

#include <iostream>
#include "string.h"

using namespace std;
bool debug = true;

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
    }

}

void two_spaces_between_sentences(char * paragraph_start, char * paragraph_end)
{

    for (int i = 0; i < strlen(paragraph_start) ; i++)
    {
        paragraph_end[i] = paragraph_start[i];
    }
}


int main(){
  char paragraph_start[300];
  char paragraph_end[300];

  cout << "Enter paragraph" << endl;
  cin.get(paragraph_start, 300);
  cout << paragraph_start << endl;

  capitalize_sentences(paragraph_start);
  two_spaces_between_sentences(paragraph_start, paragraph_end);


  cout << "Final State:" << endl;
  cout << paragraph_end << endl;
  return 0;
}
