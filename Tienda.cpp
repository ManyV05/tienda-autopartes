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

void Tienda::menu() {
    int opcion;

    do {
        cout << "\n";
        cout << "==============================================\n";
        cout << "                AUTOZONE STORE                \n";
        cout << "==============================================\n";
        cout << "  1 | Cargar Catalogo\n";
        cout << "  2 | Listar Autopartes\n";
        cout << "  3 | Agregar al Carrito\n";
        cout << "  4 | Mostrar Carrito\n";
        cout << "  5 | Finalizar Compra\n";
        cout << "  6 | Salir\n";
        cout << "==============================================\n";
        cout << "-> Opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                cargarCatalogo();
                break;

            case 2:
                listarAutopartes();
                break;

            case 3: {
                int codigo;
                cout << "Ingrese el codigo de la autoparte a agregar: ";
                cin >> codigo;
                agregarAlCarrito(codigo);
                break;
            }

            case 4:
                mostrarCarrito();
                break;

            case 5:
                finalizarCompra();
                break;

            case 6:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opción no valida, intente de nuevo.\n";
                break;
        }

    } while (opcion != 6);
}
