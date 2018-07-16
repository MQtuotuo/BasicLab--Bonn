//
//  Calculation.h
//  Sheet04
//
//  Created by QuMing on 24/5/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#ifndef __Sheet04__Calculation__
#define __Sheet04__Calculation__

#include <stdio.h>

struct Vector3
{
    double x;
    double y;
    double z;
};

void print(const Vector3& a);
Vector3 add(const Vector3& a, const Vector3& b);
Vector3 substract(const Vector3& a, const Vector3& b);
Vector3 multiply(double s, const Vector3& b);
double dot_product(const Vector3& a, const Vector3& b);
double length(const Vector3& a);
Vector3 normalize(const Vector3& a);
Vector3 cross_product(const Vector3& a, const Vector3& b);


class Line {
    Vector3 point1, point2;
public:
    Line(const Vector3& p1,
         const Vector3& p2);
    const Vector3& get_point1() const;
    const Vector3& get_point2() const;
    Vector3 closest_point(const Vector3& p);
    double distance_to(const Vector3& p);
};

class Plane {
    Vector3 point, normal;
public:
    Plane(Vector3 p1,
          Vector3 p2, Vector3 p3);
    const Vector3& get_point() const;
    const Vector3& get_normal() const;
    double get_hnf_d() const;
    Vector3 closest_point(const Vector3& p);
    double distance_to(const Vector3& p);
    Vector3 intersect_line(const Line &l);
};
#endif /* defined(__Sheet04__Calculation__) */
