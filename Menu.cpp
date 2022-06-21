#include <iostream>
#include <allegro.h>

using namespace std;

class Menu{

private:
    BITMAP *fondo1;
    BITMAP *fondo2;
    BITMAP *fondo3;
    BITMAP *cursor;
    bool salida = true;
    int opcion;


public:

    Menu(){}
    Menu(BITMAP *f1, BITMAP *f2, BITMAP *f3, BITMAP *c, int op){
        fondo1 = f1;
        fondo2 = f2;
        fondo3 = f3;
        cursor = c;
        opcion = op;
    }

    int getOpcion(){
        return opcion;
    }
    bool getSalida(){
        return salida;
    }

    void mostrarMenu(){
        if(mouse_x > 345 and mouse_x < 452 and
           mouse_y > 343 and mouse_y < 388){
               blit(fondo2,buffer,0,0,0,0,800,500);
               if(mouse_b & 1){
                    salida = false;
                    opcion = 1;
               }
            }
        else if(mouse_x > 358 and mouse_x < 436 and
                mouse_y > 397 and mouse_y < 435){
                    blit(fondo3,buffer,0,0,0,0,800,500);
                    if(mouse_b & 1){
                        salida = false;
                        }
                    }else{ blit(fondo1,buffer,0,0,0,0,800,500);}
                    masked_blit (cursor,buffer,0,0,mouse_x,mouse_y,13,22);
                    blit (buffer,screen,0,0,0,0,800,530);
        }
};
