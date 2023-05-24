#include <iostream>
#include <string>

using namespace std;

class Cliente {
protected:
    string nombre;
    string direccion;
    double saldo;

protected:
    void encriptarInformacion() {
        // Código para encriptar la información
        cout << "Encriptando información del cliente" << endl;
    }

public:
    Cliente(string _nombre, string _direccion, double _saldo) {
        nombre = _nombre;
        direccion = _direccion;
        saldo = _saldo;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Saldo: " << saldo << endl;
    }
};

class ClienteSeguro : public Cliente {
private:
    string clave;

public:
    ClienteSeguro(string _nombre, string _direccion, double _saldo, string _clave) : Cliente(_nombre, _direccion, _saldo) {
        clave = _clave;
    }

    void verificarAutenticidad() {
        // Código para verificar la autenticidad del cliente
        cout << "Verificando autenticidad del cliente" << endl;
    }

    void mostrarInformacionSegura() {
        encriptarInformacion();
        mostrarInformacion();
    }

    ~ClienteSeguro() {
        // Código para liberar los recursos utilizados por la clase derivada
        cout << "Liberando recursos de la clase ClienteSeguro" << endl;
    }
};

int main() {
    ClienteSeguro cliente("Juan Perez", "Calle 123", 1000.0, "1234");
    cliente.verificarAutenticidad();
    cliente.mostrarInformacionSegura();

    return 0;
}
