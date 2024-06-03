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

    // Getters and setters for the attributes
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