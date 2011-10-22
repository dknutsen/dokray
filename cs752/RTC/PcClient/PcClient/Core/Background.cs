/*
Author: Daniel Knutsen, Trevor Gerhardt
Date:   Spring 2010
Course: CS 752 
*/

namespace RT {

    public abstract class Background {

        public Color color;

        public void preprocess() { }

        public Color getColor(RenderContext rc, Ray ray) 
        {
            return this.color;
        }

    }

    public class ConstantBackground : Background
    {
        public ConstantBackground(Color color) 
        {
            this.color = color;
        }
    }

} // namespace RT