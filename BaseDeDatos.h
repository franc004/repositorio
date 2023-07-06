#ifndef PROYECTO_BASEDEDATOS_H
#define PROYECTO_BASEDEDATOS_H
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <random>
#include <algorithm>
using namespace std;
class CUnidad {
public:
    virtual ~CUnidad();
    [[nodiscard]] virtual std::string getNombre() const = 0;
    [[nodiscard]] virtual float getVida() const = 0;
    virtual void setVida(float ) = 0;
    [[nodiscard]] virtual float getBlindaje() const = 0;
    [[nodiscard]] virtual float getDanoTerrestre() const = 0;
    [[nodiscard]] virtual float getDanoAereo() const = 0;
    [[nodiscard]] virtual bool getautodestruccion() const = 0;
    [[nodiscard]] virtual void setautodestruccion(bool) = 0;
    [[nodiscard]] virtual std::string getTamanio() const = 0;
    [[nodiscard]] virtual bool getprimerAtaque() const =0;
    [[nodiscard]] virtual void setprimerAtaque(bool)  =0;
    [[nodiscard]] virtual std::string getTipo() const = 0;
    [[nodiscard]] virtual std::string gettipoDanoTerrestre() const = 0;
    [[nodiscard]] virtual std::string gettipoDanoAereo() const = 0;
    [[nodiscard]] virtual float getEscudo() const = 0;
    virtual void setEscudo(float ) = 0;
};

class CZerg : public CUnidad {
private:
    std::string nombre;
    float vida;
    float blindaje;
    float danoTerrestre;
    std::string tipoDanoTerrestre;
    float danoAereo;
    std::string tipoDanoAereo;
    std::string tamanio;
    std::string tipo;
    float Escudo;
    bool autodestruccion;
    bool primerAtaque;

public:
    CZerg(std::string , float , float , float , std::string ,
          float , std::string , std::string , std::string ,bool,bool );

    [[nodiscard]] void setautodestruccion(bool)  override;
    [[nodiscard]] std::string getNombre() const override;
    [[nodiscard]] std::string gettipoDanoTerrestre() const override;
    [[nodiscard]] std::string gettipoDanoAereo() const override;
    [[nodiscard]] float getVida() const override;
    [[nodiscard]] bool getautodestruccion() const override;
    [[nodiscard]] bool getprimerAtaque() const override;
    [[nodiscard]] void setprimerAtaque(bool primero)  override;
    void setEscudo(float escudo) override;
    [[nodiscard]] float getEscudo() const override ;
    void setVida(float ) override;
    [[nodiscard]] float getBlindaje() const override;
    [[nodiscard]] float getDanoTerrestre() const override;
    [[nodiscard]] float getDanoAereo() const override;
    [[nodiscard]] std::string getTamanio() const override;
    [[nodiscard]] std::string getTipo() const override;
};

class CProtos : public CUnidad {
private:
    std::string nombre;
    float vida;
    float blindaje;
    float danoTerrestre;
    std::string tipoDanoTerrestre;
    float danoAereo;
    std::string tipoDanoAereo;
    std::string tamanio;
    std::string tipo;
    float Escudo;
    bool autodestruccion;
    bool primerAtaque;
    // Resto de atributos de CProtos

public:
    CProtos(std::string , float , float , float , std::string ,
            float , std::string , std::string , std::string ,float );

    [[nodiscard]] std::string getNombre() const override; //
    [[nodiscard]] void setautodestruccion(bool)  override;
    [[nodiscard]] float getEscudo() const override ;
    [[nodiscard]] bool getautodestruccion() const override;
    [[nodiscard]] bool getprimerAtaque() const override;
    [[nodiscard]] void setprimerAtaque(bool)  override;
    [[nodiscard]] float getVida() const override ;          //
    [[nodiscard]] std::string gettipoDanoTerrestre() const override;
    [[nodiscard]] std::string gettipoDanoAereo() const override;
    void setVida(float nuevaVida) override ;

    void setEscudo(float escudo) override;

    [[nodiscard]] float getBlindaje() const override;//
    [[nodiscard]] float getDanoTerrestre() const override;//
    [[nodiscard]] float getDanoAereo() const override;//
    [[nodiscard]] std::string getTamanio() const override;//
    [[nodiscard]] std::string getTipo() const override;//
};

class CTerran : public CUnidad {
private:
    std::string nombre;
    float vida;
    float blindaje;
    float danoTerrestre;
    std::string tipoDanoTerrestre;
    float danoAereo;
    float Escudo;
    std::string tipoDanoAereo;
    std::string tamanio;
    std::string tipo;
    bool autodestruccion;
    bool primerAtaque;


public:
    CTerran(std::string , float , float , float , std::string ,
            float , std::string , std::string , std::string );

    [[nodiscard]] std::string getNombre() const override ;
    [[nodiscard]] void setautodestruccion(bool)  override;
    void setEscudo(float escudo) override;
    [[nodiscard]] float getEscudo() const override ;
    [[nodiscard]] float getVida() const override ;
    [[nodiscard]] std::string gettipoDanoTerrestre() const override;
    [[nodiscard]] std::string gettipoDanoAereo() const override;
    [[nodiscard]] bool getautodestruccion() const override;
    [[nodiscard]] bool getprimerAtaque() const override;
    [[nodiscard]] void setprimerAtaque(bool)  override;
    void setVida(float nuevaVida) override ;
    [[nodiscard]] float getBlindaje() const override;
    [[nodiscard]] float getDanoTerrestre() const override;
    [[nodiscard]] float getDanoAereo() const override;
    [[nodiscard]] std::string getTamanio() const override;
    [[nodiscard]] std::string getTipo() const override;
};
bool existeGuerreroEnBaseJugador(const vector<CUnidad*>& BaseJugador, CUnidad* guerrero);
void imprimirUnidades(const std::vector<CUnidad*>& unidades, const string&, int raza) ;
extern std::vector<CUnidad*> BaseProtos;
extern std::vector<CUnidad*> BaseTerran;
extern std::vector< CUnidad*>  BaseZerg;
void anadirguerreros(std::vector<CUnidad*>& , int , std::vector<CUnidad*>& , int);


#endif //PROYECTO_BASEDEDATOS_H
