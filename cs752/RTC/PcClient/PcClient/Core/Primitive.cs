/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

   public abstract class Primitive : Object {

       public Material material;

      public abstract Vector normal( Point point );

   }

} // namespace RT