#include "Enfrentamiento.h"

//para que a futuro se le puede meter mas modos de batalla
void enfrentamiento(int GuerreroAtacante, vector<CUnidad*>& BaseAtacante, int GuerreroAtacado, vector<CUnidad*>& BaseAtacada, Menu& jugador) {
    // Restar 1 al número ingresado para obtener el índice del vector
    int quienGolpea = GuerreroAtacante - 1;
    int quienRecibe = GuerreroAtacado - 1;

    // Verificar si los índices están dentro del rango válido
    if (quienGolpea >= 0 && quienGolpea < BaseAtacante.size() && quienRecibe >= 0 && quienRecibe < BaseAtacada.size()) {
        // Acceder a los guerreros atacante y atacado
        auto atacante = BaseAtacante[quienGolpea];
        auto agredido = BaseAtacada[quienRecibe];

        // Realizar el cálculo de daño basado en los atributos correspondientes
        float danoDelAtacante ,dano, multiplicador,vida;
        if (agredido->getTipo() == "Terrestre") {
            danoDelAtacante = atacante->getDanoTerrestre();
            //condicionales para pequeño
            if(agredido->getTamanio()=="Pequeno") {
                if (atacante->gettipoDanoTerrestre() == "Normal") {
                    multiplicador = 1;
                }else if (atacante->gettipoDanoTerrestre() == "Explosivo") {
                    multiplicador = 0.5;
                }else if (atacante->gettipoDanoTerrestre() == "Contusivo") {
                    multiplicador = 1;
                }
            }
            if(agredido->getTamanio()=="Mediano") {
                if (atacante->gettipoDanoTerrestre() == "Normal") {
                    multiplicador = 1;
                }else if (atacante->gettipoDanoTerrestre() == "Explosivo") {
                    multiplicador = 0.75;
                }else if (atacante->gettipoDanoTerrestre() == "Contusivo") {
                    multiplicador = 0.5;
                }
            }
            if(agredido->getTamanio()=="Grande") {
                if (atacante->gettipoDanoTerrestre() == "Normal") {
                    multiplicador = 1;
                }else if (atacante->gettipoDanoTerrestre() == "Explosivo") {
                    multiplicador = 1;
                }else if (atacante->gettipoDanoTerrestre() == "Contusivo") {
                    multiplicador = 0.25;
                }
            }
            if(agredido->getEscudo()!=0 ){
                dano=agredido->getEscudo() -danoDelAtacante;
                if(dano>=0){
                    agredido->setEscudo(dano);
                }
                else{
                    dano=agredido->getBlindaje() + dano*multiplicador;
                    if (dano>=0){
                        dano=0;
                    }
                    if(!atacante->getautodestruccion()){
                        atacante->setautodestruccion(true);
                        atacante->setVida(0);
                        cout<<"se autodestruyo"<<atacante->getNombre()<<"\n";
                    }
                    vida = agredido->getVida() + dano;
                    agredido->setVida(vida);
                }
            }else{
                  dano = agredido->getBlindaje() - danoDelAtacante * multiplicador;
                  if (dano >= 0) {
                      dano = 0;
                  }
                if(!agredido->getprimerAtaque() && (agredido->getVida() + dano != 0)){
                    dano=dano+1;
                    agredido->setprimerAtaque(true);
                }
                if(!atacante->getautodestruccion()){
                    atacante->setautodestruccion(true);
                    atacante->setVida(0);
                    cout<<"se autodestruyo"<<atacante->getNombre()<<"\n";
                }
                  vida= agredido->getVida() + dano;
                  agredido->setVida(vida);

              }

            } else {
            danoDelAtacante = atacante->getDanoAereo();
                if(agredido->getTamanio()=="Pequeno") {
                    if (atacante->gettipoDanoAereo() == "Normal") {
                        multiplicador = 1;
                    }else if (atacante->gettipoDanoAereo() == "Explosivo") {
                    multiplicador = 0.5;
                }else if (atacante->gettipoDanoAereo() == "Contusivo") {
                    multiplicador = 1;
                }
            }
            if(agredido->getTamanio()=="Mediano") {
                if (atacante->gettipoDanoAereo() == "Normal") {
                    multiplicador = 1;
                }else if (atacante->gettipoDanoAereo() == "Explosivo") {
                    multiplicador = 0.75;
                }else if (atacante->gettipoDanoAereo() == "Contusivo") {
                    multiplicador = 0.5;
                }
            }
            if(agredido->getTamanio()=="Grande") {
                if (atacante->gettipoDanoAereo() == "Normal") {
                    multiplicador = 1;
                }else if (atacante->gettipoDanoAereo() == "Explosivo") {
                    multiplicador = 1;
                }else if (atacante->gettipoDanoAereo() == "Contusivo") {
                    multiplicador = 0.25;
                }
            }
            if(agredido->getEscudo()!=0 ){
                dano=agredido->getEscudo() -danoDelAtacante;
                if(dano>=0){
                    agredido->setEscudo(dano);
                }
                else{
                    dano=agredido->getBlindaje() + dano*multiplicador;
                    if (dano>=0){
                        dano=0;
                    }
                    if(!atacante->getautodestruccion()){
                        atacante->setautodestruccion(true);
                        atacante->setVida(0);
                        cout<<"se autodestruyo"<<atacante->getNombre()<<"\n";
                    }
                    vida = agredido->getVida() + dano;
                    agredido->setVida(vida);
                }
            }
            else {
                dano = agredido->getBlindaje() - danoDelAtacante * multiplicador;
                if (dano >= 0) {
                    dano = 0;
                }
                if(!agredido->getprimerAtaque() && (agredido->getVida() + dano != 0)){
                    dano=dano+1;
                    agredido->setprimerAtaque(true);
                }
                if(!atacante->getautodestruccion()){
                    atacante->setautodestruccion(true);
                    atacante->setVida(0);
                    cout<<"se autodestruyo"<<atacante->getNombre()<<"\n";
                }
                vida= agredido->getVida() + dano;
                agredido->setVida(vida);
            }

        }


        // Verificar si la vida del guerrero atacado es menor o igual a cero
        if ((agredido->getVida() <= 0 ||atacante->getVida()<= 0)||(agredido->getVida() <= 0 &&atacante->getVida()<= 0) ){
            // Eliminar el guerrero del vector BaseAtacada
            BaseAtacada.erase(BaseAtacada.begin() + quienRecibe);
        }

        // Imprimir el nuevo valor de vida del guerrero atacado
        cout << "\nMuestreo de dano: " << endl;
        imprimirUnidades(BaseAtacada, "Guerreros", jugador.getEleccionDeRaza());

    } else {
        cout << "Los numeros de guerreros ingresados no son validos." << endl;
    }
}
void CDano::InflingirDano(int GuerreroAtacante, vector<CUnidad*>& BaseAtacante, int GuerreroAtacado, vector<CUnidad*>& BaseAtacada,Menu& jugador){
    if (Seleccion == ModoAtque::BattallaPorUnidad) {
        enfrentamiento( GuerreroAtacante, BaseAtacante , GuerreroAtacado, BaseAtacada ,jugador);

    }
    else if (Seleccion == ModoAtque::BattallaBrutal) {
        for (const CUnidad* unidad : BaseAtacante) {

        }
    }
}
