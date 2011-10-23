/*
     Author: dok 
     Desc:   Basic Point class
 */

#ifndef Point_hh
#define Point_hh

#include "Vector.hh"

#include <iostream>
using std::ostream;

class Point
{
private:
   float c[3];		// three components of point coordinates (x,y,z)

public:
   /*-------- Constructors -------------*/
   Point(float x, float y, float z){	// construct from coordinates
      c[0] = x; c[1] = y; c[2] = z;
   }

   Point(const Vector& v){                  	// construct from Vector
      c[0] = v[0]; c[1] = v[1]; c[2] = v[2];
   }

   Point(const Point& p){			// copy consructor
      c[0] = p.x(); c[1] = p.y(); c[2] = p.z();
   }

   Point(){					// default constructor
      c[0] = 0; c[1] = 0; c[2] = 0;
   }


   /*-------------- Accessors --------------*/
   float x() const{return c[0];}
   float y() const{return c[1];}
   float z() const{return c[2];}

   /*-------------- Operators -------------*/
   float operator[](int i) const{		// [] const operator
      return c[i%3];
   }

   float& operator[](int i){			// [] operator
      return c[i%3];
   }

   Point operator+(const Vector& v){		// + operator (add vector)
      return Point(c[0]+v.x(), c[1]+v.y(), c[2]+v.z());
   }

   Point operator*(const Vector& v){		// * operator (multiply by vector (wtf)
      return Point(c[0]*v.x(), c[1]*v.y(), c[2]*v.z());
   }

   Point& operator+=(const Point& p){		// += operator for point
      c[0] += p.x();
      c[1] += p.y();
      c[2] += p.z();
      return *this;
   }

   Point& operator+=(const Vector& v){          // += operator for vector
      c[0] += v.x();
      c[1] += v.y();
      c[2] += v.z();
      return *this;
   }

   Point& operator-=(const Point& p){		// -= operator for point
      c[0] -= p.x();
      c[1] -= p.y();
      c[2] -= p.z();
      return *this;
   }

   Point& operator-=(const Vector& v){		// -= operator for vector
      c[0] -= v.x();
      c[1] -= v.y();
      c[2] -= v.z();
      return *this;
   }

   friend Vector operator-(const Point& p1, const Point& p2){ // vector between 2 points
      return Vector(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
   }

   friend ostream& operator<<(ostream& os, const Point& p){	// stream to console
       os << "(" << p.x() << "," << p.y() << "," << p.z() << ")";
       return os;
   }
};

#endif
