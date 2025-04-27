#include "Quadro.h"

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
    Tupla posicao = p.posicao + p.velocidade;
    Tupla velocidade = p.velocidade + (a.gravidade + a.vento);
    return Projetil(posicao, velocidade);
}

int main(){
    Quadro c = Quadro(900,550);
    Cor c1 = Cor(0, 0, 1);


    Projetil p1 = Projetil(Tupla::Ponto(0,1,0), Tupla::norma(Tupla::Vetor(1,1.8,0))*11.25);
    Ambiente a1 = Ambiente(Tupla::Vetor(0,-0.1,0), Tupla::Vetor(-0.01,0,0));

    while (p1.posicao.y>=0){
        p1 = tick(a1, p1);
        c.writePixel(p1.posicao.x, 200, c1);
        Tupla::print(p1.posicao);
    }

    c.salvarQuadro();




    // Tupla t1 = Tupla(0, 0, 1, 0);
    // Tupla t2 = Tupla(0, 1, 0, 1);
    // Tupla t3 = t1 + t2;
    // Tupla t4 = t1 - t2;
    // Tupla t5 = t1 / 2;
    // float t6 = t1 * t2;
    // Tupla t7 = !t1;
    // float t8 = Tupla::magnitude(t1);
    // Tupla t9 = Tupla::norma(t1);

    // Tupla::print(t3);
    // Tupla::print(t4);
    // Tupla::print(t5);
    // Tupla::print(t7);
    // Tupla::print(t9);

    // Cor c1 = Cor(0, 0, 1);
    // Cor c2 = Cor(0,1,0);
    // Cor c3 = c1* 2;

    // std::cout << c3.red() << " " << c3.green() << " " << c3.blue() << "\n";



    return 0;
}

