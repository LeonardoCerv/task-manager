/*
 *
 * Proyecto TC1030 clase Tarea
 * Leonardo Cervantes Perez
 * A07184003
 * 12/06/2024
 * Esta clase define objeto de tipo Lista que contiene objetos de clase Tarea.
 */

#ifndef LISTA_H_
#define LISTA_H_
#include <string>

#include "tarea.h" // bibliotecas con mi objeto a usar.

using namespace std;

// Declaro la clase Usuario
class Lista {

// Variables de instancia
  private:
    string nombre;
    string descripcion;
    bool status;
    vector<Tarea*> tareas;

  public:
    // Constructores
    Lista() : nombre(""), descripcion(""), status(false), tareas() {}; // Constructor por default
    Lista(string nombre): nombre(nombre), descripcion(""), status(false), tareas() {};
    Lista(string nombre, string descripcion): nombre(nombre), descripcion(descripcion), 
    status(false), tareas() {};

    // Getters
    string getNombre() {
        return nombre; 
    }
    string getDescripcion()  { 
        return descripcion; 
    }
    bool getStatus() { 
        return status; 
    }
    vector<Tarea*> getTareas() {
        return tareas;
    }

    // Setters
    void setNombre(const std::string& nombre) { 
        this->nombre = nombre; 
    }
    void setDescripcion(const std::string& descripcion) { 
        this->descripcion = descripcion; 
    }
    void setStatus(bool status) { 
        this->status = status; 
    }
    void setTareas(vector<Tarea*> tareas) {
        this->tareas = tareas;
    }

    // Metodos
    void mostrarTareas();
    void agregarTarea(Tarea* tarea);
    void eliminarTarea(int index);

};

/**
 * mostrarTareas muestra todas las tareas de la lista
 *
 * recorre el arreglo tareas[] y muestra el nombre y la descripción 
 * de cada tarea en la consola.
 *
 * @param
 * @return
 */
void Lista::mostrarTareas(){
    cout<<"Estas son las tareas en la lista "<<nombre<<": "<<endl;
    for (int i=0; i < tareas.size(); i++){
        cout<<"Nombre: "<<tareas[i]->getNombre()<<endl;
        cout<<"Descripcion: "<<tareas[i]->getDescripcion()<<endl;
    }
}

/**
 * agregarTarea agrega una tarea a la lista
 *
 * recorre el arreglo tareas[] y verifica si la tarea ya existe en la lista
 * si no existe la agrega al final del arreglo.
 *
 * @param Tarea* tarea
 * @return
 */
void Lista::agregarTarea(Tarea* tarea){
    for (Tarea * i: tareas){
        if (i->getNombre() == tarea->getNombre() && i->getDescripcion() == tarea->getDescripcion()){
            cout<<"Esa tarea ya fue agregada a la lista"<<endl;
            return;
        }
    }
    this->tareas.push_back(tarea);
    cout<<"Se ha agregado la tarea "<<tareas.back()->getNombre()<<" a la lista "<<nombre<<endl;
}

/**
 * eliminarTarea elimina una tarea de la lista
 *
 * recorre el arreglo tareas[] y verifica si la tarea existe en la lista
 * si existe la elimina del arreglo.
 *
 * @param int index
 * @return
 */
void Lista::eliminarTarea(int index){
    if (index >= this->tareas.size()){
        cout<<"No existe una tarea en el index "<<index<<endl;
        return;
    }
    this->tareas.erase(this->tareas.begin() + index);
    cout<<"la tarea en el index "<<index<<" se ha eliminado"<<endl;
}

#endif // LISTA_H_