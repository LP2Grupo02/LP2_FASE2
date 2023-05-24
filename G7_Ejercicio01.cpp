#include <iostream>
#include <string>

using namespace std;

class Vehiculo {
protected:
    string marca;
    string modelo;
    int anioFabricacion;
    double precio;

public:
    Vehiculo(string _marca, string _modelo, int _anioFabricacion, double _precio) {
        marca = _marca;
        modelo = _modelo;
        anioFabricacion = _anioFabricacion;
        precio = _precio;
    }
};

class Automovil : public Vehiculo {
private:
    int numPuertas;
    string tipoCombustible;

public:
    Automovil(string _marca, string _modelo, int _anioFabricacion, double _precio, int _numPuertas, string _tipoCombustible)
        : Vehiculo(_marca, _modelo, _anioFabricacion, _precio) {
        numPuertas = _numPuertas;
        tipoCombustible = _tipoCombustible;
    }
    
    void info(){
        cout << "AUTOMOVIL:" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio de fabricacion: " << anioFabricacion << endl;
        cout << "Precio: " << precio << endl;
        cout << "Numero de puertas: " << numPuertas << endl;
        cout << "Tipo de combustible: " << tipoCombustible << endl;  
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    Motocicleta(string _marca, string _modelo, int _anioFabricacion, double _precio, int _cilindrada)
        : Vehiculo(_marca, _modelo, _anioFabricacion, _precio) {
        cilindrada = _cilindrada;
    }
    void info(){
        cout << "MOTOCICLETA:" << endl;
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Anio de fabricacion: " << anioFabricacion << endl;
        cout << "Precio: " << precio << endl;
        cout << "Cilindrada: " << cilindrada << endl;
    }
};

int main() {
    // Crear objetos de las clases derivadas y acceder a sus atributos
    Automovil auto1("Toyota", "Rav4", 2023, 44000, 4, "Gasolina/Electrico");
    auto1.info();
    cout<<endl;
    Motocicleta moto1("Honda", "CBR500R", 2021, 8000, 500);
    moto1.info();
    return 0;
}
