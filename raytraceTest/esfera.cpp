
#include <fstream>
#include <cmath>

  struct Vec 
  {
    double x,y,z;
    Vec(){x=y=z=0;}
    Vec(double a, double b, double c){x=a , y=b , z=c;}
    Vec operator + (Vec v) {return Vec(x+v.x , y+v.y , z+v.z);}
    Vec operator - (Vec v) {return Vec(x-v.x , y-v.y , z-v.z);}
    Vec operator * (double d) {return Vec(x*d,y*d,z*d);}
    Vec operator / (double d) {return Vec(x/d,y/d,z/d);}
    Vec normalize() {double mg = sqrt(x*x+y*y+z*z); return Vec(x/mg,y/mg,z/mg);}
  };
  double dot(Vec v, Vec b){return (v.x*b.x + v.y*b.y + v.z*b.z);}
  struct Ray
  {
    Vec o; //orgien
    Vec d; //direccion
    Ray(Vec i , Vec j){o=i,d=j;}
  };
  struct Sphere
  {
    Vec c;   //Centro
    double r;  //radio
    Sphere(Vec i, double j){c=i;r=j;}
    Vec getNormal(Vec pi) {return (pi-c)/r;}
    bool intersect(Ray ray,double &t)
    {
      Vec o = ray.o;
      Vec d = ray.d;
      Vec oc = o-c;
      double b = 2*dot(oc,d);
      double c = dot(oc,oc)-r*r;
      double disc = b*b-4*c;
      if(disc<0) return false;
      else{
        disc = sqrt(disc);
        double t0 = -b-disc;
        double t1 = -b+disc;
        t= (t0 < t1) ? t0 : t1;
        return true;
      }  
     }
  };
  struct Color{
    double r,g,b;
    Color(){r=g=b=0;}
    Color(double i, double j, double k){r=i,g=j,b=k;}
    Color operator * (double d){return Color(r*d,g*d,b*d);}
    Color operator + (Color c){return Color((r+c.r)/2,(g+c.g)/2,(b+c.b)/2);}
  };
 int main(){
   const int W = 500; //width
   const int H = 500; //high 

   out << "P3\n" << W << '\n' << H<< '\n' << "255\n";

 
  Color pixel_col[H][W];
  Color white (255,255,255);
  Color red (1,0,0);
  Color black (255,255,255);
  Sphere sphere(Vec(W/2,H/2,50),60.0);
  //Sphere light(Vec(W/2,0,50),1.0);
  //para cada pixel
  for(int y = 0; y < H; y++)
  {
    for(int x = 0;x<W;x++){
      //usar un rayo para cada uno
      Ray ray(Vec(x,y,0),Vec(0,0,1));
      double t = 20000;
      //vereificar intersecciones
      if(sphere.intersect(ray,t)){
        //[unto de interseccion]
        Vec pi = ray.o + ray.d*t;
        Vec N = sphere.getNormal(pi);
        //Vec L = light.c -pi;
        //si choca colorea pixel

        //double dt= dot(L.normalize,N.normalize());
        pixel_col[y][x]= red /*(white*dt)*0.1*/ ;
////NO ES INPORTANTE DLO DE ABAJO
      /*  if(pixel_col[y][x].r < 0) pixel_col[y][x].r=0;
        if(pixel_col[y][x].g < 0) pixel_col[y][x].g=0;
        if(pixel_col[y][x].b < 0) pixel_col[y][x].b=0;

        if(pixel_col[y][x].r > 0) pixel_col[y][x].r=255;
        if(pixel_col[y][x].g > 0) pixel_col[y][x].g=255;
        if(pixel_col[y][x].b > 0) pixel_col[y][x].b=255;*/

      }

   
  
    }
  }
  return 0;
}
//////////////////////////////////////////////////////////////ROJO DE GIT
#include <fstream>
#include <cmath>

struct Vec3 {
  double x,y,z;
  Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
  Vec3 operator + (const Vec3& v) const { return Vec3(x+v.x, y+v.y, z+v.z); }
  Vec3 operator - (const Vec3& v) const { return Vec3(x-v.x, y-v.y, z-v.z); }
  Vec3 operator * (double d) const { return Vec3(x*d, y*d, z*d); }
  Vec3 operator / (double d) const { return Vec3(x/d, y/d, z/d); }
  Vec3 normalize() const {
    double mg = sqrt(x*x + y*y + z*z);
    return Vec3(x/mg,y/mg,z/mg);
  }
};
inline double dot(const Vec3& a, const Vec3& b) {
  return (a.x*b.x + a.y*b.y + a.z*b.z);
}

struct Ray {
  Vec3 o,d;
  Ray(const Vec3& o, const Vec3& d) : o(o), d(d) {}
};

struct Sphere {
  Vec3 c;
  double r;
  Sphere(const Vec3& c, double r) : c(c), r(r) {}
  Vec3 getNormal(const Vec3& pi) const { return (pi - c) / r; }
  bool intersect(const Ray& ray, double &t) const {
    const Vec3 o = ray.o;
    const Vec3 d = ray.d;
    const Vec3 oc = o - c;
    const double b = 2 * dot(oc, d);
    const double c = dot(oc, oc) - r*r;
    double disc = b*b - 4 * c;
    if (disc < 1e-4) return false;
    disc = sqrt(disc);
    const double t0 = -b - disc;
    const double t1 = -b + disc;
    t = (t0 < t1) ? t0 : t1;
    return true;
  }
};

void clamp255(Vec3& col) {
  col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
  col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
  col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
}

int main() {

  const int H = 500;
  const int W = 500;

  const Vec3 white(255, 255, 255);
  const Vec3 black(0, 0, 0);
  const Vec3 red(255, 0, 0);

  const Sphere sphere(Vec3(W*0.5, H*0.5, 50), 50);
  const Sphere light(Vec3(0, 0, 50), 1);

  std::ofstream out("out.ppm");
  out << "P3\n" << W << ' ' << H << ' ' << "255\n";

  double t;
  Vec3 pix_col(black);

  for (int y = 0; y < H; ++y) {
    for (int x = 0; x < W; ++x) {
      pix_col = black;

      const Ray ray(Vec3(x,y,0),Vec3(0,0,1));
      if (sphere.intersect(ray, t)) {
        const Vec3 pi = ray.o + ray.d*t;
        const Vec3 L = light.c - pi;
        const Vec3 N = sphere.getNormal(pi);
        const double dt = dot(L.normalize(), N.normalize());

        pix_col = (red + white*dt) * 0.5;
        clamp255(pix_col);
      }
      out << (int)pix_col.x << ' '
          << (int)pix_col.y << ' '
          << (int)pix_col.z << '\n';
    }
  }
}