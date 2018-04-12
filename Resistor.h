/* 
 * File:   Resistor.h
 * Author: xuzhuoju
 *
 * Created on October 9, 2015, 3:18 PM
 */

#ifndef RESISTOR_H
#define	RESISTOR_H


#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Resistor {
private:
    double resistance;
    // resistance (in Ohms)
    string name;
    // C++ string holding the label
    int endpointNodeIDs[2]; // IDs of nodes it attaches to
    Resistor *next;
    
public:
    friend class Node;
    friend class NodeList;  
    friend class ResistorList;
    friend class Rparser;
    Resistor();
    Resistor(string name_, double resistance_, int nodeid1, int nodeid2, Resistor *nextRes);
    // rIndex_ is the index of this resistor in the resistor array
    // endpoints_ holds the node indices to which this resistor connects
    ~Resistor();
    string getName() const;
    // returns the name
    double getResistance() const;
    // returns the resistance
    Resistor *getNext();
    void setResistance(double resistance_);
    // you *may* create either of the below to print your resistor
    int getTerminal1()const;
    int getTerminal2()const;
    void setTerminals(int term1, int term2);
    void setname(string name_);
    void setNext(Resistor *nextRes);
    
    //Use this for insertR to print out result
    void print();
    //Use this for printR to print out result
    void print2();
    //Use this for printNode to print out result
    void print3();
    void print4();
    void print5(); 
    friend ostream& operator<<(ostream&, const Resistor&);
};
ostream& operator<<(ostream&, const Resistor&);
#endif	/* RESISTOR_H */

