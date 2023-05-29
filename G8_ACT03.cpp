#include <iostream> 
#include <string> 
 
using namespace std; 
 
class Animal{ 
    public: 
    virtual void HacerSonido() = 0; 
}; 

class Perro : public Animal{ 
    public: 
        void HacerSonido(){ 
            cout<<"El perro hace: guau guau guau!"<<endl; 
        } 
}; 

class Gato : public Animal{ 
    public: 
        void HacerSonido(){ 
            cout<<"El gato hace: miau miau miau!"<<endl; 
        } 
}; 

class Vaca : public Animal{ 
    public: 
        void HacerSonido(){ 
            cout<<"La vaca hace: muuuuu muuuuu muuuuu!"<<endl; 
        } 
}; 

int main(){ 
    Animal *animal1 = new Perro(); 
    Animal *animal2 = new Gato(); 
    Animal *animal3 = new Vaca(); 

    animal1 -> HacerSonido(); 
    animal2 -> HacerSonido(); 
    animal3 -> HacerSonido(); 
    return 0; 
} 

 