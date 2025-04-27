#include <cmath>
#include <iostream>
#include <iostream>

class Tupla
{
private:
    /* data */
public:

    float x, y, z, w;
    
    static void print(Tupla a){
        std::cout << "(" << a.x << ", " << a.y << ", " << a.z << ", " << a.w <<  ")\n";
    }

    Tupla(){}

    Tupla(float _x, float _y, float _z, float _w){
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    };

    static Tupla Ponto(float _x, float _y, float _z){
        return Tupla(_x, _y, _z, 1);
    }

    static Tupla Vetor(float _x, float _y, float _z){
        return Tupla(_x, _y, _z, 0);
    }

    static bool isVec(Tupla tupla){
        return (tupla.w == 1);
    }

    static bool isPoint(Tupla tupla){
        return (tupla.w == 0);
    }

    // operações

    Tupla operator-(const Tupla& b) const {
        Tupla resultado = *this;
        resultado.x -= b.x;
        resultado.y -= b.y;
        resultado.z -= b.z;
        resultado.w -= b.w;
        return resultado;
    }

    Tupla operator+(const Tupla& b) const {
        Tupla resultado = *this;
        resultado.x += b.x;
        resultado.y += b.y;
        resultado.z += b.z;
        resultado.w += b.w;
        return resultado;
    }

    Tupla operator!(){
        Tupla resultado = *this;
        return Tupla(-resultado.x, -resultado.y, -resultado.z, -resultado.w);
    }

    Tupla operator*(const float& escalar) const {
        Tupla resultado = *this;
        resultado.x = resultado.x * escalar;
        resultado.y = resultado.y * escalar;
        resultado.z = resultado.z * escalar;
        resultado.w = resultado.w * escalar;
        return resultado;
    }

    float operator*(const Tupla& b) const {
        Tupla a = *this;
        float resultado;
        resultado = (a.x*b.x + 
                     a.y*b.y +
                     a.z*b.z +
                     a.w*b.w);
        return resultado;
    }

    Tupla operator/(const float& escalar) const {
        Tupla resultado = *this;
        resultado.x = resultado.x / escalar;
        resultado.y = resultado.y / escalar;
        resultado.z = resultado.z / escalar;
        resultado.w = resultado.w / escalar;
        return resultado;
    }
    
    static float magnitude(Tupla v){
        return sqrt((v.x*v.x)+(v.y*v.y)+(v.z*v.z)+(v.w*v.w));
    }

    static Tupla norma(Tupla v){  
        return Tupla(v.x/magnitude(v),
                     v.y/magnitude(v),
                     v.z/magnitude(v),
                     v.w/magnitude(v));
    }


    static Tupla prodVet(Tupla a, Tupla b) {
        return Vetor(a.y*b.z-a.z*b.y,
                     a.z*b.x-a.x*b.z,
                     a.x*b.y-a.y*b.x);
    }
};


