#ifndef LISTA_H_
#define LISTA_H_
#include <string>
#include "tarea.h"

using namespace std;

class Lista {
private:
    string nombre;
    string descripcion;
    bool status;
    vector<Tarea*> tareas;
public:
    // Constructors
    Lista() : nombre(""), descripcion(""), status(false), tareas() {};
    Lista(string nombre): nombre(nombre), descripcion(""), status(false), tareas() {};
    Lista(string nombre, string descripcion): nombre(nombre), descripcion(descripcion), status(false), tareas() {};

    // Getters
    string getNombre() { return nombre; }
    string getDescripcion()  { return descripcion; }
    bool getStatus() { return status; }
    vector<Tarea*> getTareas() {return tareas;}

    // Setters
    void setNombre(const std::string& nombre) { this->nombre = nombre; }
    void setDescripcion(const std::string& descripcion) { this->descripcion = descripcion; }
    void setStatus(bool status) { this->status = status; }
    void setTareas(vector<Tarea*> tareas) {this->tareas = tareas;}

    // Other methods
    void mostrarTareas();
    void agregarTarea(Tarea* tarea);
    void eliminarTarea(int index);
};

// Definition of moved methods
void Lista::mostrarTareas(){
    cout<<"Estas son las tareas en la lista "<<nombre<<": "<<endl;
    for (int i=0; i < tareas.size(); i++){
        cout<<"Nombre: "<<tareas[i]->get_nombre()<<endl;
        cout<<"Descripcion: "<<tareas[i]->get_descripcion()<<endl;
    }
}

void Lista::agregarTarea(Tarea* tarea){
    for (Tarea * i: tareas){
        if (i->get_nombre() == tarea->get_nombre() && i->get_descripcion() == tarea->get_descripcion()){
            cout<<"Esa tarea ya fue agregada a la lista"<<endl;
            return;
        }
    }
    this->tareas.push_back(tarea);
    cout<<"Se ha agregado la tarea "<<tarea->get_nombre()<<" a la lista"<<nombre<<endl;
}

void Lista::eliminarTarea(int index){
    if (index >= this->tareas.size()){
        cout<<"No existe una tarea en el index "<<index<<endl;
        return;
    }
    this->tareas.erase(this->tareas.begin() + index);
    cout<<"la tarea en el index "<<index<<" se ha eliminado"<<endl;
}

#endif