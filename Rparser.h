/* 
 * File:   Rparser.h
 * Author: xuzhuoju
 *
 * Created on October 11, 2015, 12:56 PM
 */

#ifndef RPARSER_H
#define	RPARSER_H
#include "Rparser.h"
#include "Node.h"
#include "Resistor.h"
#include "ResistorList.h"
#include "NodeList.h"

class Rparser {
public:
    friend class Node;
    friend class NodeList;  
    friend class Resistor;
    friend class ResistorList;
    //Use this for printing out result,since it is a requirement.
    Rparser();
    Rparser(const Rparser& orig);
 
private:

};

#endif	/* RPARSER_H */

