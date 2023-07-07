#include "BaseDeDatos.h"
#include "Enfrentamiento.h"
#include "Menu.h"
enum class Estado {
    MenuPrincipal,
    Partida,
    GameOver
};
void Comienzo_aleatorio(Menu& jugador1,Menu& jugador2,random_device& rd){
    int item;
    item= rd()%2;
    if(item==0){
        jugador1.jugar();
    }
    else{
        jugador2.jugar();
    }
}
void SiguienteEnJugar(Menu& jugador1,Menu& jugador2, string& EstadoDeJuego ,int& num){
    if(EstadoDeJuego!="Partida terminada") {
        if (jugador1.getJugando() == 1) {
            jugador1.descansa();
            jugador2.jugar();
        } else {
            jugador2.descansa();
            jugador1.jugar();
        }
        std::cout << "                ======================== Batalla "<<num<<"======================== " << std::endl;
    }


}
void JuegoTerminado(vector<CUnidad*>& guerreros1, vector<CUnidad*>& guerreros2,string& estadodejuego) {
    bool hayGuerreros1 = (!guerreros1.empty());
    bool hayGuerreros2 = (!guerreros2.empty());

    if (!hayGuerreros1 && !hayGuerreros2) {
        cout << "Empate Ambos jugadores se quedaron sin guerreros." << endl;
        estadodejuego="Partida terminada";
    } else if (!hayGuerreros1) {
        cout << "Jugador 2 ha ganado Jugador 1 se quedo sin guerreros." << endl;
        estadodejuego="Partida terminada";
    }
    if(!hayGuerreros2){
        cout << "Jugador 1 ha ganado Jugador 2 se quedo sin guerreros." << endl;
        estadodejuego="Partida terminada";
    }
}


// Clase para representar el juego
class Juego {
private:
    Estado estadoActual;
public:
    Juego() : estadoActual(Estado::MenuPrincipal) {}

    void iniciar(Menu& jugador1,Menu& jugador2,vector<CUnidad*>& guerreros1,vector<CUnidad*>& guerreros2,random_device& rd) {
        string EstadoDeJuego="partida en juego";
        int num=1;
        int modoDeJuego;
        while (estadoActual != Estado::GameOver && EstadoDeJuego=="partida en juego") {
            if (estadoActual == Estado::MenuPrincipal) {
                mostrarMenu(jugador1,jugador2,guerreros1,guerreros2,modoDeJuego);
                estadoActual=Estado::Partida;
                std::cout << "                ======================== Batalla "<<num<<"======================== " << std::endl;

                Comienzo_aleatorio(jugador1,jugador2,rd);
            }
            else if (estadoActual == Estado::Partida) {
                procesarEntradaPartida(modoDeJuego,jugador1,jugador2,guerreros1,guerreros2);
                jugarPartida();
                JuegoTerminado(guerreros1,  guerreros2, EstadoDeJuego);
                num++;
                SiguienteEnJugar( jugador1, jugador2,EstadoDeJuego,num);



            }
        }
    }

    static void mostrarMenu(Menu& jugador1,Menu& jugador2,vector<CUnidad*>& guerreros1,vector<CUnidad*>& guerreros2, int& modoDeJuego) {
        int turno=1;
        cout<<"-----Bienvenidos al juego de StarCraft: Brood War-------\n";
        cout<<"ingrese la modalidad de modelo de juego:\n";
        cout<<"1. batalla por unidad\n";
        cout<<"2. Batalla brutal\n";
        cout<<"Selecione un numero: ";
        cin>>modoDeJuego;
        jugador1.nombreJuegador();
        jugador1.EligirRaza(guerreros1,modoDeJuego,turno,jugador2);

        jugador2.nombreJuegador();
        jugador2.EligirRaza(guerreros2,modoDeJuego,turno,jugador1);
    }

    void jugarPartida() {

    }

    static void procesarEntradaPartida(int formaDeAtacar,Menu& jugador1,Menu& jugador2,vector<CUnidad*>& guerreros1,vector<CUnidad*>& guerreros2) {
        int guerreroAtacante=0;
        int guerreroAtacado=0;
        if(formaDeAtacar==1){
            if(jugador1.getJugando()==1){
                cout<<"\nGuerreros disponibles:\n";
                imprimirUnidades(guerreros1,"Guerreros",jugador1.getEleccionDeRaza());
                cout<<"Ingrese el numero de orden del guerrero que va a atacar: ";
                cin>>guerreroAtacante;
                cout<<"\nquien sera su contrincante en esta batalla\n";
                imprimirUnidades(guerreros2,"Guerreros",jugador2.getEleccionDeRaza());
                cout<<"Ingrese el numero de orden del guerrero a atacar: ";
                cin>>guerreroAtacado;
                enfrentamiento( guerreroAtacante, guerreros1 , guerreroAtacado, guerreros2,jugador1);
            }
            else{
                cout<<"\nGuerreros disponibles:\n";
                imprimirUnidades(guerreros2,"Guerreros",jugador2.getEleccionDeRaza());
                cout<<"Ingrese el numero de orden del guerrero que va a atacar: ";
                cin>>guerreroAtacante;
                cout<<"quien sera su contrincante en esta batalla\n";
                imprimirUnidades(guerreros1,"Guerreros",jugador1.getEleccionDeRaza());
                cout<<"Ingrese el numero de orden del guerrero a atacar: ";
                cin>>guerreroAtacado;
                enfrentamiento( guerreroAtacante, guerreros2 , guerreroAtacado, guerreros1 ,jugador2);
            }
        }
        if (formaDeAtacar==2){
            int n=1;
            if(jugador1.getJugando()==1){
                ataqueEnGrupo( guerreros1 , guerreros2,jugador1,n);
            }
            else{
                ataqueEnGrupo( guerreros2 , guerreros1,jugador1,n);
                }

        }
    }

    void setEstadoActual(Estado _estadoActual) {
        estadoActual = _estadoActual;
    }

};





// Función principal
int main() {
    random_device rd;
    Juego juego;
    vector<CUnidad*> guerreros1;
    vector<CUnidad*> guerreros2;
    Menu jugador1(1);
    Menu jugador2(2);
    juego.iniciar(jugador1,jugador2,guerreros1,guerreros2,rd);


    return 0;
}