/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_POINT_H
#define RT_POINT_H

#include "Vector.h"

namespace RT {

   class Point {
   private:

      float c[3];

   public:

      Point( float x, float y, float z ) {
         this->c[0] = x; this->c[1] = y; this->c[2] = z;
      }

      Point( const Vector& v ) {
         this->c[0] = v[0]; this->c[1] = v[1]; this->c[2] = v[2];
      }

      Point( const Point& p ) {
         this->c[0] = p.x(); this->c[1] = p.y(); this->c[2] = p.z();
      }

      Point() {
         this->c[0] = 0; this->c[1] = 0; this->c[2] = 0;
      }

      float x() const { return this->c[0]; }
      float y() const { return this->c[1]; }
      float z() const { return this->c[2]; }

      float operator[]( int i ) const {
         return this->c[i%3];
      }

      float& operator[]( int i ) {
         return this->c[i%3];
      }

      Point operator+( const Vector& v ) {
         return Point( this->c[0]+v.x(), this->c[1]+v.y(), this->c[2]+v.z() );
      }

      Point operator*( const Vector& v ) {
         return Point( this->c[0]*v.x(), this->c[1]*v.y(), this->c[2]*v.z() );
      }

      Point& operator+=( const Point& p ) {

         this->c[0] += p.x(); 
         this->c[1] += p.y(); 
         this->c[2] += p.z();

         return *this;
      }

      Point& operator-=( const Point& p ) {

         this->c[0] -= p.x(); 
         this->c[1] -= p.y(); 
         this->c[2] -= p.z();
         
         return *this;
      
      }

      friend Vector operator-(const Point& p1, const Point& p2) {
         return Vector( p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z() );
      }
      /*friend operator<<(ostream& os, const Point& p){
      os << "(" << p.x() << "," << p.y() << "," << p.z() << ")";
      return os;
      }*/
   };

} // namespace RT

#endif // RT_POINT_H