/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file:   main.cpp
 * @author: William Sullivan
 *
 * Created on April 14, 2019, 6:45 PM
 */

#include <cstdlib>
#include <iostream>
#include "ArrayMaxHeap.h"
#include "Airworthy.h"

using namespace std;

/*
 * 
 */
void description() {
    cout << "The following program simulates the total boarding \n"
            "times for different boarding procedures at 70% plane \n"
            "capacity, 85% plane capacity, and 100% plane capacity."
            << endl;
    cout << endl;
}
int main() {
//    ArrayMaxHeap<int> priQ;
//    cout << boolalpha << "Empty? " << priQ.isEmpty() << endl;
//    
//    cout << "Adding 1000 " << endl;
//    priQ.add(1000);
//    
//    cout << priQ.getItemCount() << " items" << endl;
//    cout << "Highest priority: " << priQ.peek() << endl;
//    
//    priQ.remove();


    Airworthy pass;
    Airworthy pass2;
    Airworthy pass3;
    const string FILENAME = "airworthy70.txt";
    const string FILENAME2 = "airworthy85.txt";
    const string FILENAME3 = "airworthy100.txt";
    
    description();
    pass.readFile(FILENAME);   
    pass.runSim("results70.txt");
    
    pass2.readFile(FILENAME2);
    pass2.runSim("results85.txt");
    
    pass3.readFile(FILENAME3);
    pass3.runSim("results100.txt");
   
    
    //readFile(FILENAME);
    return 0;
}

