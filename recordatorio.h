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

class Recordatorio {
private:
    vector<int> fecha;
    int hora;

public:
    Recordatorio(): fecha(), hora(12) {};
    Recordatorio(vector<int> fecha): fecha(fecha), hora(12){};
    Recordatorio(vector<int> fecha, int hora): fecha(fecha), hora(hora){};

    vector<int> get_fecha() {
        return fecha;
    }

    int get_hora() {
    return hora;
   }

    void setFecha(vector<int> fecha) {
        this->fecha = fecha;
    }

    void setHora(int hora) {
        this->hora = hora;
    }
};

#endif // RECORDATORIO_H_