#include <iostream>
#include <string>
using namespace std;

class Banco {
private:
    static float tasaDeInteres;
public:
    static void establecerTasaDeInteres(float tasa) {
        tasaDeInteres = tasa;
    }
    static float obtenerTasaDeInteres() {
        return tasaDeInteres;
    }
};

float Banco::tasaDeInteres = 0.0;

class CuentaBancaria {
private:
    float saldo;
public:
    CuentaBancaria(float _saldo = 0.0) {
        saldo = _saldo;
    }
    void depositar(float _cantidad) {
        saldo += _cantidad;
    }
    bool retirar(float _cantidad) {
        if (saldo >= _cantidad) {
            saldo -= _cantidad;
            return true;
        }
        return false;
    }
    float obtenerSaldo() const {
        return saldo;
    }
    float calcularInteres() const {
        return saldo * Banco::obtenerTasaDeInteres();
    }
};

int main() {

    Banco::establecerTasaDeInteres(0.05);
    
    CuentaBancaria cuenta(700.0);
    
    cuenta.depositar(500.0);
    if (cuenta.retirar(200.0)) {
        cout << "Retiro exitoso, su saldo es: " << cuenta.obtenerSaldo() <<endl;
    } else {
        cout << "Fondos insuficientes" << endl;
    }

    cout << "Interes ganado: " << cuenta.calcularInteres() << endl;

    Banco::establecerTasaDeInteres(0.02);
    
     if (cuenta.retirar(600.0)) {
        cout << "Retiro exitoso, su saldo es: " << cuenta.obtenerSaldo() <<endl;
    } else {
        cout << "Fondos insuficientes" << endl;
    }
    cout << "Interes ganado: " << cuenta.calcularInteres() << endl;
    
    return 0;
}
