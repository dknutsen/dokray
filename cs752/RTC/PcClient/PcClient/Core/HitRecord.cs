/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

   public class HitRecord {

       public float t;
       public Primitive primitive;
       public Material material;

       public HitRecord()
       {
         this.t = float.PositiveInfinity;
         this.primitive = null;
         this.material = null;
      }

       public float getT() { return this.t; }
       public Primitive getPrimitive() { return this.primitive; }
       public Material getMaterial() { return this.material; }

       public bool hit(float t, Primitive hitPrimitive, Material hitMaterial)
       {
         
         if ( this.t > t ) {
         
            this.t = t;
            this.primitive = hitPrimitive;
            this.material = hitMaterial;
            return true;
         
         }
     
         return false;
      
      }

   }

} // namespace RT