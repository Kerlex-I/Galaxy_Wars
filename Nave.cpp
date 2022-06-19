#include <iostream>
using namespace std;

class Nave {
    private:
int nBalas,direccion;
    public:
        Nave (){}
        Nave (int nBalas,int direccion){
        nDisparos=nb;
        direccion=d;
        }
      void setNBalas( int nb){
        nBalas = nb;
      }
      void setDireccion(int d){
         direccion = d;
      }

      int getNBalas (){
      return nBalas;
      }
      int getDireccion (){
      return direccion;
      }
      void imprimir(){
         cout<<"nBalas: "<<nBalas;
         cout<<"direccion: "<<direccion;
     }
};
