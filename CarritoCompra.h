//
// Created by medin on 02/12/2025.
//

#ifndef PROYECTO_C___CARRITOCOMPRA_H
#define PROYECTO_C___CARRITOCOMPRA_H
#include <vector>
#include "Autoparte.h"
using namespace std;


class CarritoCompra {
private:
    vector<Autoparte> productos;
public:
    CarritoCompra();
    explicit CarritoCompra(vector<Autoparte> &productos);
    void agregarAutoparte(const Autoparte& p);
    double calculaTotal();
    void mostrarCarrito();
};

#endif //PROYECTO_C___CARRITOCOMPRA_H