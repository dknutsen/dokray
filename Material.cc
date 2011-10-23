

#include "Material.hh"
#include "HitRecord.hh"
#include "Scene.hh"
#include "Primitive.hh"
#include "Ray.hh"
#include "RenderContext.hh"
#include "Light.hh"
#include "Camera.hh"

#include <math.h>


//////////////////////////////////////////////////////////////////////////////
//------------------------------ Lambertian --------------------------------/
////////////////////////////////////////////////////////////////////////////
LambertianMaterial::LambertianMaterial(Color color, float kd, float ka){
   this->color = color; 
   this->kd = kd; 
   this->ka = ka;
}

void LambertianMaterial::Preprocess(){

}

Color LambertianMaterial::Shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth) const{
   Point hp = ((Ray&)ray).PointOn(((HitRecord&)hrec).GetT());
   Vector normal = ((HitRecord&)hrec).GetPrimitive()->Normal(hp);

   hp += 0.0001f * normal;
	
   Scene* scene = (Scene*)rc.GetScene();
   int numlights = scene->NumLights();
   Color finalc(0.f,0.f,0.f);

   for(int i=0; i<numlights; i++){
      Vector ldir;
      Color lcolor;
      float ldist = scene->GetLight(i)->GetLight(lcolor, ldir, rc, hp);
		
      HitRecord shadowhr;
      Ray shadowray(hp, ldir);
      scene->GetObject()->Intersect(shadowhr, rc, shadowray);
      if(shadowhr.GetT()>=ldist || shadowhr.GetT()<0.01){
         float dp = Dot(normal, ldir);
         if(dp > 0) 
            finalc += dp*lcolor;
      }
   }

   return color*(finalc*kd + scene->GetAmbient()*ka);
}



////////////////////////////////////////////////////////////
//----------------------- Phong -------------------------//
//////////////////////////////////////////////////////////
PhongMaterial::PhongMaterial(Color color, float ke, float kd, float ka, float ks, float shininess){
   this->color = color; 
   this->ke = ke; 
   this->kd = kd; 
   this->ka = ka; 
   this->ks = ks;
   n = shininess;
}

void PhongMaterial::Preprocess(){
	//if(kd+ks > 1.f){
	//	float d = 1/(kd+ks);
	//	kd*=d; ks*=d;
	//}
}

Color PhongMaterial::Shade(const RenderContext& rc, const Ray& ray, const HitRecord& hrec, int depth) const{
   Scene* scene = (Scene*)rc.GetScene();
   Point hp = ((Ray&)ray).PointOn(((HitRecord&)hrec).GetT());
   Vector normal = ((HitRecord&)hrec).GetPrimitive()->Normal(hp);
   Vector v = scene->GetCamera()->GetEye() - hp;
   v.Normalize();

   hp += 0.0001f * normal;
	
   int numlights = scene->NumLights();
   Color finalc(0.f,0.f,0.f);

   for(int i=0; i<numlights; i++){
      Vector ldir;
      Color lcolor;
      float ldist = scene->GetLight(i)->GetLight(lcolor, ldir, rc, hp);
		
      HitRecord shadowhr;
      Ray shadowray(hp, ldir);
      scene->GetObject()->Intersect(shadowhr, rc, shadowray);
      if((shadowhr.GetT()>=ldist || shadowhr.GetT()<0.01)){
         float dp = Dot(normal, ldir) * kd;
         if(!(dp > 0)) dp = 0;
         Vector r = 2*(Dot(ldir, normal))*normal - ldir;
         r.Normalize();

         float spec = Dot(r, v);
         if(!(spec > 0)) spec = 0;
         else spec = pow(spec,n);
				
         finalc += (dp*kd+spec*ks)*lcolor;
      }
   }
	
   return color*(finalc + scene->GetAmbient()*ka);
}




