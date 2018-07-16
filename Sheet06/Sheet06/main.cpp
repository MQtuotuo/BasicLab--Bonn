//
//  main.cpp
//  Sheet06
//
//  Created by QuMing on 6/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;

bool check(string ani, string animal[]);
int main(int argc, const char * argv[]) {
    string animal[11] = { "wolverine", "chicken", "turtle", "dog", "snail", "cat", "sardine", "zebra", "dog", "snail", "dog" };
    LinkedList ll; //create a list

    cout<<"//////////////////////Assignment 3(c)///////////////////"<<endl;
    cout << "Adding the following animals: " << endl;
    Element* element = NULL;
    for (int i = 0; i < 11; i++){
        ll.insert(element, animal[i]);
        ll.print();
        if (ll.head() ==ll.tail()){
            element = ll.head();
        }
        else{ element = element->_next; }
    }
  
    cout<<"//////////////////////Assignment 3(d)///////////////////"<<endl;
    ll.remove_value("dog");
    ll.remove_value("wolverine");
    cout << "After removing dog and wolverine, the list is: " << endl;
    ll.print();
    ll.clear();
    
    cout<<"//////////////////////Assignment 3(e)///////////////////"<<endl;
    cout << "Insert sorted test: " << endl;
    for (int i = 0; i < 11; i++){
        ll.insert_sorted(animal[i]);
        ll.print();
    }
    
    cout<<"//////////////////////Assignment 3(f)///////////////////"<<endl;
    string ani;
    cout<<"Input an animal:"<<endl;
    cin>>ani;
    
    while (ani!="end") {
        
        if (check(ani, animal)) {
            cout<<"deleting "<<ani<<endl;
            ll.remove_value(ani);
            ll.print();
            cout<<"----------------------"<<endl;
        }
        else{
            cout<<"Inserting "<<ani<<endl;
            ll.insert_sorted(ani);
            ll.print();
            cout<<"----------------------"<<endl;

        }
        
        cout<<"Input an animal:"<<endl;
        cin>>ani;

    }

    
    cout<<"//////////////////////Assignment 3(g)///////////////////"<<endl;
    cout<<"inserting: o(1)"<<endl;
    cout<<"removing: o(1)"<<endl;
    cout<<"inserting sorted: o(1)"<<endl;
    cout<<"remove by value: o(1) "<<endl;
    cout<<"accessing by index: ??can it access by index?? "<<endl;
    
    cout<<"//////////////////////Assignment 3(h)///////////////////"<<endl;
    cout<<"Advantages: dynamic size; easy for inserting and removing "<<endl;
    cout<<"Disadvantages: more memory space for pointer "<<endl;
    
    return 0;
}

bool check(string ani, string animal[]){
    for (int i=0; i<11; i++) {
        if (ani==animal[i]) {
            return true;
        }
    }
    return false;
}






