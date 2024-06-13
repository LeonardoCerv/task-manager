/*
 *
 * Proyecto TC1030 clase Tarea
 * Leonardo Cervantes Perez
 * A07184003
 * 12/06/2024
 * Esta clase define objeto de tipo Tarea que contiene las clases heredadas
 * TareaTrabajo y TareaPersonal.
 */

#ifndef TAREA_H_
#define TAREA_H_

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "recordatorio.h" // bibliotecas con mi objeto a usar.

using namespace std;

// Declaro clase Tarea que es abstracta
class Tarea {

  // Variables de instancia
  protected:
    string nombre;
    int prioridad ;
    string descripcion;
    bool status;
    vector<Recordatorio> recordatorios;

  public:
    //constructores
    Tarea(): nombre(""), prioridad(0), descripcion(""), status(false), 
      recordatorios() {}; //constructor por default
    Tarea(string nom, int pri): nombre(nom), prioridad(pri), descripcion(""), 
      status(false),recordatorios() {};

    // Getters
    string getNombre() {
      return nombre;
    }
    int getPrioridad() {
      return prioridad;
    }
    string getDescripcion() {
      return descripcion;
    }
    bool getStatus() {
      return status;
    }
    vector<Recordatorio> getRecordatorios() {
      return recordatorios;
    }

    // Setters
    void setNombre(string nombre) {
      this->nombre = nombre;
    }
    void setPrioridad(int prioridad) {
      this->prioridad = prioridad;
    }
    void setDescripcion(string descripcion) {
      this->descripcion = descripcion;
    }
    void setStatus(bool status) {
      this->status = status;
    }
    void setRecordatorios(vector<Recordatorio> recordatorios) {
      this->recordatorios = recordatorios;
    }

    // Metodos
    void eliminarRecordatorio(int index);
    void mostrarRecordatorios();
    virtual void crearRecordatorio() = 0;
};

/**
 * eliminarRecordatorio elimina un recordatorio en el índice dado
 *
 * utiliza el índice proporcionado para eliminar un objeto del arreglo 
 * recordatorios[]. Verifica si el índice es válido antes de realizar 
 * la operación.
 *
 * @param int index
 * @return
 */
void Tarea::eliminarRecordatorio(int index){
  if (index >= recordatorios.size()){
    cout<<"No existe un recordatorio en el index "<<index<<endl;
    return;
  }
  recordatorios.erase(recordatorios.begin() + index);
}

/**
 * mostrarRecordatorios muestra todos los recordatorios de la tarea
 *
 * recorre el arreglo recordatorios[] y muestra la fecha y hora de cada 
 * recordatorio en la consola.
 *
 * @param
 * @return
 */
void Tarea::mostrarRecordatorios(){
  cout<<"Estos son tus recordatorios: "<<endl;
  int counter = 1;
  for (Recordatorio i: recordatorios){
    vector<int>fecha = i.getFecha();
    cout<<"Recordatorio "<<counter<<": ";
    cout<<"fecha: "<< fecha[0] << "/"<< fecha[1] << "/" << fecha[2]; 
    cout<<"   hora: "<< i.getHora()<<endl;
    counter++;
  }
}

//Declaro objeto TareaTrabajo que hereda de Tarea
class TareaTrabajo: public Tarea {

  // Variables de instancia
  private: 
    vector<int> fechaEntrega;

  public:
    //constructores
    TareaTrabajo(): Tarea("", 0) {}; //constructor por default
    TareaTrabajo(string nom, int pri, vector<int> fech): Tarea(nom, pri), 
      fechaEntrega(fech){
      string des =  "Esta es una Tarea de Trabajo prevista para el dia "+
        to_string(fech[0])+" del mes "+to_string(fech[1])+" del año "+
        to_string(fech[2]);
      setDescripcion(des);
    };

    // Getters
    vector<int> getFechaEntrega() {
      return fechaEntrega;
    }
  
    // Setters
    void setFechaEntrega(vector<int> fechaEntrega) {
      this->fechaEntrega = fechaEntrega;
    }

    // Metodos
    void crearRecordatorio();
  
    // Destructores
    ~TareaTrabajo() {
      cout << "Tarea de trabajo destruida" << endl;
    }
};

/**
 * crearRecordatorio crea un nuevo recordatorio para la tarea de trabajo
 *
 * pregunta al usuario si desea utilizar la fecha de entrega de la tarea
 * como recordatorio. Si la respuesta es "si", solicita la hora del 
 * recordatorio y agrega el recordatorio si no existe uno con la misma 
 * fecha y hora. Si la respuesta es "no", solicita la fecha y hora del 
 * recordatorio y lo agrega si no existe uno con la misma fecha y hora.
 * 
 * @param
 * @return
 */
void TareaTrabajo::crearRecordatorio() {
  string respuesta;
  cout<<"desea utilizar la fecha de entrega de la tarea como recordatorio?";
  cout<<" (si/no)"<<endl;
  cin>>respuesta;
  if (respuesta == "si"){
    int hora;
    cout << "Ingrese la hora del recordatorio: ";
    cin >> hora;
    for (Recordatorio i: recordatorios){
      if (i.getFecha() == fechaEntrega && i.getHora() == hora){
        cout<<"Ya existe un recordatorio con esa fecha y hora"<<endl;
        return;
      }
    }
    recordatorios.push_back(Recordatorio(fechaEntrega, hora));
  }
  else{
    vector<int> fecha;
    int hora;
    cout << "Ingrese la fecha del recordatorio (dd/mm/aaaa): ";
    cin >> fecha[0] >> fecha[1] >> fecha[2];
    cout << "Ingrese la hora del recordatorio: ";
    cin >> hora;
    for (Recordatorio i: recordatorios){
      if (i.getFecha() == fecha && i.getHora() == hora){
        cout<<"Ya existe un recordatorio con esa fecha y hora"<<endl;
        return;
      }
    }
    recordatorios.push_back(Recordatorio(fecha, hora));
  }
};


//Declaro el objeto TareaPersonal que hereda de Tarea
class TareaPersonal: public Tarea {

  //Variables de instancia
  private:
    string categoria;

  public:
  //constructores
  TareaPersonal(): Tarea("", 0) {}; //constructor por default
  TareaPersonal(string nom, int pri, string categoria): Tarea(nom, pri), 
      categoria(categoria) {
    string des = "Esta es una Tarea Personal perteneciente a la categoria ";
    des = des+categoria;
    setDescripcion(des);
  };

  // Getters
  string getCategoria() {
    return categoria;
  }

  // Setters
  void set_categoria(string categoria) {
    this->categoria = categoria;
  }

  // Metodos
  void crearRecordatorio();

  // Destructores
  ~TareaPersonal() {
    cout << "Tarea personal destruida" << endl;
  }
};

/**
 * crearRecordatorio crea un nuevo recordatorio para la tarea personal
 *
 * solicita la fecha y hora del recordatorio y lo agrega si no existe uno 
 * con la misma fecha y hora.
 * 
 * @param
 * @return
 */
void TareaPersonal::crearRecordatorio() {
  vector<int> fecha;
  int hora;
  cout << "Ingrese la fecha del recordatorio (dd/mm/aaaa): ";
  cin >> fecha[0];
  cin >> fecha[1];
  cin >> fecha[2];
  cout << "Ingrese la hora del recordatorio: ";
  cin >> hora;
  recordatorios.push_back(Recordatorio(fecha, hora));
};

#endif // TAREA_H_