#include <iostream> 

using namespace std; 

class Forma { 
    public: 
        virtual void calcularArea() = 0; // Función puramente virtual 
};

class Circulo: public Forma { 
    public: 
        int r; 
        void calcularArea() { 
            cout << "El Área es " << 3.1416 * r*r << endl; 
        } 
}; 

class Rectangulo : public Forma { 
    public: 
        int a, l; 
        void calcularArea() { 
            cout << "El Área es " << a*l << endl; 
        } 
}; 

class Triangulo: public Forma { 
    public: 
        int a,l; 
        void calcularArea() { 
            cout << "El Área es " << (a*l)/2 << endl; 
        } 
}; 

int main() { 
    int op = 0, r, a, l; 
    while (op != 4) { 
        cout << "MENU" << endl; 
        cout << "1.- Area de Circulo." << endl; 
        cout << "2.- Area de Rectangulo." << endl; 
        cout << "3.- Area de Triangulo." << endl; 
        cout << "4.- SALIR." << endl; 
        cin >> op; 
        switch (op) { 
        case 1: 
            cout << "Ingrese el radio del circulo: " << endl; 
            cin >> r; 
            { 
                Circulo obj1; 
                obj1.r = r; 
                obj1.calcularArea(); 
            } 
            break; 
        case 2: 
            cout << "Ingrese el ancho del rectangulo: " << endl; 
            cin >> a; 
            cout << "Ingrese el largo del rectangulo: " << endl; 
            cin >> l; 
            { 
                Rectangulo obj2; 
                obj2.a = a; 
                obj2.l = l; 
                obj2.calcularArea(); 
            } 
            break; 
        case 3: 
            cout << "Ingrese el ancho y la altura respectivamente: " << endl; 
                cin >> a; 
                cin >> l; 
                { 
                    Triangulo obj3; 
                    obj3.a = a; 
                    obj3.l = l; 
                    obj3.calcularArea(); 
                } 
        } 
    } 
} 