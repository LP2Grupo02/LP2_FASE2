#include <iostream>
#include <string>

using namespace std;

class Movil {
    protected:
        string marca;
        string modelo;
        string sistemaOperativo;

    public:
        Movil() {
            this->marca = "XYZ";
            this->modelo = "ABC";
            this->sistemaOperativo = "NoIdentificado";
            cout<<"Constructor de Movil01: "<<marca<<" "<<modelo<<endl;
        }
        Movil(const string& ma, const string& mo, const string& sO) : marca(ma), modelo(mo), sistemaOperativo(sO) {
            cout<<"Constructor de Movil02: "<<marca<<" "<<modelo<<endl;
        }

        virtual ~Movil() {
            cout<<"Destructor de Movil: "<<marca<<" "<<modelo<<endl;
        }

        void Llamar() {
            cout<<"Llamando desde el móvil "<<marca<<" "<<modelo<<endl;
};

class Telefono : public Movil {
    private:
        int numero;

    public:
        Telefono() : Movil("XYZ", "ABC", "NoIdentificado") {
            this->numero = 123456789;
            cout<<"Constructor de Telefono01: "<<marca<<" "<<modelo<<endl;
        }

        Telefono(const string& ma, const string& mo, const string& sO, int n) : Movil(ma, mo, sO), numero(n) {
            cout<<"Constructor de Telefono02: "<<marca<<" "<<modelo<<endl;
        }

        ~Telefono() override {
            cout<<"Destructor de Telefono: "<<marca<<" "<<modelo<<endl;
        }

        void Marcar() {
            cout<<"Marcando al número "<<numero<<" desde el teléfono "<<marca<<" "<<modelo<<endl;
        }
};

class Tablet : protected Movil {
    private:
        string tamano;

    public:
        Tablet() : Movil("XYZ", "ABC", "NoIdentificado") {
            this->tamano = "0 pulgadas";
            cout<<"Constructor de Tablet01: "<<marca<<" "<<modelo<<endl;
        }

        Tablet(const string& ma, const string& mo, const string& sO, const string& t) : Movil(ma, mo, sO), tamano(t) {
            cout<<"Constructor de Tablet02: "<<marca<<" "<<modelo<<endl;
        }

        ~Tablet() override {
            cout<<"Destructor de Tablet: "<<marca<<" "<<modelo<<endl;
        }

        void Navegar() {
            cout<<"Navegando en la tablet "<<marca<<" "<<modelo<<endl;
        }
};

int main() {
    Telefono telefono("Samsung", "Galaxy S21", "Android", 123456789);
    telefono.Llamar();
    telefono.Marcar();

    Tablet tablet("Apple", "iPad Pro", "iOS", "12.9 pulgadas");
    tablet.Navegar();

    return 0;
}
