#include <iostream>
#include <string>


using namespace std;


class persona
{
    private:
        string nombre;
        int edad;
        int salario;
    protected:
        string correo;
    public:
        persona()
        {
            this -> nombre = " ";
            this -> edad = 0;
            this -> salario = 0;
        }
        persona( string a, int b, int c, int d)
        {
            nombre = a;
            edad = b;
            salario = c;
            correo = d;
        }
        void info()
        {
            cout << "El correo es: "<< correo << endl;
        }
};


class Empleado : public persona
{
        string nombre;
        int edad;
        int salario;


    public:
        Empleado(string a, int b, int c) : persona(d)
        {
            nombre = a;
            edad = b;
            salario = c;
        }
        void info()
        {
            persona::info();
            cout << "el nombre es: "<< nombre << " la edad: " << edad << " y el salario: "<< salario << endl;
        }
};


class Cliente : public persona
{
    private:
        string nombre;
        int edad;
        int salario;


    public:
        Cliente(string a, int b, int c) : persona(d)
        {
            nombre = a;
            edad = b;
            salario = c;
        }
        void info()
        {
            persona::info(nombre , edad, salario);
            cout << "el nombre es: "<< nombre << " la edad: " << edad << " y el salario: "<< salario << endl;
        }


};



int main()
{
    Empleado a();
    a.info("jose", 32, 2000);
    
    Cliente b;
    b.info("martin", 54, 3000);


    return 0;
}
