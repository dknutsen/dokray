/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_VECTOR_H
#define RT_VECTOR_H

#include <math.h>
#include <iostream>
using std::ostream;

namespace RT {

   class Vector  { 
   private:

      float c[3];

   public: 

      friend class Color; 

      Vector( float x, float y, float z ) {

         this->c[0] = x; 
         this->c[1] = y; 
         this->c[2] = z;

      }

      Vector() {

         this->c[0] = 0; 
         this->c[1] = 0; 
         this->c[2] = 0;

      } 

      float x() const { return this->c[0]; } 
      float y() const {	return this->c[1]; } 
      float z() const { return this->c[2]; }

      float  operator[]( int i ) const { return this->c[i%3]; }
      float& operator[]( int i ) { return this->c[i%3]; }

      float length2() const { return ( this->c[0] * this->c[0] ) + ( this->c[1] * this->c[1] ) + ( this->c[2] * this->c[2] ); }
      float length() const { return sqrt( this->length2() ); } 

      Vector normal() const {

         float length = this->length();
         float div = 1/length;
         return Vector( this->c[0]*div, this->c[1]*div, this->c[2]*div );

      }

      float normalize(){

         float length = this->length();
         float div = 1/length;
         this->c[0] *= div; 
         this->c[1] *= div; 
         this->c[2] *= div;
         return length;

      }

      Vector operator-() const { return Vector( -this->c[0], -this->c[1], -this->c[2] ); }
      Vector operator+( const Vector& v ) const { return Vector( this->c[0]+v.x(), this->c[1]+v.y(), this->c[2]+v.z() ); }
      Vector operator-( const Vector& v ) const { return Vector( this->c[0]-v.x(), this->c[1]-v.y(), this->c[2]-v.z() ); } 
      Vector operator*( const Vector& v ) const { return Vector( this->c[0]*v.x(), this->c[1]*v.y(), this->c[2]*v.z() ); }
      Vector operator*( float d ) const {	return Vector( this->c[0]*d, this->c[1]*d, this->c[2]*d ); } 
      Vector& operator+=( const Vector& v ) {

         this->c[0] += v.x(); 
         this->c[1] += v.y(); 
         this->c[2] += v.z();
         return *this;

      }

      Vector& operator-=( const Vector& v ) {

         this->c[0] -= v.x(); 
         this->c[1] -= v.y(); 
         this->c[2] -= v.z();
         return *this;

      } 

      friend Vector operator*( float x, const Vector& v ) {	return Vector( v.x()*x, v.y()*x, v.z()*x ); } 
      friend Vector operator/( float x, const Vector& v ) {	return Vector( v.x()/x, v.y()/x, v.z()/x ); } 

      friend float dot( const Vector& v1, const Vector& v2 ) {	return ( v1.x() * v2.x() ) + ( v1.y() * v2.y() ) + ( v1.z() * v2.z() );	} 
      friend Vector cross( const Vector& v1, const Vector& v2 ) {

         return Vector(
            v1.y()*v2.z() - v1.z()*v2.y(),
            v1.z()*v2.x() - v1.x()*v2.z(),
            v1.x()*v2.y() - v1.y()*v2.x() );

      }

      friend ostream& operator<<( ostream& os, const Vector& v ) {

         os << "<" << v.x() << "," << v.y() << "," << v.z() << ">";
         return os;

      }

   };

} // namespace RT

#endif // RT_VECTOR_H