#ifndef TAREA_H_
#define TAREA_H_

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "recordatorio.h"

using namespace std;

//Declaracion de clase empleado que es abstracta
class Tarea {

  //Declaro variables de instancia
  protected:
  string nombre;
  int prioridad ;
  string descripcion;
  bool status;
  vector<Recordatorio> recordatorios;

  //Declaro los métodos que va a tener el objeto
  public:
    Tarea(): nombre(""), prioridad(0), descripcion(""), status(false),recordatorios({}) {}; //constructor por omision
    Tarea(string nom, int pri,  string des): nombre(nom), prioridad(pri), descripcion(des), status(false),recordatorios({}) {};
    Tarea(string nom, int pri,  string des, vector<int> fechaEntrega): 
    nombre(nom), prioridad(pri), descripcion(des), status(false), recordatorios({Recordatorio(fechaEntrega)}){};

    string get_nombre() {
      return nombre;
    }

    int get_prioridad() {
      return prioridad;
    }

    string get_descripcion() {
      return descripcion;
    }

    bool get_status() {
      return status;
    }

    vector<Recordatorio> get_recordatorios() {
      return recordatorios;
    }

  virtual string mostrarRecordatorios() = 0; //método abstracto será sobreescrito
  virtual Recordatorio crearRecordatorio() = 0;
  virtual Recordatorio eliminarRecordatorio() = 0;
};

//Declaro objeto asalariado que hereda de Empleado
class TareaTrabajo: public Tarea {

  //Variables de instancia del objeto
  private: vector<int> fechaEntrega;

  //Metodos del objeto
  public:

  TareaTrabajo(): Tarea("", 0, "") {};
  TareaTrabajo(string nom, int pri, vector<int> fechaEntrega): Tarea(nom, pri, "Esta es una Tarea de Trabajo", fechaEntrega)
  , fechaEntrega(fechaEntrega) {};

  string get_nombre() {
    return nombre;
  }

  int get_prioridad() {
    return prioridad;
  }

  vector<int> get_fechaEntrega() {
    return fechaEntrega;
  }

  string mostrarRecordatorios() {
  }
};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string TareaTrabajo::mostrarRecordatorios() {
  stringstream aux, aux2;
  int i=0;
  for (auto x: recordatorios){
    vector<int> fecha = x.get_fecha();
    aux2 << fecha[0] << "/"<< fecha[1] << "/" << fecha[2] << "/";
  }
  string fecha = aux2.str();
  aux << "numero de recordatorio es " << i << " fecha " << fecha << "su hora es " << recordatorios[i].get_hora() << "\n";
  return aux.str();
};

//Declaro el objet Practicante que hereda de Empleado
class TareaPersonal: public Tarea {

  //Variables de instancia privadas del objeto
  private:
  string categoria;

   //Metodos del objeto
  public:

  TareaPersonal(): Tarea("", 0, "") {};
  TareaPersonal(string nom, int pri, string categoria): Tarea(nom, pri, "Esta es una Tarea de Trabajo")
  , categoria(categoria) {};

  string get_nombre() {
    return nombre;
  }

  int get_prioridad() {
    return prioridad;
  }

  string get_categoria() {
    return categoria;
  }

  string mostrarRecordatorios() {
    
  }
};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string TareaPersonal::mostrarRecordatorios() {
  stringstream aux, aux2;
  int i=0;
  for (auto x: recordatorios){
    vector<int> fecha = x.get_fecha();
    aux2 << fecha[0] << "/"<< fecha[1] << "/" << fecha[2] << "/";
  }
  string fecha = aux2.str();
  aux << "numero de recordatorio es " << i << " fecha " << fecha << "su hora es " << recordatorios[i].get_hora() << "\n";
  return aux.str();
};

#endif // TAREA_H_