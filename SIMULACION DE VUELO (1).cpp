#include <iostream>
#include <string>

using namespace std;

class Mision {
private:
    string destino;
    int duracion;
    int tripulacion;

public:
    Mision(string destino, int duracion, int tripulacion) {
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

class Avion {
private:
    string modelo;
    int capacidadCombustible;
    int consumoCombustible;

public:
    Avion(string modelo, int capacidadCombustible, int consumoCombustible) {
        this->modelo = modelo;
        this->capacidadCombustible = capacidadCombustible;
        this->consumoCombustible = consumoCombustible;
    }

    bool tieneSuficienteCombustible(Mision mision) {
        int combustibleNecesario = mision.getDuracion() * consumoCombustible;
        return capacidadCombustible >= combustibleNecesario;
    }
};
int main() {
    Mision mision("Destino 1", 5, 3);
    Avion avion("Modelo 1", 100, 20);

    if (avion.tieneSuficienteCombustible(mision)) {
        cout << "El avión tiene suficiente combustible para completar la misión." << endl;
    } else {
        cout << "El avión no tiene suficiente combustible para completar la misión." << endl;
    }

    return 0;
}