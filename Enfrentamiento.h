//
// Created by Usuario on 4/07/2023.
//

#ifndef PROYECTO_ENFRENTAMIENTO_H
#define PROYECTO_ENFRENTAMIENTO_H

#include "BaseDeDatos.h"
#include "Menu.h"

enum class ModoAtque {
    BattallaPorUnidad,
    BattallaBrutal,
};
//para que a futuro se le pueda meter mas modos de batalla
class CDano{
private:
    ModoAtque Seleccion;

public:
    void InflingirDano(int ,vector<CUnidad*> &  ,int ,vector<CUnidad*> &,Menu& );

};

void enfrentamiento(int ,vector<CUnidad*> &  ,int ,vector<CUnidad*> &,Menu&  );

#endif //PROYECTO_ENFRENTAMIENTO_H
