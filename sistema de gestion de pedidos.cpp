#include <iostream>
#include <list>
#include <string>
using namespace std;
class Producto {
public:
    string nombre;
    int precio;
    int cantidad;
    Producto(string nombre, int precio, int cantidad) {
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    }
};
class Inventario {
private:
    list<Producto> productos_disponibles;
    list<Producto> productos_agotados;
public:
    void agregarProducto(Producto producto) {
        if (producto.cantidad > 0) {
            productos_disponibles.push_back(producto);
        } else {
            productos_agotados.push_back(producto);
        }
    }
    void actualizarProducto(string nombre, int cantidad_nueva) {
        for (auto i = productos_disponibles.begin(); i!= productos_disponibles.end(); i++) {
            if (i->nombre == nombre) {
                i->cantidad += cantidad_nueva;
                if (i->cantidad > 0) {
                    productos_disponibles.remove(*i);
                    productos_disponibles.push_back(*i);
                } else {
                    productos_disponibles.remove(*i);
                    productos_agotados.push_back(*i);
                }
                break;
            }
        }
    }
    void realizarPedido(string nombre, int cantidad) {
        for (auto i = productos_disponibles.begin(); i!= productos_disponibles.end(); i++) {
            if (i->nombre == nombre && i->cantidad >= cantidad) {
                i->cantidad -= cantidad;
                if (i->cantidad == 0) {
                    productos_disponibles.remove(*i);
                    productos_agotados.push_back(*i);
                }
                break;
            }
        }
    }
    void actualizarFactura(string nombre_cliente, int precio_total) {
    }
};