/* 
 * File:   Node.cpp
 * Author: xuzhuoju
 * 
 * Created on October 11, 2015, 1:28 PM
 */
#include "ResistorList.h"
#include "NodeList.h"
#include "Node.h"
#include "Resistor.h"
#include <string>
#include <iomanip>


//Constructor
Node::Node(int nodeNum_, Node *nextNode) {
    nodeNum = nodeNum_;
    next = nextNode;
    //set initial voltage to 0;
    voltage = 0;                
    //a new ResistorList,more like a bridge
    reshead = new ResistorList;    
    //use this for solve,setV,unsetV
    set = false; 
}

//Destructor
Node::~Node() {
    //corrsponds to reshead=new in the constructor
    delete reshead;
}

//used to return next, but mainly used friend instead of this function.
Node*Node::getNext() {
    return next;
}

//set the next node
void Node::setNext(Node *nextNode) {
    next = nextNode;
    return;
}

//get the node number
int Node::getNodeNum() {
    return nodeNum;
}

//another way of getting node number, depending for the situation 
int Node::getNodeNum2(int nodeNum_) {
    return nodeNum;
}

//set new nodeNumber
void Node::setNodeNum(int nodeNum_) {
    nodeNum = nodeNum_;
    return;
}

//used to find resistor's name.
bool Node::findRes(string name) {
    return reshead->findResistance(name);
}

//return head, use friend function in the main as reshead
ResistorList* Node::gethead() {
    return reshead;
}

//print the node
void Node::printNode() {
    if (reshead->countResistor()>0) {
        cout << "Connections at node " << nodeNum << ": " << 
                reshead->countResistor() << " resistor(s)" << endl;
        reshead->printRAll();
    }
    else if (set) {
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std::cout << "Connections at node " << nodeNum << ": " << 
                std::setprecision(2)<< voltage << " V " << endl;
    }
}

//Use this to print the voltage if resistor is not there.
void Node::printNode2() {
    if (set) {
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std:: cout << "Connections at node " << nodeNum << ": " << 
                 std::setprecision(2)<< voltage << " V " << endl;
    }
}

//to set new voltage and set it to true
void Node::setVoltage(double voltage_) {
    voltage = voltage_;
    set = true;
}

//unset the voltage, to return voltage=0, set=false.
void Node::unsetVoltage() {
    set = false;
    voltage = 0;
}

//change the voltage
void Node::changeVoltage(double voltage_) {
    voltage = voltage_;
}

//return set, in solve command
bool Node::getset() {
    return set;
}

//return voltage, used as friend in setV, unsetV, solve.
double Node::getVoltage(){
    return voltage;
}




