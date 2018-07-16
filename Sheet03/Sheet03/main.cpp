//
//  main.cpp
//  Sheet03
//
//  Created by QuMing on 12/5/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#include <iostream>
using namespace std;

void task1_b();
void task1_c();
void task1_def();
void task2();


void callByValue(int value);
void callByReference(int& reference);
void callByPointer(int* pointer);
int string_length(const char* string);
char* string_copy(const char* string);
double getMean();
double getVariance();


int main(int argc, const char * argv[]) {
    task1_b();
    task1_c();
    task1_def();
    task2();
    return 0;

}

void task1_b(){
    cout << "\n/////////////Assignment 1_b ///////////////" << endl;
    double number = 10.0;
    double& reference(number); // reference to variable number
    double* pointer(&number); // pointer to variable number
    std::cout << &number << "; " << &reference << "; " << pointer << std::endl;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    *pointer = 15;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    reference = 50;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    number = 10;
    std::cout << number << "; " << reference << "; " << *pointer << std::endl;
    
}

void task1_c(){
     cout << "\n/////////////Assignment 1_c ///////////////" << endl;
    int value = 0;
    callByValue(value);
    std::cout << value << std::endl;
    callByReference(value);
    std::cout << value << std::endl;
    callByPointer(&value);
    std::cout << value << std::endl;
}

void callByValue(int value) {
    //std::cout << value << std::endl;
    value = 5;
}
void callByReference(int& reference) {
    reference = 10;
}
void callByPointer(int* pointer) {
    *pointer = 20;
}

void task1_def(){
    cout << "\n/////////////Assignment 1_d ///////////////" << endl;
    double array[5] = { 10.0, 20.0, 30.0, 40.0, 50.0 };
    double* begin = array;
    std::cout << *(begin + 0) << std::endl;
    std::cout << *(begin + 1) << std::endl;
    std::cout << *(begin + 2) << std::endl;
    double* end = array + 5;
    int diff = end - begin;
   
    diff/= 2;
    //std::cout << *(end - 2) << std::endl;
    double value = *(begin + 1) + *(end - (diff));
    
    std::cout << value << std::endl;
    std::cout << *end << std::endl;
    
    
    cout << "\n/////////////Assignment 1_e ///////////////" << endl;
    double* ptr = begin;
    
    while (ptr != end) {
        std::cout << *(ptr ++) << " ";
    }
    std::cout << endl;
    ptr = end;
    while (ptr != begin) {
        std::cout << *(-- ptr) << " ";
    };
    std::cout << endl;
    
    cout << "\n/////////////Assignment 1_f ///////////////" << endl;
    
    
    for(const double* ptr=end-1; ptr != begin; ) {
        std::cout << *(-- ptr) << " ";
    }
    cout<<endl;
    for(const double* ptr=end-1; ptr != begin; --ptr) {
        std::cout << *ptr << " ";
        
    }
    cout<<endl;
    for(const double* ptr=end-1; ptr >= begin; --ptr) {
        std::cout << *ptr << " ";
    }
    

}

int string_length(const char* string) {
    int length = 0;
    for(const char* ptr = string; *ptr != '\0'; ++ ptr) {
        ++ length;
    }
    return length;
}

char* string_copy(const char* string) {
    // we need to add 1 because of ’\0’
    char* result = new char[string_length(string) + 1];
    // write your code here (remember zero-termination !)
    for(int idx = 0; idx < string_length(string) + 1; ++ idx) {
        result[idx] = *(string+idx);
    }
   // delete [] result;
    return result;
}

void task2() {
    
    cout << "\n/////////////Assignment 2_a ///////////////" << endl;
    const char* string_c = "This is a string and is a long one so that we can create memory leaks when it is copied and not deleted";
    // write your code here
    cout << string_copy(string_c) <<endl;
    
    cout << "\n/////////////Assignment 2_b ///////////////" << endl;
    char* copy=string_copy(string_c);
    for(int i=0; i<1000000; i++){
        char* old=copy;
        copy=string_copy(copy);
        delete []old;
        
    }
    cout<<copy<<endl;
    delete []copy;
    
    cout << "\n/////////////Assignment 2_c ///////////////" << endl;
    cout <<"DO NOT delete: Require memory 106.3 MB"<<endl;
    cout <<"ADD delete: Require memory 488 KB"<<endl;
    
    cout << "\n/////////////Assignment 2_d ///////////////" << endl;
    int i,n;
    int * p;
    double sum = 0;
    double mean;
    double variance;
    cout << "How many numbers would you like to type? ";
    cin >> i;
    p= new (nothrow) int[i];
    if (p == 0)
        cout << "Error: memory could not be allocated";
    else
        {
            for (n=0; n<i; n++)
            {
                cout << "Enter number: ";
                cin >> p[n]; }
            cout << "You have entered: ";
            for (n=0; n<i; n++){
                cout << p[n] << ", ";
                sum+=p[n];
            }
            cout<<endl;
            mean = sum/n;
            cout<<"The mean is: "<<mean<<endl;
            
            double temp=0;
            for (n=0; n<i; n++){
                temp += (mean-p[n])*(mean-p[n]);
            }
            variance = temp/n;
            cout<<"The variance is: "<<variance<<endl;
            
            delete[] p;
        }
    
}


