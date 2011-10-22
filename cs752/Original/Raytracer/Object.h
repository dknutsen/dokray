#ifndef Object_h
#define Object_h

#include <vector>
using std::vector;

class HitRecord;
class RenderContext;
class Ray;

class Object{
private:

public:
	virtual void preprocess() = 0;
	virtual void intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray) const=0;
};


class Group : public Object{
private:
	vector<Object*> objects;
public:
	void preprocess();
	void intersect(HitRecord& hit, const RenderContext& rc, const Ray& ray) const;

	void add_object(Object* object);
};

#endif