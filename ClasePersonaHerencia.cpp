//Este programa crea y manipula las clases Persona, Estudiante y Maestro
//en su relaci�n de Herencia
// A00838521 Bruno Vázquez Espinoza
// A01253750 Alejandro Uribe Moreno
// A01571663 Bruno Rivera Juáre

//Incluir librerias
#include <iostream>
using namespace std;



//Declarar las clases
//Declarar la clase Persona
class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona();
    Persona(string, int);

    void muestraPersona();

    void cantar();

    void declamar();

    //Sobrecarga del operador +
    Persona operator+(Persona);

};



//Definir los metodos de las clases segun el orden de declaracion
//Metodos de la clase Persona
Persona::Persona(){
    nombre = "Sin nombre";
    edad = 0;
}

Persona::Persona(string _nombre, int _edad){
    nombre = _nombre;
    edad = _edad;
}

void Persona::muestraPersona(){
    cout << endl << "Datos de la Persona: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

void Persona::cantar(){
    cout << endl << "Soy " << nombre << " y voy a cantar" << endl;
    cout << "Todo bien al cien, calma en mi para poder ver" << endl;
    cout << "Y reconocer Bendiciones en mi poder" << endl;
}

void Persona::declamar(){
    cout << endl << "Declamacion: " << endl;
    cout << "Vive la vida con alegria y siente toda la empatia" << endl;
}

//Sobrecarga del operador +
Persona Persona::operator+(Persona p2){
    string nombreNuevo;
    int edadNueva;

    nombreNuevo = nombre + " " + p2.nombre;
    edadNueva = edad + p2.edad;

    Persona nuevaPersona(nombreNuevo, edadNueva);

    return nuevaPersona;
}

//Crear objetos y manipularlos en el main
int main(){
    Persona pers1("Felipe",24), pers2("Pedro Pancho",17), pers3, pers4,pers5;


    //Mostrar Personas
    pers1.muestraPersona();
    pers2.muestraPersona();
    pers3.muestraPersona();

    //Sumar personas
    cout << endl << "sumando per1 y per2" << endl;
    pers4 = pers1 + pers2;
    pers4.muestraPersona();

    cout << endl << "Sumando las personas per2 y per3" << endl;
    pers5 = pers2 + pers3;
    pers5.muestraPersona();

    cout << endl << "Sumando las personas per1 per2 y per3" << endl;
    pers5 = pers1 + pers2 + pers3;
    pers5.muestraPersona();


    return 0;
}

