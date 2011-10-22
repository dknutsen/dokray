/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#include "Timer.h"

#include <iomanip>
using std::setprecision;
using std::setw;

#include <iostream>
using std::ios;

namespace RT {

   ostream& operator << ( ostream& out, Timer& timer ) {

      double seconds = timer.getElapsed();
      int minutes = 0;
      int hours = 0;
      if ( seconds > 60 ) {
         minutes = static_cast<int>(seconds/60);
         seconds -= 60*minutes;

         hours = minutes/60;
         minutes = minutes%60;
      }

      char fill = out.fill('0');
      out << setw(2) << hours << ":";
      out << setw(2) << minutes << ":";
      out.setf(ios::fixed);
      int precision = out.precision(2);
      out << setw(5) << seconds;
      out.precision(precision);
      out.unsetf(ios::fixed);
      out.fill(fill);

      return out;
   }

}
