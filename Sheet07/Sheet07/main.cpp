//
//  main.cpp
//  Sheet07
//
//  Created by QuMing on 14/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#include <iostream>
#include "Heap.h"
#include "DynamicDoubleArray.h"
#include "HeapVector.h"
#include <limits>
using namespace std;


int main(int argc, const char * argv[]) {
    Heap heap;
    cout<<"Heap: inserting the inputs: "<<endl;
    double input[20] = { 29, 49, 52, 26, 29, 89, 11, 91, 65, 68, 91, 44, 19, 74, 51, 77, 93, 90, 56, 28 };
    for (int i = 0; i < 20; i++){
        heap.insert(input[i]);
        heap.print();
    }
   
    
    cout<<"//////////////////Assignment 1(b)///////////////////"<<endl;
    DynamicDoubleArray dda;
    cout<<"Heap: removing the smallest number iteratively: "<<endl;
    for (int j = 0; j <20; j++){
        dda.push_back(heap.top());
        heap.pop_top();
        heap.print();
    }
    
    cout<<"Heap: after appending, the dynamic array is "<<endl;
    for (int j = 0; j <20; j++){
        cout<<dda.at(j)<<" ";
    }
    cout<<endl<<endl;
    
    cout<<"//////////////////Assignment 1(c)///////////////////"<<endl;
    cout<<"top:o(n);      insert: o(logn);    poptop: o(logn)  "<<endl<<endl;
    
    cout<<"//////////////////Assignment 2(a)///////////////////"<<endl;
    cout<<"i: an arbitrary valid index of the array storing the heap."<<endl;
    cout<<"If tree root at index 0, with valid indices 0 througn n-1  "<<endl;
    cout<<"For each element at index i: "<<endl<<"children at indices 2i + 1 and 2i + 2  "<<endl;
    cout<<"parent at index floor((i − 1) ∕ 2)  "<<endl;
    cout<<"If tree root at index 1, with valid indices 1 througn n  "<<endl;
    cout<<"For each element at index i: "<<endl<<"children at indices 2i and 2i + 1  "<<endl;
    cout<<"parent at index floor(i ∕ 2)  "<<endl<<endl;
    
    cout<<"//////////////////Assignment 2(b)///////////////////"<<endl;
    cout<<" Binary tree can be stored in an array. No space is required for Pointer"<<endl;
    
    cout<<"//////////////////Assignment 2(c)///////////////////"<<endl;
    cout<<"HeapVector: inserting the inputs: "<<endl;
    HeapVector hv;
    for (int i = 0; i < 20; i++){
        hv.insert(input[i]);
        hv.print();
    }
    
    cout<<"HeapVector: removing the smallest number iteratively: "<<endl;
    DynamicDoubleArray dda1;
    hv.print();
    for (int j = 0; j <20; j++){
        dda1.push_back( hv.top());
        hv.pop_top();
        hv.print();
    }
    
    cout<<"HeapVector: after appending, the dynamic array is "<<endl;
    for (int j = 0; j <20; j++){
        cout<<dda1.at(j)<<" ";
    }

    
    return 0;
}
