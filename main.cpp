#include <iostream>
#include <allegro.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int pos=1;
const int maxdisp = 9, ANCHO = 800, ALTO = 500, numenemigos = 50;
int ndisparos=0;
BITMAP *buffer;
BITMAP *personaje;
BITMAP *enemigo;
BITMAP *bala;
BITMAP *espacio;
BITMAP *fondo1;
BITMAP *fondo2;
BITMAP *fondo3;
BITMAP *cursor;

int cdw = 0, cont = 0;
int opcion = 0;

#include "Nave.cpp"
#include "Menu.cpp"

struct Balas{
    int x,y;
    int dx,dy;
}disparos[maxdisp];
Balas disparose[maxdisp];
void rutinaDisparos(int &cdw, Nave &n1, int maxdisp, int &cont);
void iniciarEnemigo(Nave e[],int nd);

int main()
{

    allegro_init();
    install_keyboard();
    install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800,500,0,0);
    personaje=load_bitmap("recursos/Nave.bmp",NULL);
    enemigo=load_bitmap("recursos/Enemigo.bmp",NULL);
    bala=load_bitmap("recursos/Bala.bmp",NULL);
    espacio = load_bitmap("recursos/Space.bmp",NULL);
    fondo1=load_bitmap("recursos/Fondo1.bmp",NULL);
    fondo2=load_bitmap("recursos/Fondo2.bmp",NULL);
    fondo3=load_bitmap("recursos/Fondo3.bmp",NULL);
    cursor=load_bitmap("recursos/cursor.bmp",NULL);
    buffer=create_bitmap(800,500);

    Nave npersonaje = Nave(ANCHO/2,ALTO-100, ndisparos, personaje);
    Nave nenemigo[50];
    iniciarEnemigo(nenemigo,ndisparos);
    Menu nmenu = Menu(fondo1,fondo2,fondo3,cursor,opcion);



    while(nmenu.getSalida()){
        nmenu.mostrarMenu();
    }

    if(nmenu.getOpcion() != 0){
        while( !key[ KEY_ESC]){
            blit(espacio,buffer,0,0,0,0,800,500);
            npersonaje.mostrarNave();
            npersonaje.moverDer();
            npersonaje.moverIzq();
            rutinaDisparos(cdw, npersonaje,maxdisp,cont);


            blit(buffer,screen,0,0,0,0,800,500);
            rest (15);

        }
    }

    return 0;
}
END_OF_MAIN();
void iniciarEnemigo(Nave e[], int nd){
    int indice = -1;
    for(int i=0;i<5;i++){
        for(int j=0;j<11;j++){
            indice++;
            e[indice] = Nave(140+j*30,100+i*24,nd,enemigo);
        }
    }
}
void rutinaDisparos(int &cdw, Nave &n1, int maxdisp, int &cont){
    if(key[KEY_SPACE] and cdw == 0){
            if(n1.getNdisparos() < maxdisp){
                n1.sumarAndisparos(1);
                disparos[n1.getNdisparos()].x = n1.getMx() + 22;
                disparos[n1.getNdisparos()].y = n1.getMy();
                disparos[n1.getNdisparos()].dx = 0;
                disparos[n1.getNdisparos()].dy = -6;
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
