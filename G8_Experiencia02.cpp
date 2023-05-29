#include <iostream>

class Forma {
public:
    virtual double calcularPerimetro() = 0;
};

class Circulo : public Forma {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}

    double calcularPerimetro() override {
        return 2 * 3.14159 * radio;
    }
};

class Rectangulo : public Forma {
private:
    double base;
    double altura;
public:
    Rectangulo(double b, double h) : base(b), altura(h) {}

    double calcularPerimetro() override {
        return 2 * (base + altura);
    }
};

class Triangulo : public Forma {
private:
    double lado1;
    double lado2;
    double lado3;
public:
    Triangulo(double l1, double l2, double l3) : lado1(l1), lado2(l2), lado3(l3) {}

    double calcularPerimetro() override {
        return lado1 + lado2 + lado3;
    }
};

int main() {
    Forma* forma = nullptr;
    int opcion;

    std::cout << "Seleccione una forma:" << std::endl;
    std::cout << "1. Círculo" << std::endl;
    std::cout << "2. Rectángulo" << std::endl;
    std::cout << "3. Triángulo" << std::endl;
    std::cin >> opcion;

    if (opcion == 1) {
        double radio;
        std::cout << "Ingrese el radio del círculo: ";
        std::cin >> radio;
        forma = new Circulo(radio);
    }
    else if (opcion == 2) {
        double base, altura;
        std::cout << "Ingrese la base del rectángulo: ";
        std::cin >> base;
        std::cout << "Ingrese la altura del rectángulo: ";
        std::cin >> altura;
        forma = new Rectangulo(base, altura);
    }
    else if (opcion == 3) {
        double lado1, lado2, lado3;
        std::cout << "Ingrese el lado 1 del triángulo: ";
        std::cin >> lado1;
        std::cout << "Ingrese el lado 2 del triángulo: ";
        std::cin >> lado2;
        std::cout << "Ingrese el lado 3 del triángulo: ";
        std::cin >> lado3;
        forma = new Triangulo(lado1, lado2, lado3);
    }

    if (forma != nullptr) {
        double perimetro = forma->calcularPerimetro();
        std::cout << "El perímetro de la forma seleccionada es: " << perimetro << std::endl;
        delete forma;
    }

    return 0;
}