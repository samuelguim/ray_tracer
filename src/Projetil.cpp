#include "Tupla.h"
#include <iostream>

class Projetil {
    public:
        Tupla posicao;
        Tupla velocidade;
        
        Projetil(Tupla p, Tupla v){
            posicao = p;
            velocidade = v;
        }
    };

class Ambiente {
    public:
        Tupla gravidade;
        Tupla vento;
        
        Ambiente(Tupla g, Tupla v){
            gravidade = g;
            vento = v;
        }
    };

Projetil tick(Ambiente a, Projetil p){
    Tupla posicao = Tupla::opAdd(p.posicao, p.velocidade);
    Tupla velocidade = Tupla::opAdd(p.velocidade,(Tupla::opAdd(a.gravidade,a.vento)));
    return Projetil(posicao, velocidade);
}

int main(){
    Projetil p1 = Projetil(Tupla::Ponto(1,1,1), Tupla::norma(Tupla::Vetor(1,1,0)));
    Ambiente a1 = Ambiente(Tupla::Vetor(0,0.1,0), Tupla::Vetor(0.01,0,0));

    return 0;
}

