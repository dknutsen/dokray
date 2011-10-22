/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    public class Core {
        
        public Scene scene;

        public Core(Scene scene)
        {
            this.scene = scene;
        }

        public void setScene(Scene scene)
        {
            this.scene = scene;
        }

        public Color renderPixel(int x, int y)
        {

          Color color;
          HitRecord hitRecord = new HitRecord();
          Ray ray;
          RenderContext renderContext = new RenderContext( this.scene );

          float step = 2 / (float)this.scene.getXResolution();
          float xStart = -1 + ( 0.5f * step );
          float yStart = (-(float)this.scene.getYResolution() * (0.5f * step)) + (0.5f * step);

          ray = this.scene.getCamera().generateRay( xStart + (x * step), yStart + (y * step) );
          this.scene.traceRay( ray, hitRecord, renderContext );

          if ( hitRecord.getT() == float.PositiveInfinity || hitRecord.getMaterial() == null || hitRecord.getPrimitive() == null ) {

             color = this.scene.getBackground().getColor( renderContext, ray );

          } else {

             color = hitRecord.getMaterial().shade( renderContext, ray, hitRecord, 1 );

          }

          return color;

        }

   }

}