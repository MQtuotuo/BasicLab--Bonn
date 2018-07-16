//
//  DynamicDoubleArray.cpp
//  Sheet07
//
//  Created by QuMing on 14/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#include "DynamicDoubleArray.h"
#include "DynamicDoubleArray.h"
DynamicDoubleArray::DynamicDoubleArray(){
    size = 0;
    elements = new double[100];
    
}

DynamicDoubleArray::~DynamicDoubleArray(){
    delete [] elements;
}

int DynamicDoubleArray::get_size(){
    return size;
}

double& DynamicDoubleArray::at(int idx){
    return elements[idx];
}

void DynamicDoubleArray::push_back(double d){
    elements[size] = d;
    size++;
}

void DynamicDoubleArray::remove(int idx){
    for(int i=idx; i<size; i++){
        elements[i]=elements[i+1];
    }
    elements[size-1]=0;
    size--;
}

void DynamicDoubleArray::clear(){
    for (int i=0; i<size; i++) {
        elements[i]=0;
    }
    size=0;
}
