#include <allegro.h>
#include <iostream>

using namespace std;

class Nave{

private:
    int vida,direccion;
    string nombre;
    public:
        Nave (){}
        Nave (int direccion, int vida, string nombre){
        direccion = d;
        vida = v;
        nombre = n;
        }

      void setDireccion(int d){
         direccion = d;
      }
      void setVida (int v){
      vida= v;
      }
      void setNombre (string n){
      nombre=n;
      }
      int getDireccion (){
      return direccion;
      }
      int getVida (){
      return vida;
      }
      string getNombre (){
      return nombre;
      }
      void imprimir(){
         cout<<"direccion: "<<direccion;
         cout<<"vida:"<<nombre;
         cout<<"nombre:"<<nombre;
     }
};


