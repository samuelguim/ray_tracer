#include <cmath>

class Tupla
{
private:
    /* data */
public:

    float x;
    float y;
    float z;
    float w;

    Tupla(float _x, float _y, float _z, float _w){
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    };

    Tupla Ponto(float _x, float _y, float _z){
        return Tupla(_x, _y, _z, 1);
    }

    Tupla Vetor(float _x, float _y, float _z){
        return Tupla(_x, _y, _z, 0);
    }

    bool isVec(Tupla tupla){
        return (tupla.w == 1);
    }

    bool isPoint(Tupla tupla){
        return (tupla.w == 0);
    }

    // operações

    Tupla opSub(Tupla a, Tupla b){
        return Tupla(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
    }

    Tupla opAdd(Tupla a, Tupla b){
        return Tupla(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
    }

    Tupla negar(Tupla a){
        return Tupla(-a.x, -a.y, -a.z, -a.w);
    }

    Tupla multEscalar(Tupla a, float escalar){
        return Tupla(a.x*escalar, a.y*escalar, a.z*escalar, a.w*escalar);
    }

    Tupla divEscalar(Tupla a, float escalar){
        return Tupla(a.x/escalar, a.y/escalar, a.z/escalar, a.w/escalar);
    }

    float magnitude(Tupla v){
        return sqrt((v.x*v.x)+(v.y*v.y)+(v.z*v.z)+(v.w*v.w));
    }

    Tupla norma(Tupla v){
        return Tupla(v.x/magnitude(v),
                     v.y/magnitude(v),
                     v.z/magnitude(v),
                     v.w/magnitude(v));
    }

    float prodEscalar(Tupla a, Tupla b){
        return (a.x*b.x + 
                a.y*b.y +
                a.z*b.z +
                a.w*b.w);
    }

};


