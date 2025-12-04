//
// Created by capit on 12/2/2025.
//

#include "Tienda.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

void Tienda::cargarCatalogo() {
    std::ifstream inputFile("catalogo.csv");
    cout << "El catalogo ha sido cargado: " << endl;

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

    if (catalogo.size() == 0) {
        std::cout << "El catalogo esta vacio o no ha sido importado aun! \n";
    }
    else {
        for (const auto &p: catalogo) {
            std::cout << p.getNombre() << " " << p.getCodigo() << "\n";
        }
    }
}

void Tienda::agregarAlCarrito(int codigo) {
    auto it = std::find_if(
        catalogo.begin(),
        catalogo.end(),
        [codigo](const Autoparte& p) {
            return p.getCodigo() == codigo;
        }
    );

    if (it != catalogo.end()) {
        std::cout << it->getNombre() << " ha sido agregado al carrito! \n";

        carrito.agregarAutoparte(*it);

        catalogo.erase(it);
    } else {
        std::cout << "Error: Autoparte con codigo " << codigo << " no encontrada en el catalogo. \n";
    }
}

void Tienda::eliminarAutoparte(int &codigo) {
    auto it=std::remove_if(
        catalogo.begin(),
        catalogo.end(),
        [codigo](const Autoparte& p) {
            return (p.getCodigo() == codigo);
        }
    );
    catalogo.erase(it, catalogo.end());
}

void Tienda::mostrarCarrito() {
    carrito.mostrarCarrito();
}

void Tienda::finalizarCompra() {
    std::cout << "Ticket de compra: \n";


    carrito.mostrarCarrito();
    std::cout << "El total de su compra es de: " << carrito.calcularTotal();
}

void Tienda::eliminarProductoCarrito(int codigo) {
    for (const auto& e :  catalogo) {
        if (e.getCodigo() == codigo) {
            carrito.eliminarAutoparte(codigo);
            catalogo.push_back(e);
            std::cout << e.getNombre() << " ha sido eliminado del carrito! \n";
        }
    }
}

void Tienda::menu() {

    while (true) {  // el menú se repite hasta que se seleccione la opcion 6 que es salir de la tienda
        string input;
        int opcion;

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


        cin >> input;

        // Validación 1: tamaño
        if (input.size() != 1) {
            cout << "Error: Opcion invalida.\n";
            continue;
        }

        // Validación 2: dígito
        if (!isdigit(input[0])) {
            cout << "Error: Solo se permiten numeros.\n";
            continue;
        }

        // Convertimos el único caracter a número
        opcion = input[0] - '0';

        // Validación 3: rango
        if (opcion < 1 || opcion > 6) {
            cout << "Error: Opcion invalida.\n";
            continue;
        }

        // Ya es válido: ejecutar
        switch (opcion) {
            case 1:
                cargarCatalogo();
                break;

            case 2:
                listarAutopartes();
                break;

            case 3: {
                int codigo;
                cout << "Ingresa el codigo de autoparte: ";
                cin >> codigo;
                agregarAlCarrito(codigo);
                break;
            }

            case 4:
                mostrarCarrito();
                break;

            case 5:
                finalizarCompra();

            case 6:
                cout << "\nSaliendo del sistema...Gracias por su compra\n";
                return;     // ← sale de la función Y del menú
        }
    }
}