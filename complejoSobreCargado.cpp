// Creando la clase Complejo y SobreCargando Operadores
// A00838521 Bruno Vázquez Espinoza
// A01253750 Alejandro Uribe Moreno
// A01571663 Bruno Rivera Juárez

// Incluir las librerias
#include <iostream>
using namespace std;

// Declarar la clase complejo
class Complejo{
    private:
        int real;
        int imaginaria;
    public:
        Complejo();
        Complejo(int, int);

        void muestraComplejo();

        Complejo operator+(Complejo); // Declaramos la sobrecarga del operadoor + en Complejo
        Complejo operator-(Complejo); // Declaramos la sobrecarga del operadoor - en Complejo
};

// Definir sus metodos
Complejo::Complejo(){
    real = 1;
    imaginaria = 1;
}

Complejo::Complejo(int _real, int _imaginaria){
    real = _real;
    imaginaria = _imaginaria;
}

void Complejo::muestraComplejo(){
    cout << real << " + " << imaginaria << "i" << endl;
}

Complejo Complejo::operator+(Complejo c2){
    int realNueva;
    int imaginariaNueva;

    realNueva = real + c2.real;
    imaginariaNueva = imaginaria + c2.imaginaria;

    Complejo nuevo(realNueva, imaginariaNueva);

    return nuevo;
}

Complejo Complejo::operator-(Complejo c2){
    int realNueva;
    int imaginariaNueva;

    realNueva = real - c2.real;
    imaginariaNueva = imaginaria - c2.imaginaria;

    Complejo nuevo(realNueva, imaginariaNueva);

    return nuevo;
}

// Crear objetos y manipularlos en el main
int main(){
    // Crear o instanciar objetos de la clase complejo
    Complejo a(3, 7), b(2,10), c(1,15), d, e;

    // Mostrar los complejos
    a.muestraComplejo();
    b.muestraComplejo();
    c.muestraComplejo();
    d.muestraComplejo();
    e.muestraComplejo();

    // Sumar los complejos
    cout << endl << "Sumando d = a + b " << endl;
    d = a + b;
    d.muestraComplejo();

    cout << endl << "Sumando e = b + c " << endl;
    e = b + c;
    e.muestraComplejo();

    cout << endl << "********  Sumando e = a + b + c + d " << endl;
    e = a + b + c + d;
    e.muestraComplejo();

    // Restar los complejos
    cout << endl << "Restando d = a - b " << endl;
    d = a - b;
    d.muestraComplejo();

    cout << endl << "Restando e = b - c " << endl;
    e = b - c;
    e.muestraComplejo();

    cout << endl << "********  Restando e = a - b - c - d " << endl;
    e = a - b - c - d;
    e.muestraComplejo();

    return 0;
}