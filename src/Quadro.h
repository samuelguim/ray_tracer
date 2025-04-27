#include "Cor.h"
#include <vector>
#include <iostream>
#include <fstream> 

using namespace std;

class Quadro{
private:
    vector<vector<Cor>> pixels;
public: 
    int largura, altura;
    Quadro(int w, int h){
        largura = w;
        altura = h;
        pixels.resize(w, vector<Cor>(h));
    }

    Cor getPixel(int w, int h){
        return pixels[w][h];
    }

    void writePixel(int w, int h, Cor c){
        pixels[w][h] = c;
    }

    int escalaCor(float cor){
        int resultado = cor*255;
        if (resultado > 255){
            return 255;
        }
        else if (resultado < 0){
            return 0;
        }
        else {
            return resultado;
        }
    }

    void salvarQuadro(){
        ofstream arquivo("render.ppm");
        arquivo << "P3" << "\n" << largura << " " << altura << "\n" << 255 << "\n";
        for(int i = 0; i < largura; i++){
            for (int j = 0; j < altura; j++){
                arquivo << escalaCor(pixels[i][j].red()) << " " << escalaCor(pixels[i][j].green()) << " " << escalaCor(pixels[i][j].blue()) << " ";
                // if (j % 5 == 0){
                //     arquivo << "\n";
                // }
            }
            arquivo << "\n";
        }
        arquivo.close();
    }
};