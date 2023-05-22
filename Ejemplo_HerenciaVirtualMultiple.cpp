#include <iostream>
#include <string>
using namespace std;
class Producto {
    public:
        Producto() { }
        // Producto(string n, string d, double p) : nombre(n), descripcion(d), precio(p) {}
        Producto(string n, string d, double p) {
            this->nombre = n;
            this->descripcion = d;
            this->precio = p;
        }
        // virtual ~Producto() {}
        string nombre;
        string descripcion;
        double precio;
};

class ProductoBase : virtual public Producto {
    public:
        ProductoBase() { }
        ProductoBase(string n, string d, double p) : Producto(n, d, p) {
            this->nombre = n;
            this->descripcion = d;
            this->precio = p;
        }
        // ProductoBase(string n, string d, double p) : Producto(n, d, p) {}
};

class ProductoFisico : virtual public ProductoBase {
    public:
        double peso;
        double tamano;
        ProductoFisico() { }
        ProductoFisico(string n, string d, double p, double w, double s) : ProductoBase(n, d, p), peso(w), tamano(s) {}
};

class ProductoDigital : virtual public ProductoBase {
    public:
        string link;
        ProductoDigital(string n, string d, double p, string l) : ProductoBase(n, d, p), link(l) {}
        ProductoDigital() {}
};

class proVenta : virtual public ProductoDigital, virtual public ProductoFisico {
    public:
        proVenta() { }
        proVenta(string n, string d, double p, string l, double w, double t) : ProductoDigital(n, d, p, l), ProductoFisico(n, d, p, w, t) {
            this->nombre = n;            
            this->descripcion = d;
            this->precio = p;
            this->link = l;
            this->peso = w;
            this->tamano = t;
        }
};

int main() {
    ProductoFisico libro("Cien años de soledad", "Libro de Gabriel García Márquez", 12.99, 1.2, 10.5);
    ProductoDigital cancion("Bohemian Rhapsody", "Canción de Queen", 0.99, "https://www.youtube.com/watch?v=fJ9rUzIMcZQ");
    proVenta prod001 ("Nat king cole", "FRANK SINATRA", 0.99, "https://www.youtube.com/watch?v=fJ9rUzIMcZQ", 3.0, 2.0);

    cout << "Producto Físico: " << libro.nombre << endl;
    cout << "Descripción: " << libro.descripcion << endl;
    cout << "Precio: $" << libro.precio << endl;
    cout << "Peso: " << libro.peso << " kg" << endl;
    cout << "Tamaño: " << libro.tamano << " cm" << endl;
    
    cout << "Producto Digital: " << cancion.nombre << endl;
    cout << "Descripción: " << cancion.descripcion << endl;
    cout << "Precio: $" << cancion.precio << endl;
    cout << "Link de descarga: " << cancion.link << endl;

    cout << "Descripción PRODVENTA: " << prod001.descripcion << endl;
    cout << "Precion: PRODVENTA$ " << prod001.precio << endl;
    cout << "Link de descarga: PRODVENTA" << prod001.link << endl;
    cout << "Peso: " << prod001.peso << " kg" << endl;
    cout << "Tamaño: " << prod001.tamano << " cm" << endl;

    return 0;
}