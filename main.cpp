#include <iostream>
#include <allegro.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
int pos=1;
int x=740, y=500;

BITMAP *buffer;
BITMAP *Nav;
BITMAP *Enemigo;
int main()
{

    allegro_init();
    install_keyboard();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 740,500,0,0);
    BITMAP*buffer=create_bitmap(740,500);

    Nav=load_bitmap("recursos/Nave.bmp",NULL);




    int x1,x2,y1,y2;

    x1=0;
    y1=0;
    x2=30;
    y2=30;

    while( !key[ KEY_ESC]){
        clear_to_color(buffer, 0x000000);
            blit(Nav,screen,x1,y1,x2,y2,30,54);
            blit (buffer,screen,0,0,0,0,740,500);
        if (key[ KEY_RIGHT]){

           x1 +=10;
           x2 +=10;
        }

        if (key[ KEY_LEFT]){

           x1 -=10;
           x2 -=10;
        }


        rest (10);
    }

    return 0;
}
END_OF_MAIN();

