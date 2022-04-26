/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Passenger.cpp
 * Author: williamsullivan
 * 
 * Created on May 12, 2020, 1:33 PM
 */
#include "Passenger.h"
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

Passenger::Passenger() {
}
Passenger::Passenger(string line, bool genBoard) {
    stringstream ss(line);
    ss >> lastName;
    ss >> type;
    ss >> row;
    key = 1;
    if(type == 'H'){
        priority = true;
        key = 7;
    }else if(row <= 4){
        priority = true;
        key = 6;
    }else if(row == 10 || row == 11 || type == 'E'){
        priority = true;
        key = 5;
    }else {
        priority = false; 
    }
//Parameter flag indicates if non-priority get sorted
    if(genBoard && !priority){
        if(row <= 26 && row >= 23) {    
            key = 4; 
        } else if(row <= 22 && row >= 17) {
            key = 3;
        } else if(row <= 16 && row >= 11) {
            key = 2; 
        } else if(row <= 10 && row >= 5) {
            key = 1; 
        }

    }
}
int Passenger::getKey() {
    return key;
}
string Passenger::getLastName() {
    return lastName;
}
char Passenger::getType() {
    return type;
}
int Passenger::getRow() {
    return row;
}
void Passenger::setKey(int k) {
    key = k;
}
void Passenger::setLastName(string n) {
    lastName = n;
}
void Passenger::setType(char t) {
    type = t;
}
void Passenger::setRow(int r) {
    row = r;
}
bool Passenger::operator> (const Passenger &right) {
    return (key > right.key);
}
bool Passenger::operator< (const Passenger &right) {
    return (key < right.key);
}
bool Passenger::operator== (const Passenger &right) {
    return (key == right.key && lastName == right.lastName && type == right.type && row == right.row);
}
ostream& operator<< (ostream& out, Passenger& rhs) {
    out << setw(15) << left << rhs.lastName << "\t"
            << setw(5) << left << rhs.type << "\t"
            << "\t" << setw(5) << left << rhs.row << endl;
    return out;
} 

