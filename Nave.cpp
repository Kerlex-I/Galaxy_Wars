#include <allegro.h>
#include <iostream>

using namespace std;

class Nave{

private:
    float mx;
    float my;
    int ndisparos = 0;
    BITMAP *personaje = load_bitmap("recursos/Nave.bmp",NULL);
    BITMAP *espacio = load_bitmap("recursos/Space.bmp",NULL);

public:
    Nave(){}
    Nave(float x, float y, int nd, BITMAP *p){
        mx = x;
        my = y;
        ndisparos = nd;
        personaje = p;
    }

    void setMx(float x){
        mx = x;
    }
    void setMy(float y){
        my = y;
    }
    void mostrarNave(){
        blit(espacio,buffer,0,0,0,0,800,500);
        masked_blit(personaje,buffer, 0, 0, mx, my, 50, 50);
        blit(buffer,screen,0,0,0,0,800,500);
    }
    float getMx(){
        return mx;
    }
    float getMy(){

        return my;
    }

    void moverDer(){
        if(key[KEY_RIGHT]){
            mx+=5;
        }
    }
    void moverIzq(){
        if(key[KEY_LEFT]){
            mx-=5;
        }
    }

    void setNdisparos(int nd){
        ndisparos = nd;
    }
    int getNdisparos(){
        return ndisparos;
    }

    void sumarAndisparos(int a){
        ndisparos+=a;
    }
    void restarAndisparos(int a){
        ndisparos-=a;
    }

};
