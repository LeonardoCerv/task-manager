#include <string>
#include "tarea.h"
#include "lista.h"

class Usuario {
private:
    string nombreUsuario;
    vector <Lista> listas;
    vector <Tarea> tareas;

public:
    // Constructor
    Usuario(string nombreUsuario) {
        this->nombreUsuario = nombreUsuario;
    }

    // Getters and Setters
    string getNombreUsuario() {
        return nombreUsuario;
    }

    vector <Lista> getListas() {
        return listas;
    }

    vector <Tarea> getTareas() {
        return tareas;
    }

    void setNombreUsuario(string nombreUsuario) {
        this->nombreUsuario = nombreUsuario;
    }

    void setListas(vector<Lista> listas) {
        this->listas = listas;
    }

    void setTareas(vector<Tarea> tareas) {
        this->tareas = tareas;
    }

    // Listas methods
    void mostrarListas() {
        for (Lista i:listas) {
            cout<<"estas son tus listas:"<<endl;
            cout<<i.getNombre()<<endl;
        }
    }

    void crearLista() {
        string nom;
        string des;
        cout<<"Ingrese el nombre de la lista: ";
        cin>>nom;
        cout<<"Ingrese la descripcion de la lista: ";
        cin>>des;
        Lista l(nom, des);
        listas.push_back(l);
    }

    void eliminarLista(int index) {
        listas.erase(listas.begin() + index);
    }

    // Tareas methods
    void mostrarTareas() {
        // Code to display the tareas
    }

    void crearTarea() {
        // Code to create a new tarea
    }

    void eliminarTarea() {
        // Code to delete a tarea
    }
};