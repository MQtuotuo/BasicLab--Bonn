//
//  main.cpp
//  Sheet11
//
//  Created by QuMing on 11/7/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//


#include <iostream>
#include "tools_11.h"
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <queue>
#include <cmath>
#include <math.h>
#include "gradient_descent_skel.h"
using namespace std;

void print_vec(vector<double> vec){
    for (int i=0; i<vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

vector<double> f_x(vector<double> x, int u){
    vector<double> fs;
    double fx;
    for (int i=0; i<x.size(); i++) {
        fx=x[i]*x[i]-u;
        fs.push_back(fx);
    }
    return fs;

}

double f(double x){
    return x*x-2;
}

double f_dev(double x){
    return 2*x;
}

double g(double x){
    return (x/2+1/x);
}

double f_est(double x, double x0){
    return f(x0)+(x-x0)*f_dev(x0);
}

vector<double> f_dev(vector<double> x){
    vector<double> f_dev;
    double epsilon = 0.1e-10; //say
    double temp;
    for (int i=0; i<x.size(); i++){
        temp= (f(x[i]+epsilon)-f(x[i]))/epsilon;
        f_dev.push_back(temp);
    }
    return f_dev;
}



vector<double> g_x(vector<double> x){
    vector<double> gs, f, fdev;
    f=f_x(x, 2);
    fdev=f_dev(x);
    double g;
    for (int i=0; i<x.size(); i++) {
        g=x[i]-f[i]/fdev[i];
        gs.push_back(g);
    }
    return gs;
}


double skel_gradient_descent_1d( double x0, double (*energy)( double, double& ) ){
    
    double lambda=1e-4;
    double x=x0;
    double grad;
    double y=energy(x, grad);
    
    while (lambda > 1e-6 && abs(grad)> 1e-3) {
        double x1=x-lambda*grad;
        double y1=energy(x1, grad);
        
        if (y1<y){
            x=x1;
            y=y1;
            lambda=lambda*1.2;
        }
        else{
            lambda=lambda/2.0;
        }
    }
    return x;
    
}

vector<double> skel_gradient_descent_nd(const vector<double>& x0, double (*energy_nd)( const vector<double>&, vector<double>& ) ){
    double lambda=1e-4;
    vector <double> x=x0;
    vector <double> x1, grads;
    
    double y=energy_nd(x, grads);
    
    while (lambda > 1e-6 && norm_vector(grads)> 1e-3) {
        x1.resize(x.size());
        for (int i=0; i<x.size(); i++) {
            x1[i]=x[i]-lambda*grads[i];
        }
        
        double y1=energy_nd(x1, grads);
        
        if (y1<y){
            x=x1;
            y=y1;
            lambda=lambda*1.2;
        }
        else{
            lambda=lambda/2.0;
        }
    }
    return x;
    
    
}







double energy( double x, double& grad ) {
    grad = 2*x;
    return x*x;
}

double energy_nd (const vector<double>& xs, vector<double>& grads ) {
    double value = xs[0]*xs[0] + (xs[2]-1)*(xs[2]-1) + (xs[0]-xs[1])*(xs[0]-xs[1]) + (xs[1] - xs[2])*(xs[1] - xs[2]);
    grads.resize(xs.size());
    grads[0] = 2*xs[0] + 2*(xs[0]-xs[1]);
    grads[1] = 2*(xs[1]-xs[0]) + 2* (xs[1]-xs[2]);
    grads[2] = 2*(xs[2]-1) + 2*(xs[2]-xs[1]);
    return value;
}






int main(int argc, const char * argv[]) {
    
    cout<<"//////////////////////Assignment 2/////////////////////"<<endl;
    
    SimpleGraph* plot = SimpleGraph::getInstance();
    vector<double> fs, xs, fdev, gs;;
    for (int i=0.0; i<=2/0.002; i++) {
        xs.push_back((double)i*0.002);
    }
    //print_vec(xs);
    
    //print f_x in [0, 2]
    fs=f_x(xs, 2);
    plot->setData( xs, fs );
    plot->show(); //close window to continue
    
    
    //draw f_dec in [0, 2].
    fs=f_x(xs, 2);
    fdev=f_dev(xs);
    plot->setData( xs, fdev );
    plot->show(); //close window to continue

    /**
    //draw g_x in [0, 2]
    gs=g_x(xs);
    plot->setData( xs, gs );
    plot->show(); //close window to continue
    //print_vec(gs);
     */
    
    cout<<"f_dev = 2x"<<endl;
    cout<<"g_x = x/2+1/x"<<endl;

    
    double x0=2;
    double root0=g(x0);
    cout<<"First estimate is: "<<root0<<endl;
    
    fs=f_x(xs, 2);
    plot->setData( xs, fs );
    plot->markPosition(root0);
    plot->show(); //close window to continue
    plot->clear();
    
    
    const double epsilon = 0.000001; //tolerance
    double root=2.0;
    int count=0;
    

    while (abs(sqrt(2)-root)>=epsilon) {
        
        x0=root;
        double x1=0.0;
        double y1=f_est(x1, x0);
        
        double y0=f_est(x0, x0);
        
        fs=f_x(xs, 2);
        plot->setData( xs, fs );
        
        root=g(x0);
        
        plot->markPosition(root);
        plot->addLine(x1, y1, x0, y0);
        
        
        plot->show(); //close window to continue
        count++;
        
    }

    cout<<"Total iterations: "<<count<<endl;
    
    cout<<"Root is: "<<root<<endl;
    

    
    cout<<"//////////////////////Assignment 3/////////////////////"<<endl;
    double xSolution = skel_gradient_descent_1d( 2, energy );
    cout<<"1d:  "<<xSolution<<endl;
    cout<<"The 1d gradient is: "<<endl;
    cout<<2*xSolution<<endl<<endl;
    
    
    vector<double> start;
    start.push_back( 1 );
    start.push_back( 2 );
    start.push_back( 3 );
    vector<double> grads;
    vector<double> x2Solution = skel_gradient_descent_nd( start, energy_nd );
    printf("nd:  ");
    print_vec(x2Solution);
    
    cout<<"The nd gradient is: "<<endl;
    double grad1 = 2*x2Solution[0]+2*(x2Solution[0]-x2Solution[1]);
    double grad2 = 2*(x2Solution[1]-x2Solution[0]) + 2*(x2Solution[1]-x2Solution[2]);
    double grad3 = 2*(x2Solution[2]-1) + 2*(x2Solution[2]-x2Solution[1]);
    cout<<grad1<<" "<<grad2<<" "<<grad3<<endl;


    return 0;
}
