

#ifndef rt361_Image_h
#define rt361_Image_h


#include <string>
using std::string;

#include "Color.h"

class Image
{
public:
  Image(unsigned int xres_, unsigned int yres_);
  ~Image();

  unsigned int get_xres() const { return xres; }
  unsigned int get_yres() const { return yres; }
  float aspect() const { return static_cast<float>(xres)/yres; }
  void set(unsigned int x, unsigned int y, const Color& c) { pixels[y][x] = c; }

  void writePPM(const string& fname) const;
  void writeBMP(const string& fname) const;

private:
  unsigned int xres;
  unsigned int yres;
  Color** pixels;

  Image(const Image&);
  Image& operator=(const Image&);

  void writeLittleEndian(unsigned long int num, ostream& out, int numBytes) const;

  static const int BITS_PER_BYTE           = 8;   //number of bits per byte
	static const int MAX_BYTE_VALUE          = 256; //the max value a byte can hold
	static const int BMP_HEADER_SIZE         = 54;  //the total size of the header data in a BMP imgae
	static const int BMP_BYTES_PER_COLOR     = 3;   //number of bytes used for each pixel of data
	static const int BMP_PARTIAL_HEADER_SIZE = 40;  //size of the secondary header in a BMP image
	static const int BMP_NUM_OF_PLANES       = 1;   //the number of layers in a BMP
	static const int BMP_COMPRESSION         = 0;   //the compression to be used in a BMP
};

#endif // rt361_Image_h
