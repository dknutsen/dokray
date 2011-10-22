/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    public abstract class Material {
        public float kd, ka;
        public Color color;
        public abstract void preprocess();
        public abstract Color shade( RenderContext rc, Ray ray, HitRecord hrec, int depth );
    }

    public class LambertianMaterial : Material {

        public LambertianMaterial(Color color, float kd, float ka)
        {
          this.color = color; 
          this.kd = kd; 
          this.ka = ka;
       }

        public override void preprocess() { }

        public override Color shade(RenderContext rc, Ray ray, HitRecord hrec, int depth)
        {

          Point hp = ray.pointOn(hrec.getT());
          Vector normal = hrec.getPrimitive().normal(hp);

          hp += 0.0001f * normal;

          Scene scene = rc.getScene();
          int numlights = scene.numberOfLights();
          Color finalc = new Color(0,0,0);
          for ( int i = 0; i < numlights; i++ ) {

              Vector ldir = new Vector();
             Color lcolor = new Color();
             float ldist = scene.getLight(i).getLight(ref lcolor, ref ldir, rc, hp);

             HitRecord shadowhr = new HitRecord();
             Ray shadowray = new Ray(hp, ldir);
             scene.getObject().intersect(ref shadowhr, rc, shadowray);
             if ( shadowhr.getT() >= ldist || shadowhr.getT() < 0.01 ) {

                float dp = Vector.dot(normal, ldir);
                if( dp > 0 ) { 
                   finalc += dp*lcolor;
                }

             }
          }

          return color * ( finalc * kd + scene.getAmbient() * ka );
       }

    }

    class PhongMaterial : Material {

        public float ks, ke, n;

        public PhongMaterial(Color color, float ke, float kd, float ka, float ks, float shininess)
        {

            this.color = color; 
            this.ke = ke; 
            this.kd = kd; 
            this.ka = ka; 
            this.ks = ks;
            this.n = shininess;

        }

        public override void preprocess() { }

        public override Color shade(RenderContext rc, Ray ray, HitRecord hrec, int depth)
        {

          Scene scene = rc.getScene();
          Point hp = ray.pointOn(hrec.getT());
          Vector normal = hrec.getPrimitive().normal(hp);
          Vector v = scene.getCamera().getEye() - hp;
          v.normalize();

          hp += 0.0001f * normal;

          int numlights = scene.numberOfLights();
          Color finalc = new Color(0,0,0);

          for(int i = 0; i < numlights; i++) {

              Vector ldir = new Vector();
              Color lcolor = new Color();
              float ldist = scene.getLight(i).getLight(ref lcolor, ref ldir, rc, hp);

             HitRecord shadowhr = new HitRecord();
             Ray shadowray = new Ray(hp, ldir);
             scene.getObject().intersect(ref shadowhr, rc, shadowray);
              if((shadowhr.getT() >= ldist || shadowhr.getT() < 0.01)) {
                float dp = Vector.dot(normal, ldir) * this.kd;
                if(!(dp > 0)) dp = 0;
                Vector r = 2*(Vector.dot(ldir, normal))*normal - ldir;
                r.normalize();
                float spec = Vector.dot(r, v);
                if(!(spec > 0)) spec = 0;
                else 
                   spec = (float)System.Math.Pow(spec, this.n);

                finalc += (dp*kd+spec*ks)*lcolor;
             }
          }

          return color*(finalc + scene.getAmbient()*ka);

       }

    }

} // namespace RT