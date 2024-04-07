#include <iostream>
#include <list>
#include <string>

using namespace std;

class Inventario {
private:
    list<string> productosDisponibles;
    list<string> productosAgotados;
    list<string> facturasClientes;

public:
    // Métodos para agregar productos al inventario
    void agregarProducto(string producto) {
        if (productoDisponible(producto)) {
            productosDisponibles.push_back(producto);
        } else {
            productosAgotados.push_back(producto);
        }
    }

    // Métodos para actualizar las listas de productos disponibles y agotados
    bool productoDisponible(string producto) {
        for (auto i = productosDisponibles.begin(); i!= productosDisponibles.end(); i++) {
            if (*i == producto) {
                return true;
            }
        }
        return false;
    }

    void actualizarProductos() {
        for (auto i = productosAgotados.begin(); i!= productosAgotados.end(); i++) {
            if (productoDisponible(*i)) {
                productosAgotados.erase(i);
            }
        }
    }

    // Métodos para realizar pedidos y actualizar la lista de facturas de clientes
    void realizarPedido(string producto, string cliente) {
        if (productoDisponible(producto)) {
            facturasClientes.push_back(cliente + " - " + producto);
            productosDisponibles.remove(producto);
            productosAgotados.push_back(producto);
        } else {
            cout << "El producto " << producto << " no está disponible." << endl;
        }
    }

    void mostrarFacturas() {
        for (auto i = facturasClientes.begin(); i!= facturasClientes.end(); i++) {
            cout << *i << endl;
        }
    }
};

int main() {
    Inventario inventario;

    // Agregar productos al inventario
    inventario.agregarProducto("Producto 1");
    inventario.agregarProducto("Producto 2");
    inventario.agregarProducto("Producto 3");

    // Realizar pedidos
    inventario.realizarPedido("Producto 1", "Cliente 1");
    inventario.realizarPedido("Producto 2", "Cliente 2");
    inventario.realizarPedido("Producto 4", "Cliente 3");

    // Mostrar facturas
    inventario.mostrarFacturas();

    return 0;
}
