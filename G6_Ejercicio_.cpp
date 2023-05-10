#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno{
    public:
        string nombre;                              //Atributos: str nombre, int edad, float promedio
        int edad;
        float promedio;
        
        Alumno(string nm, int ed, float pro){       //Constructor: Recibe nombre, edad y promedio 
            this->nombre = nm;
            this->edad = ed;
            this->promedio = pro;
        }

        void Imprimir(){                            //Método: muestra los atributos del alumno
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Edad: "<<edad<<endl;
            cout<<"Promedio: "<<promedio<<endl;
        }

        bool Compara(Alumno &A1, Alumno &A2){      //Método: compara promedios de un objeto (A1) 
            if (A1.promedio < A2.promedio){        //a otro objeto (A2) y muestra true 
                return true;                       //si el promedio de A1 es mayor
            }
            return false;
        }
};

class Grupo{
    public:
        vector<Alumno> alumnos;                                 //Atributos: vectores de Clase Alumno y int cantidad
        static int cantidad;

        Grupo(int cantidad, vector<Alumno> alumnos){            //Constructor: recibe cantidad, vector de Clase Alumno
            this->cantidad = cantidad;
            this->alumnos = alumnos;
        }

        Grupo(int cantidad){ this->cantidad = cantidad; }       //Constructor: recibe cantidad

        void Imprimir(){                                        //Método: muestra los alumnos con sus atributos y la cantidad de ellos
            cout<<"Cantidad: "<<cantidad<<endl;
            for(size_t i = 0; i < alumnos.size(); i++){         //size_t: tipo de dato, entero sin signo (parecido a int)
                cout<<"Alumno 0"<<i<<": "<<endl;
                cout<<"Nombre: "<<alumnos[i].nombre<<endl;
                cout<<"Edad: "<<alumnos[i].edad<<endl;
                cout<<"Promedio: "<<alumnos[i].promedio<<endl;
            }
        }

        void AgregarAlumno(string nm, int ed, float pro){       //Método: Agrega alumnos al vector con sus respectivos atributos
            while(alumnos.size() < cantidad){
                cout<<"Ingrese su nombre: "<<endl;
                cin>>nm;
                cout<<"Ingrese su edad: "<<endl;
                cin>>ed;
                cout<<"Ingrese su promedio: "<<endl;
                cin>>pro;
                Alumno NuevoAlumno(nm, ed, pro);                    //Crea un objeto Alumno, con sus atributos
                alumnos.push_back(NuevoAlumno);                     //Agrega al final al objeto alumno en el vector alumnos
            }
            cout<<"NO SE PUEDE INGRESAR MAS ALUMNOS"<<endl;
        }

        void OrdenarPorPromedio(){                              //Método: Ordena a los alumnos por su promedio (menor a mayor)
            for(size_t i = 0; i < alumnos.size() - 1; i++){     //Recorremos el vector, desde 0
                for(size_t j = i+1; j < alumnos.size(); j++){   //Volvemos a recorrer el vector, desde 1
                    if(alumnos[j].promedio < alumnos[i].promedio){      //Buscamos el menor promedio 
                        Alumno VarTemp = alumnos[i];            //Equivalente
                        alumnos[i] = alumnos[j];                //a swap()
                        alumnos[j] = VarTemp;                   //: Intercambia valores
                    }
                }
            }
        }
        
        float PromedioGrupo(){                                  //Método: hace un promedio de los promedios de los alumnos, promedio grupal
            float sum = 0.0;                                    //Variable float sum
            for(size_t i = 0; i < alumnos.size(); i++){         //Recorremos el vector alumnos
                sum += alumnos[i].promedio;                     //Sumamos los promedios
            }
            return sum / alumnos.size();                        //Retornamos el promedio, sum entre el tamaño del vector (nº alumnos)
        }

        Alumno MejorPromedio(){                                 //Método: muestra el mejor promedio
            Alumno mejor_alumno = alumnos[0];                   //Objeto mejor_alumno de clase Alumno, lo declaramos igual al primer elemento del vector alumnos
            for(size_t i = 1; i < alumnos.size(); i++){         //Recorremos el vector
                if(alumnos[i].promedio > mejor_alumno.promedio){    //Buscamos el mayor promedio
                    mejor_alumno = alumnos[i];                  //Declaramos a mejor_alumno = al alumno del mejor promedio
                }
            }
            return mejor_alumno;                                //Retornamos el alumno del mejor promedio
        }
};

int cnt;
int Grupo::cantidad = cnt;

int main(){
    cout<<"Ingrese la cantidad de alumnos que estaran en el grupo: "<<endl;
    cin>>cnt;
    Grupo grupo(cnt);                                             //Declaramos un objeto grupo con 5 elementos
    grupo.AgregarAlumno("", 0, 0.0);                              //Agregamos sus alumnos
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);

    cout<<"Grupo:"<<endl;                                       //Mostramos el grupo
    grupo.Imprimir();
    cout<<"Promedio de promedios: "<<grupo.PromedioGrupo()<<endl;   //Mostramos el promedio del grupo
    cout<<"Mejor promedio: "<<endl;
    grupo.MejorPromedio().Imprimir();                           //Mostramos el mejor promedio

    cout<<"Grupo ordenado por promedio:"<<endl;                 //Ordenamos el grupo por sus promedios
    grupo.OrdenarPorPromedio();
    grupo.Imprimir();                                           //Mostramos el nuevo orden del grupo

    return 0;
}
