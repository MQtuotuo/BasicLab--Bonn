//
//  main.cpp
//  Sheet01
//
//  Created by QuMing on 29/4/16.
//  Copyright (c) 2016 QuMing. All rights reserved.

//  Matrikel-Nr: 2896560

//directives for the preprocessor, tell the preprocessor to include the iostream standard file
#include <iostream>

//All the elements of the standard C++ library are declared within what is called a namespace
using namespace std;


int min(int a, int b);
int max(int a, int b);
double mean(int a, int b);

int sumfirstN(int n);
int sumfirstN_withoutloop(int n);
int fib_loop(int n);

int fib_cursion(int i);
int binomial(int n, int i);
void space(int num, int mul);

//argv and argc are how command line arguments are passed to main()
int main(int argc, char** argv) {
    
    cout << "\n/////////////Assignment 1(b)///////////////" << endl;
    cout << "Hello world" << endl;
    /*
     main function is not a call back function
     main function is the point by where all C++ programs start their execution
     cout represents the standard output stream in C++
     **/
   

    cout << "\n/////////////Assignment 1(c)///////////////" << endl;
    cout << "Please enter your name !" << endl;
    string name;
    cin >> name;
    int birthmonth,birthyear;
    int currentmonth,currentyear;
    int agey,agem;
    cout<<"Enter Your Birth Year(Eg:1989):"<<endl;
    cin>>birthyear;
    cout<<"Enter Your Birth Month(Eg:7):"<<endl;
    cin>>birthmonth;
    cout<<"Enter The Current Month(Eg:5):"<<endl;
    cin>>currentmonth;
    cout<<"Enter The Current Year(Eg:2016):"<<endl;
    cin>>currentyear;
    agey=currentyear-birthyear;
    agem=12-birthmonth;
    cout<<"Welcome "<<name<<"!  Your Age is "<<agey<<" Years And "<<agem<<" Months "<<endl;
    
    
    cout << "\n/////////////Assignment 2(a)///////////////" << endl;
    int i = 10;
    int j = 23;
    float f = 3.141f;
    double d = 2.718281828459045;
    
    double result1, result2, result4, result11, result12;
    int result3, result5, result6, result7;
    float result8, result9, result10;
    
    result1=(double)i/j;
    result2=(double)j/i;
    result3=(int)i/2;
    result4=(double)j/2;
    result5=(int)i%2;
    result6=(int)j%2;
    result7=(int)(j/3) * 3 + j%3;
    result8=(float)f*f*5;
    result9=(float)f/d;
    result10=(float)d/f;
    result11=(double)d*i;
    result12=(double)d/i;
    cout<<"i/j:   "<<result1<<endl;
    cout<<"j/i:   "<<result2<<endl;
    cout<<"i/2:   "<<result3<<endl;
    cout<<"j/2:   "<<result4<<endl;
    cout<<"i%2:   "<<result5<<endl;
    cout<<"j%2:   "<<result6<<endl;
    cout<<"(j/3) * 3 + j%3:   "<<result7<<endl;
    cout<<"f*f*5:   "<<result8<<endl;
    cout<<"f/d:   "<<result9<<endl;
    cout<<"d/f:   "<<result10<<endl;
    cout<<"d*i:   "<<result11<<endl;
    cout<<"d/i:   "<<result12<<endl;
    
    
    cout << "\n/////////////Assignment 2(c)///////////////" << endl;
    double basicResult;
    basicResult = mean(min(max(10, 1), abs(-9)), 6);
    cout << "The result is:  "<< basicResult << endl;
    
    cout << "\n/////////////Assignment 3(a)///////////////" << endl;
    cout << "while loop" << endl;
    int a = 0;
    while (a < 10) {
        cout << "This is the " << a << " th time !" << endl;
        a++;
    }
    
    cout << "for loop" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "This is the  " << i << " th time !" << endl;
    }
    
    cout << "do while loop" << endl;
    int k=0;
    do{
        cout << "This is the  " << k << " th time !" << endl;
        k++;
    }
    while (k < 10);
    
    cout << "while if break loop" << endl;
    int c = 0;
    while (c < 10) {
        cout << "This is the  " << c << " th time !" << endl;
        c++;
        if (c == 10)
            break;
    }
    
    cout << "\n/////////////Assignment 3(b)///////////////" << endl;
    cout << "1+2+3+....+100 = " << endl;
    cout<<"with loop: "<<sumfirstN(100)<<endl;
    cout<<"without loop: "<<sumfirstN_withoutloop(100)<<endl;
    
    
    cout << "\n/////////////Assignment 3(c)///////////////" << endl;
    cout << "The a8 number is(0 1 1 2 3 5 8 13 21): " << endl;
    c = fib_loop(8);
    cout << c << endl;
    
    cout << "\n/////////////Assignment 4(a)///////////////" << endl;
    int a1, a5, a6;
    a1=fib_cursion(1);
    a5=fib_cursion(5);
    a6=fib_cursion(6);
    cout << "a1: "<<a1 << endl;
    cout << "a5: "<<a5 << endl;
    cout << "a6: "<<a6 << endl;
    
    //when calculating a100, the program is going to die....too much computation...

    cout << "\n/////////////Assignment 4(b)///////////////" << endl;
    
    cout <<"binomial (2, 0) is:  "<< binomial(2, 0) << endl;
    
    
    cout << "\n/////////////Assignment 4(c)///////////////" << endl;
    int number;
    int ii, jj;
    printf("Enter the no. of rows required: ");
    scanf("%d",&number);
    for(ii=1;ii<=number;ii++)
    {
        space(number-ii,3);
        for(jj=1;jj<=ii;jj++)
        {
            printf("%3d",binomial(ii,jj));
            space(1,3);
        }
        printf("\n");
    }
    
    //finish the main
    return 0;
    
}



int min(int a,int b) {
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int max(int a,int b) {
    if (a < b) {
        return b;
    }
    else {
        return a;
    }
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    else {
        return a;
    }
}

int square(int a) {
    
    return a*a;
}

double mean(int a,int b) {
    return (double)(a + b) / 2;
}



int sumfirstN(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int sumfirstN_withoutloop(int n){
    
    return (n+1)*n/2;
}


int fib_loop(int n){
    int first = 0;
    int second = 1;
    int next = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < 1)
            next = i;
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
    }
    return next;
}


int fib_cursion(int i){
    if (i == 0 || i == 1)
    {
        return i;
    }
    else
    {
        return fib_cursion(i - 1) + fib_cursion(i - 2);
    }
}

int binomial(int n, int i){
    
    if (i == 0 || n == i || n==0)
    {
        return 1;
    }
    else if( i > n)
    {
        return 0;
    }
    else
    {
        return binomial(n - 1, i - 1) + binomial(n - 1, i);
    }
}

void space(int num, int mul)
{
    int i;
    num *= mul;
    for(i=0; i<num; i++)
        printf(" ");
}


/**
 
 Step over; that is, execute the current line of code and, if the current line is a function or method, step out to the next line in the current file
 Step in; that is, execute the current line of code and, if the current line is a routine, jump to the first line of that routine
 Step out of a jumped-to routine; that is, complete the current routine and step to the next routine or back to the calling routine.
 
 */


