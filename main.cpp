#include <iostream>
#include "lista.h" // Assuming lista.h is the header file for the lista class
#include "tarea.h" 
#include "usuario.h"

int main() {
Usuario myU;

myU.crearTarea();
myU.crearLista();

myU.mostrarTareas();
myU.mostrarListas();
myU.agregarTareaLista(0, 0);

vector<Lista> myL = myU.getListas();
myL[0].mostrarTareas();


    /*
    vector<int> fecha = {2021, 12, 31};
    Tareas.push_back(new TareaTrabajo("Tarea 1", 1,  fecha)); // Use push_back to add new Tarea objects
    Tareas.push_back(new TareaPersonal("Tarea 2", 2, "casa")); // Use push_back to add new Tarea objects
    Tareas.push_back(new TareaTrabajo("Tarea 3", 3,  fecha)); // Use push_back to add new Tarea objects

    myL.agregarTarea(Tareas[1]); // Pass the address of the Tarea object
    myL.setTareas(Tareas);

    Tareas[0]->crearRecordatorio();
    
    Tareas[0]->mostrarRecordatorios(); // Change -> to .
    
    myL.agregarTarea(Tareas[0]);

    myL.agregarTarea(Tareas[1]);

    myL.agregarTarea(Tareas[2]);
    
    myL.mostrarTareas();

    myL.eliminarTarea(3);

    myL.mostrarTareas();
        //cout<<myL.getTareas()->get_nombre()<<endl;0
 
    return 0;
    */
}