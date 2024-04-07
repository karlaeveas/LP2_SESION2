#include <iostream>
#include <string>
using namespace std;
class Misión {
private:
    string destino;
    int duracion;
    int tripulacion;
public:
    Misión(string destino, int duracion, int tripulacion) {
        this->destino = destino;
        this->duracion = duracion;
        this->tripulacion = tripulacion;
    }
    string getDestino() {
        return destino;
    }
    int getDuracion() {
        return duracion;
    }
    int getTripulacion() {
        return tripulacion;
    }
};

class Avión {
private:
    int capacidad_combustible;
    int consumo_combustible;
public:
    Avión(int capacidad_combustible, int consumo_combustible) {
        this->capacidad_combustible = capacidad_combustible;
        this->consumo_combustible = consumo_combustible;
    }
    int getCapacidadCombustible() {
        return capacidad_combustible;
    }
    int getConsumoCombustible() {
        return consumo_combustible;
    }
    bool tieneSuficienteCombustible(Misión misión) {
        int combustible_necesario = misión.getDuracion() * this->consumo_combustible;
        return this->capacidad_combustible >= combustible_necesario;
    }
};