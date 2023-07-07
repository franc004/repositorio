#include "Enfrentamiento.h"

//para que a futuro se le puede meter mas modos de batalla
void enfrentamiento(int GuerreroAtacante, vector<CUnidad*>& BaseAtacante, int GuerreroAtacado, vector<CUnidad*>& BaseAtacada, Menu& jugador) {
    // Restar 1 al número ingresado para obtener el índice del vector
    int quienGolpea = GuerreroAtacante - 1;
    int quienRecibe = GuerreroAtacado - 1;

    // Verificar si los índices están dentro del rango válido
    if (quienGolpea >= 0 && quienGolpea < BaseAtacante.size() && quienRecibe >= 0 && quienRecibe < BaseAtacada.size()) {
        // Acceder a los guerreros atacante y atacado
        CUnidad* atacante = BaseAtacante[quienGolpea];
        CUnidad* agredido = BaseAtacada[quienRecibe];

        // Realizar el cálculo de daño basado en los atributos correspondientes
        float danoDelAtacante, multiplicador, vida;

        if (agredido->getTipo() == "Terrestre") {
            danoDelAtacante = atacante->getDanoTerrestre();
            multiplicador = calcularMultiplicador(agredido->getTamanio(), atacante->gettipoDanoTerrestre());
        } else {
            danoDelAtacante = atacante->getDanoAereo();
            multiplicador = calcularMultiplicador(agredido->getTamanio(), atacante->gettipoDanoAereo());
        }

        // Calcular el daño al guerrero agredido
        float dano = calcularDaño(agredido, danoDelAtacante, multiplicador);

        // Aplicar el daño al guerrero agredido
        agredido->setVida(agredido->getVida() - dano);

        // Verificar si la vida del guerrero agredido es menor o igual a cero
        if (agredido->getVida() <= 0) {
            // Eliminar el guerrero del vector BaseAtacada
            BaseAtacada.erase(BaseAtacada.begin() + quienRecibe);
        }

        // Verificar si la vida del guerrero atacante es menor o igual a cero
        if (atacante->getVida() <= 0) {
            // Eliminar el guerrero del vector BaseAtacante
            BaseAtacante.erase(BaseAtacante.begin() + quienGolpea);
        }

        // Imprimir el nuevo valor de vida del guerrero agredido
        cout << "\nMuestreo de daño: " << endl;
        imprimirUnidades(BaseAtacada, "Guerreros", jugador.getEleccionDeRaza());

    } else {
        cout << "Los números de guerreros ingresados no son válidos." << endl;
    }
}
float calcularMultiplicador(const string& tamanio, const string& tipoAtaque) {
    if (tamanio == "Pequeno") {
        if (tipoAtaque == "Normal") {
            return 1.0;
        } else if (tipoAtaque == "Explosivo") {
            return 0.5;
        } else if (tipoAtaque == "Contusivo") {
            return 1.0;
        }
    } else if (tamanio == "Mediano") {
        if (tipoAtaque == "Normal") {
            return 1.0;
        } else if (tipoAtaque == "Explosivo") {
            return 0.75;
        } else if (tipoAtaque == "Contusivo") {
            return 0.5;
        }
    } else if (tamanio == "Grande") {
        if (tipoAtaque == "Normal") {
            return 1.0;
        } else if (tipoAtaque == "Explosivo") {
            return 1.0;
        } else if (tipoAtaque == "Contusivo") {
            return 0.25;
        }
    }

    return 1.0; // Valor predeterminado si no se cumple ninguna condición
}

float calcularDaño(CUnidad* agredido, float danoDelAtacante, float multiplicador) {
    float dano;

    if (agredido->getEscudo() != 0) {
        dano = agredido->getEscudo() - danoDelAtacante;
        if (dano >= 0) {
            agredido->setEscudo(dano);
        } else {
            dano = agredido->getBlindaje() + dano * multiplicador;
            if (dano >= 0) {
                dano = 0;
            }
            if (!agredido->getautodestruccion()) {
                agredido->setautodestruccion(true);
                agredido->setVida(0);
                cout << "Se autodestruyó " << agredido->getNombre() << "\n";
            }
            dano += agredido->getVida();
            agredido->setVida(dano);
        }
    } else {
        dano = agredido->getBlindaje() - danoDelAtacante * multiplicador;
        if (dano >= 0) {
            dano = 0;
        }
        if (!agredido->getprimerAtaque() && (agredido->getVida() + dano != 0)) {
            dano += 1;
            agredido->setprimerAtaque(true);
        }
        if (!agredido->getautodestruccion()) {
            agredido->setautodestruccion(true);
            agredido->setVida(0);
            cout << "Se autodestruyó " << agredido->getNombre() << "\n";
        }
        dano += agredido->getVida();
        agredido->setVida(dano);
    }

    return dano;
}
void ataqueEnGrupo(vector<CUnidad*>& BaseAtacante, vector<CUnidad*>& BaseAtacada, Menu& jugador, int& n) {
    cout << "Ataque en grupo:" <<"(batalla brutal numero"<<n<<")"<< endl;

    // Iterar sobre todos los guerreros de BaseAtacante
    for (int i = 0; i < BaseAtacante.size(); i++) {
        // Iterar sobre todos los guerreros de BaseAtacada
        for (int j = 0; j < BaseAtacada.size(); j++) {
            // Realizar el enfrentamiento entre el guerrero atacante y el guerrero agredido
            enfrentamiento(i + 1, BaseAtacante, j + 1, BaseAtacada, jugador);
        }
    }

    // Verificar si la BaseAtacada resistió la batalla
    if (!BaseAtacada.empty()) {
        cout << "La BaseAtacada resistió la batalla brutal." << endl;
        cout << "\nMuestreo de daño: " << endl;
        imprimirUnidades(BaseAtacada, "Guerreros", jugador.getEleccionDeRaza());
    }
    else{
        cout << "La BaseAtacada no resistió la batalla brutal." << endl;
    }
    n++;
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
