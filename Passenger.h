/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passenger.h
 * Author: williamsullivan
 *
 * Created on May 12, 2020, 1:33 PM
 */

#ifndef PASSENGER_H
#define PASSENGER_H
#include <string>

using namespace std;
class Passenger {
public:
    Passenger();
    Passenger(string line, bool genBoard);
    int getKey();
    string getLastName();
    char getType();
    int getRow();
    void setKey(int k);
    void setLastName(string n);
    void setType(char t);
    void setRow(int r);
    
    bool operator> (const Passenger &right);
    bool operator< (const Passenger &right);
    bool operator== (const Passenger &right);

    friend ostream& operator<< (ostream& out, Passenger& rhs);

private:
    int key;
    string lastName;
    char type;
    int row;
    bool priority;

};

#endif /* PASSENGER_H */

