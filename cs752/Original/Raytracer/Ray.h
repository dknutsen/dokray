/*
	Author: Daniel Knutsen
	Course: Comp 361, Computer Graphics
	Date:   4/28/09
	Desc:	Ray class
*/

#ifndef Ray_h
#define Ray_h

#include "Vector.h"
#include "Point.h"

class Ray
{
private:
	Point o;
	Vector dir;

public:
	Ray(){
		o = Point(0,0,0);
		dir = Vector(0,0,0);
	}
	Ray(const Point& point, const Vector& direction)
	{
		o = point;
		dir = direction;
		dir.normalize();
	}
	Ray(float x, float y, float z, float u, float v, float w)
	{
		o = Point(x,y,z);
		dir = Vector(u,v,w);
	}

	
	Point p()const{
		return o;
	}
	Vector d()const{
		return dir;
	}
	Point& p(){
		return o;
	}
	Vector& d(){
		return dir;
	}

	Point pointOn(float t){
		return o + t*dir;
	}
};


#endif
