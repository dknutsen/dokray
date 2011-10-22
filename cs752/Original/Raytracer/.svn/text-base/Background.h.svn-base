#ifndef Background_h
#define Background_h

#include "RenderContext.h"
#include "Ray.h"
#include "Color.h"

class Background
{
public:
	virtual void preprocess() = 0;
	virtual Color getColor(const RenderContext& rc, const Ray& ray) const = 0;
};

class ConstantBackground : public Background
{
private:
	Color color;
public:
	ConstantBackground(Color color);
	void preprocess();
	Color getColor(const RenderContext& rc, const Ray& ray)const;
};

#endif