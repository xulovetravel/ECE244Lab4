/* 
 * File:   ResistorList.h
 * Author: xuzhuoju
 *
 * Created on October 30, 2015, 9:10 PM
 */

#ifndef RESISTORLIST_H
#define	RESISTORLIST_H
#include "Resistor.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class ResistorList {
private:
    Resistor *reshead;
    //Nodelist *nodehead;
public:
    friend class Node;
    friend class NodeList;  
    friend class Resistor;
    friend class Rparser;
    ResistorList();
    ResistorList(const ResistorList& orig);
    void insertResistance(string name, double resistance, int node1, int node2);
    void insertResistance2(string name, double resistance, int node1, int node2);
    bool checkResistance(string name); // check the resistor name
    bool deleteResistance(string name); //delete the resistor name
    void checkName(string name); //check the resistor name
    void printRAll();//print all resistors
    void deleteAll();//delete all resistors
    Resistor* findResPointer(string name);//used this for modifyR
    bool checkVoltage(int nodeNumber);//check the existence of voltage
    bool findResistance(string name);
    void modifyR(string name, double resistance);
    void printR(string name);
    double calculation();//calculate the term1
    Resistor *gethead();
    //virtual ~ResistorList();
    int countResistor();
};

#endif	/* RESISTORLIST_H */

