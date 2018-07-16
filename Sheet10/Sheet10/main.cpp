//
//  main.cpp
//  Sheet10
//
//  Created by QuMing on 5/7/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#include <iostream>
#include "tools.h"
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <queue>
#include <cmath>
#include <math.h>
using namespace std;


double mySum(double d1, double d2) {
    double reduce_d1 = reducePrecision(d1);
    double reduce_d2 = reducePrecision(d2);
    return (reduce_d1+reduce_d2);
}

void print_vec(vector<double> vec){
    for (int i=0; i<vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

vector<double> generateSamplePoints(double x1, double x2, int number){
    vector<double> xs;
    double x;
    for (int i=0; i<number; i++) {
        x=exp(log(x1) + (log(x2)-log(x1))*i/number);
        xs.push_back(x);
    }
    return xs;
}

vector<double> f_x(vector<double> x){
    vector<double> ys;
    double y;
    for (int i=0; i<x.size(); i++) {
        y=(1-cos(x[i]))/(x[i]*x[i]);
        ys.push_back(y);
    }
    return ys;
}

vector<double> g_x(vector<double> x){
    vector<double> gs;
    double g;
    for (int i=0; i<x.size(); i++) {
        g=(1.0/2*pow(x[i], 2)-1.0/24*pow(x[i], 4))/(pow(x[i], 2));
        cout<<g<<"  ";
        gs.push_back(g);
    }
    return gs;
}

vector<double> b_x(vector<double> x){
    vector<double> bs;
    double b;
    for (int i=0; i<x.size(); i++) {
        b=exp(-abs(x[i])*pow(10, 3));
        bs.push_back(b);
    }
    return bs;
}

vector<double> F_x(vector<double> x){
    vector<double> Fs, f, g, b;
    double F;
    f=f_x(x);
    g=g_x(x);
    b=b_x(x);
    for (int i=0; i<x.size(); i++) {
        F = b[i]*g[i]-(1-b[i])*f[i];
        Fs.push_back(F);
    }
    return Fs;
}

vector<double> f_2(vector<double> x, int u){
    vector<double> f_2;
    double f2;
    for (int i=0; i<x.size(); i++) {
        f2=x[i]*x[i]-u;
        f_2.push_back(f2);
    }
    return f_2;
}


/**
 function root = bisection( a, b, f, epsilon )
 if f(a)*f(b) >= 0
 error "No root detected in [a,b]!"
 root <- 0
 return
 end
 while b-a > epsilon do
 c <- (a+b)/2.0
 if f(c) == 0
 a <- c, b <- c
 else if f(a)f(c) < 0
 b <- c
 else // f(b)f(c)<0
 a <- c
 end end
 root <- (a+b)/2.0 // return the middle of the interval as guess
 end
 */

double func(double x){
    return (x*x-2);
}

double bisection(double a, double b, double epsilon){
    double root;
    if (func(a)*func(b) > 0){
        cout<<"No root detected in ["<<a<<", "<<b<<" ]!"<<endl;
        root=0;
        return root;
    }
    
    while ((b-a)>epsilon) {
        double c=(a+b)/2;
        if (func(c)==0) {
            a=c;
            b=c;
        }
        else if(func(a)*func(c)<0){
            b=c;
        }
        else if(func(b)*func(c)<0){
            a=c;
        }
    }
    
    root=(a+b)/2;
    
    return root;
}



int main(int argc, const char * argv[]) {
   
    /**
     Assignment 1:
     a)
     Signle precision:
     usually used to represent the "float" type in the C language family (though this is not guaranteed).
     This is a binary format that occupies 32 bits (4 bytes) and its significand has a precision of 24 bits (about 7 decimal
     digits).
     double precision:
     usually used to represent the "double" type in the C language family (though this is not guaranteed). 
     This is a binary format that occupies 64 bits (8 bytes) and its significand has a precision of 53 bits (about 16 decimal 
     digits).
     
     b)
     Any integer with absolute value less than 2^24 can be exactly represented in the single precision format.
     Any integer with absolute value less than 2^53 can be exactly represented in the double precision format.
     
     C)
     Addition and Subtraction:
     First represent the numbers with the same exponent, and then rounding and normalization
     
     Multiplication and Division:
     To multiply, the significands are multiplied while the exponents are added, and the result is rounded and normalized.
     Division is accomplished by subtracting the divisor's exponent from the dividend's exponent, and dividing the dividend's 
     significand by the divisor's significand.
     
     */
    cout<<"//////////////////////Assignment 2/////////////////////"<<endl;
    int count=1000;
    double min=100;
    double max=101;
    int seed=22;
    std::vector<double> out;
    
    createRandom(seed, count, min, max, out);
    //print_vec(out);
    
    //first method
    double sum1 = accumulate(out.begin(), out.end(), 0.0, mySum);
    cout<<"Add them up using std::accumulate: "<<sum1<<endl;
    
    //second method
    vector<double> ascend = out;
    sort(ascend.begin(), ascend.end() );
    double sum2 = accumulate(ascend.begin(), ascend.end(),0.0, mySum);
    cout<<"Sort values ascending and then add: "<<sum2<<endl;
                             
    //third method
    vector<double> descend = ascend;
    reverse(descend.begin(), descend.end());
    double sum3 = accumulate(descend.begin(), descend.end(),0.0, mySum);
    cout<<"Sort values descending and then add: "<<sum3<<endl;
    
    //fourth method
    priority_queue<double, std::vector<double>, std::greater<double> > pq;
    for (int i=0; i<out.size(); i++) {
        pq.push(out[i]);
    }
    //print_queue(pq);
    double sum4=0.0;
    while(!pq.empty()) {
        double small1=pq.top();
        pq.pop();
        double small2=pq.top();
        sum4=sum4+mySum(small1, small2);
        pq.pop();
    }
    cout<<"Gather the values in a min-heap and then add: "<<sum4<<endl;
    
    cout<<"//////////////////////Assignment 3/////////////////////"<<endl;
    vector<double> xs, ys, gs, bs, Fs;
    double x1=pow(10, -15);
    double x2=1;
    int number =1000;
    xs=generateSamplePoints(x1, x2, number);
    //print_vec(xs);
    ys=f_x(xs);
    plotLogX(xs, ys);
    
    gs=g_x(xs);
    plotLogX(xs, gs);
    
    bs=b_x(xs);
    plotLogX(xs, bs);
    
    Fs=F_x(xs);
    plotLogX(xs, Fs);
    
    cout<<"//////////////////////Assignment 4/////////////////////"<<endl;
    SimpleGraph* plot = SimpleGraph::getInstance();
    vector<double> f2, x;
    for (int i=0; i<=2/0.002; i++) {
        x.push_back((double)i*0.002);
    }
    //print_vec(x);
    //draw f2 in [0, 2].
    f2=f_2(x, 2);
    plot->setData( x, f2 );
    plot->show(); //close window to continue
    
    double a=0.0;
    double b=2.0;
    double epsilon=0.001;
    double root;
    int coun=0;
    if (func(a)*func(b) > 0){
        cout<<"No root detected in ["<<a<<", "<<b<<" ]!"<<endl;
        root=0;
        return root;
    }
    
    while ((b-a)>epsilon) {
        double c=(a+b)/2;
        if (func(c)==0) {
            a=c;
            b=c;
            coun++;
            plot->markPosition(a);
            plot->markPosition(b);
            plot->show();
        }
        else if(func(a)*func(c)<0){
            b=c;
            coun++;
            plot->markPosition(a);
            plot->markPosition(b);
            plot->show();
        }
        else if(func(b)*func(c)<0){
            a=c;
            coun++;
            plot->markPosition(a);
            plot->markPosition(b);
            plot->show();
        }
    }
    
    root=(a+b)/2;
    cout<<root<<endl;
    cout<<"Maximal error is 1-sqrt(2)"<<endl;
    cout<<coun<<" iterations are necessary to determine sqrt(2) up to the third decimal"<<endl;
    
    
    

    
    
    return 0;
}
