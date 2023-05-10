#include <iostream>

using namespace std;
//Creamos la clase circulo
class Circulo {
public:
    Circulo(double radio = 0) : radio_(radio), diametro_(radio * 2) {}//constructor con atributos por defecto

    double radio() const { return radio_; }
    double diametro() const { return diametro_; }
//Definimos cual sera la funcion amiga
    friend double calcular_area(const Circulo& c);

private:
    double radio_;
    double diametro_;
};
// Creanos la funcion amiga
double calcular_area(const Circulo& c) {
    double radio = c.radio_;
    return 3.14 * radio * radio;
}

int main() {
    Circulo c1(3);
    Circulo c2(5.2);
    Circulo c3(8.9);

    cout << "El area del circulo c1 es: " << calcular_area(c1) << endl;
    cout << "El area del circulo c2 es: " << calcular_area(c2) << endl;
    cout << "El area del circulo c3 es: " << calcular_area(c3) << endl;

    return 0;
}
