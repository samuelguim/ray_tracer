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
        pixels.resize(h, vector<Cor>(w));
    }

    Cor getPixel(int x, int y){
        return pixels[y][x];
    }

    void writePixel(int x, int y, Cor c){
        pixels[y][x] = c;
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
        for(int i = altura-1; i>=0; i--){
            for (int j = 0; j < largura; j++){
                arquivo << escalaCor(pixels[i][j].red()) << " " << escalaCor(pixels[i][j].green()) << " " << escalaCor(pixels[i][j].blue()) << " ";
            }
            arquivo << "\n";
        }
        arquivo.close();
    }
};