#include <iostream>
#include <allegro.h>
#include <stdlib.h>
#include <conio.h>


using namespace std;

int pos=1;
int x=400, y=400;
const int maxdisp = 8, ANCHO = 800, ALTO = 500;
int ndisparos=0;
BITMAP *buffer;
BITMAP *personaje;
BITMAP *bala;
BITMAP *fondo1;
BITMAP *fondo2;
BITMAP *fondo3;
BITMAP *cursor;
int cdw = 0, cont = 0;
int opcion;
bool salir = true;
#include "Nave.cpp"
#include "Menu.cpp"

struct Balas{
    int x,y;
    int dx,dy;
}disparos[maxdisp];
void rutinaDisparos(int &cdw, Nave &n1, int maxdisp, int &cont);

int main()
{

    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800,500,0,0);
    personaje=load_bitmap("recursos/Nave.bmp", NULL);
    bala=load_bitmap("recursos/Bala.bmp",NULL);
    fondo1=load_bitmap("recursos/Fondo1.bmp",NULL);
    fondo2=load_bitmap("recursos/Fondo2.bmp",NULL);
    fondo3=load_bitmap("recursos/Fondo3.bmp",NULL);
    cursor=load_bitmap("recursos/cursor.bmp",NULL);
    buffer=create_bitmap(800,500);




    Nave npersonaje = Nave(x,y, ndisparos, personaje);
    Menu nmenu = Menu(fondo1,fondo2,fondo3,cursor,salir,opcion);



    while(nmenu.getSalida()){
        nmenu.mostrarMenu();
    }
    while( !key[ KEY_ESC]){
        npersonaje.mostrarNave();
        npersonaje.moverDer();
        npersonaje.moverIzq();
        rutinaDisparos(cdw, npersonaje,maxdisp,cont);
        rest (15);
    }

    return 0;
}
END_OF_MAIN();
void rutinaDisparos(int &cdw, Nave &n1, int maxdisp, int &cont){
    if(key[KEY_SPACE] and cdw == 0){
            if(n1.getNdisparos() < maxdisp){
                n1.sumarAndisparos(1);
                disparos[n1.getNdisparos()].x = n1.getMx() + 22;
                disparos[n1.getNdisparos()].y = n1.getMy();
                disparos[n1.getNdisparos()].dx = 0;
                disparos[n1.getNdisparos()].dy = -8;
                cdw=1;
            }

        }
        if(cont++ > 5){
            cdw = 0;
            cont = 0;
        }

        if(n1.getNdisparos() > 0){
            for(int i = 1; i <= n1.getNdisparos(); i++){
                    disparos[i].x += disparos[i].dx;
                    disparos[i].y += disparos[i].dy;
                    masked_blit(bala,buffer, 0, 0, disparos[i].x, disparos[i].y, 6, 10);

                    if(disparos[i].y < 0){
                        disparos[i] = disparos[n1.getNdisparos()];
                        n1.restarAndisparos(1);
                        if(n1.getNdisparos() < 0){
                            n1.setNdisparos(0);
                        }
                    }
            }
        }
        blit(buffer,screen,0,0,0,0,800,500);
}
