#include <iostream> 

using namespace std; 
 
class Reproductor { 
    public: 
        virtual void reproducir() = 0; 
        virtual void pausar() = 0; 
        virtual void detener() = 0; 
}; 

class ReproductorMP3 : public Reproductor { 
    public: 
        void reproducir() override { 
            cout << "Reproduciendo archivo de audio MP3." << endl; 
        } 
        void pausar() override { 
            cout << "Pausando reproducción de archivo de audio MP3." <<endl; 
        } 
        void detener() override { 
            cout << "Deteniendo reproducción de archivo de audio MP3." << endl; 
        } 
}; 

int main() { 
    ReproductorMP3 reproductor; 
    int op = 0;  
    while (op != 4) {  
        cout << "MENU" << endl;  
        cout << "1.- Reproducir" << endl;  
        cout << "2.- Pausar" << endl;  
        cout << "3.- Detener" << endl;  
        cout << "4.- SALIR." << endl;  
        cin >> op;  
        
        switch (op) {  
        case 1:  
            reproductor.reproducir(); 
            break;  
        case 2:  
            reproductor.pausar(); 
            break;  
        case 3:  
            reproductor.detener();  
        }  
    }  
} 