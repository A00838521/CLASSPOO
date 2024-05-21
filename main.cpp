// Incluir librerías
#include <iostream>
using namespace std;
// Declarar la clase Persona
class Persona {
    protected:
        string nombre;
        int edad;
    public:
        Persona();
        Persona(string, int);

        void muestraPersona();
        void cantar();
};

// Declarar la clase Estudiante Derivada de Persona
class Estudiante : public Persona {
    private:
        string carrera;
    public:
        Estudiante();
        Estudiante(string, int, string);

        void muestraEstudiante();
};

// Declarar la clase Maestro derivada de Persona
class Maestro : public Persona {
    private:
        string depto;
    public:
        Maestro();
        Maestro(string,int,string);
        
        void muestraMaestro();
};

//Definir los metodos de las clases segun el orden de declaracion
//Metodo de la clase Persona
Persona::Persona() { //Perteneciente a la clase persona, el metodo persona, y no recibe ningun parametro porque es un constructor por default
    nombre = "Sin nombre";
    edad = 0;
};

Persona::Persona(string _nombre, int _edad) {
    nombre = _nombre;
    edad = _edad;
}

void Persona::muestraPersona() {
    cout << endl << "Datos de la Persona: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

void Persona::cantar() {
    cout << endl << "Soy " << nombre << " y voy a cantar" << endl;
    cout << "Todo bien al cien, calma en mi pode ver" << endl;
    cout << "Y reconocer Bendiciones en mi poder" << endl;

}

// Metodo de la clase Estudiante
Estudiante::Estudiante():Persona(){
    carrera = "Sin carrera";
}

Estudiante::Estudiante(string _nombre, int _edad, string _carrera):Persona(_nombre, _edad){
    carrera = _carrera;
}

void Estudiante::muestraEstudiante(){
    cout << endl << "Datos del Estudiante: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Carrera: " << carrera << endl;
}

//Metodo de la clase Maestro
Maestro::Maestro():Persona(){
    depto = "Sin depto";
}

Maestro::Maestro(string _nombre, int _edad, string _depto):Persona(_nombre, _edad){
    depto = _depto;
}

void Maestro::muestraMaestro(){
    cout << endl << "Datos del Maestro: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Departamento: " << depto << endl;
}

//Crear objetos y manipularlos en el main
int main(){
    Persona pers1("Felipe",24), pers2("Pedro Pancho",17), pers3;
    Estudiante est1("Margarita",21,"ITC"), est2("Leon",20,"ARQ"), est3;
    Maestro maestro1("Juan",45,"Matematicas"), maestro2;

    // Mostrar Personas
    pers1.muestraPersona();
    pers2.muestraPersona();
    pers3.muestraPersona();

    // Mostrar Estudiantes
    est1.muestraEstudiante();
    est2.muestraEstudiante();
    est3.muestraEstudiante();

    // Mostrar Maestros
    maestro1.muestraMaestro();
    maestro2.muestraMaestro();

    cout << endl << "************************" << endl;

    // Mostrar un maestro como persona
    maestro1.muestraPersona();

    // Cantar
    est2.cantar();

    return 0;
};