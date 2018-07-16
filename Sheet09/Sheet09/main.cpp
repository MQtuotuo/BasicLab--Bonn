//
//  main.cpp
//  Sheet09
//
//  Created by QuMing on 28/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>      // std::accumulate
#include <map>
#include <iomanip>
#include <string>


using namespace std;

//print the vector
void print_vec(vector<double> vec){
    for (int i=0; i<vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
}

double getMin(vector<double> vec){
    double min=vec[0];
    for (int i=1; i<vec.size(); i++) {
        if (min > vec[i]) {
            min = vec[i];
        }
    }
    return min;
}

double getMax(vector<double> vec){
    double max=vec[0];
    for (int i=1; i<vec.size(); i++) {
        if (max < vec[i]) {
            max = vec[i];
        }
    }
    return max;
}

double getMean(vector<double> vec){
    double sum=0;
    int size=vec.size();
    for (int i=0; i<size; i++) {
        sum+=vec[i];
    }
    double mean=sum/size;
    return mean;
}


double getDeviation(vector<double> vec){
    double m=getMean(vec);
    int size=vec.size();
    double temp = 0;
    for(int i = 0; i < size; i++)
    {
        temp += (vec[i] - m) * (vec[i] - m) ;
    }
    return sqrt(temp / size);
}

int smaller(vector<double> vec, int val){
    int count=0;
    for (int i=0; i<vec.size(); i++) {
        if (val>vec[i]) {
            count++;
        }
    }
    return count;
}

string toLowerCase(string str){
    string lowStr("");
    for (string::iterator it = str.begin(); it != str.end(); ++it){
        char chacracter = *it;
        lowStr +=tolower(chacracter);
    }
    return lowStr;
}

void print_map(map<string, string> m){
    
    cout << setw(12) << "        name: "<< " contact" << endl;
    for (map<string, string>::iterator it = m.begin(); it != m.end(); it++){
        cout << setw(12) << (*it).first << ":  " << (*it).second << endl;
    }
    cout << endl;
}

//printing vector<pair>
void print_vec(vector<pair<string, string>> vv){
    cout << setw(15) << "        contact: "<< "name" << endl;
    for (int i = 0; i != vv.size(); ++i) {
        cout << setw(15) << vv[i].first << ": " << vv[i].second << endl;
    }
}


int main(int argc, const char * argv[]) {
    
    const double data[] = {
        -1.37, 2.04, 4.98, 5.36, 8.88e-1, 2.47, -1.19e-1, -5.57e-1,
        2.83, 5.38e-1, 4.69, 7.37, 3.78, 5.29, 6.30, 2.62, 2.60,
        4.35, 5.31, 3.53, 7.64, 4.41e-1, 1.61, 4.71 };
    const int dataCount = sizeof(data) / sizeof(data[0]);
    
    //fill the data in vector
    vector<double> data_vec;
    for (int i = 0; i < dataCount; ++i){
        data_vec.push_back(data[i]);
    }
    
    cout<<"//////////////////////Assignment 2(a)//////////////////////"<<endl;
    cout<<"The vector is: "<<endl;
    print_vec(data_vec);
    
    double pos2=data_vec[1];
    
    cout<<"//////////////////////Assignment 2(b)//////////////////////"<<endl;
    //erase the 2nd element
    cout<<"After erasing and inserting: "<<endl;
    data_vec.erase(data_vec.begin()+1);
    data_vec.insert(data_vec.begin()+6, pos2);
    print_vec(data_vec);
    
    cout<<"//////////////////////Assignment 2(c)//////////////////////"<<endl;
    double min=getMin(data_vec);
    double max=getMax(data_vec);
    double mean=getMean(data_vec);
    double dev=getDeviation(data_vec);
    cout<<"min: "<<min<<endl;
    cout<<"max: "<<max<<endl;
    cout<<"mean: "<<mean<<endl;
    cout<<"standard deviation: "<<dev<<endl;
    
    cout<<"//////////////////////Assignment 2(d)//////////////////////"<<endl;
    int s2=smaller(data_vec, 2);
    int s4=smaller(data_vec, 4);
    int s6=smaller(data_vec, 6);
    cout<<"# of smaller than 2: "<<s2<<endl;
    cout<<"# of smaller than 4: "<<s4<<endl;
    cout<<"# of smaller than 6: "<<s6<<endl;
    
    cout<<"//////////////////////Assignment 3(b)//////////////////////"<<endl;
    double minimum = *( min_element(data_vec.begin(), data_vec.end()) );
    double maximum = *( max_element(data_vec.begin(), data_vec.end()) );
    double sum = accumulate(data_vec.begin(), data_vec.end(), 0.0);
    double mean2 = sum / double(data_vec.size());

    cout<<"min: "<<minimum<<endl;
    cout<<"max: "<<maximum<<endl;
    cout<<"mean: "<<mean2<<endl;
    
    cout<<"//////////////////////Assignment 3(c)//////////////////////"<<endl;
    int s2_2 = count_if(data_vec.begin(), data_vec.end(), [](double i) {return i < 2; });
    int s4_2 = count_if(data_vec.begin(), data_vec.end(), [](double i) {return i < 4; });
    int s6_2 = count_if(data_vec.begin(), data_vec.end(), [](double i) {return i < 6; });
    cout<<"# of smaller than 2: "<<s2_2<<endl;
    cout<<"# of smaller than 4: "<<s4_2<<endl;
    cout<<"# of smaller than 6: "<<s6_2<<endl;
    
    
    cout<<"//////////////////////Assignment 3(d)//////////////////////"<<endl;
    sort(data_vec.begin(), data_vec.end());
    cout<<"After sorting: "<<endl;
    print_vec(data_vec);
    
    vector<double>::iterator low2, low4, low6;
    low2 = lower_bound(data_vec.begin(), data_vec.end(), 2);
    low4 = lower_bound(data_vec.begin(), data_vec.end(), 4);
    low6 = lower_bound(data_vec.begin(), data_vec.end(), 6);
    
    int s2_3 = low2 - data_vec.begin();
    int s4_3 = low4 - data_vec.begin();
    int s6_3 = low6 - data_vec.begin();
    cout<<"# of smaller than 2: "<<s2_3<<endl;
    cout<<"# of smaller than 4: "<<s4_3<<endl;
    cout<<"# of smaller than 6: "<<s6_3<<endl;
    
    
    cout<<"//////////////////////Assignment 3(e)//////////////////////"<<endl;
    vector<double> data_vec4(4*data_vec.size());
    copy(data_vec.begin(), data_vec.end(), data_vec4.begin());
    copy(data_vec.begin(), data_vec.end(), data_vec4.begin() + data_vec.size());
    copy(data_vec.begin(), data_vec.end(), data_vec4.begin() + 2 * data_vec.size());
    copy(data_vec.begin(), data_vec.end(), data_vec4.begin() + 3 * data_vec.size());
    cout<<"After copying: "<<endl;
    print_vec(data_vec4);
    
    cout<<"//////////////////////Assignment 3(f)//////////////////////"<<endl;
    sort(data_vec4.begin(), data_vec4.end());
    auto last = unique(data_vec4.begin(), data_vec4.end());
    data_vec4.erase(last, data_vec4.end());
    cout<<"After sorting and unique: "<<endl;
    print_vec(data_vec4);

    cout<<"//////////////////////Assignment 4 (a)//////////////////////"<<endl;
    string test="Standard Template Library STL uses C++ templates to abstract away MANY differences of datatype implementations while not in- troducing ANY overhead!";
    string lower=toLowerCase(test);
    cout<<lower<<endl;
    
    cout<<"//////////////////////Assignment 4 (b)//////////////////////"<<endl;
    map<string, string> telephoneDic;
    //add paras to map
    telephoneDic[toLowerCase("Max")] = "0157/123456";
    telephoneDic[toLowerCase("Stefan")] = "0228/3734342";
    telephoneDic[toLowerCase("Anne")] = "0228/7629431";
    telephoneDic[toLowerCase("Office")] = "0228/272930";
    telephoneDic[toLowerCase("Bank")] = "0228/2223332";
    cout << "The telephone directory is "<<endl;
    print_map(telephoneDic);
    
    cout<<"//////////////////////Assignment 4 (c)//////////////////////"<<endl;
    //query the directory
    while (true){
        cout << "Input some name: " << endl;
        string queryName;
        cin >> queryName;
        if (queryName == "exit"){
            break;
        }
        else{
            if (telephoneDic.find(queryName) != telephoneDic.end()){
                cout << "The telephone number of " << queryName << " is "
                << telephoneDic.find(queryName)->second << endl;
            }
            else{
                string phoneNo;
                cout << "Please input the phone number for " << queryName << endl;
                cin >> phoneNo;
                telephoneDic[toLowerCase(queryName)] = phoneNo;
            }
        }
        
    }
    
    cout<<"//////////////////////Assignment 4 (e)//////////////////////"<<endl;
    vector<pair<string, string>> telephoneDic_vec;
    for (map<string, string>::iterator it = telephoneDic.begin(); it != telephoneDic.end(); ++it){
        telephoneDic_vec.push_back(make_pair((*it).second, (*it).first));
    }
    print_vec(telephoneDic_vec);
    
    cout<<"//////////////////////Assignment 4 (f)//////////////////////"<<endl;
    sort(telephoneDic_vec.begin(), telephoneDic_vec.end());
    cout << "After sorting:"<<endl;
    print_vec(telephoneDic_vec);
    
    cout<<"//////////////////////Assignment 4 (g)//////////////////////"<<endl;
    reverse(telephoneDic_vec.begin(), telephoneDic_vec.end());
    cout << "After reversing: "<<endl;
    print_vec(telephoneDic_vec);


    
    return 0;
}
