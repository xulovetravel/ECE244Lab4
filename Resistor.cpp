/* 
 * File:   Resistor.cpp
 * Author: xuzhuoju
 * 
 * Created on October 9, 2015, 3:18 PM
 */
#include "ResistorList.h"
#include "NodeList.h"
#include "Resistor.h"
#include "Node.h"

//set resistor function the new next is setting initial 
Resistor::Resistor(string name_, double resistance_, 
        int nodeid1, int nodeid2, Resistor *nextRes) {
    name = name_;
    resistance = resistance_;
    endpointNodeIDs[0] = nodeid1;
    endpointNodeIDs[1] = nodeid2;
    next = nextRes;
}

//constructor
Resistor::Resistor() {
}

//destructor
Resistor::~Resistor() {

}

//return name, use friend in Rparser.cpp
string Resistor::getName() const {
    return name;
}

//return next, use friend in Rparser.cpp
Resistor* Resistor::getNext() {
    return next;
}

//set new next.
void Resistor::setNext(Resistor *nextRes) {
    next = nextRes;
    return;
}




double Resistor::getResistance() const {
    return resistance;
}

void Resistor::setResistance(double resistance_) {
    resistance = resistance_;
    return;
}

//return the name
void Resistor::setname(string name_) {
    name = name_;
    return;
}

//return the terminals for nodes
void Resistor::setTerminals(int term1, int term2) {
    endpointNodeIDs[0] = term1;
    endpointNodeIDs[1] = term2;
    return;
}

//return nodeid1
int Resistor::getTerminal1() const {
    return endpointNodeIDs[0];
}

//return nodeid2
int Resistor::getTerminal2() const {
    return endpointNodeIDs[1];
}

//Use this for insertR
void Resistor::print() {
    cout << "resistor" << " " << name << " "
            << resistance << " " << "Ohms " << endpointNodeIDs[0]
            << " -> " << endpointNodeIDs[1] << endl;
    return;
}

//Use this for printR command
void Resistor::print2() {
    cout << "  " << left << setw(20) << name << " " << right << setw(8)
            << resistance << " " << "Ohms " << endpointNodeIDs[0]
            << " -> " << endpointNodeIDs[1] << endl;
    return;
}

//Use this for printNode command
void Resistor::print3() {
    cout << left << setw(20) << name << " " << right << setw(8)
            << resistance << " " << "Ohms " << endpointNodeIDs[0]
            << " -> " << endpointNodeIDs[1] << endl;
    return;
}

void Resistor::print4() {
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout << "Inserted: resistor " << name << " " <<
            std::setprecision(2) << resistance << " Ohms"
            << " " << nodeid1 << " -> " << nodeid2 << endl;
    return;
}


