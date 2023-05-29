#include <iostream> 
#include <string> 

using namespace std; 

class Figura { 
    public: 
        virtual float CalcularArea() = 0; 
}; 

class Circulo : public Figura{ 
    private: 
        float radio; 
    public: 
        Circulo(float _radio){ 
            radio = _radio; 
        } 
        float CalcularArea(){ 
            return 3.14159 * (radio * radio); 
        } 
}; 

class Rectangulo : public Figura{ 
    private:
        float base; 
        float altura; 
    public: 
        Rectangulo(float _base, float _altura){ 
            base = _base; 
            altura = _altura; 
        } 
        float CalcularArea(){ 
            return base * altura; 
        } 
}; 

class Triangulo : public Figura{ 
    private: 
        float base; 
        float altura; 
    public: 
        Triangulo(float _base, float _altura){ 
            base = _base; 
            altura = _altura; 
        }
        float CalcularArea(){ 
            return (base * altura)/2; 
        } 
}; 

class Cuadrado : public Figura{ 
    private: 
        float lado; 
    public: 
        Cuadrado(float _lado){ 
            lado = _lado; 
        }
        float CalcularArea(){ 
            return lado * lado; 
        } 
}; 

class Rombo : public Figura{ 
    private: 
        float DiaMayor; 
        float DiaMenor; 
    public: 
        Rombo(float Dmayor, float Dmenor){ 
            DiaMayor = Dmayor; 
            DiaMenor = Dmenor; 
        }
        float CalcularArea(){ 
            return (DiaMayor * DiaMenor)/2; 
        } 
}; 

int main(){ 
    int opc = 0; 
    while(opc < 1 or opc > 5){ 
        cout<<"CALCULO DE AREAS"<<endl; 
        cout<<"Seleccione la figura:"<<endl; 
        cout<<"1. Circulo"<<endl; 
        cout<<"2. Rectangulo"<<endl; 
        cout<<"3. Triangulo"<<endl; 
        cout<<"4. Cuadrado"<<endl; 
        cout<<"5. Rombo"<<endl; 
        cout<<"Seleccione que Area desea hallar: "; 
        cin>>opc;  
    } 
    Figura *area = nullptr; 
    switch (opc){ 
        case 1: 
            float radio; 
            cout<<"Selecciono Circulo"<<endl; 
            cout<<"Ingrese el radio: "; 
            cin>>radio; 
            area = new Circulo(radio); 
            break; 
        case 2: 
            float base, altura; 
            cout<<"Selecciono Rectangulo"<<endl; 
            cout<<"Ingrese la base: "; 
            cin>>base; 
            cout<<"Ingrese la altura: "; 
            cin>>altura; 
            area = new Rectangulo(base,altura); 
            break; 
        case 3: 
            //float base, altura; 
            cout<<"Selecciono Triangulo"<<endl; 
            cout<<"Ingrese la base: "; 
            cin>>base; 
            cout<<"Ingrese la altura: "; 
            cin>>altura; 
            area = new Triangulo(base,altura); 
            break; 
        case 4: 
            float lado; 
            cout<<"Selecciono Cuadrado"<<endl; 
            cout<<"Ingrese el lado: "; 
            cin>>lado; 
            area = new Cuadrado(lado); 
            break; 
        case 5: 
            float Dmayor, Dmenor; 
            cout<<"Selecciono Rombo"<<endl; 
            cout<<"Ingrese el diagonal mayor: "; 
            cin>>Dmayor; 
            cout<<"Ingrese el diagonal menor: "; 
            cin>>Dmenor; 
            area = new Rombo(Dmayor,Dmenor); 
            break; 
        return 0; 
    } 
    if(area != nullptr){ 
        float CalArea = area -> CalcularArea(); 
        cout<<"El area de la figura es: "<<CalArea<<endl; 
    } 
    return 0; 
} 