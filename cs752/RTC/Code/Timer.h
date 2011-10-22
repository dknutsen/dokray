/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_TIMER_H
#define RT_TIMER_H

#if defined(__APPLE__) && defined(__POWERPC__)
#include <ppc_intrinsics.h>
#include <mach/mach.h>
#include <mach/mach_time.h>
#elif _WIN32
#include <time.h>
#else
#include <sys/time.h>
#endif

#include <algorithm>

#include <iosfwd>
using std::ostream;

namespace RT {

   class Timer {
   public:

      Timer();

      void reset();
      float getElapsed() const;
      float getReset();

   private:

#if defined(__APPLE__) && defined(__POWERPC__)
      uint64_t getTime() const;
      float mach_scale;
      uint64_t start;
#elif _WIN32
      clock_t start;
#else
      timeval start;
#endif

   };

   class ParallelTimer {
   public:

      ParallelTimer() {}

      ~ParallelTimer() {
         delete [] data;
      }

      inline void init( unsigned int nthreads_ ) {
         nthreads = nthreads_;
         data = new Data[nthreads];
         for (size_t i = 0; i < nthreads; ++i)
            data[i].timer.reset();
      }

      inline void reset( unsigned int tid ) const {
         data[tid].timer.reset();
      }

      inline float getElapsed( unsigned int tid ) const {
         return data[tid].timer.getElapsed();
      }

      inline float getMaxElapsed() const {
         float max = data[0].timer.getElapsed();
         for ( size_t i = 0; i < nthreads; ++i )
            max = std::max(max, data[i].timer.getElapsed());

         return max;
      }

      inline float getTotalElapsed() const {
         float total = data[0].timer.getElapsed();
         for ( size_t i = 1; i < nthreads; ++i )
            total += data[i].timer.getElapsed();

         return total;
      }

      inline float getReset( unsigned int tid ) const {
         return data[tid].timer.getReset();
      }

      inline float getMaxReset() const {
         float max = data[0].timer.getReset();
         for ( size_t i = 0; i < nthreads; ++i )
            max = std::max( max, data[i].timer.getReset() );

         return max;
      }

      inline float getTotalReset() const {
         float total = data[0].timer.getReset();
         for ( size_t i = 0; i < nthreads; ++i )
            total += data[i].timer.getReset();

         return total;
      }

   private:

      struct Data {
         Timer timer;
         char pad[128 - 1*sizeof(Timer)];
      };

      Data* data;
      unsigned int nthreads;

   };

   inline Timer::Timer() {
#if defined(__APPLE__) && defined(__POWERPC__)
      mach_timebase_info_data_t time_info;
      mach_timebase_info(&time_info);

      // Scales to nanoseconds without 1e-9f
      mach_scale = (1e-9*static_cast<float>(time_info.numer))/
         static_cast<float>(time_info.denom);
#endif

      reset();
   }

   inline void Timer::reset() {
#if defined(__APPLE__) && defined(__POWERPC__)
      start = getTime();
#elif _WIN32
      start = clock();
#else
      gettimeofday(&start, 0);
#endif
   }

   inline float Timer::getElapsed() const {
#if defined(__APPLE__) && defined(__POWERPC__)
      uint64_t now = getTime();
      return (static_cast<float>(now - start)*mach_scale);
#elif _WIN32
      return (static_cast<float>(clock() - start)/
         static_cast<float>(CLOCKS_PER_SEC));
#else
      timeval now;
      gettimeofday(&now, 0);
      return (static_cast<float>(now.tv_sec - start.tv_sec) +
         static_cast<float>(now.tv_usec - start.tv_usec)/1000000.);
#endif // defined(__APPLE__) && defined(__POWERPC__)
   }

   inline float Timer::getReset() {
      float elapsed = getElapsed();
      reset();
      return elapsed;
   }

#if defined(__APPLE__) && defined(__POWERPC__)
   inline uint64_t Timer::getTime() const {
      unsigned int tbl, tbu0, tbu1;

      do {
         __asm__ __volatile__ ("mftbu %0" : "=r"(tbu0));
         __asm__ __volatile__ ("mftb %0"  : "=r"(tbl));
         __asm__ __volatile__ ("mftbu %0" : "=r"(tbu1));
      } while (tbu0 != tbu1);

      return ((static_cast<unsigned long long>(tbu0) << 32) | tbl);
   }
#endif

   ostream& operator<<( ostream& os, Timer& timer );

}

#endif // RT_TIMER_H
