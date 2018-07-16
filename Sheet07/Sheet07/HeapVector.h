//
//  HeapVector.h
//  Sheet07
//
//  Created by QuMing on 14/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#ifndef __Sheet07__HeapVector__
#define __Sheet07__HeapVector__

#include <stdio.h>
#include <vector>
class HeapVector {
    std::vector<double> values;
    int size;
    
public:
    HeapVector();
    ~HeapVector();
    unsigned int heap_size();
    double top() const; // returns the smallest element
    void insert( double d ); // inserts value d into the heap
    void pop_top(); // removes the smallest element
    void print();

};



#endif /* defined(__Sheet07__HeapVector__) */
