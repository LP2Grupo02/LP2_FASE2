#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Constructores, destructores, objetos como atributos de clase y autorreferencias

class Producto{
    private:
        string nombre;
        string descripcion;
        int cantidad;
        int precio;
    public:
        Producto(string nm, string dc, int ct, int pr){
            this->nombre=nm;
            this->descripcion=dc;
            this->cantidad=ct;
            this->precio=pr;
        }
        Producto(string nm, int ct, int pr){
            this->nombre=nm;
            this->descripcion=" ";
            this->cantidad=ct;
            this->precio=pr;
        }
        void setNombre(string nm){ nombre = nm; }
        void setDescripcion(string dc){ descripcion = dc; }
        void setCantidad(int ct){ cantidad = ct; }
        void setPrecio(int pr){ precio = pr; }
        string getNombre(){ return nombre; }
        string getDescripcion(){ return descripcion; }
        int getCantidad(){ return cantidad; }  
        int getPrecio(){ return precio; }
        Producto& sumaTotal(){
            int total = 0;
            total += cantidad;
            return *this;
        }
        ~Producto(){
            cout<<"Liberando memoria de Producto..."<<endl;
        }
};

class Inventario{
    private:
        vector<Producto> productos;
    public:
        Inventario(){}
        void agregarProducto(Producto p) {
            productos.push_back(p);
        }
        void eliminarProducto(int i) {
            productos.erase(productos.begin() + i);
        }
        void imprimirInventario() {
            for (int i = 0; i < productos.size(); i++) {
                cout<<"Producto: "<<productos[i].getNombre()<<endl;
                cout<<"Descripción: "<<productos[i].getDescripcion()<<endl;
                cout<<"Cantidad: "<<productos[i].getCantidad()<<endl;
                cout<<"Precio: "<<productos[i].getPrecio()<<endl;
            }
        }
        vector<Producto>& getProductos() { 
            return productos;
        }
};

class Compra{
    private:
        vector<Producto> compra;
    public:
        Compra(){}
        void carrito(){
            Producto p1("Lapicero", "Tinta negra", 50, 1.5);
            Producto p2("Cuaderno", "Cuadriculado", 20, 5.0);
            Producto p3("Calculadora", "Calculadora cientifica", 10, 24.0);
            Producto p4("Lapiz", 50, 2.5);
            Inventario inv;
            inv.agregarProducto(p1);
            inv.agregarProducto(p2);
            inv.agregarProducto(p3);
            inv.agregarProducto(p4);
            while (true) {
                string prod;
                int cant;
                int op;
                cout<<"========MENU DE OPCIONES========"<<endl;
                cout<<"1. Ingresar producto al carrito."<<endl;
                cout<<"2. Eliminar producto del carrito."<<endl;
                cout<<"3. Mostrar carrito y Salir."<<endl;
                cin>>op;
                if (op == 1){
                    vector<Producto>& prods = inv.getProductos();
                    for (int i = 0; i < prods.size(); i++) {
                        cout<<"Producto: "<<prods[i].getNombre()<<endl;
                        cout<<"Descripción: "<<prods[i].getDescripcion()<<endl;
                        cout<<"Cantidad: "<<prods[i].getCantidad()<<endl;
                        cout<<"Precio: "<<prods[i].getPrecio()<<endl;
                    }
                    cout<<"Seleccione su producto: "<<endl;
                    cin>>prod;
                    bool encontrado = false;
                    for (int i = 0; i < prods.size(); i++) {
                        if(prod == prods[i].getNombre()){
                            cout<<"Ingrese cantidad deseada: "<<endl;
                            cin>>cant;
                            if(cant <= prods[i].getCantidad()){
                                cout<<"Cantidad suficiente."<<endl;
                                compra.push_back(prods[i]);
                                int nc;
                                nc = prods[i].getCantidad()-cant;
                                prods[i].setCantidad(nc);
                            }
                            else{
                                cout<<"Cantidad insuficiente."<<endl;
                            }
                            encontrado = true;
                            break;
                        }
                    }
                    if(!encontrado) {
                        cout<<"El producto no existe."<<endl;
                    }
                }
                if (op == 2){
                    cout<<"Ingrese el producto que desea sacar del carrito: "<<endl;
                    cin>>prod;
                    bool encontrado = false;
                    for (int i = 0; i < compra.size(); i++) {
                        if(prod == compra[i].getNombre()){
                            encontrado = true;
                            compra.erase(compra.begin() + i);
                            break;
                        }
                    }
                    if(!encontrado) {
                        cout<<"El producto no existe en el carrito."<<endl;
                    }
                }
                else if (op == 3){
                    int ttl = 0;
                    for (int i = 0; i < compra.size(); i++) {
                        cout<<"Producto: "<<compra[i].getNombre()<<endl;
                        cout<<"Descripción: "<<compra[i].getDescripcion()<<endl;
                        cout<<"Cantidad: "<<compra[i].getCantidad()<<endl;
                        cout<<"Precio: "<<compra[i].getPrecio()<<endl;
                        ttl += compra[i].getPrecio();
                    }
                    cout<<"TOTAL: "<<ttl<<endl;
                    cout<<"FIN DEL PROGRAMA"<<endl;
                    break;
                }
                else{
                    cout<<"Opción invalida"<<endl;
                }
            }
        }
        ~Compra(){
            cout<<"Liberando memoria de Compra..."<<endl;
        }
};

class Usuario {
    private:
        string nombreU;
        int dni;
        string correo;
    public:
        Usuario(string nmU, int _dni, string cr){
            this->nombreU=nmU;
            this->dni=_dni;
            this->correo=cr;
        }
        Usuario(string nmU, string cr){
            this->nombreU=nmU;
            this->dni=0;
            this->correo=cr;
        }
        Usuario(string nmU){
            this->nombreU=nmU;
            this->dni=0;
            this->correo=" ";
        }
        void setNombreU(string nmU){ nombreU = nmU; }
        void setDni(int _dni){ dni = _dni; }
        void setCorreo(string cr){ correo = cr; }
        string getNombreU(){ return nombreU; }
        int getDni(){ return dni; }
        string getCorreo(){ return correo; }
        void realizarCompra(Compra& c){
            c.carrito();
        }   
        ~Usuario(){
            cout<<"Liberando memoria de Usuario..."<<endl;
        }
};

int main() {
    Usuario u1("Alexa", 18965412, "alexa@gmail.com");
    Usuario u2("Juan");
    Usuario u3("Pedro", "pedro@gmail.com");
    Compra com1;
    u1.realizarCompra(com1);
    Compra com2;
    u2.realizarCompra(com2);
    Compra com3;
    u3.realizarCompra(com3);
    return 0;
}
