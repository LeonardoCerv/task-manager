#include <string>
#include "tarea.h"
#include "lista.h"

class Usuario {
private:
    string nombreUsuario;
    vector <Lista> listas;
    vector <Tarea*> tareas;

public:
    // Constructor
    Usuario() : nombreUsuario(""), listas(), tareas() {}
    Usuario(string nombreUsuario): nombreUsuario(nombreUsuario), listas(), tareas() {}

    // Getters and Setters
    string getNombreUsuario() {return nombreUsuario;}
    vector <Lista> getListas() {return listas;}
    vector<Tarea*> getTareasPersonal() {return tareas;}

    void setNombreUsuario(string nombreUsuario) {this->nombreUsuario = nombreUsuario;}
    void setListas(vector<Lista> listas) {this->listas = listas;}
    void setTareasTrabajo(vector<Tarea*> tareas) {this->tareas = tareas;}

    // Tareas methods
    void mostrarTareas();

    void crearTarea();

    void eliminarTarea(int index);

    // Listas methods
    void mostrarListas();

    void crearLista();

    void eliminarLista(int index);

    void agregarTareaLista(int indexLista, int indexTarea);

};

// Listas methods
void Usuario::mostrarListas() {
    int counter = 1;
    for (Lista i:listas) {
        cout<<"estas son tus listas:"<<endl;
        cout<<"Lista "<<counter<<": "<<i.getNombre()<<endl;
    }
}

void Usuario::crearLista() {
    string nom;
    string des;
    cout<<"Ingrese el nombre de la lista: ";
    cin>>nom;
    cout<<"Ingrese la descripcion de la lista: ";
    cin>>des;
    Lista l(nom, des);
    for (Lista i:listas) {
        if (i.getNombre() == nom) {
            cout<<"Ya existe una lista con ese nombre"<<endl;
            return;
        }
    }
    listas.push_back(l);
}

void Usuario::eliminarLista(int index) {
    if (index >= listas.size()) {
        cout<<"No existe una lista en el index "<<index<<endl;
        return;
    }
    listas.erase(listas.begin() + index);
    cout<<"La lista en el index "<<index<<" se ha eliminado"<<endl;
}

// Tareas methods
void Usuario::mostrarTareas() {
    cout<<"Estas son tus tareas: "<<endl;
    for (int i=0; i < tareas.size(); i++){
        cout<<"Tarea "<<i+1<<": "<<endl;
        cout<<"Nombre: "<<tareas[i]->get_nombre()<<endl;
        cout<<"Descripcion: "<<tareas[i]->get_descripcion()<<endl;
    }
}


void Usuario::crearTarea() {
    string tipo;
    cout<<"Ingrese el tipo de tarea (Trabajo o Personal): ";
    cin>>tipo;
    if (tipo == "Trabajo" || tipo == "trabajo") { 
        string nom;
        int pri;
        vector<int> fecha;
        int aux = 0;
        cout<<"Ingrese el nombre de la tarea: ";
        cin>>nom;
        cout<<"Ingrese la prioridad de la tarea: ";
        cin>>pri;
        cout << "Ingrese la fecha de entrega (dd/mm/aaaa): ";
        cin>>aux;
        fecha.push_back(aux);
        cin>>aux;
        fecha.push_back(aux);
        cin>>aux;
        fecha.push_back(aux);
        for (Tarea * i: tareas){
                if (i->get_nombre() == nom){
                cout<<"Ya existe una tarea con ese nombre"<<endl;
                return;
            }
        }
        Tarea * t = new TareaTrabajo(nom, pri, fecha);
        tareas.push_back(t);
        cout<<"Se ha creado la tarea "<<tareas.back()->get_nombre()<<endl;
    } 
    else if (tipo == "Personal" || tipo == "personal") {
        string nom;
        int pri;
        string cat;  
        cout<<"Ingrese el nombre de la tarea: ";
        cin>>nom;
        cout<<"Ingrese la prioridad de la tarea: ";
        cin>>pri;
        cout << "Ingrese la categoria: ";
        cin >> cat;
        for (Tarea * i: tareas) {
            if (i->get_nombre() == nom) {
                cout<<"Ya existe una tarea con ese nombre"<<endl;
                return;
           }
        }
    tareas.push_back(new TareaPersonal(nom, pri, cat));
    cout<<"Se ha creado la tarea "<<tareas.back()->get_nombre()<<endl;
    }
    else{
        cout<<"Tipo de tarea invalido"<<endl;
        return;
    }
}


void Usuario::eliminarTarea(int index) {
    if (index >= tareas.size()) {
        cout<<"No existe una tarea en el index "<<index<<endl;
        return;
    }
    tareas.erase(tareas.begin() + index);
    cout<<"La Tarea en el index "<<index<<" se ha eliminado"<<endl;
}

void Usuario::agregarTareaLista(int indexLista, int indexTarea) {
    if (indexLista >= listas.size()) {
        cout<<"No existe una lista en el index "<<indexLista<<endl;
        return;
    }
    if (indexTarea >= tareas.size()) {
        cout<<"No existe una tarea en el index "<<indexTarea<<endl;
        return;
    }
    listas[indexLista].agregarTarea(tareas[indexTarea]);
}