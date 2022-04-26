/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Airworthy.cpp
 * Author: williamsullivan
 * 
 * Created on May 13, 2020, 12:08 PM
 */

#include "Airworthy.h"
#include <fstream>
using namespace std;

const int NOTBLOCKED = 1, BLOCKED = 25;
Airworthy::Airworthy() {
}

void Airworthy::readFile(const string FILENAME) {
	string inString;
	ifstream inFile(FILENAME);
//        string tempLastName;
//        string tempRow;
//        string strType;
//        char tempType;
//        int tempIntRow;
	if (!inFile)
		cout << "Error opening file - " << FILENAME << endl;
	else {
		getline (inFile, inString);
		while (inFile) {
			Passenger newPass(inString, true);
                        Passengers.add(newPass);
                        
                        Passenger pass2(inString, false);
                        newMethod.add(pass2);
			getline (inFile, inString);

		}
		inFile.close();
                cout << FILENAME << " loaded." << endl;
	}
}

void Airworthy::runSim(string myFile) {
    ofstream outFile(myFile);
    Passenger pass1;
    Passenger pass2;
    int tempRow = 100;
    seconds = 0;
    newSeconds = 0;
    int capacity = Passengers.getItemCount();
    int newCapacity = newMethod.getItemCount();
    string cap;
    string newCap;
    cout << "Total passengers: " << capacity << endl;
    if(capacity == 103) {
        cap = "70% capacity";
        cout << "Plane capacity: 70%" << endl;
    }else if (capacity == 125) {
        cap = "85% capacity";
        cout << "Plane capacity: 85%" << endl;
    }else {
        cap = "100% capacity";
        cout << "Plane capacity: 100%" << endl;
    }
    cout << endl;

    cout << "Simulating first boarding procedure at " << cap << endl;
    cout << endl;
    while(!Passengers.isEmpty()) {
        pass1 = Passengers.peek();         
        cout << pass1;
        Passengers.remove();      
        if(tempRow < pass1.getRow()) {
            seconds += 25;
        } else seconds +=1;
        tempRow = pass1.getRow();
    }
    cout << endl;
    double minutes = seconds / 60;
    cout << "Minutes: " << minutes << endl;
    cout << endl;
    
    cout << "Total passengers: " << newCapacity << endl;
    if(newCapacity == 103) {
        newCap = "70% capacity";
        cout << "Plane capacity: 70%" << endl;
    }else if (newCapacity == 125) {
        newCap = "85% capacity";
        cout << "Plane capacity: 85%" << endl;
    }else {
        newCap = "100% capacity";
        cout << "Plane capacity: 100%" << endl;
    }
    cout << endl;

    cout << "Simulating second boarding procedure at " << newCap << endl;
    cout << endl;
    while(!newMethod.isEmpty()) {
        pass2 = newMethod.peek();
        cout << pass2;
        newMethod.remove();
        if(tempRow < pass2.getRow()) {
            newSeconds += 25;
        } else newSeconds +=1;
        tempRow = pass1.getRow();
    }
    cout << endl;
    double newMinutes = newSeconds / 60;
    cout << "New procedure minutes: " << newMinutes << endl;
    cout << endl;
    
    
}


