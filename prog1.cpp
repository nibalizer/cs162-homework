
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


using namespace std;


struct weatherday { 
   char dayname[20];
//   int low;
//   int high;
//   int rain;
//   int wind;
//   int f_low;
//   int f_high;
//   int f_rain;
//   int f_wind;
   int values[8];
};


void welcome () { 
  cout << "Welcome to Spencer Krum's CS 162 Prog #1" << endl;
}


int main () {
  welcome();

  weatherday week[7];
  char weathertype[8][50] = {"low", "high", "rain", "wind", "forcasted low", "forcasted high", "forcasted rain", "forcasted wind"};

  strcpy(week[0].dayname, "Monday");
  strcpy(week[1].dayname, "Tuesday");
  strcpy(week[2].dayname, "Wednesday");
  strcpy(week[3].dayname, "Thursday");
  strcpy(week[4].dayname, "Friday");
  strcpy(week[5].dayname, "Saturday");
  strcpy(week[6].dayname, "Sunday");
  


  for(int i = 0; i<7; i++){
    for(int j = 0; j<7; j++){ 
      cout << "Please enter the " << weathertype[j] << " for " << week[i].dayname << endl;
    } 
  }

  char input[50];

  cin >> input;

  cout << "focuk ya!" << endl;
  cout << "you typed: " << input  << endl;


  exit(0);

}
