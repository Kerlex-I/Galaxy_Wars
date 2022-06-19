#include <iostream>
using namespace std;

class NaveEnemiga {
    private:
        int nDisparos, nNaves, direccion;
    public:
        NaveEnemiga(){}
        NaveEnemiga (int nDisparos, int nNaves, int direccion){
        nDisparos = nd;
        nNaves = nv;
        direccion=di;
        }
        void setNDisparos( int nd){
        nDisparos = nd;
      }
      void setNNaves (int nv){
      nNaves = nv;
      }
      void setDireccion(int di){
         direccion = di;
      }

      int getNBalas (){
      return nBalas;
      }
      int getNNaves (){
      return nNaves
      }
      int getDireccion (){
      return direccion;
      }
      void imprimir(){
         cout<<"nBalas: "<<nBalas;
         cout<<"nNaves:"<<nNaves;
         cout<<"direccion: "<<direccion;
     }
};
