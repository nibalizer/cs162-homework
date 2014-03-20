//Spencer Krum
//CS 162
//Karla Fant
//Program 4
//
//
//
/*
 *
 * content of the external data file
 * 2220,2725,2,northeast,good schools,nice view,vaults,
 * 1120,2958,1,southeast,quiet neighborhood,non-smoking,two-car garage,
 * 1445,1579,1,Clackamas,cats ok,close to parks,quiet neighborhood,
 * 1070,1330,2,St. Helens,gated property,close to shopping,close to parks,
 * 1300,2595,4,Lake Oswego,quiet neighborhood,close to shopping,pool,
 * 1810,2119,4,Hillsboro,cats ok,close to campus,laundry on-site,
 * 1080,857,4,north Portland,duplex,fireplace,close to campus,
 * 1960,3952,1,Vancouver,cats ok,quiet neighborhood,pool,
 * 1720,1499,0,southwest,laundry on-site,close to shopping,fireplace,
 * 2550,3959,2,St. Johns,good schools,gated property,one-car garage,
 */

/* algorithm

Open the file
Allocate a static array of structs
set a counter to zero

read until comma, put that value into array[counter].property -- for every value in the struct
at newline, increment the counter
continue until end of file is reached

Dump out the contents of the array of structs using iteration and print

Promp the user for a price range... save a max and min value

for each element in the array, check if the price is between the max and min value
   if it is,
      print the metadata for that element

Promp the user for string location to match on 

for each element in the array, check if the location given matches the location of the element
   if it is,
      print the metadata for that element


*/

#include <fstream>
#include "string.h"
#include <iostream>

using namespace std;

static bool debug = false; //global STATIC variable.. to aid in debugging only

struct house { //struct to hold the data
  int price;
  int sqft;
  int bedrooms;
  char * location;
  char * amenities1;
  char * amenities2;
  char * amenities3;
};

class Housing //class to hold the array of structs
{
  public:
    Housing(char filename[]);
    ~Housing(); //destructor
    void Prioritize(int selection);
    void Display_all();
    void Display_top();
    void Display_by_price();
    void Display_by_name();

  private:
    house houses[10]; // A static array, to be replaced with an LLL in program 5
    
    
    

};

void Housing::Display_by_name(){
//function to match on string

    cout << "Enter location name to match on";
    char locationname[20];
    cin.get(locationname, 20, '\n');

    for (int current = 0; current < 10; current++){
        if (!strcmp(locationname, houses[current].location)) {

            cout << "sqft: " << houses[current].sqft << endl;
            cout << "price: " << houses[current].price << endl;
            cout << "bedrooms: " << houses[current].bedrooms << endl;
            cout << "location: " << houses[current].location << endl;
            cout << "amenities1: " << houses[current].amenities1 << endl;
            cout << "amenities2: " << houses[current].amenities2 << endl;
            cout << "amenities3: " << houses[current].amenities3 << endl;

        }

    }


}

void Housing::Display_by_price(){
//function to match on integer range

    cout << "Enter max price: ";
    int max_price;
    cin >> max_price;
    cout << "Enter min price: ";
    int min_price;
    cin >> min_price;
    cin.ignore();

    for (int current = 0; current < 10; current++){
        if (houses[current].price <= max_price && houses[current].price >= min_price) {

            cout << "sqft: " << houses[current].sqft << endl;
            cout << "price: " << houses[current].price << endl;
            cout << "bedrooms: " << houses[current].bedrooms << endl;
            cout << "location: " << houses[current].location << endl;
            cout << "amenities1: " << houses[current].amenities1 << endl;
            cout << "amenities2: " << houses[current].amenities2 << endl;
            cout << "amenities3: " << houses[current].amenities3 << endl;

        }

    }


}

void Housing::Prioritize(int selection){
//function to build a set of options
//incomplete because ran out of time

    switch (selection) {
        case 1:
            Display_by_price();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
    }

}

void Housing::Display_all(){
//function to dump data 
    cout << "Displaying all options" << endl;

    for (int current = 0; current < 10; current++){
        cout << "sqft: " << houses[current].sqft << endl;
        cout << "price: " << houses[current].price << endl;
        cout << "bedrooms: " << houses[current].bedrooms << endl;
        cout << "location: " << houses[current].location << endl;
        cout << "amenities1: " << houses[current].amenities1 << endl;
        cout << "amenities2: " << houses[current].amenities2 << endl;
        cout << "amenities3: " << houses[current].amenities3 << endl;

    }

}


Housing::Housing(char filename[]){
//constructor

    if (debug){
        cout << "opening " << filename << endl;
    }

//open file
    ifstream houses_db;
    houses_db.open(filename);
    int current = 0;

    while (!houses_db.eof()){

        //temporary variables
        char temp[50];
        int size;

        //set sqft
        int sqft;
        houses_db >> sqft;
        if (houses_db.eof()){
            break;
        }
        if (debug) {
            cout << "sqft: " << sqft << endl;
        }
        houses[current].sqft = sqft;
        houses_db.ignore(); //eat the delimiter

        //set price
        int price;
        houses_db >> price;
        if (debug) {
            cout << "price: " << price << endl;
        }
        houses[current].price= price;
        houses_db.ignore(); //eat the delimiter

        //set bedrooms
        int bedrooms;
        houses_db >> bedrooms;
        if (debug) {
            cout << "bedrooms: " << bedrooms << endl;
        }
        houses[current].bedrooms= bedrooms;
        houses_db.ignore(); //eat the delimiter

        //set location
        houses_db.get(temp, 20, ',');
        size = strlen(temp);
        houses[current].location = new char [size];
        strcpy(houses[current].location, temp);
        if (debug) {
            cout << "location: " << houses[current].location << endl;
        }
        houses_db.ignore(); //eat the delimiter

        //set amenities1
        houses_db.get(temp, 20, ',');
        size = strlen(temp);
        houses[current].amenities1 = new char [size];
        strcpy(houses[current].amenities1, temp);
        if (debug) {
            cout << "amenities1: " << houses[current].amenities1 << endl;
        }
        houses_db.ignore(); //eat the delimiter

        //set amenities2
        houses_db.get(temp, 20, ',');
        size = strlen(temp);
        houses[current].amenities2 = new char [size];
        strcpy(houses[current].amenities2, temp);
        if (debug) {
            cout << "amenities2: " << houses[current].amenities2 << endl;
        }
        houses_db.ignore(); //eat the delimiter

        //set amenities3
        houses_db.get(temp, 20, ',');
        size = strlen(temp);
        houses[current].amenities3 = new char [size];
        strcpy(houses[current].amenities3, temp);
        if (debug) {
            cout << "amenities3: " << houses[current].amenities3 << endl;
        }
        houses_db.ignore(); //eat the delimiter

        houses_db.ignore(); //eat the final newline 

        current++;
        //increment the counter

    }

}

Housing::~Housing(){
//destructor, doesn't do much

}

int main() {

    char filename[20];

    strcpy(filename, "houses.txt");
    Housing housing(filename);
    //sorry there is no interactive menu here
    //ran out of time
    housing.Display_all();
    housing.Display_by_price();
    housing.Display_by_name();
    return 0;

}
