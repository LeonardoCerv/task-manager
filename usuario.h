/*
 *
 * Proyecto TC1030 clase Tarea
 * Leonardo Cervantes Perez
 * A07184003
 * 12/06/2024
 * Esta clase define objeto de tipo Usuario que contiene objetos de la 
 * clase Lista y Tarea ademas permite al usuario interactuar con sus 
 * tareas y listas.
 */

#ifndef USUARIO_H_
#define USUARIO_H_
#include <string>

#include "tarea.h" // bibliotecas con mis objetos a usar.
#include "lista.h"

// Declaro la clase Usuario
class Usuario {

// Variables de instancia
private:
    string nombreUsuario;
    vector <Lista> listas;
    vector <Tarea*> tareas;

public:
    // Constructores
    Usuario() : nombreUsuario(""), listas(), tareas() {} // Constructor por default
    Usuario(string nombreUsuario): nombreUsuario(nombreUsuario), 
    listas(), tareas() {}

    // Getters
    string getNombreUsuario() {
        return nombreUsuario;
    }
    vector <Lista> getListas() {
        return listas;
    }
    vector<Tarea*> getTareasPersonal() {
        return tareas;
    }

    // Setters
    void setNombreUsuario(string nombreUsuario) {
        this->nombreUsuario = nombreUsuario;
    }
    void setListas(vector<Lista> listas) {
        this->listas = listas;
    }
    void setTareasTrabajo(vector<Tarea*> tareas) {
        this->tareas = tareas;
    }

    // Declaracion de metodos
    // Métodos relacionados a Tareas
    void mostrarTareas(); 
    void crearTarea(); 
    void eliminarTarea(int index); 
    void menuTareas();

    // Métodos relacionados a Listas
    void mostrarListas();
    void crearLista();
    void eliminarLista(int index); 
    void agregarTareaLista(int indexLista, int indexTarea); 
    void mostrarTareasLista(Lista lista); 
    void menuListas(); 

    // Otros métodos
    void menu(); 
    void cambiarNombre();
};

/**
 * mostrarListas imprime todas las listas del usuario
 *
 * utiliza el arreglo listas[] y un contador, para recorrer todo el
 * arreglo imprimiendo cada uno de los objetos de la clase Lista.
 *
 * @param
 * @return
 */
void Usuario::mostrarListas() {
    int counter = 1;
    for (Lista i:listas) {
        cout<<"estas son tus listas:"<<endl;
        cout<<"Lista "<<counter<<": "<<i.getNombre()<<endl;
    }
}

/**
 * crearListas crea una lista nueva para el usuario
 *
 * utiliza valores que ingresa el usuario y el arreglo listas[]
 * para almacenar el nuevo objeto de la clase Lista.
 *
 * @param
 * @return
 */
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

/**
 * eliminarListas elimina la lista en el index del arreglo listas[]
 *
 * utiliza el index y el arreglo listas[] para eliminar el objeto de 
 * el arreglo.
 *
 * @param int index
 * @return
 */
void Usuario::eliminarLista(int index) {
    if (index >= listas.size()) {
        cout<<"No existe una lista en el index "<<index<<endl;
        return;
    }
    listas.erase(listas.begin() + index);
    cout<<"La lista en el index "<<index<<" se ha eliminado"<<endl;
}

/**
 * mostrarTareas muestra todas las tareas del usuario
 *
 * recorre el arreglo tareas[] y muestra el nombre y la descripción 
 * de cada tarea en la consola.
 *
 * @param
 * @return
 */
void Usuario::mostrarTareas() {
    cout<<"Estas son tus tareas: "<<endl;
    for (int i=0; i < tareas.size(); i++){
        cout<<"Tarea "<<i+1<<": "<<endl;
        cout<<"Nombre: "<<tareas[i]->get_nombre()<<endl;
        cout<<"Descripcion: "<<tareas[i]->get_descripcion()<<endl;
    }
}

/**
 * crearTarea crea una nueva tarea de tipo Trabajo o Personal
 *
 * solicita al usuario el tipo de tarea (Trabajo o Personal), y luego
 * recibe los valores necesarios para crear la tarea específica.
 * Verifica si ya existe una tarea con el mismo nombre antes de 
 * agregar la nueva tarea al arreglo de tareas.
 * Si el tipo de tarea ingresado no es válido, muestra un mensaje de
 * error y vuelve a solicitar el tipo de tarea.
 *
 * @param
 * @return
 */
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

/**
 * eliminarTarea elimina la tarea en el index del arreglo tareas[]
 *
 * utiliza el index y el arreglo tareas[] para eliminar el objeto de 
 * el arreglo.
 *
 * @param int index
 * @return
 */
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

/**
 * menuTareas es el menu de tareas del usuario
 *
 * muestra las opciones de tareas (crear, eliminar, mostrar) y 
 * solicita al usuario que ingrese el número de la opción deseada.
 * Llama a los métodos correspondientes según la opción ingresada.
 * Si la opción ingresada no es válida, muestra un mensaje de error.
 * Llama a sí mismo al final para que el usuario pueda seguir
 * interactuando con el programa.
 *
 * @param
 * @return
 */
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


/**
 * agregarTareaLista agrega una tarea existente a una lista específica
 *
 * utiliza los índices proporcionados para agregar una tarea del 
 * arreglo tareas[] a una lista del arreglo listas[]. Verifica si 
 * los índices proporcionados son válidos antes de realizar la 
 * operación.
 *
 * @param int indexLista
 * @param int indexTarea
 * @return
 */
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

/**
 * mostrarTareasLista muestra las tareas de una lista específica
 *
 * recorre el arreglo de tareas de la lista y muestra el nombre y 
 * la descripción de cada tarea en la consola.
 * Verifica si las tareas de la lista existen en el arreglo tareas[]
 * antes de mostrarlas.
 *
 * @param Lista lista
 * @return
 */
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

/**
 * menuListas es el menu de listas del usuario
 *
 * muestra las opciones de listas (crear, eliminar, mostrar, agregar 
 * tarea, mostrar tareas) y solicita al usuario que ingrese el número 
 * de la opción deseada. Llama a los métodos correspondientes según 
 * la opción ingresada. Si la opción ingresada no es válida, muestra
 * un mensaje de error. Llama a sí mismo al final para que el usuario
 * pueda seguir interactuando con el programa.
 *
 * @param
 * @return
 */
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

/**
 * menu es el menu principal del usuario
 *
 * muestra las opciones de menú (tareas, listas, cambiar nombre, salir)
 * y solicita al usuario que ingrese el número de la opción deseada.
 * Llama a los métodos correspondientes según la opción ingresada.
 * Si la opción ingresada no es válida, muestra un mensaje de error.
 * Llama a sí mismo al final para que el usuario pueda seguir
 * interactuando con el programa.
 * 
 * @param
 * @return
 */

void Usuario::menu(){
    string seleccion;
    cout<<"Bienvenido "<<nombreUsuario<<endl;
    cout<<"1. Menu de tareas"<<endl;
    cout<<"2. Menu de listas"<<endl;
    cout<<"3. Cambiar nombre de usuario"<<endl;
    cout<<"4. Salir"<<endl;
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

/**
 * cambiarNombre cambia el nombre de usuario
 *
 * solicita al usuario que ingrese un nuevo nombre de usuario y 
 * actualiza el valor de la variable nombreUsuario.
 *
 * @param
 * @return
 */
void Usuario::cambiarNombre() {
    string nuevoNombre;
    cout<<"Ingrese su nuevo nombre de usuario: ";
    cin>>nuevoNombre;
    nombreUsuario = nuevoNombre;
    cout<<"Se nombre de usuario es "<<nombreUsuario<<endl;
}

#endif // USUARIO_H_