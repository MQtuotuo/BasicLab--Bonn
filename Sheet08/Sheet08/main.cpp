//
//  main.cpp
//  Sheet08
//
//  Created by QuMing on 20/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;


void print(vector<string> array){
    for (int i=0; i<array.size(); i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    
}

vector<int> counts(vector<string> array){
    vector<int> counts;
    int temp;
    for (int i=0; i<array.size(); i++) {
        temp= count (array.begin(), array.end(), array[i]);
        cout << array[i]<<" : " << temp  << " times.\n";
        counts.push_back(temp);
    }
    return counts;
}

vector<string> split(string in){
    string temp;
    vector<string> strings;
    while(in!=temp){
        int pos=in.find_first_of(" ");
        if(pos>in.find_first_of("\r")) pos=in.find_first_of("\r");
        if(pos>in.find_first_of("\n")) pos=in.find_first_of("\n");
        
        temp=in.substr(0, pos);
        if (temp!="") {
            strings.push_back(temp);
        }
        in=in.substr(pos+1);
        
    }
    return strings;
}

map<string,int>  seperate(string in){
    map<string, int>  string_count;
    
    string token;
    while (in != token){
        int delimiter_pos = in.find_first_of(" ");
        if (delimiter_pos > in.find_first_of("\r")) delimiter_pos = in.find_first_of("\r");
        if (delimiter_pos > in.find_first_of("\n")) delimiter_pos = in.find_first_of("\n");
        
        token = in.substr(0, delimiter_pos);
        if (token != "")   {
            //check this word is stored in string_count or not.
            auto it = string_count.find(token);
            if (it != string_count.end()){
                //is already exist, then count++
                (*it).second++;
            }
            else{ // a new word, count = 1.
                string_count[token] = 1 ;//string_count.insert(pair<string, int>(token, 1));
            }
        }
        in = in.substr(delimiter_pos + 1);
    }
    return string_count;
}

void print_map(map<string, int> m){
    cout << "The map size: " << m.size() << endl;
    for (map<string, int>::iterator it = m.begin(); it != m.end(); it++){
        cout << (*it).first << ": " << (*it).second << endl;
    }
    cout << endl;
}

void testHistogram(){
    vector<string> strings;
    std::ifstream t("/Users/Ming/Documents/Bonn/Lectures/BasicLab/Sheet08/test.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    string tok=buffer.str();
    
    strings=split(tok);
    cout<<"sorting the strings "<<endl;
    sort(strings.begin(), strings.end());
    print(strings);
    cout<<endl;
    
    cout<<"unique the strings "<<endl;
    vector<string> uniques=strings;
    unique(uniques.begin(), uniques.end());
    print(uniques);
    cout<<endl;

    cout<<"counting the words "<<endl;
    vector<int> counts_uniques=counts(uniques);
    cout<<endl;

}

int main(int argc, const char * argv[]) {
    
    cout<<"///////////////////Assignment 1 (a)//////////////////"<<endl;
    std::vector<double> array;
    // fill this array with values
    array.push_back( 29 );
    array.push_back( 49 );
    array.push_back( 52 );
    array.push_back( 26 );
    array.push_back( 89 );
    
    // iterate using pointers
    // &array[0] : is the pointer to the first element
    // (&array[0]) + array.size() : is the pointer *behind* the last element
    for (double* it1=&array[0]; it1!=(&array[0])+array.size(); ++it1) {
        cout<<*it1<<" ";
    }
    cout<<endl;
    

    // change the data
    array[0] = 49;
    array[1] = 29;
    std::swap( array[2], array[3]) ;
    // iterate using iterators. See that they share the same semantics.
    for( std::vector<double>::iterator it1 = array.begin(); it1 != array.end(); ++ it1 )
    {
        std::cout << *it1 << " ";
    }
    std::cout << endl;
    
    cout<<"///////////////////Assignment 1 (c)//////////////////"<<endl;
    std::list<double> list;
    // fill this array with values
    list.push_back(29);
    list.push_back(49);
    list.push_back(52);
    list.push_back(26);
    list.push_back(89);
    
    // iterate using iterators. See that they share the same semantics.
    for( std::list<double>::iterator it1 = list.begin(); it1 != list.end(); ++ it1 )
    {
        std::cout << *it1 << " ";
    }
    std::cout << endl;
    



    cout<<"///////////////////Assignment 2 //////////////////"<<endl;
    string str;
    cout << "Please enter a sentence" << endl;
    getline(cin, str);
    
    vector<string> strings;
    stringstream buffer(str); // Turn the string into a stream.
    string tok=buffer.str();

    strings=split(tok);
    cout<<"array of the string: "<<endl;
    print(strings);
    cout<<endl;
    
    cout<<"sorting the strings "<<endl;
    sort(strings.begin(), strings.end());
    print(strings);
    cout<<endl;
    
    cout<<"unique the strings "<<endl;
    vector<string> uniques=strings;
    auto last=unique(uniques.begin(), uniques.end());
    uniques.erase(last, uniques.end());
    print(uniques);
    cout<<endl;
    
    cout<<"counting the sorted strings "<<endl;
    vector<int> counts_strings=counts(strings);
    cout<<endl;
    
    cout<<"counting the unique strings "<<endl;
    vector<int> counts_uniques=counts(uniques);
    cout<<endl;
    
    testHistogram();
    

    map<string,int> string_map = seperate(str);
    print_map(string_map);
    cout<<endl;
    
    cout<<" Map: O(logn);       UnorderedMap: O(n)"<<endl;
    /**
     map allows to iterate over the elements in a sorted way, but unordered_map does not.
     */
    
    
    return 0;
    
    
}
