//
// Created by medin on 02/12/2025.
//

#include "CarritoCompra.h"
#include "Autoparte.h"
#include <iostream>
#include <ostream>
#include <vector>

void CarritoCompra::agregarAutoparte(const Autoparte& p) {
    productos.push_back(p);
}

double CarritoCompra::calcularTotal() {
    double total = 0.0;
    for (const auto& p : productos) {
        total += p.getPrecio();
    }
    return total;
}

void CarritoCompra::mostrarCarrito() {

    if (productos.size() == 0) {
        std::cout << "El carrito esta vacio. \n";
    }
    else {
        for (const auto& p : productos) {
            cout << "Producto: " << p.getNombre() << "\n" << "Codigo: " << p.getCodigo() << "\n";
            cout << "Precio: " << p.getPrecio() << "\n";
        }
    }
}

void CarritoCompra::vaciarCarrito() {
    productos.clear();
}

