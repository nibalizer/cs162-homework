//Spencer Krum
//CS 162
//Karla Fant
//Program 5
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

#include <fstream>
#include "string.h"
#include <iostream>

using namespace std;

static bool debug = false;

struct house {
  int price;
  int sqft;
  int bedrooms;
  char * location;
  char * amenities1;
  char * amenities2;
  char * amenities3;
  house * next;
};

class Housing
{
  public:
    Housing(char filename[]);
    ~Housing();
    void Prioritize(int selection);
    void Display_all();
    void Display_top();
    void Display_by_price();
    void Display_by_name();
    void Display_and_proceed(house * cur);

  private:
    //house houses[10]; // A static array, to be replaced with an LLL in program 5
    house * head; // The head of our LLL
    house houses[10];
    
    
    

};

void Housing::Display_by_name(){

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

    head = new house;
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

void Housing::Display_and_proceed(house * cur){

    
    cout << "sqft: " << cur->sqft << endl;
    cout << "price: " << cur->price << endl;
    cout << "bedrooms: " << cur->bedrooms << endl;
    cout << "location: " << cur->location << endl;
    cout << "amenities1: " << cur->amenities1 << endl;
    cout << "amenities2: " << cur->amenities2 << endl;
    cout << "amenities3: " << cur->amenities3 << endl;
    
    if (cur->next) {
        Display_and_proceed(cur->next);
    }

}

void Housing::Display_all(){
    cout << "Displaying all options" << endl;
    cout << "Displaying all more" << endl;

    


    Display_and_proceed(head->next);

}


Housing::Housing(char filename[]){

    if (debug){
        cout << "opening " << filename << endl;
    }
    
    head = new house;

    ifstream houses_db;
    houses_db.open(filename);

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
        head->sqft = sqft;
        if (debug) {
            cout << "sqft: " << sqft << endl;
            cout << "sqft: " << head->sqft << endl;
        }
        houses_db.ignore(); //eat the delimiter

        int price;
        houses_db >> price;
        if (debug) {
            cout << "price: " << price << endl;
        }
        head->price  = price;
        houses_db.ignore(); //eat the delimiter

        int bedrooms;
        houses_db >> bedrooms;
        if (debug) {
            cout << "bedrooms: " << bedrooms << endl;
        }
        head->bedrooms = bedrooms;
        houses_db.ignore(); //eat the delimiter

        //set location
        houses_db.get(temp, 20, ',');
        size = strlen(temp);
        head->location = new char [size];
        strcpy(head->location, temp);
        if (debug) {
            cout << "location: " << head->location << endl;
        }
        houses_db.ignore(); //eat the delimiter

        //set amenities1
        houses_db.get(temp, 20, ',');
        size = strlen(temp);
        head->amenities1 = new char [size];
        strcpy(head->amenities1, temp);
        if (debug) {
            cout << "amenities1: " << head->amenities1 << endl;
        }
        houses_db.ignore(); //eat the delimiter

        //set amenities2
        houses_db.get(temp, 20, ',');
        size = strlen(temp);
        head->amenities2 = new char [size];
        strcpy(head->amenities2, temp);
        if (debug) {
            cout << "amenities2: " << head->amenities2 << endl;
        }
        houses_db.ignore(); //eat the delimiter

        //set amenities3
        houses_db.get(temp, 20, ',');
        size = strlen(temp);
        head->amenities3 = new char [size];
        strcpy(head->amenities3, temp);
        if (debug) {
            cout << "amenities3: " << head->amenities3 << endl;
        }
        houses_db.ignore(); //eat the delimiter

        houses_db.ignore(); //eat the final newline 

        house * housetemp = new house;
        housetemp->next = head;
        head = housetemp;

    }

}

Housing::~Housing(){

}

int main() {

    char filename[20];

    strcpy(filename, "houses.txt");
    Housing housing(filename);
    housing.Display_all();
    //housing.Display_by_price();
    //housing.Display_by_name();
    return 0;

}





