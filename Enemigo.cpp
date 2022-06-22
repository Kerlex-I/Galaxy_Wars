#include <allegro.h>
#include <iostream>

using namespace std;

class Enemigo{

    private:
    int mx;
    float my;
    int ndisparos;
    BITMAP *enemigo;

public:
    Enemigo(){}
    Enemigo(int x, int y, int nd, BITMAP *p){
        mx = x;
        my = y;
        ndisparos = nd;
        personaje = p;
    }

    void setMx(int x){
        mx = x;
    }
    void setMy(int y){
        my = y;
    }
    void setNdisparos(int nd){
        ndisparos = nd;
    }

    int getMx(){
        return mx;
    }
    int getMy(){
        return my;
    }
    void mostrarEnemigo(){
        masked_blit(personaje,buffer, 0, 7, mx, my, 50, 45);
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
