/* 
 * File:   Rparser.cpp
 * Author: xuzhuoju
 * 
 * Created on October 11, 2015, 12:56 PM
 */

#include "Rparser.h"
#include "Resistor.h"
#include "ResistorList.h"
#include "Node.h"
#include "NodeList.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#define MAX_NODE_NUMBER 5000
#define MIN_ITERATION_CHANGE 0.0001
int nodeid1, nodeid2, count = 0;
using namespace std;
//ResistorList resistorlist;
NodeList nodelist;
Resistor res;
//Node *findNodeNumber = NULL;

Rparser::Rparser() {
    string line, command;
    string name;
    double voltage;
    double resistors;
    int nodeid1, nodeid2;
    int nodeNumber;
    int newNode1;
    // May have some setup code here
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::setprecision(2);
    while (!cin.eof()) {
        cout << "> ";
        getline(cin, line);

        // Get a line from standard input
        if (cin.eof()) {
            break;
        }
        // Put the line in a stringstream for parsing
        // Making a new stringstream for each line so flags etc. 
        //are in a known state
        stringstream lineStream(line);
        lineStream >> command;
        //declare a new stringstream copy if inserting command printNode
        stringstream copy(line);
        //Typing nothing and only space can cause invalid command
        //insert insertR
        if (command == "insertR") {
            Node* temp = nodelist.gethead();
            // parse an insertR command
            //check for the name
            bool same = false;
            //Firstly, enter the name, resistors, node1 and node2;
            lineStream >> name >> resistors >> nodeid1 >> nodeid2;
            while (temp != NULL) {
                //check the name
                if (temp->findRes(name) == true) {
                    same = true;
                }
                temp = temp->next;
            }
            //if typed the name twice.
            if (same == true) {
                cout << "Error: resistor " << name
                        << " already exists" << endl;
                //below the four cases checks the node
                //if node doesn't exist, insert and then find the node.
                //both cases need to find the node
            } else {
                //condition for existence of both nodes, just find them.
                if (((nodelist.nodeExist(nodeid1)) == true)
                        &&((nodelist.nodeExist(nodeid2)) == true)) {
                    nodelist.findNode(nodeid1)->reshead
                            ->insertResistance(name,
                            resistors, nodeid1, nodeid2);
                    nodelist.findNode(nodeid2)->reshead->
                            insertResistance(name,
                            resistors, nodeid1, nodeid2);
                    std::cout.setf(std::ios::fixed, std::ios::floatfield);
                    std::cout << "Inserted: resistor " << name << " " <<
                            std::setprecision(2) << resistors << " Ohms"
                            << " " << nodeid1 << " -> " << nodeid2 << endl;

                    //condition for nodeid1 doesn't exist, insert the node1
                } else if (((nodelist.nodeExist(nodeid1)) == false)
                        &&((nodelist.nodeExist(nodeid2)) == true)) {
                    nodelist.insertNode(nodeid1);
                    nodelist.findNode(nodeid1)->reshead
                            ->insertResistance(name,
                            resistors, nodeid1, nodeid2);
                    nodelist.findNode(nodeid2)->reshead
                            ->insertResistance(name,
                            resistors, nodeid1, nodeid2);
                    std::cout.setf(std::ios::fixed, std::ios::floatfield);
                    std::cout << "Inserted: resistor " << name << " " <<
                            std::setprecision(2) << resistors << " Ohms"
                            << " " << nodeid1 << " -> " << nodeid2 << endl;

                    //condition for nodeid2 doesn't exist, insert the node2
                } else if (((nodelist.nodeExist(nodeid1)) == true)
                        &&((nodelist.nodeExist(nodeid2)) == false)) {
                    nodelist.insertNode(nodeid2);
                    nodelist.findNode(nodeid1)->reshead
                            ->insertResistance(name,
                            resistors, nodeid1, nodeid2);
                    nodelist.findNode(nodeid2)->reshead
                            ->insertResistance(name,
                            resistors, nodeid1, nodeid2);
                    std::cout.setf(std::ios::fixed, std::ios::floatfield);
                    std::cout << "Inserted: resistor " << name << " " <<
                            std::setprecision(2) << resistors << " Ohms"
                            << " " << nodeid1 << " -> " << nodeid2 << endl;

                    //condition for both nodes doesn't exist, insert both nodes.
                } else {
                    nodelist.insertNode(nodeid1);
                    nodelist.insertNode(nodeid2);
                    nodelist.findNode(nodeid1)->reshead
                            ->insertResistance(name,
                            resistors, nodeid1, nodeid2);
                    nodelist.findNode(nodeid2)->reshead
                            ->insertResistance(name,
                            resistors, nodeid1, nodeid2);
                    std::cout.setf(std::ios::fixed, std::ios::floatfield);
                    std::cout << "Inserted: resistor " << name << " " <<
                            std::setprecision(2) << resistors << " Ohms"
                            << " " << nodeid1 << " -> " << nodeid2 << endl;
                }
            }
        }//insert modifyR
        else if (command == "modifyR") {
            Node* temp = nodelist.gethead();
            double newresistors;
            bool same = false;
            //enter the name and resistors
            lineStream >> name >> newresistors;
            while (temp != NULL) {
                if (temp->findRes(name) == true) {
                    same = true;
                    resistors = temp->reshead->findResPointer(name)->resistance;
                    temp->reshead->modifyR(name, newresistors);
                }
                temp = temp->next;
            }
            if (same == true) {
                std::cout << "Modified: resistor " << name
                        << " from " << std::setprecision(2)
                        << resistors << " Ohms" << " to " << newresistors <<
                        " " << "Ohms" << endl;

            }//print out the right result
            else {
                cout << "Error: resistor " << name << " not found" << endl;
            }
        }            //insert the command printR
        else if (command == "printR") {
            bool same = false; //set it does not found the name
            lineStream>>name;
            Node *temp = nodelist.gethead(); //for checking same name
            Node *temp2 = nodelist.gethead(); //for printing out result
            while (temp != NULL) {
                //if the name has been found
                if (temp->findRes(name) == true) {
                    same = true;
                }
                //move on to the next step
                temp = temp->next;
            }
            //if name is the same as found
            if (same == true) {
                nodelist.printR(name); //use this function to do it.
            } else {
                cout << "Error: resistor " << name << " not found" << endl;
            }
        }//insert the command deleteR
        else if (command == "deleteR") {
            bool same = false;
            lineStream>>name;
            Node *temp = nodelist.gethead();
            //determine the condition for deleteR .
            //determine the condition for typing all.
            if (name == "all") {
                //delete the resistors
                while (temp != NULL) {
                    temp->reshead->deleteAll();
                    temp = temp->next;
                }
                cout << "Deleted: all resistors" << endl;
            } else {
                while (temp != NULL) {
                    if (temp->findRes(name) == true) {
                        temp->reshead->deleteResistance(name);
                        same = true;
                    }
                    temp = temp->next;
                }
                if (same == true) {
                    //if resistor is found
                    cout << "Deleted: resistor " << name << endl;
                } else {
                    //if resistor is not found
                    cout << "Error: resistor " << name << " not found" << endl;
                }
            }
            //enter the command printNode
        } else if (command == "printNode") {
            string specialAll;
            //int nodeNumber;
            lineStream >> specialAll;
            Node *temp = nodelist.gethead();
            if (specialAll == "all") {
                cout << "Print:" << endl;
                while (temp != NULL) {
                    if (temp->reshead != NULL) {
                        temp->printNode();
                    }
                    temp = temp->next;
                }
            } else {
                copy << specialAll;
                copy >> nodeNumber;
                cout << "Print:" << endl;
                while (temp != NULL) {
                    if (temp->reshead != NULL &&
                            temp->getNodeNum() == nodeNumber) {
                        temp->printNode();
                    }
                    temp = temp->next;
                }
            }
        }//enter the command setV
        else if (command == "setV") {
            Node* temp = nodelist.gethead();
            lineStream >> nodeNumber>>voltage;
            //if node does not exist
            if (nodelist.nodeExist(nodeNumber) == false) {
                nodelist.insertNode(nodeNumber);
                nodelist.findNode(nodeNumber)->setVoltage(voltage);
            } else {
                //make a while loop to set new Voltage
                while (temp != NULL) {
                    if (temp->nodeNum == nodeNumber) {
                        temp->setVoltage(voltage);
                    }
                    temp = temp->next;
                }
            }
            std::cout.setf(std::ios::fixed, std::ios::floatfield);
            std::cout << "Set: node " << nodeNumber << " to "
                    << std::setprecision(2) << voltage << " Volts" << endl;
            //insert the command unsetV
        } else if (command == "unsetV") {
            Node* temp = nodelist.gethead();
            lineStream>>nodeNumber;
            //if the node does not exist
            if (nodelist.nodeExist(nodeNumber) == false) {
                nodelist.insertNode(nodeNumber);
            } else {
                //make a while loop to unset voltage.
                while (temp != NULL) {
                    if (temp->nodeNum == nodeNumber) {
                        temp->unsetVoltage();
                    }
                    temp = temp->next;
                }
            }
            cout << "Unset: the solver will determine the voltage of node "
                    << nodeNumber << endl;

        }//insert the command solve
        else if (command == "solve") {
            bool same = false; //check if it has voltage at the point
            bool same2 = false; //to stop the loop
            bool same3 = false; //check for min change smaller than 0.0001
            double result;
            double oldVoltage;

            Node* temp = nodelist.gethead();
            while (temp != NULL) {
                if (temp->set == true) {
                    same = true;
                }
                temp = temp->next;
            }
            if (same == true) {
                //I use do while loop to get the result of answers for voltage
                do {
                    temp = nodelist.gethead();
                    while (temp != NULL) {
                        if (temp->set == false && temp->reshead
                                ->reshead != NULL) {
                            //voltage equation(1st part)
                            double equation1 = 0;
                            //voltage equation(2nd part)
                            double equation2 = 0;
                            oldVoltage = temp->voltage;
                            Resistor *temp2 = temp->reshead
                                    ->reshead;
                            while (temp2 != NULL) {
                                equation1 += (1 / (temp2->getResistance()));
                                temp2 = temp2->next;
                            }
                            //points to list of resistors
                            Resistor* temp3 = temp->reshead->reshead;
                            while (temp3 != NULL) {
                                int Noderesult;
                                if (temp3->getTerminal1() == temp->nodeNum) {
                                    Noderesult = temp3->getTerminal2();
                                } else {
                                    Noderesult = temp3->getTerminal1();
                                }
                                //do the 2nd equation
                                equation2 += (nodelist.findNode(Noderesult)
                                        ->voltage) / (temp3->getResistance());
                                //checks next resistor
                                temp3 = temp3->next;
                            }
                            result = equation2 / equation1;
                            temp->changeVoltage(result);
                            //make same3 to true (MIN_ITERATION>CHANGE))
                            if (abs(oldVoltage - result) 
                                    <= MIN_ITERATION_CHANGE)
                                same3 = true;
                            else
                                same3 = false;
                        }
                        temp = temp -> next;

                    }
                    temp = nodelist.gethead();
                    //if all nodes have been checked,get out of loop.
                    if (same3 == true) {
                        same2 = true;
                    }
                } while (same2 == false);
                cout << "Solve:" << endl;
                //make a linklist to print out result
                temp = nodelist.gethead();
                while (temp != NULL) {
                    if (temp->reshead != NULL) {
                        cout << "  Node " << temp->nodeNum << ": "
                                << temp->voltage << " V" << endl;
                    }

                    temp = temp->next;
                }
            }//the condition that if the node does not have voltage
            else {
                cout << "Error: no nodes have their voltage set" << endl;
            }


            //Finally,do the draw command, but I did not do the bonus
        } else if (command == "draw") {
            ;
        }


    }
}

