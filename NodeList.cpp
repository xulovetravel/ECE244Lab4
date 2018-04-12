/* 
 * File:   NodeList.cpp
 * Author: xuzhuoju
 * 
 * Created on October 30, 2015, 9:10 PM
 */
#include "Resistor.h"
#include "Node.h"
#include "ResistorList.h"
#include "NodeList.h"
#include <iostream>
#include <string>
#include <iomanip>

NodeList::NodeList() {
    nodehead = NULL;
}

NodeList::NodeList(const NodeList& orig) {

}

Node*NodeList::gethead() {
    return nodehead;
}

//void NodeList::setLink(NodeList *next) {
// nodehead=next;
//}

int NodeList::countNode() {
    //add the resistor
    int count;
    Node *temp = nodehead;
    while (temp != NULL) {
        count += 1;
        temp = temp->next;
    }
    return count;
}
//finding the Node for solve and so on.
Node* NodeList::findNode(int nodeNumber) {
    Node *temp = nodehead;
    while (temp != NULL) {
        if (nodeNumber == temp->getNodeNum()) {
            return temp;
        }
        temp = temp->next;
    }
}
//Use this for command printR
void NodeList::printR(string name) {
    Node* temp = nodehead;
    while (temp != NULL) {
        temp->reshead->printR(name);
        if (temp->reshead->findResistance(name) == true) {
            break; //prevent printing twice
        }
        temp = temp->next;
    }
}

//insert the node and make new node in insertNode, then put in insertR
//and node.cpp
void NodeList::insertNode(int nodeNumber) {
    Node* temp = nodehead;
    Node* prev;
    if(temp == NULL){ //if there are no nodes in list
        Node* node = new Node(nodeNumber, NULL);
        nodehead = node;
    }
    else{
        bool breakCase1 = false;
        bool breakCase2 = false;
        while(temp != NULL){
            //if the node to insert's number is smaller 
            //than the head node's number
            if (temp->getNodeNum() > nodeNumber){ 
                breakCase1 = true;
                //to prevent checking twice
                break; 
            }
            if (temp->next != NULL){
                //if the next node's number is greater than temp nodenumber
                //then insert between current and next node
                if(temp->next->getNodeNum() > nodeNumber){ 
                    breakCase2 = true;
                    break;
                }
            }
            prev = temp;
            temp = temp->next;
        }
        //insert to front of list
        if (temp == nodehead && breakCase1 == true && breakCase2 == false){ 
            Node* node = new Node(nodeNumber, temp);
            nodehead = node;
        }
        //insert in middle of list
        else if (breakCase1 == false && breakCase2 == true){ 
            Node* node = new Node(nodeNumber, temp->next);
            temp->setNext(node);
        }
        //insert to end of list
        else if (temp == NULL){ 
            Node* node = new Node(nodeNumber, NULL);
            prev->setNext(node);
        }
    }
}

//check the existence of the node
bool NodeList::nodeExist(int nodeNumber) {
    Node *temp = nodehead;
    while (temp != NULL) {
        if (temp->getNodeNum() == nodeNumber) {
            return true;
        }
        temp = temp->next;
        
    }
    return false;
}

//check the voltage, to use it for solve command.
bool NodeList::checkVoltage(int nodeNumber) {
    Node *temp = nodehead;
    while (temp != NULL) {
        if (temp->getNodeNum() == nodeNumber) {
            temp->getVoltage();
            return true;
        }
        temp = temp->next;
       
    }
     return false;
}

//count the voltage,planning to do printNode command
int NodeList::countVoltage() {
    //set the 
    int count = 0;
    Node *temp = nodehead;
    while (temp != NULL) {
        count += 1;
        temp = temp->next;
    }
    return count;
}

//destructor
NodeList::~NodeList() {
}

