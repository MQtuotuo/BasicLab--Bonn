//
//  LinkedList.h
//  Sheet06
//
//  Created by QuMing on 6/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#ifndef __Sheet06__LinkedList__
#define __Sheet06__LinkedList__

#include <stdio.h>
#include <string>


struct Element {
    Element* _previous;
    Element* _next;
    std::string value;
};
class LinkedList {
private:
    Element* _head;
    Element* _tail;
    unsigned int number_of_elements;
public:
       
    LinkedList();
    ~LinkedList();
    Element* head();     // return first element
    Element* tail();     // return last element
    unsigned int size(); // return number of elements
    Element* remove(Element* element); // remove element e, return the previous element
    Element* insert(Element* previous, std::string value);
    // add value after ’previous’; if ’previous’ is ’NULL’ prepend; return the new element
    void clear();  // clear elements
    void print();  // print contents
    
    unsigned int remove_value(std::string value);
    void insert_sorted(std::string value);
    
   };


#endif /* defined(__Sheet06__LinkedList__) */
