/*
 *
 * Proyecto TC1030 clase Tarea
 * Leonardo Cervantes Perez
 * A07184003
 * 12/06/2024
 * Este es un proyecto para la clase TC1030 Programación Orientado a
 * Objetos. Es un programa que te permite crear tareas y listas de tareas,
 * estas tareas pueden ser de tipo personal o de trabajo. Cada tarea puede
 * tener recordatorios y cada lista puede tener tareas.
 * el proposito es poder organizar tus deberes de una forma mas ordenada.
 */

#include <iostream>

#include "lista.h" // bibliotecas con objetos de mi proyecto.
#include "tarea.h" 
#include "usuario.h"

int main() {
    Usuario myU;
    myU.cambiarNombre();
    myU.menu();
}