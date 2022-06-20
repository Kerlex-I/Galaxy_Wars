#include <iostream>
#include <allegro.h>
#include <stdlib.h>
#include <conio.h>



using namespace std;

int pos=1;
int x=400, y=400;


BITMAP *buffer;
BITMAP *personaje;
#include "Nave.cpp"

int main()
{

    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 740,500,0,0);
    BITMAP *personaje=load_bitmap("recursos/Enemigo.bmp", NULL);
    buffer=create_bitmap(740,500);
    Nave npersonaje = Nave(x,y,personaje);

    while( !key[ KEY_ESC]){
        npersonaje.mostrarNave();
        npersonaje.moverDer();
        npersonaje.moverIzq();

        rest (15);
    }

    return 0;
}
END_OF_MAIN();

