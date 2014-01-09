
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
  cout << "Press ^C to exit" << endl;
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
  

  while (1) {

  for(int i = 0; i<7; i++){
    for(int j = 0; j<8; j++){ 
      cout << "Please enter the " << weathertype[j] << " for " << week[i].dayname << ": ";
      int value;
      cin >> value;
      week[i].values[j] = value;
      cout << "The value for " << weathertype[j] << " for " << week[i].dayname << " was: " << week[i].values[j] << endl;

    } 
    cout << "The high for " << week[i].dayname << " was " << week[i].values[1] << endl;
    cout << "The low for " << week[i].dayname << " was " << week[i].values[0] << endl;
    cout << "The average for " << week[i].dayname << " was " << ((week[i].values[0] + week[i].values[1] ) / 2) << endl;
    cout << "The forcast for the low was " << abs(100 * ((float(week[i].values[0]) - float(week[i].values[4]))/float(week[i].values[0]))) << "\% off" << endl;
    cout << "The forcast for the high was " << abs(100 * ((float(week[i].values[1]) - float(week[i].values[5]))/float(week[i].values[0]))) << "\% off" << endl;
    cout << "The forcast for the rain was " << abs(100 * ((float(week[i].values[2]) - float(week[i].values[6]))/float(week[i].values[0]))) << "\% off" << endl;
    cout << "The forcast for the wind was " << abs(100 * ((float(week[i].values[3]) - float(week[i].values[7]))/float(week[i].values[0]))) << "\% off" << endl;
  }

  cout << "Press Ctrl + C to exit. Press any key to go again" << endl;
  char yesno[10];
  cin >> yesno;

  }


  exit(0);

}
