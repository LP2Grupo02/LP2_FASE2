#include <iostream> 

using namespace std;

class Vehiculo { 
public:
    void acelerar() { 
        cout << "Acelerando el vehículo" << std::endl; 
    } 
};   

class Coche : public Vehiculo { 
public: 
    void acelerar() { 
        cout << "Acelerando el coche" << std::endl; 
    }   
    void encenderLuces() { 
        cout << "Luces del coche encendidas" << std::endl; 
    } 
}; 

class Motocicleta : public Vehiculo { 
public: 
    void acelerar() { 
        cout << "Acelerando la motocicleta" << std::endl; 
    } 
}; 

int main() { 
    Coche coche; 
    coche.acelerar(); // Imprime "Acelerando el coche" 
  
    Motocicleta motocicleta; 
    motocicleta.acelerar(); // Imprime "Acelerando la motocicleta" 
    // Llamar al método "encenderLuces()" en una instancia de la clase "Coche" 
    coche.encenderLuces(); // Imprime "Luces del coche encendidas" 

    return 0; 
} 

 