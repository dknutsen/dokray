/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    public abstract class Light {
        public Color color;
        public abstract void preprocess();
        public abstract float getLight(ref Color lcolor, ref Vector ldir, RenderContext rc, Point hp);
    }

    public class PointLight : Light {

        public Point point;

        public PointLight(Point p, Color color)
        {
            this.color = color;
            this.point = p;
        }

        public override void preprocess() { }

        public override float getLight(ref Color lcolor, ref Vector ldir, RenderContext rc, Point hp)
        {

            lcolor = this.color;
            ldir = this.point - hp;
            return ldir.normalize();

        }

    }

    class DirectionalLight : Light
    {

        public Vector dir;

        DirectionalLight(Vector dir, Color color)
        {
            this.dir = dir;
            this.color = color;
        }

        public override void preprocess() { this.dir.normalize(); }

        public override float getLight(ref Color lcolor, ref Vector ldir, RenderContext rc, Point hp) {

            lcolor = this.color;
            ldir = -this.dir;
            return float.PositiveInfinity;

        }

    }

} // namespace RT