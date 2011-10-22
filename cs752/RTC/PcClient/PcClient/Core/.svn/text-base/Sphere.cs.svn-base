/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    class Sphere : Primitive
    {

        public Point p;
        public float rad;

        public Sphere()
        {
            this.material = null;
            this.p = new Point(0, 0, 0);
            this.rad = 1;
        }

        public Sphere(Material material, Point c, float radius)
        {

            this.material = material;
            this.p = c;
            this.rad = radius;

        }

        public Point c() { return this.p; }
        public float r() { return this.rad; }
        public float r2() { return this.rad * this.rad; }

        public override void preprocess()
        {

            this.material.preprocess();

        }

        public override Vector normal(Point point)
        {

            return (point - this.p).normal();

        }

        public override void intersect(ref HitRecord hit, RenderContext rc, Ray ray)
        {

            Vector dist = ray.p() - this.p;
            float b = Vector.dot(dist, ray.d());
            float c = Vector.dot(dist, dist) - this.r2();
            float d = b * b - c;
            float t = (d > 0) ? -b - (float)System.Math.Sqrt(d) : float.PositiveInfinity;

            hit.hit(t, this, this.material);

        }

    }

} // namespace RT