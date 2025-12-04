//
// Created by capit on 12/2/2025.
//

#ifndef TIENDA_TIENDA_H
#define TIENDA_TIENDA_H
#include "CarritoCompra.h"
#include "Autoparte.h"
#include <vector>
#include <string>




class Tienda {
private:

    std::vector<Autoparte> catalogo;
    CarritoCompra carrito;

public:

    void cargarCatalogo();
    void listarAutopartes();
    void agregarAlCarrito(const int& codigo);
    void mostrarCarrito();
    void finalizarCompra();
    void menu();

};


#endif //TIENDA_TIENDA_H
