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
float calcularDaño(CUnidad* agredido, float danoDelAtacante, float multiplicador);
float calcularMultiplicador(const string& tamanio, const string& tipoAtaque);
void enfrentamiento(int ,vector<CUnidad*> &  ,int ,vector<CUnidad*> &,Menu&  );
void ataqueEnGrupo(vector<CUnidad*>& BaseAtacante, vector<CUnidad*>& BaseAtacada, Menu& jugador, int& n);

#endif //PROYECTO_ENFRENTAMIENTO_H
