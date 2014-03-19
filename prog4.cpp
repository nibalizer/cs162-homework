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
 * 2220|2725|2|northeast|good schools|nice view|vaults|
 * 1120|2958|1|southeast|quiet neighborhood|non-smoking|two-car garage|
 * 1445|1579|1|Clackamas|cats ok|close to parks|quiet neighborhood|
 * 1070|1330|2|St. Helens|gated property|close to shopping|close to parks|
 * 1300|2595|4|Lake Oswego|quiet neighborhood|close to shopping|pool|
 * 1810|2119|4|Hillsboro|cats ok|close to campus|laundry on-site|
 * 1080|857|4|north Portland|duplex|fireplace|close to campus|
 * 1960|3952|1|Vancouver|cats ok|quiet neighborhood|pool|
 * 1720|1499|0|southwest|laundry on-site|close to shopping|fireplace|
 * 2550|3959|2|St. Johns|good schools|gated property|one-car garage|
 */

#include <fstream>
#include "string.h"
#include <iostream>

using namespace std;

static bool debug = true;

struct house {
  int price;
  int sqft;
  int bedrooms;
  char * location;
  char * amenities1;
  char * amenities2;
  char * amenities3;
};

class Housing
{
  public:
    Housing(char filename[]);
    ~Housing();
    void Prioritize(int selection);
    void Display_all();
    void Display_top();

  private:
    house houses[10]; // A static array, to be replaced with an LLL in program 5
    
    
    

};


Housing::Housing(char filename[]){

    if (debug){
        cout << "opening " << filename << endl;
    }

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

        int price;
        houses_db >> price;
        if (debug) {
            cout << "price: " << price << endl;
        }
        houses[current].price= price;
        houses_db.ignore(); //eat the delimiter

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

    }

}

Housing::~Housing(){

}

int main() {

    char filename[20];

    strcpy(filename, "houses.txt");
    Housing housing(filename);
    return 0;

}
