/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    public class Scene
    {

        public int xResolution;
        public int yResolution;

        public Camera camera;
        public Color ambient;
        public Background background;
        public Object obj;
        public System.Collections.Generic.List<Light> lights = new System.Collections.Generic.List<Light>();

        public void setAmbient(Color ambient) { this.ambient = ambient; }
        public void setBackground(Background background) { this.background = background; }
        public void setCamera(Camera camera) { this.camera = camera; }
        public void setObject(Object obj) { this.obj = obj; }
        public void setResolution(int x, int y) { this.xResolution = x; this.yResolution = y; }
        public void addLight(Light light) { this.lights.Add(light); }

        public Light getLight(int index) { return this.lights[index]; }
        public int numberOfLights() { return this.lights.Count; }
        public Color getAmbient() { return this.ambient; }
        public Object getObject() { return this.obj; }
        public Camera getCamera() { return this.camera; }
        public Background getBackground() { return this.background; }
        public float getAspect() { return (this.xResolution / this.yResolution); }
        public int getXResolution() { return xResolution; }
        public int getYResolution() { return yResolution; }

        public void preprocess()
        {

            this.background.preprocess();
            this.camera.preprocess(this.getAspect());
            this.obj.preprocess();

            for (int i = 0; i < lights.Count; i++)
                this.lights[i].preprocess();
        }

        public void traceRay(Ray ray, HitRecord hr, RenderContext rc)
        {
            this.obj.intersect(ref hr, rc, ray);
        }

    }

} // namespace RT