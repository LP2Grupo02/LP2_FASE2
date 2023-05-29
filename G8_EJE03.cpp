#include <iostream>

using namespace std;

class Empleado {                                            // Clase abstracta Empleado
protected:
    double salario;
public:
    Empleado(double sl) : salario(sl) {}
    Empleado() {
        this->salario = 1025.0;
    }
    virtual double calcularSalario() const = 0;             // Método virtual puro calcularSalario()
};

class EmpleadoTiempoCompleto : public Empleado {
protected:
    double bono;
public:
    EmpleadoTiempoCompleto(double sl, double bn) : Empleado(sl), bono(bn) {}
    EmpleadoTiempoCompleto() {
        this->salario = 1025.0;
        this->bono = 500.0;
    }
    double calcularSalario() const override {               // Cálculo del salario tiempo completo
        return this->salario + this->bono;
    }
};

class EmpleadoMedioTiempo : public Empleado {
protected:
    double bono;
public:
    EmpleadoMedioTiempo(double sl, double bn) : Empleado(sl), bono(bn) {}
    EmpleadoMedioTiempo() {
        this->salario = 1025.0;
        this->bono = 500.0;
    }
    double calcularSalario() const override {              // Cálculo del salario medio tiempo
        return (this->salario / 2) + this->bono;
    }
};

int main() {
    EmpleadoTiempoCompleto empleadoTiempoCompleto;
    EmpleadoMedioTiempo empleadoMedioTiempo;

    cout << "Salario del Empleado a Tiempo Completo: S/. " << empleadoTiempoCompleto.calcularSalario() << endl;
    cout << "Salario del Empleado a Medio Tiempo: S/. " << empleadoMedioTiempo.calcularSalario() << endl;

    return 0;
}
