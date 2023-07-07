#include "BaseDeDatos.h"
#include <utility>


CZerg::CZerg(std::string _nombre, float _vida, float _blindaje, float _danoTerrestre, std::string _tipoDanoTerrestre,
             float _danoAereo, std::string _tipoDanoAereo, std::string _tamanio, std::string _tipo,bool _autodestruccion, bool _primerataque)
        : nombre(std::move(_nombre)), vida(_vida), blindaje(_blindaje), danoTerrestre(_danoTerrestre),tipoDanoTerrestre(std::move(_tipoDanoTerrestre)), danoAereo(_danoAereo),
                  tipoDanoAereo(std::move(_tipoDanoAereo)),tamanio(std::move(_tamanio)),tipo(std::move(_tipo)),autodestruccion(_autodestruccion),primerAtaque(_primerataque)  {}

    std::string CZerg::getNombre() const {
        return nombre;
    }
void CZerg::setEscudo(float escudo) {
    Escudo = escudo;
}
std::string CZerg::gettipoDanoTerrestre() const {
    return tipoDanoTerrestre;
}
std::string CZerg::gettipoDanoAereo() const {
    return tipoDanoAereo;
}
float CZerg::getVida() const  {
        return vida;
    }

void CZerg::setVida(float nuevaVida)  {
        vida = nuevaVida;
    }
float CZerg::getBlindaje() const {
    return blindaje;
}

float CZerg::getDanoTerrestre() const {
    return danoTerrestre;
}
float CZerg::getEscudo() const {
    return 0;
}

float CZerg::getDanoAereo() const {
    return danoAereo;
}

std::string CZerg::getTamanio() const {
    return tamanio;
}

std::string CZerg::getTipo() const {
    return tipo;
}
bool CZerg::getautodestruccion() const {
    return autodestruccion;
}
bool CZerg::getprimerAtaque() const {
    return primerAtaque;
}

void CZerg::setautodestruccion(bool destruccion)  {
    autodestruccion=destruccion;
}

void CZerg::setprimerAtaque(bool primer)  {
    primerAtaque=primer;
}


CProtos::CProtos(std::string _nombre, float _vida, float _blindaje, float _danoTerrestre, std::string _tipoDanoTerrestre,
                 float _danoAereo, std::string _tipoDanoAereo, std::string _tamanio, std::string _tipo,float Escudo)
        :nombre(std::move(_nombre)), vida(_vida), blindaje(_blindaje), danoTerrestre(_danoTerrestre),tipoDanoTerrestre(std::move(_tipoDanoTerrestre)), danoAereo(_danoAereo),
                  tipoDanoAereo(std::move(_tipoDanoAereo)),tamanio(std::move(_tamanio)),tipo(std::move(_tipo)),Escudo(Escudo) {}

    std::string CProtos::getNombre() const  {
        return nombre;
    }

float CProtos::getVida() const  {
        return vida;
    }
bool CProtos::getautodestruccion() const {
    return true;
}
std::string CProtos::gettipoDanoTerrestre() const {
    return tipoDanoTerrestre;
}
std::string CProtos::gettipoDanoAereo() const {
    return tipoDanoAereo;
}
    void CProtos::setVida(float nuevaVida)  {
        vida = nuevaVida;
    }
float CProtos::getBlindaje() const {
    return blindaje;
}

float CProtos::getDanoTerrestre() const {
    return danoTerrestre;
}

float CProtos::getDanoAereo() const {
    return danoAereo;
}

std::string CProtos::getTamanio() const {
    return tamanio;
}

std::string CProtos::getTipo() const {
    return tipo;
}
float CProtos::getEscudo() const {
    return Escudo;
}

void CProtos::setEscudo(float escudo) {
    Escudo = escudo;
}
bool CProtos::getprimerAtaque() const {
    return true;
}

void CProtos::setautodestruccion(bool destruccion)  {
    autodestruccion=destruccion;

}

void CProtos::setprimerAtaque(bool primer)  {
    primerAtaque=primer;

}


CTerran::CTerran(std::string _nombre, float _vida, float _blindaje, float _danoTerrestre, std::string _tipoDanoTerrestre,
                 float _danoAereo, std::string _tipoDanoAereo, std::string _tamanio, std::string _tipo)
        :nombre(std::move(_nombre)), vida(_vida), blindaje(_blindaje), danoTerrestre(_danoTerrestre),tipoDanoTerrestre(std::move(_tipoDanoTerrestre)), danoAereo(_danoAereo),
         tipoDanoAereo(std::move(_tipoDanoAereo)),tamanio(std::move(_tamanio)),tipo(std::move(_tipo))  {}
    std::string CTerran::getNombre() const  {
        return nombre;
    }

float CTerran::getVida() const  {
        return vida;
    }
void CTerran::setEscudo(float escudo) {
    Escudo = escudo;
}
float CTerran::getEscudo() const {
    return 0;
}
bool CTerran::getautodestruccion() const {
    return true;
}
std::string CTerran::gettipoDanoTerrestre() const {
    return tipoDanoTerrestre;
}
std::string CTerran::gettipoDanoAereo() const {
    return tipoDanoAereo;
}
    void CTerran::setVida(float nuevaVida)  {
        vida = nuevaVida;
    }
float CTerran::getBlindaje() const {
    return blindaje;
}

float CTerran::getDanoTerrestre() const {
    return danoTerrestre;
}

float CTerran::getDanoAereo() const {
    return danoAereo;
}

std::string CTerran::getTamanio() const {
    return tamanio;
}

std::string CTerran::getTipo() const {
    return tipo;
}

bool CTerran::getprimerAtaque() const {
    return true;
}

void CTerran::setautodestruccion(bool destruccion)  {
    autodestruccion=destruccion;
}

void CTerran::setprimerAtaque(bool primer)  {
    primerAtaque=primer;


}


std::vector<CUnidad*> BaseProtos = {
        new CProtos ("Arbiter", 200, 1, 10, "Explosivo", 10, "Explosivo", "Grande", "Aereo", 150),
        new CProtos ("Archon", 10, 0, 30, "Normal", 30,"Normal", "Grande", "Terrestre", 350),
        new CProtos("Carrier", 300, 4, 48, "Normal", 48, "Normal", "Grande", "Aereo", 150),
        new CProtos("Corsair", 100, 1, 0, "Normal", 6, "Explosivo", "Mediano", "Aereo", 80),
        new CProtos("Templar", 80, 1, 40, "Normal", 0, "Normal", "Pequeno", "Terrestre", 40),
        new CProtos("Dragoon", 100, 1, 20, "Explosivo", 20,"Explosivo", "Grande", "Terrestre", 80),
        new CProtos("Probe", 20, 0, 5, "Normal", 0, "Normal", "Pequeno", "Terrestre", 20),
        new CProtos("Reaver", 100, 0, 125, "Normal", 0, "Normal", "Grande", "Terrestre", 80),
        new CProtos("Scout", 150, 0, 8, "Normal", 28, "Explosivo","Grande", "Aereo", 100),
        new CProtos("Zelaot", 100, 1, 16, "Normal", 0, "Normal", "Pequeno", "Terrestre", 60)
};
std::vector<CUnidad*> BaseTerran = {
        new CTerran("Batlecuirser", 500, 3, 25, "Normal", 25, "Normal", "Grande", "Aereo"),
        new CTerran("Firebat", 50, 1, 16, "Contusivo", 0, "Normal", "Pequeno", "Terrestre"),
        new CTerran("Ghost", 45, 0, 10, "Contusivo", 10, "Contusivo", "Pequeno", "Terrestre"),
        new CTerran("Goliath", 125, 1, 12, "Normal", 20, "Explosivo", "Grande", "Aereo"),
        new CTerran("Marine", 40, 0, 6, "Normal", 6, "Normal", "Pequeno", "Terrestre"),
        new CTerran("Duran", 200, 2, 25, "Contusivo", 25, "Contusivo", "Pequeno", "Terrestre"),
        new CTerran("Scv", 60, 0, 5, "Normal", 0, "Normal", "Pequeno","Terrestre"),
        new CTerran("Tank", 150, 1, 70, "Explosivo", 0, "Normal", "Grande", "Terrestre"),
        new CTerran("Valkyrie", 200, 2, 0, "Normal", 48 , "Explosivo", "Grande", "Aereo"),
        new CTerran("Vulture", 80, 0, 20, "Contusivo", 0, "Normal", "Mediano", "Terrestre"),
        new CTerran("Wraith", 120, 0, 8, "Normal", 20, "Explosivo", "Grande", "Aereo")
};
std::vector< CUnidad*> BaseZerg ={
        new CZerg("Broodling", 30, 0, 4, "Normal", 0, "Normal", "Pequeno", "Terrestre", false,false),
        new CZerg("Devourer", 250, 2, 0, "Normal", 25, "Explosivo", "Grande", "Aereo", false,false),
        new CZerg("Drone", 40, 0, 5, "Normal", 0, "Normal", "Pequeno", "Terrestre", false,false),
        new CZerg("Hydralisk", 80, 0, 10, "Explosivo", 10, "Explosivo", "Mediano", "Aereo", false,false),
        new CZerg("Infested", 60, 0, 500, "Explosivo", 0, "Normal", "Pequeno", "Terrestre", false,false),
        new CZerg("Lurker", 125, 1, 20, "Normal", 0, "Normal", "Mediano", "Terrestre", false,false),
        new CZerg("Mutalisk", 120, 0, 9, "Normal", 9, "Normal", "Pequeno", "Aereo", false,false),
        new CZerg("Scourge", 25, 0, 0, "Normal", 110, "Normal", "Pequeno", "Aereo", false,false),
        new CZerg("Ultralisk", 400, 3, 20, "Normal", 0, "Normal", "Grande", "Terrestre", false,false),
        new CZerg("Zergling", 35, 0, 5, "Normal", 0, "Normal", "Pequeno", "Terrestre", false,false)
};
void imprimirUnidades(const std::vector<CUnidad*>& unidades, const string& modoDeImpresion,int raza) {//guerreo
    int NumeroDeOrden=1;
    if (raza!=1&&modoDeImpresion=="Guerreros"){
        cout << left << setw(15) << "num de orden" <<setw(15) << "Nombre" << setw(10) << "Vida" << setw(10) << "Blindaje" << setw(18) << "Dano Terrestre" << setw(15) << "Dano Aereo" << setw(10) << "Tamano" << setw(10) << "Tipo" << endl;
    }
    if(raza==1&&modoDeImpresion=="Guerreros"){
        cout << left << setw(15) << "num de orden" <<setw(15) << "Nombre" << setw(10) << "Vida" << setw(10) << "Escudo" << setw(10) << "Blindaje" << setw(18) << "Dano Terrestre" << setw(15) << "Dano Aereo" << setw(10) << "Tamano" << setw(10) << "Tipo" << endl;
    }
    if(raza!=1&&modoDeImpresion=="Base"){
        cout<<left<<setw(15)<<"Nombre"<<setw(10)<<"Vida"<<setw(10)<<"Blindaje"<<setw(18)<<"Dano Terrestre"<<setw(15)<<"Dano Aereo"<<setw(10)<<"Tamano"<<setw(10)<<"Tipo"<<endl;
    }
    if(raza==1&&modoDeImpresion=="Base"){
        cout << left <<setw(15) << "Nombre" << setw(10) << "Vida" << setw(10) << "Escudo" << setw(10) << "Blindaje" << setw(18) << "Dano Terrestre" << setw(15) << "Dano Aereo" << setw(10) << "Tamano" << setw(10) << "Tipo" << endl;
    }
    for (const auto& unidad : unidades) {
        if (unidad != nullptr) {
            auto* zerg = dynamic_cast<CZerg*>(unidad);

            if (zerg != nullptr) {
                if(modoDeImpresion=="Guerreros"){
                    cout<<"       "<<NumeroDeOrden<<"       ";
                }
                cout << left << setw(15) << zerg ->getNombre()
                     << setw(10) << zerg ->getVida()
                     << setw(10) << zerg ->getBlindaje()
                     << setw(18) << zerg->getDanoTerrestre()
                     << setw(15) << zerg->getDanoAereo()
                     << setw(10) << zerg->getTamanio()
                     << setw(10) << zerg->getTipo() << endl;
                // Imprimir los demás atributos de CZerg
            } else {
                auto* protos = dynamic_cast<CProtos*>(unidad);
                if (protos != nullptr) {
                    if(modoDeImpresion=="Guerreros"){
                        cout<<"       "<<NumeroDeOrden<<"       ";
                    }
                    cout << left << setw(15) << protos ->getNombre()
                         << setw(10) << protos ->getVida()
                         << setw(10) << protos ->getEscudo()
                         << setw(10) << protos ->getBlindaje()
                         << setw(18) << protos->getDanoTerrestre()
                         << setw(15) << protos->getDanoAereo()
                         << setw(10) << protos->getTamanio()
                         << setw(10) << protos->getTipo() << endl;
                    // Imprimir los demás atributos de CProtos
                } else {
                    auto* terran = dynamic_cast<CTerran*>(unidad);
                    if (terran != nullptr) {
                        if(modoDeImpresion=="Guerreros"){
                            cout<<"       "<<NumeroDeOrden<<"       ";
                        }
                        cout << left << setw(15) << terran ->getNombre()
                             << setw(10) << terran ->getVida()
                             << setw(10) << terran ->getBlindaje()
                             << setw(18) << terran->getDanoTerrestre()
                             << setw(15) << terran->getDanoAereo()
                             << setw(10) << terran->getTamanio()
                             << setw(10) << terran->getTipo() << endl;
                        // Imprimir los demás atributos de CTerran
                    }
                }
            }

        }
        NumeroDeOrden++;
    }

        std::cout << "\n";

}
void anadirguerreros(vector<CUnidad*>& BaseDeDatos, int cantidadDeGuerreros, vector<CUnidad*>& BaseJugador, int modoJuego) {
    for (int i = 0; i < cantidadDeGuerreros; ) {
        string var;
        cout << "Ingrese el nombre del heroe que desea: ";
        cin >> var;

        auto iterador = find_if(BaseDeDatos.begin(), BaseDeDatos.end(), [&var](CUnidad* unidad) {
            return unidad->getNombre() == var;
        });

        if (iterador != BaseDeDatos.end()) {
            if (modoJuego == 2 || (modoJuego == 1 && !existeGuerreroEnBaseJugador(BaseJugador, *iterador))) {
                BaseJugador.push_back(*iterador);
                i++;
            } else {
                cout << "Ya se ha seleccionado ese héroe. Ingrese nuevamente." << endl;
            }
        } else {
            cout << "No se encontró el héroe. Ingrese nuevamente." << endl;
        }
    }
}

bool existeGuerreroEnBaseJugador(const vector<CUnidad*>& BaseJugador, CUnidad* guerrero) {
    for(const auto& unidad : BaseJugador) {
        if (unidad->getNombre() == guerrero->getNombre()) {
            return true;
        }
    }
    return false;
}




CUnidad::~CUnidad() {
}
