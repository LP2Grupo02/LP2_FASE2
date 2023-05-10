#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Alumno{
    public:
        string nombre;
        int edad;
        float promedio;
        
        Alumno(string nm, int ed, float pro){
            this->nombre = nm;
            this->edad = ed;
            this->promedio = pro;
        }

        void Imprimir(){
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Edad: "<<edad<<endl;
            cout<<"Promedio: "<<promedio<<endl;
        }

        float Compara(Alumno &A1, Alumno &A2){
            if (A1.promedio < A2.promedio){
                return true;
            }
            else{
                return false;
            }
        }
};

class Grupo{
    public:
        vector<Alumno> alumnos;
        vector<Alumno> _alumnos;
        int cantidad;

        Grupo(int cantidad, vector<Alumno> alumnos){
            this->cantidad = cantidad;
            this->alumnos = alumnos;
        }

        Grupo(int cantidad){ this->cantidad = cantidad; }

        void Imprimir(){
            cout<<"Cantidad: "<<cantidad<<endl;
            for(size_t i = 0; i < alumnos.size(); i++){
                cout<<"Nombre: "<<alumnos[i].nombre<<endl;
                cout<<"Edad: "<<alumnos[i].edad<<endl;
                cout<<"Promedio: "<<alumnos[i].promedio<<endl;
            }
        }

        void AgregarAlumno(string nm, int ed, float pro){
            cout<<"Ingrese su nombre: "<<endl;
            cin>>nm;
            cout<<"Ingrese su edad: "<<endl;
            cin>>ed;
            cout<<"Ingrese su promedio: "<<endl;
            cin>>pro;
            Alumno NuevoAlumno(nm, ed, pro);
            alumnos.push_back(NuevoAlumno);
        }

        void OrdenarPorPromedio(){
            for(size_t i = 0; i < alumnos.size() - 1; i++){
                for(size_t j = i+1; j < alumnos.size(); j++){
                    if(alumnos[j].promedio < alumnos[i].promedio){
                        Alumno VarTemp = alumnos[i];
                        alumnos[i] = alumnos[j];
                        alumnos[j] = VarTemp;
                    }
                }
            }
        }
        
        float PromedioGrupo(){
            float sum = 0.0;
            for(size_t i = 0; i < alumnos.size(); i++){
                sum += alumnos[i].promedio;
            }
            return sum / alumnos.size();
        }

        Alumno MejorPromedio(){
            Alumno mejor_alumno = alumnos[0];
            for(size_t i = 1; i < alumnos.size(); i++){
                if(alumnos[i].promedio > mejor_alumno.promedio){
                    mejor_alumno = alumnos[i];
                }
            }
            return mejor_alumno;
        }
};

int main(){
    Grupo grupo(5);
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);
    grupo.AgregarAlumno("", 0, 0.0);

    cout<<"Grupo:"<<endl;
    grupo.Imprimir();
    cout<<"Promedio de promedios: "<<grupo.PromedioGrupo()<<endl;
    cout<<"Mejor promedio: "<<endl;
    grupo.MejorPromedio().Imprimir();

    cout<<"Grupo ordenado por promedio:"<<endl;
    grupo.OrdenarPorPromedio();
    grupo.Imprimir();

    return 0;
}
