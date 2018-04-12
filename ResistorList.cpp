/* 
 * File:   ResistorList.cpp
 * Author: xuzhuoju
 * 
 * Created on October 30, 2015, 9:10 PM
 */

#include "ResistorList.h"
#include "Resistor.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

ResistorList::ResistorList() {
    reshead == NULL;
}

void ResistorList::insertResistance(string name, double resistance, int node1, int node2) {
    Resistor *temp = reshead;
    Resistor *temp2 = reshead;
    //add the resistor at the beginning
    if (temp == NULL) {
        Resistor *newres = new Resistor(name, resistance, node1, node2, NULL);
        reshead = newres;
    }//add the resistor at the end of the list for the second time
    else {
        while (temp->getNext() != NULL) {
            temp = temp->getNext();
        }
        Resistor *newres = new Resistor(name, resistance, node1, node2, NULL);
        temp->setNext(newres);
    }
}

void ResistorList::insertResistance2(string name, double resistance, int node1, int node2) {
    Resistor *temp = reshead;
    //add the resistor at the beginning
    if (temp == NULL) {
        Resistor *newres = new Resistor(name, resistance, node1, node2, NULL);
        reshead = newres;
    }//add the resistor at the end of the list for the second time
    else {
        while (temp->getNext() != NULL) {
            temp = temp->next;
        }
        Resistor *newres = new Resistor(name, resistance, node1, node2, NULL);
        temp->setNext(newres);
    }
}
//Use it for command modifyR

Resistor* ResistorList::findResPointer(string name) {
    Resistor *temp = reshead;
    while (temp != NULL) {
        if (temp->getName() == name) {
            return temp; //returns pointer to needed resistor
        }
        temp = temp->next;
    }
    return NULL; //if not found return NULL
}

bool ResistorList::findResistance(string name) {
    Resistor *temp = reshead;
    while (temp != NULL) {
        if (temp->getName() == name) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void ResistorList::modifyR(string name, double resistance) {
    Resistor *temp = reshead;
    while (temp != NULL) {
        if (temp->getName() == name) {
            temp->setResistance(resistance);
        }
        temp = temp->next;
    }
}

void ResistorList::printR(string name) {
    Resistor *temp = reshead;
    while (temp != NULL) {
        if (temp->getName() == name) {
            cout << "Print: " << endl;
            temp->print3();

        }
        temp = temp->next;
    }

}

void ResistorList::printRAll() {
    Resistor *temp = reshead;
    while (temp != NULL) {
        temp->print2();
        temp = temp->next;
    }
}

bool ResistorList::checkResistance(string name) {
    Resistor *temp = reshead;
    while (temp != NULL) {
        if (temp->getName() == name) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
//bool ResistorList::checkVoltage(int nodeNumber) {
// Resistor *temp = reshead;
//while (temp != NULL) {
//if (temp->getNodeNum() == nodeNumber) {
//temp->getVoltage();
//return true;
//}
// temp = temp->next;
// return false;
// }
//}

Resistor* ResistorList::gethead() {
    return reshead;
}

bool ResistorList::deleteResistance(string name) {
    Resistor *temp = reshead;
    Resistor *prev;
    while (temp != NULL) {
        if (temp->getName() == name) {
            //want to delete at the beginning(more than one)
            if (temp == reshead && temp->next != NULL) { 
                Resistor *temp2 = reshead;
                reshead = reshead->next;
                delete temp2;
                return true;
                //only 1 object to delete (beginning case)
            } else if (temp == reshead && temp->next == NULL) { 
                Resistor *temp2 = reshead;
                delete temp2;
                reshead = NULL;
                return true;
                //want to delete at the end
            } else if (temp != reshead && temp->next == NULL) {
                delete temp;
                prev->setNext(NULL);
                return false;
            } //want to delete in the middle of list
            else { 
                prev->setNext(temp->next);
                delete temp;
                return false;
            }
        }
        prev = temp;
        temp = temp->next;
    }
}

void ResistorList::deleteAll() {
    Resistor *temp = reshead;
    Resistor *prev;
    while (temp != NULL) {
        prev = temp;
        temp = temp->next;
        delete prev;
    }
    reshead = NULL;
}

double ResistorList::calculation() {
    double denominator = 0;
    Resistor *temp = reshead;
    while (temp != NULL) {
        denominator += (1 / (temp->getResistance()));
        temp = temp->next;
    }
    return (denominator);
}

int ResistorList::countResistor() {
    //add the resistor
    int count = 0;
    Resistor *temp = reshead;
    while (temp != NULL) {
        count += 1;
        temp = temp->next;
    }
    return count;
}

