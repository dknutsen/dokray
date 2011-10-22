/*
	Author: Daniel Knutsen
	Course: Comp 361, Computer Graphics
	Date:   4/28/09
	Desc:	Point class
*/

#ifndef Point_h
#define Point_h

#include "Vector.h"

#include <iostream>
using std::ostream;

class Point
{
private:
	float c[3];
public:
	Point::Point(float x, float y, float z){
		c[0] = x; c[1] = y; c[2] = z;
	}
	Point(const Vector& v){
		c[0] = v[0]; c[1] = v[1]; c[2] = v[2];
	}
	Point(const Point& p){
		c[0] = p.x(); c[1] = p.y(); c[2] = p.z();
	}
	Point(){
		c[0] = 0; c[1] = 0; c[2] = 0;
	}

	float x() const{return c[0];}
	float y() const{return c[1];}
	float z() const{return c[2];}
	
	float operator[](int i) const{
		return c[i%3];
	}
	float& operator[](int i){
		return c[i%3];
	}

	Point operator+(const Vector& v){
		return Point(c[0]+v.x(), c[1]+v.y(), c[2]+v.z());
	}
	Point operator*(const Vector& v){
		return Point(c[0]*v.x(), c[1]*v.y(), c[2]*v.z());
	}

	Point& operator+=(const Point& p){
		c[0] += p.x(); 
		c[1] += p.y(); 
		c[2] += p.z();
		return *this;
	}
	Point& operator-=(const Point& p){
		c[0] -= p.x(); 
		c[1] -= p.y(); 
		c[2] -= p.z();
		return *this;
	}

	friend Vector operator-(const Point& p1, const Point& p2){
		return Vector(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
	}
	/*friend operator<<(ostream& os, const Point& p){
		os << "(" << p.x() << "," << p.y() << "," << p.z() << ")";
		return os;
	}*/
};

#endif