//
// Created by manyv on 30/11/2025.
//

#ifndef PROYECTOFINAL_AUTOPARTE_H
#define PROYECTOFINAL_AUTOPARTE_H
#include <string>
using namespace std;

class Autoparte {
private:
    string nombre;
    int codigo;
    double precio;
public:
    Autoparte();
    Autoparte( const string& cNombre, int &cCodigo, double &cPrecio);
    string getNombre() const;
    void setNombre( const string &cNombre);
    int getCodigo() const;
    void setCodigo(const int &cCodigo) ;
    double getPrecio() const;
    void setPrecio(const double &cPrecio) ;

};


#endif //PROYECTOFINAL_AUTOPARTE_H