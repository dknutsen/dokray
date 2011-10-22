/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    public abstract class Object {
        public abstract void preprocess();
        public abstract void intersect(ref HitRecord hit, RenderContext rc, Ray ray);
    }

    public class Group : Object {

        System.Collections.Generic.List<Object> objects = new System.Collections.Generic.List<Object>();

        public override void preprocess() {
            for( int i = 0; i < this.objects.Count; i++ )
                this.objects[i].preprocess();
        }

        public override void intersect(ref HitRecord hit, RenderContext rc, Ray ray)
        {
            for( int i = 0; i < this.objects.Count; i++ )
                this.objects[i].intersect( ref hit, rc, ray );
        }

        public void addObject( Object obj ) {
            this.objects.Add(obj);
        }

    }

} // namespace RT