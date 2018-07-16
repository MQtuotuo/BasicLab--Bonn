#include <vector>
#include <numeric>
#include <algorithm>
#include "SimpleGraph.h"
#include "SimpleImage.h"
#include "tools_11.h"
#include <assert.h>
//#include <omp.h>
#include "gradient_descent_skel.h"

using namespace std;

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



