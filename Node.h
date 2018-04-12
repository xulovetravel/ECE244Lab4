/* 
 * File:   Node.h
 * Author: xuzhuoju
 *
 * Created on October 11, 2015, 1:28 PM
 */



#ifndef NODE_H
#define NODE_H
#define MAX_RESISTORS_PER_NODE 5

#include "Resistor.h"
#include "ResistorList.h"
#include <string>
#include <iostream>
#include <iomanip>

class Node {
private:
    int nodeNum;
    int numRes;
    Node *next;
    ResistorList *reshead;
    double voltage;
    bool set;
    // stores the index of each resistor connected

public:
    //Node();
    ~Node();
    friend class NodeList;  
    friend class ResistorList;
    friend class Resistor;
    friend class Rparser;
    // Updates resIDArray to show the resistor in position rIndex in
    // the resistor array is now connected to this node.
    // Returns true if successful
    //int getData() const;
    //Node *getlink() const;
    //void setData(int nodeValue);
    //void setLink(Node *next);
    Node(int nodeNum_,Node *nextNode);
    Node *getNext();
    void setNext(Node *nextNode);
    int addResistor();
    void printNode();
    // prints the whole node
    // nodeIndex is the position of this node in the node array.
    int getNodeNum();
    int getNodeNum2(int nodeNum_);
    ResistorList* gethead();
    void setNodeNum(int nodeNum_);
    bool findRes(string name);
    //double getVoltage() const;
    //void setVoltage(double voltage_);
    void print(int nodeIndex);
    void modifyRes(string name, double resistance);
    //Use this to check if node is larger than 5.
    bool check();
    //Use numRes to return the number of Resistors, for printNode.
    int getNumRes();
    void deleteR(string name);
    void printRes(string name);
    //Use this to make the instead of void print(int nodeIndex).
    void print2(Resistor*a);
    //return this function to return resIDArray.
    int takeoutResistor(int rIndex);
    double getVoltage();
    void printNode2();
    //below these voltage functions are to set and get voltage
    void setVoltage(double voltage_);
    void unsetVoltage();
    void setNewVoltage(double voltage_);
    void unsetNewVoltage();
    void changeVoltage(double voltage_);
    //to return set, used in command solve.
    bool getset();
};


extern int nodeid1, nodeid2, count;
extern Resistor *a;

#endif /* NODE_H */


