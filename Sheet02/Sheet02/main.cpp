//
//  main.cpp
//  Sheet02
//
//  Created by QuMing on 5/5/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//  Matrikel-Nr: 2896560

#include <iostream>
#include <math.h>
using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();

int string_length(const char* s);
char map(char ch);

int main(int argc, char** argv) {
    //task1();
    task2();
    task3();
    task4();
    task5();
    return 0;
    
}

void task1(){
    cout << "\n/////////////Assignment 1 ///////////////" << endl;
    cout << "\nListing1: " << endl;
    char res = 0;
    for( int c = 0; c < 1000; ++ c ) {
        res = res + 1;
        
    }
    cout << (int) res << endl;
    
    cout << "\nListing2: " << endl;
    int res1 = 0;
    for(unsigned char c=100; c>=0; --c
        ){
        res1 = res1 + 1;
        cout<<c<<endl;
        
    }
    cout << (int) res1 << endl;
    
    
}

void task2(){
    cout << "\n/////////////Assignment 2 ///////////////" << endl;
    int a_i [40];
    for (int i=0; i<40; i++) {
        a_i[i] = 2*(i+1);
    }
    
    int b_i [40], d_i[40], c_i[8];
    
    //initialize b_i
    for (int bi=0; bi<40; bi++) {
        for (int bj=0; bj<=bi; bj++) {
            b_i[bi] += a_i[bj];
        }
    }
    
    //initialize d_i
    for (int di=0; di<40; di++) {
        d_i[di] = a_i[39-di];
    }
    
    //initialize c_i
    c_i[0]=a_i[0];
    for (int ci=1; ci<8; ci++) {
            c_i[ci] = c_i[ci-1]* a_i[ci];
    }
    
    cout << "\n/////////////array ai, bi, di:  ///////////////" << endl;
    for (int i=0; i<40; i++) {
        cout << "\n ai["<<i<<"] = "<<a_i[i]<<", "<<" bi["<<i<<"] = "<<b_i[i]<<", "<<" di["<<i<<"] = "<<d_i[i]<<"; " << endl;
    }
    
    cout << "\n/////////////array ci:  ///////////////" << endl;
    for (int j=0; j<8; j++) {
        cout << "\n ci["<<j<<"] = "<<c_i[j]<<"; "<<endl;
    }
    
    cout << "The 6th of ai:  "<<a_i[6]<<"; "<<endl;
    cout << "The 100th of ai:  "<<a_i[100]<<"; "<<endl;
  //  cout << "The 100000th of ai:  "<<a_i[1000000]<<"; "<<endl;
    //EXC_BAD_ACCESS
    
    
}


void task3(){
    cout << "\n/////////////Assignment 3 (a)///////////////" << endl;
    char a ;
    int b;
    cout<<"char: "<<a<<endl;
    cout<<"int: "<<b<<endl;
    
    cout << "\n/////////////Assignment 3 (b)///////////////" << endl;
    cout<<"a: "<<(int)'a'<<", "<<"b: "<<(int)'b'<<", "<<"c: "<<(int)'c'<<", "<<"z: "<<(int)'z'<<"; "<<endl;
    cout<<"A: "<<(int)'A'<<", "<<"B: "<<(int)'B'<<", "<<"C: "<<(int)'C'<<", "<<"Z: "<<(int)'Z'<<"; "<<endl;
    cout<<"0: "<<(int)'0'<<", "<<"1: "<<(int)'1'<<", "<<"2: "<<(int)'2'<<", "<<"9: "<<(int)'9'<<"; "<<endl;
    
    /**
     65 – 90 – capital letters 'A' to 'Z' 64+i
     97 –122 – small letters 'a' to 'z' (97 – 65 = 32 – difference between capital and small letter!) 96+i
     */

    cout << "\n/////////////Assignment 3 (c)///////////////" << endl;
    char c;
    for(c='a'; c<='z'; ++c){
        printf("%c ",c);
    }
    printf("\n");
    for(c='A'; c<='Z'; ++c){
        printf("%c ",c);
    }
    printf("\n");
    for(c='0'; c<='9'; ++c){
        printf("%c ",c);
    }
    
    cout << "\n/////////////Assignment 3 (d)///////////////" << endl;
    const char* message = "Hello world";
    cout<<"The message: "<<message<<endl;
    
    cout << "\n/////////////Assignment 3 (e)///////////////" << endl;
    cout<<"The message length: "<<string_length(message)<<endl;

    cout << "\n/////////////Assignment 3 (f)///////////////" << endl;
    cout <<"Please input a character: " <<endl;
    char input;
    cin >> input;
    cout <<"Mapping to: "<<map(input)<<endl;
    
    cout << "\n/////////////Assignment 3 (g)///////////////" << endl;
    char buffer[100];
    
    for (int i=0;i<string_length(message);i++){
        buffer[i] = message[i];
    }
    cout <<"Copy message: "<<buffer<<endl;

    
    for (int i=0;i<string_length(buffer);i++){
        buffer[i] = map(buffer[i]);
    }
    cout <<"Copy and mapping to: "<<buffer<<endl;

}

void task4(){
    cout << "\n/////////////Assignment 4 (a)///////////////" << endl;
    char char4;
    int int4;
    double double4;
    cout <<"char: "<<char4<<endl;
    cout <<"int: "<<int4<<endl;
    cout <<"double: "<<double4<<endl;
    
    cout << "\n/////////////Assignment 4 (b)///////////////" << endl;
    int array4[100];
    cout <<"array4: "<<array4<<endl;
    for (int i=0; i<100; i++) {
        cout<<array4[i];
    }
    
    cout << "\n/////////////Assignment 4 (c)///////////////" << endl;
    cout << "if stack value: undefined"<<endl;
    
}

void task5(){
    cout << "\n/////////////Assignment 5///////////////" << endl;
    /**
     Input: an integer n > 1
     
     Let A be an array of Boolean values, indexed by integers 2 to n,
     initially all set to true.
     
     for i = 2, 3, 4, ..., not exceeding √n:
     if A[i] is true:
     for j = i^2, i^2+i, i^2+2i, i^2+3i, ..., not exceeding n :
     A[j] := false
     
     Output: all i such that A[i] is true.
     */
    
    int number = 100;
    bool * prime = new bool[number];
    
    for(int i = 0; i < 100; i++){ //sets all to true for the marking
        prime[i] = true;
    }
    
    for(int i = 2; i < number; i++){
        if(i <= sqrt(number) && prime[i] == true){
            for(int j = i*i; j < number; j+=i){
                prime[j] = false;
            }
        }
    }
    
    for(int i = 2; i < number; i++){
        if(prime[i] == true){
            cout << i<<"; ";
        }
    }
    
    
}

int string_length(const char* s){
    int i = 0;
    for(; s[i] != 0; i++);
    return i;
}

char map(char ch){
    
    if ('a'<=ch && ch<='z'){
        return char(((int)ch)-32);
    }
    
    else if ('A'<=ch && ch<='Z'){
        return char(((int)ch)+32);
    }
    
    else
        return ch;
}
