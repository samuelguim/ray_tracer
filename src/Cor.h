#include "Tupla.h"

class Cor : Tupla{
public:
    
    float red(){
        return x;
    }
    float green(){
        return y;
    }
    float blue(){
        return z;
    }

    Cor(){}

    Cor(float red, float green, float blue)
        :Tupla(red, green, blue, 0)
    {}

    Cor operator-(const Cor& b) const {
        Cor resultado = *this;
        resultado.x -= b.x;
        resultado.y -= b.y;
        resultado.z -= b.z;
        resultado.w -= b.w;
        return resultado;
    }

    Cor operator+(const Cor& b) const {
        Cor resultado = *this;
        resultado.x += b.x;
        resultado.y += b.y;
        resultado.z += b.z;
        resultado.w += b.w;
        return resultado;
    }

    Cor operator*(const float& escalar) const {
        Cor resultado = *this;
        resultado.x = resultado.x * escalar;
        resultado.y = resultado.y * escalar;
        resultado.z = resultado.z * escalar;
        resultado.w = resultado.w * escalar;
        return resultado;
    }

    Cor operator*(const Cor& b) const {
        Cor resultado = *this;
        resultado.x = resultado.x * b.x;
        resultado.y = resultado.y * b.y;
        resultado.z = resultado.z * b.z;
        resultado.w = resultado.w * b.w;
        return resultado;
    }
};