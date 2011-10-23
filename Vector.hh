/*
       Author: dok
       Desc:   Basic Vector class
 */

#ifndef Vector_hh
#define Vector_hh

#include <math.h>
#include <iostream>
using std::ostream;

class Vector
{
private:
   float c[3];

public:
   friend class Color;

   /*---------------- Constructors -----------------*/
   Vector(float x, float y, float z){		// parameter coordinate constructor
      c[0] = x; c[1] = y; c[2] = z;
   }

   Vector(const Vector &v){			// copy construtor
      c[0] = v.x(); c[1] = v.y(); c[2] = v.z();
   }

   Vector(){					// default constructor
      c[0] = 0; c[1] = 0; c[2] = 0;
   }


   /*---------------- Accessors --------------------*/
   float x()const{
      return c[0];
   }

   float y() const{
      return c[1];
   }

   float z() const{
      return c[2];
   }

   /*-------------- Operators ---------------------*/
   float  operator[](int i) const{		// [] const operator
      return c[i%3];
   }

   float& operator[](int i){			// [] operator
      return c[i%3];
   }

   Vector operator-()const{			// - unary operator 
      return Vector(-c[0], -c[1], -c[2]);
   }

   Vector operator+(const Vector& v)const{	// + binary operator
      return Vector(c[0]+v.x(), c[1]+v.y(), c[2]+v.z());
   }

   Vector operator-(const Vector& v)const{	// - binary operator
      return Vector(c[0]-v.x(), c[1]-v.y(), c[2]-v.z());
   }

   Vector operator*(const Vector& v)const{	// * operator (wtf) not dot product
      return Vector(c[0]*v.x(), c[1]*v.y(), c[2]*v.z());
   }

   Vector operator*(float d)const{		// * operator (scalar)
      return Vector(c[0]*d, c[1]*d, c[2]*d);
   }

   Vector& operator+=(const Vector& v){
      c[0] += v.x();
      c[1] += v.y();
      c[2] += v.z();
      return *this;
   }

   Vector& operator-=(const Vector& v){
      c[0] -= v.x();
      c[1] -= v.y();
      c[2] -= v.z();
      return *this;
   }

   friend Vector operator*(float x, const Vector& v){
      return Vector(v.x()*x, v.y()*x, v.z()*x);
   }

   friend Vector operator/(float x, const Vector& v){
      return Vector(v.x()/x, v.y()/x, v.z()/x);
   }

   /*---------------- Vector Functions -------------*/
   float  Length()const{
      return sqrt(this->Length2());
   }

   float  Length2()const{
      return c[0]*c[0] + c[1]*c[1] + c[2]*c[2];
   }

   Vector Normal()const{
      float length = this->Length();
      float div = 1/length;
      return Vector(c[0]*div, c[1]*div, c[2]*div);
   }

   float Normalize(){
      float length = this->Length();
      float div = 1/length;
      c[0] *= div; c[1] *= div; c[2] *= div;
      return length;
   }

   friend float Dot(const Vector& v1, const Vector& v2){
      return v1.x()*v2.x() + v1.y()*v2.y() + v1.z()*v2.z();
   }

   friend Vector Cross(const Vector& v1, const Vector& v2){
      return Vector(
         v1.y()*v2.z() - v1.z()*v2.y(),
         v1.z()*v2.x() - v1.x()*v2.z(),
         v1.x()*v2.y() - v1.y()*v2.x()
      );
   }

   friend ostream& operator<<(ostream& os, const Vector& v){
      os << "<" << v.x() << "," << v.y() << "," << v.z() << ">";
      return os;
   }

};

#endif
