#include <iostream>
#include <string>

using namespace std;

class Auto {
private:
    double velocidad;
    double aceleracion;

public:
    Auto(double velocidad, double aceleracion){
        this -> velocidad = velocidad;
        this -> aceleracion = aceleracion;
    }

    double getVelocidad() {
        return velocidad;
    }

    double getAceleracion() {
        return aceleracion;
    }

    void acelerar() {
        velocidad += aceleracion;
    }
};

class Carrera {
private:
    int distancia_total;
    int oponente;

public:
    Carrera(double distancia_total, int oponente) {
        this -> distancia_total = distancia_total;
        this -> oponente = oponente;
    }

    int getDistanciaTotal() {
        return distancia_total;
    }

    int getOponente() {
        return oponente;
    }

    bool simularCarrera(Auto jugador) {
        double distanciaRecorridaJugador = 0;
        double distanciaRecorridaOponente = 0;

        while (distanciaRecorridaJugador < distancia_total && distanciaRecorridaOponente < distancia_total) {
            jugador.acelerar();
            distanciaRecorridaJugador += jugador.getVelocidad();
            oponente.acelerar();
            distanciaRecorridaOponente += oponente.getVelocidad();
        }

        return distanciaRecorridaJugador > distanciaRecorridaOponente;
    }
};