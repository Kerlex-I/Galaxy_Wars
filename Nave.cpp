#include <allegro.h>
#include <iostream>

using namespace std;

class Nave{

private:
    float mx;
    float my;
    BITMAP *personaje = load_bitmap("recursos/Nave.bmp",NULL);

public:
    Nave(){}
    Nave(float x, float y, BITMAP *p){
        mx = x;
        my = y;
        personaje = p;
    }

    void setMx(float x){
        mx = x;
    }
    void setMy(float y){
        my = y;
    }
    void mostrarNave(){
        clear_to_color(buffer,0x000000);
        blit(personaje,buffer, 0, 0, mx, my, 50, 50);
        blit(buffer,screen,0,0,0,0,740,500);
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

};
