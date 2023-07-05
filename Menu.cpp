#include "Menu.h"
Menu::Menu(){}
Menu::Menu(int _numero):NumeroDelJugador(_numero),jugando(0){}

void Menu::EligirRaza(vector<CUnidad*>& guerreros, int modoDeJuego,int &turno,Menu& jugador){
    cout<<"\nA cual raza desea perteneser \n";
    cout<<"1. protos\n";
    cout<<"2. Zerg\n";
    cout<<"3. Terran\n";
    cout<<"Selecione un numero: ";
    cin >> EleccionDeRaza;
    if(turno==2){
        for(int i=0;EleccionDeRaza==jugador.getEleccionDeRaza();i++){
            cout<<"recuerde que los dos jugadores no podran escojer la misma raza: ";
            cin >> EleccionDeRaza;
        }
        cout<<"\n";
    };
    if(turno==1){
        turno++;
    }

    cout<<"Ingrese la cantidad de guerreros que desea seleccionar: ";
    cin>>CantidadDeGuerreros;
    cout<<"\nLos heroes disponibles son: \n";
    switch (EleccionDeRaza) {
        case 1:
            imprimirUnidades(BaseProtos,"Base",EleccionDeRaza);
            anadirguerreros(BaseProtos,CantidadDeGuerreros,guerreros,modoDeJuego);
            cout<<"\nSus guerreros que selecciono previamente son los siguientes:\n";

            imprimirUnidades(guerreros,"Guerreros",EleccionDeRaza);
            break;
        case 2:
            imprimirUnidades(BaseZerg,"Base",EleccionDeRaza);
            anadirguerreros(BaseZerg,CantidadDeGuerreros,guerreros,modoDeJuego);
            cout<<"\nSus guerreros que selecciono previamente son los siguientes:\n";

            imprimirUnidades(guerreros,"Guerreros",EleccionDeRaza);
            break;
        case 3:
            imprimirUnidades(BaseTerran,"Base",EleccionDeRaza);
            anadirguerreros(BaseTerran,CantidadDeGuerreros,guerreros,modoDeJuego);
            cout<<"\nSus guerreros que selecciono previamente son los siguientes:\n";

            imprimirUnidades(guerreros,"Guerreros",EleccionDeRaza);
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
    }
}
void Menu::nombreJuegador(){
    cout<<"\nIngrese su nombre jugador "<<NumeroDelJugador<<": ";
    cin>>nombre;
}
void Menu::jugar(){
    cout<<"Turno de "<<nombre<<"( jugador "<<NumeroDelJugador<<") \n";
    jugando=1;
}

int Menu::getJugando()  {
    return jugando;
}
void Menu::descansa(){
    jugando=0;
}

int Menu::getEleccionDeRaza() const {
    return EleccionDeRaza;
}
