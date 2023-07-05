#ifndef PROYECTO_MENU_H
#define PROYECTO_MENU_H
#include "BaseDeDatos.h"

class Menu{
private:
    string nombre;
    int EleccionDeRaza{};
    int CantidadDeGuerreros{};
    int NumeroDelJugador{};
    int jugando{};// 0 para establecer que no esta jugando y 1 para establecer que si esta jugando
public:
    //constructores
    Menu();
    Menu(int );
    //metodos
    void EligirRaza(vector<CUnidad*>& , int, int& ,Menu&);
    void nombreJuegador();
    void jugar( );
    void descansa();
    int getEleccionDeRaza() const;

    int getJugando() ;
};


#endif //PROYECTO_MENU_H
