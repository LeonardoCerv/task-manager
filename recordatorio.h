/*
 *
 * Proyecto TC1030 clase Tarea
 * Leonardo Cervantes Perez
 * A07184003
 * 12/06/2024
 * Esta clase define objeto de tipo Recordatorio.
 */

#ifndef RECORDATORIO_H_
#define RECORDATORIO_H_

#include <vector>
using namespace std;

// Declaro clase Recordatorio
class Recordatorio {

// Variables de instancia
private:
    vector<int> fecha;
    int hora;

public:
    // Constructores
    Recordatorio(): fecha(), hora(12) {}; // Constructor por default
    Recordatorio(vector<int> fecha): fecha(fecha), hora(12){};
    Recordatorio(vector<int> fecha, int hora): fecha(fecha), hora(hora){};

    // Getters
    vector<int> getFecha() {
        return fecha;
    }
    int getHora() {
        return hora;
    }

    // Setters
    void setFecha(vector<int> fecha) {
        this->fecha = fecha;
    }
    void setHora(int hora) {
        this->hora = hora;
    }
};
#endif // RECORDATORIO_H_