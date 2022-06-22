#include <iostream>
#include <allegro.h>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int pos=1;
const int maxdisp = 4, ANCHO = 800, ALTO = 500, numenemigos = 50;
int ndisparos=0;
int indice=-1;
int indice2=-1;
int azar;
int nb;
BITMAP *buffer;
BITMAP *personaje;
BITMAP *enemigo;
BITMAP *bala;
BITMAP *bala2;
BITMAP *espacio;
BITMAP *fondo1;
BITMAP *fondo2;
BITMAP *fondo3;
BITMAP *cursor;

int cdw = 0, cont = 0, cdwe = 0, conte = 0;
int opcion = 0;

#include "Nave.cpp"
#include "Enemigo.cpp"
#include "Menu.cpp"
void pintaEnemigos(Enemigo e[]);
struct Balas{
    int x,y;
    int dx,dy;
}disparos[maxdisp];
struct BalasE{
    int x,y;
    int dx,dy;
}disparose;

void rutinaDisparos(int &cdw, Nave &n1, int maxdisp, int &cont);
void rutinaDisparosE(int &cdw, Enemigo e1[], int maxdisp, int &cont, int nb);


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
    bala2=load_bitmap("recursos/Bala2.bmp",NULL);
    espacio = load_bitmap("recursos/Space.bmp",NULL);
    fondo1=load_bitmap("recursos/Fondo1.bmp",NULL);
    fondo2=load_bitmap("recursos/Fondo2.bmp",NULL);
    fondo3=load_bitmap("recursos/Fondo3.bmp",NULL);
    cursor=load_bitmap("recursos/cursor.bmp",NULL);
    buffer=create_bitmap(800,500);

    srand(time(0));
    nb=0;



    Nave npersonaje = Nave(ANCHO/2,ALTO-100, ndisparos, personaje);
    Enemigo nenemigo[22];
    for(int i=0; i<2; i++){
        for(int j=0; j<11; j++){
            indice++;
            nenemigo[indice] = Enemigo(100+j*54,150+i*50,ndisparos,enemigo);
        }
    }

    Menu nmenu = Menu(fondo1,fondo2,fondo3,cursor,opcion);

    while(nmenu.getSalida()){
        nmenu.mostrarMenu();
    }

    if(nmenu.getOpcion() != 0){
        while( !key[ KEY_ESC]){
            azar = rand()%21;
            blit(espacio,buffer,0,0,0,0,800,500);
            pintaEnemigos(nenemigo);
            npersonaje.mostrarNave();
            npersonaje.moverDer();
            npersonaje.moverIzq();
            rutinaDisparos(cdw, npersonaje,maxdisp,cont);
            rutinaDisparosE(cdwe,nenemigo,1,conte,nb);

            blit(buffer,screen,0,0,0,0,800,500);
            rest (25);

        }
    }

    return 0;
}
END_OF_MAIN();

void pintaEnemigos(Enemigo e[]){
    for(int i=0;i<22;i++){
        e[i].mostrarEnemigo();
    }
}
void rutinaDisparos(int &cdw, Nave &n1, int maxdisp, int &cont){
    if(key[KEY_SPACE] and cdw == 0){
            if(n1.getNdisparos() < maxdisp){
                n1.sumarAndisparos(1);
                disparos[n1.getNdisparos()].x = n1.getMx() + 22;
                disparos[n1.getNdisparos()].y = n1.getMy() + 7;
                disparos[n1.getNdisparos()].dx = 0;
                disparos[n1.getNdisparos()].dy = -8;
                cdw=1;
            }

        }
        if(cont++ > 10){ //45
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
void rutinaDisparosE(int &cdw, Enemigo e1[], int maxdisp, int &cont, int nb){
    if(cdw == 0){
        if(nb < maxdisp){
            nb++;
            disparose.x = e1[azar].getMx() + 22;
            disparose.y = e1[azar].getMy() + 25;
            disparose.dx = 0;
            disparose.dy = 8;
            cdw = 1;
        }
    }
    if(conte++ > 50){
        conte = 0;
        cdw = 0;
    }
    if(nb>0){
        disparose.x += disparose.dx;
        disparose.y += disparose.dy;
        masked_blit(bala,buffer, 0, 0, disparose.x, disparose.y, 6, 10);

        if(disparose.y > ALTO){
            nb--;
            if(nb<0){
                nb=0;
            }
        }
    }
    blit(buffer,screen,0,0,0,0,800,500);
}
