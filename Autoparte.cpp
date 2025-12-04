//
// Created by manyv on 30/11/2025.
//

#include "Autoparte.h"

Autoparte::Autoparte()  {
    this->nombre="";
    this->codigo=0000;
    this->precio=00.0;
};

Autoparte::Autoparte(const string& cNombre, int& cCodigo, double& cPrecio){
    this->nombre=cNombre;
    this->codigo=cCodigo;
    this->precio=cPrecio;
};

string Autoparte::getNombre() const {
    return this->nombre;
};
void Autoparte::setNombre(const string &cNombre) {
    this->nombre=cNombre;
};
int Autoparte::getCodigo() const {
    return this->codigo;
};
void Autoparte::setCodigo(const int &cCodigo) {
    this->codigo=cCodigo;
};
double Autoparte::getPrecio() const {
    return this->precio;
};
void Autoparte::setPrecio(const double &cPrecio) {
    this->precio=cPrecio;
};