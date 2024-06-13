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

#include "recordatorio.h"

using namespace std;

//Declaracion de clase Tarea que es abstracta
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
    Tarea(): nombre(""), prioridad(0), descripcion(""), status(false),recordatorios() {}; //constructor por omision
    Tarea(string nom, int pri): nombre(nom), prioridad(pri), descripcion(""), status(false),recordatorios() {};

    string get_nombre() {return nombre;}
    int get_prioridad() {return prioridad;}
    string get_descripcion() {return descripcion;}
    bool get_status() {return status;}
    vector<Recordatorio> get_recordatorios() {return recordatorios;}

    //setters
    void set_nombre(string nombre) {this->nombre = nombre;}
    void set_prioridad(int prioridad) {this->prioridad = prioridad;}
    void set_descripcion(string descripcion) {this->descripcion = descripcion;}
    void set_status(bool status) {this->status = status;}
    void set_recordatorios(vector<Recordatorio> recordatorios) {this->recordatorios = recordatorios;}

    void eliminarRecordatorio(int index);
    void mostrarRecordatorios();
    virtual void crearRecordatorio() = 0;
};

void Tarea::eliminarRecordatorio(int index){
      if (index >= recordatorios.size()){
        cout<<"No existe un recordatorio en el index "<<index<<endl;
        return;
      }
      recordatorios.erase(recordatorios.begin() + index);
    }
    
  void Tarea::mostrarRecordatorios(){
    cout<<"Estos son tus recordatorios: "<<endl;
    int counter = 1;
      for (Recordatorio i: recordatorios){
      vector<int>fecha = i.get_fecha();
      cout<<"Recordatorio "<<counter<<": ";
      cout<<"fecha: "<< fecha[0] << "/"<< fecha[1] << "/" << fecha[2]; 
      cout<<"   hora: "<< i.get_hora()<<endl;
      }
    }

//Declaro objeto asalariado que hereda de Empleado
class TareaTrabajo: public Tarea {

  //Variables de instancia del objeto
  private: vector<int> fechaEntrega;

  //Metodos del objeto
  public:

  TareaTrabajo(): Tarea("", 0) {};

  TareaTrabajo(string nom, int pri, vector<int> fech): Tarea(nom, pri), fechaEntrega(fech){
    string des =  "Esta es una Tarea de Trabajo prevista para el dia "+to_string(fech[0])+" del mes "+to_string(fech[1])+" del año "+to_string(fech[2]);
    set_descripcion(des);
  };

  vector<int> get_fechaEntrega() {return fechaEntrega;}
  
  void set_fechaEntrega(vector<int> fechaEntrega) {this->fechaEntrega = fechaEntrega;}

  void crearRecordatorio();
  
  //destructores
  ~TareaTrabajo() {
    cout << "Tarea de trabajo destruida" << endl;
  }

};

void TareaTrabajo::crearRecordatorio() {
  string respuesta;
  cout<<"desea utilizar la fecha de entrega de la tarea como recordatorio? (si/no)"<<endl;
  cin>>respuesta;
  if (respuesta == "si"){
    int hora;
    cout << "Ingrese la hora del recordatorio: ";
    cin >> hora;
    for (Recordatorio i: recordatorios){
      if (i.get_fecha() == fechaEntrega && i.get_hora() == hora){
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
      if (i.get_fecha() == fecha && i.get_hora() == hora){
        cout<<"Ya existe un recordatorio con esa fecha y hora"<<endl;
        return;
      }
    }
    recordatorios.push_back(Recordatorio(fecha, hora));
  }
};


//Declaro el objeto TareaPersonal que hereda de Tarea
class TareaPersonal: public Tarea {

  //Variables de instancia privadas del objeto
  private:
  string categoria;
   //Metodos del objeto
  public:

  TareaPersonal(): Tarea("", 0) {};
  TareaPersonal(string nom, int pri, string categoria): Tarea(nom, pri), categoria(categoria) {
     string des = "Esta es una Tarea Personal perteneciente a la categoria ";
    des = des+categoria;
    set_descripcion(des);
  };

  string get_categoria() {return categoria;}

  void set_categoria(string categoria) {this->categoria = categoria;}

  void crearRecordatorio();

  //destructores
  ~TareaPersonal() {
    cout << "Tarea personal destruida" << endl;
  }
};

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