//
// Created by medin on 02/12/2025.
//

#include "CarritoCompra.h"
#include "Autoparte.h"
#include <iostream>
#include <ostream>
#include <vector>

CarritoCompra::CarritoCompra() {
    this->productos;
}
CarritoCompra::CarritoCompra(vector<Autoparte> &cProductos) {
    this->productos = cProductos;
}
void CarritoCompra::agregarAutoparte(const Autoparte& p) {
    Autoparte nueva(const string& cNombre, int &cCodigo, double &cPrecio);
    productos.push_back(p);
}

double CarritoCompra::calculaTotal() {
    double total = 0.0;
    for (const auto& p : productos) {
        total += p.getPrecio();
    }
    return total;
}

void CarritoCompra::mostrarCarrito() {
    cout << "Productos: " << endl;
    for (const auto& p : productos) {
        cout << p.getNombre() << endl;
    }
    cout << "Codigo: " << endl;
    for (const auto& p : productos) {
        cout << p.getCodigo() << endl;
    }
    cout << "Precio: " << endl;
    for (const auto& p : productos) {
        cout << p.getPrecio() << endl;
    }
}

