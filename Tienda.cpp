//
// Created by capit on 12/2/2025.
//

#include "Tienda.h"
#include <fstream>
#include <iostream>
#include <sstream>

void Tienda::cargarCatalogo() {
    std::ifstream inputFile("catalogo.csv");

    if (inputFile) {

        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            std::string nombre;
            std::string codigoS;
            std::string precioS;

            std::getline(ss, nombre, ',');
            std::getline(ss, codigoS, ',');
            std::getline(ss, precioS, ',');

            int codigo = std::stoi(codigoS);
            double precio = std::stod(precioS);

            Autoparte p(nombre, codigo, precio);
            catalogo.push_back(p);
        }

    } else {
        std::cout << "Error critico al intentar abrir el archivo de catalogo! Favor de intentar de nuevo.";
    }
}

void Tienda::listarAutopartes() {

    for (const auto& p : catalogo) {
        std::cout << p.getNombre() << " " << p.getCodigo() <<"\n";
    }
}

void Tienda::agregarAlCarrito(const int& codigo) {
    for (const auto& e :  catalogo) {
        if (e.getCodigo() == codigo) {
            carrito.agregarAutoparte(e);
            std::cout << e.getNombre() << " ha sido agregado al carrito! \n";
        }
    }
}

void Tienda::mostrarCarrito() {
    carrito.mostrarCarrito();
}

void Tienda::finalizarCompra() {
    std::cout << "Ticket de compra: \n";

    carrito.mostrarCarrito();
    std::cout << "El total de su compra es de: " << carrito.calcularTotal();
}
