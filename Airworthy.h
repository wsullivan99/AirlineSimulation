/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Airworthy.h
 * Author: williamsullivan
 *
 * Created on May 13, 2020, 12:08 PM
 */

#ifndef AIRWORTHY_H
#define AIRWORTHY_H
#include <string>
#include <iostream>
#include "Passenger.h"
#include "ArrayMaxHeap.h"
#include "HeapADT.h"

class Airworthy {
public:
    Airworthy();
    void readFile(const string FILENAME);
    void runSim(string myFile);
    void writeFile(string myFile);
    
private:
    ArrayMaxHeap<Passenger> Passengers;
    ArrayMaxHeap<Passenger> newMethod;
    int seconds;
    int newSeconds;

};

#endif /* AIRWORTHY_H */

