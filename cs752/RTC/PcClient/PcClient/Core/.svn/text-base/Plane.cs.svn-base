/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    class Plane : Primitive
    {

        public Vector norm;
        public Point point;

        public Plane(Material material, Vector normal, Point point)
        {
            this.material = material;
            this.norm = normal;
            this.point = point;
        }

        public override void preprocess()
        {
            this.norm.normalize();
            this.material.preprocess();
        }

        public override Vector normal(Point point)
        {
            return this.norm;
        }

        public override void intersect(ref HitRecord hit, RenderContext rc, Ray ray)
        {

          float num = Vector.dot( -this.norm, ray.p() - this.point );
          float denom = Vector.dot( this.norm, ray.d() );
          float t = num/denom;
          if ( denom==0 || num==0 || t < 0 ) hit.hit( float.PositiveInfinity, this, this.material );
          else hit.hit( num/denom, this, this.material );

       }

    }

} // namespace RT