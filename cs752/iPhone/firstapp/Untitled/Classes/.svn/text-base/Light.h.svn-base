#ifndef Light_h
#define Light_h

#include "Color.h"
#include "Vector.h"
#include "RenderContext.h"
#include "Point.h"

class Light{
private:

public:
	virtual void preprocess() = 0;
	virtual float getLight(Color& lcolor, Vector& ldir, const RenderContext& rc, 
		const RPoint& hp) const=0;
};


class PointLight : public Light{
private:
	RPoint p;
	Color color;
public:
	PointLight(RPoint p, Color color);
	void preprocess();
	float getLight(Color& lcolor, Vector& ldir, const RenderContext& rc, const RPoint& hp) const;
};


class DirectionalLight : public Light{
private:
	Vector dir;
	Color color;
public:
	DirectionalLight(Vector dir, Color color);
	void preprocess();
	float getLight(Color& lcolor, Vector& ldir, const RenderContext& rc, const RPoint& hp) const;
};

#endif