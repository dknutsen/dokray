/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

#ifndef RT_IMAGE_H
#define RT_IMAGE_H

#include <iostream>
#include <string>

#include "Color.h"

namespace RT {

   class Image {
   public:

      Image( unsigned int xres_, unsigned int yres_ );
      ~Image();

      unsigned int get_xres() const { return this->xres; }
      unsigned int get_yres() const { return this->yres; }
      void set( unsigned int x, unsigned int y, const Color& c ) { this->pixels[y][x] = c; }

      void writePPM( const std::string& fname ) const;
      void writeBMP( const std::string& fname ) const;

   private:

      unsigned int xres;
      unsigned int yres;
      Color** pixels;

      Image( const Image& );
      Image& operator = ( const Image& );

      void writeLittleEndian( unsigned long int num, std::ostream& out, int numBytes ) const;

      static const int BITS_PER_BYTE           = 8;   // number of bits per byte
      static const int MAX_BYTE_VALUE          = 256; // the max value a byte can hold
      static const int BMP_HEADER_SIZE         = 54;  // the total size of the header data in a BMP imgae
      static const int BMP_BYTES_PER_COLOR     = 3;   // number of bytes used for each pixel of data
      static const int BMP_PARTIAL_HEADER_SIZE = 40;  // size of the secondary header in a BMP image
      static const int BMP_NUM_OF_PLANES       = 1;   // the number of layers in a BMP
      static const int BMP_COMPRESSION         = 0;   // the compression to be used in a BMP

   };

} // namespace RT

#endif // RT_IMAGE_H
