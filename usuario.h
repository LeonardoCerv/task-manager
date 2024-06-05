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

    void menuTareas();

    // Listas methods
    void mostrarListas();

    void crearLista();

    void eliminarLista(int index);

    void agregarTareaLista(int indexLista, int indexTarea);

    void mostrarTareasLista(Lista lista);

    void menuListas();

    // Otros metodos

    void menu();

    void cambiarNombre();
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
    cout<<"Se ha creado la lista "<<listas.back().getNombre()<<endl;
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
        crearTarea();
    }
}

void Usuario::eliminarTarea(int index) {
    if (index >= tareas.size()) {
        cout<<"No existe una tarea en el index "<<index<<endl;
        return;
    }
    tareas.erase(tareas.begin() + index);
    //delete tareas[index];
    //tareas[index]->~Tarea();
    cout<<"La Tarea en el index "<<index<<" se ha eliminado"<<endl;
}

void Usuario::menuTareas() {
    string seleccion;
    cout<<"Bienvenido a tu menu de tareas"<<endl;
    cout<<"1. Crear tarea"<<endl;
    cout<<"2. Eliminar tarea"<<endl;
    cout<<"3. Mostrar tareas"<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"Ingrese el numero de la opcion que desea realizar: ";
    cin>>seleccion;
    if (seleccion == "1") {
        crearTarea();
    }
    else if (seleccion == "2") {
        int index;
        cout<<"Ingrese el numero de la tarea que desea eliminar: ";
        cin>>index;
        eliminarTarea(index-1);
    }
    else if (seleccion == "3") {
        mostrarTareas();
    }
    else if (seleccion == "4") {
        return;
    }
    else {
        cout<<"Opcion invalida"<<endl;
    }
    menuTareas();
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

void Usuario::mostrarTareasLista(Lista lista) {
    int counter = 0;
    bool valid = false;
    for (Tarea * j: lista.getTareas()){
        for (int i = 0; i < tareas.size(); i++){
            if (tareas[i]->get_nombre() == j->get_nombre() && tareas[i]->get_descripcion() == j->get_descripcion()){
                valid = true;
            }
        }
        if (!valid){
            cout<<"La tarea "<<j->get_nombre()<<" no existe en la lista de tareas"<<endl;
            lista.eliminarTarea(counter);
            continue;
        }
        counter++;
    }


    cout<<"Estas son las tareas de la lista: "<<lista.getNombre()<<endl;
    for (Tarea * i: lista.getTareas()) {
        cout<<"Nombre: "<<i->get_nombre()<<endl;
        cout<<"Descripcion: "<<i->get_descripcion()<<endl;
    }
}

void Usuario::menuListas(){
    string seleccion;
    cout<<"Bienvenido a tu menu de listas"<<endl;
    cout<<"1. Crear lista"<<endl;
    cout<<"2. Eliminar lista"<<endl;
    cout<<"3. Mostrar listas"<<endl;
    cout<<"4. Agregar tarea a lista"<<endl;
    cout<<"5. Mostrar tareas de la lista"<<endl;
    cout<<"6. Salir"<<endl;
    cout<<"Ingrese el numero de la opcion que desea realizar: ";
    cin>>seleccion;
    if (seleccion == "1") {
        crearLista();
    }
    else if (seleccion == "2") {
        int index;
        cout<<"Ingrese el numero de la lista que desea eliminar: ";
        cin>>index;
        eliminarLista(index-1);
    }
    else if (seleccion == "3") {
        mostrarListas();
    }
    else if (seleccion == "4") {
        int indexLista;
        int indexTarea;
        cout<<"Ingrese el numero de la lista a la que desea agregar la tarea: ";
        cin>>indexLista;
        cout<<"Ingrese el numero de la tarea que desea agregar: ";
        cin>>indexTarea;
        agregarTareaLista(indexLista-1, indexTarea-1);
    }
    else if (seleccion == "5") {
        int index;
        cout<<"Ingrese el numero de la lista que desea ver: ";
        cin>>index;
        mostrarTareasLista(listas[index-1]);
    }
    else if (seleccion == "6") {
        return;
    }
    else {
        cout<<"Opcion invalida"<<endl;
    }
    menuListas();
}

void Usuario::menu(){
    string seleccion;
    cout<<"Bienvenido "<<nombreUsuario<<endl;
    cout<<"1. Menu de tareas"<<endl;
    cout<<"2. Menu de listas"<<endl;
    cout<<"3. Cambiar nombre de usuario"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Ingrese el numero de la opcion que desea realizar: ";
    cin>>seleccion;
    if (seleccion == "1") {
        menuTareas();
    }
    else if (seleccion == "2") {
        menuListas();
    }
    else if (seleccion == "3") {
        cambiarNombre();
    }
    else if (seleccion == "4") {
        return;
    }
    else {
        cout<<"Opcion invalida"<<endl;
    }
    menu();
}

void Usuario::cambiarNombre() {
    string nuevoNombre;
    cout<<"Ingrese su nuevo nombre de usuario: ";
    cin>>nuevoNombre;
    nombreUsuario = nuevoNombre;
    cout<<"Se nombre de usuario es "<<nombreUsuario<<endl;
}