#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estudiante {
public:
    Estudiante(string nombre = "", int edad = 0, double nota1 = 0, double nota2 = 0)
        : nombre_(nombre), edad_(edad), nota1_(nota1), nota2_(nota2) {}

    string nombre() const { return nombre_; }
    int edad() const { return edad_; }
    double nota1() const { return nota1_; }
    double nota2() const { return nota2_; }
    double promedio() const { return (nota1_ + nota2_) / 2; }

private:
    string nombre_;
    int edad_;
    double nota1_;
    double nota2_;
};

void impriestudiantes(const vector<Estudiante>& estudiantes) {
    for (const Estudiante& estudiante : estudiantes) {
        cout << "Nombre: " << estudiante.nombre() << endl;
        cout << "Edad: " << estudiante.edad() << endl;
        cout << "Nota 1: " << estudiante.nota1() << endl;
        cout << "Nota 2: " << estudiante.nota2() << endl;
        cout << "Promedio: " << estudiante.promedio() << endl << endl;
    }
}

void ordpromedio(vector<Estudiante>& estudiantes) {
    int n = estudiantes.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (estudiantes[j].promedio() > estudiantes[i].promedio()) {
                swap(estudiantes[i], estudiantes[j]);
            }
        }
    }
}

int main() {
    vector<Estudiante> estudiantes;
    estudiantes.push_back(Estudiante("Juan", 20, 8.5, 7.2));
    estudiantes.push_back(Estudiante("Ana", 19, 9.1, 8.3));
    estudiantes.push_back(Estudiante("Pedro", 21, 6.8, 7.5));
    estudiantes.push_back(Estudiante("María", 20, 7.4, 8.6));
    estudiantes.push_back(Estudiante("Sofía", 18, 8.9, 9.0));


    cout << "Estudiantes:" << endl;
    impriestudiantes(estudiantes);


    ordpromedio(estudiantes);
    cout << "Estudiantes ordenados por promedio:" << endl;
    impriestudiantes(estudiantes);
}
