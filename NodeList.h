/* 
 * File:   NodeList.h
 * Author: xuzhuoju
 *
 * Created on October 30, 2015, 9:10 PM
 */

#ifndef NODELIST_H
#define	NODELIST_H

#include "Node.h"
#include "ResistorList.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
class NodeList {
private:
    Node *nodehead;
    Node *newnode;
public:
    friend class Node;  
    friend class ResistorList;
    friend class Resistor;
    friend class Rparser;
    NodeList();
    NodeList(const NodeList& orig);
    int countNode();
    void printR(string name);
    void insertNode(int nodeNumber);
    Node* findNode(int nodeNumber);
    bool nodeExist(int nodeNumber);
    void insertR(string name);
    void printR(int nodeNumber);
    int countVoltage();
    bool checkVoltage(int nodeNumber);
    void modifyRes(string name, double resistance);
    Node *gethead();
    ~NodeList();
};
#endif	/* NODELIST_H */

