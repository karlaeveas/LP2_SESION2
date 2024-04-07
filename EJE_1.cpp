#include <iostream>
#include <string>
using namespace std;
class Auto {
private:
  double velocidad;
  double aceleracion;
public:
  Auto(double velocidad, double aceleracion) {
    this->velocidad = velocidad;
    this->aceleracion = aceleracion;
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
    this->distancia_total = distancia_total;
    this->oponente = oponente;
  }
  int getDistanciaTotal() {
    return distancia_total;
  }
  int getOponente() {
    return oponente;
  }
  bool simularCarrera(Auto& jugador, Auto& oponente) {
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
int main() {
  Auto auto1(10, 2);
  Auto auto2(15, 3);
  Carrera carrera(100, 2);
  if (carrera.simularCarrera(auto1, auto2)) {
    cout << "El jugador 1 gana la carrera!" << endl;
  } else {
    cout << "El jugador 2 gana la carrera!" << endl;
  }
  return 0;
}
