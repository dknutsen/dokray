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
	RPoint o;
	Vector dir;

public:
	Ray(){
		o = RPoint(0,0,0);
		dir = Vector(0,0,0);
	}
	Ray(const RPoint& point, const Vector& direction)
	{
		o = point;
		dir = direction;
		dir.normalize();
	}
	Ray(float x, float y, float z, float u, float v, float w)
	{
		o = RPoint(x,y,z);
		dir = Vector(u,v,w);
	}

	
	RPoint p()const{
		return o;
	}
	Vector d()const{
		return dir;
	}
	RPoint& p(){
		return o;
	}
	Vector& d(){
		return dir;
	}

	RPoint pointOn(float t){
		return o + t*dir;
	}
};


#endif
