//
// Created by capit on 12/2/2025.
//

#include "Tienda.h"
#include <fstream>
#include <iostream>

void Tienda::cargarCatalogo() {
    std::string nombre;
    int codigo;
    double precio;

    std::ifstream inputFile(catalogo.txt);

    if (inputFile) {

        std::cout << "El catalogo ha sido importado de manera exitosa!! \n";

        while(inputFile >> nombre >> codigo >> precio) {
            catalogo.emplace_back(nombre, codigo, precio);
        }

    } else {
        std::cout << "Error critico al intentar abrir el archivo de catalogo! Favor de intentar de nuevo.";
    }
}

void Tienda::listarAutopartes() {

    for (const auto& e : catalogo) {
        std::cout << e.getNombre() << "\n";
    }
}

void Tienda::agregarAlCarrito(const std::string& codigo) {
    for (const auto& e :  catalogo) {
        if (e.codigo == codigo) {
            carrito.agregarAutoparte(e);
        }
    }
}

void Tienda::finalizarCompra() {
    std::cout << "Ticket de compra: \n";

    carrito.mostrarCarrrito();
    std::cout << "El total de su compra es de: " << carrito.calcularTotal();
}
