// Incluir librerias
#include <iostream>
#include <string>
using namespace std;

// Declarar la clase Persona
class Persona {
    protected:
        string nombre;
        int edad;
    public:
        Persona();
        Persona(string, int);

        virtual void muestraDatos(); // Virtual le dice al compilador que las clases derivadas tendran su propio muestraDatos
        // Y que aun que el apuntador sea de la clase Padre, el metodo se comporte de acuerdo a su clase
        virtual void cantar();
};

// Declarar la clase Alumno Derivada de Persona
class Alumno : public Persona {
    private:
        string carrera;
    public:
        Alumno();
        Alumno(string, int, string);

        void muestraDatos();
        void cantar();
};

// Declarar la clase Maestro derivada de Persona
class Maestro : public Persona {
    private:
        string depto;
    public:
        Maestro();
        Maestro(string, int, string);

        void muestraDatos();
        void cantar();
};

// Definir los metodos de las clases segun el orden de declaracion
// Metodo de la clase Persona
Persona::Persona() {
    nombre = "Pancho Pantera";
    edad = 18;
};

Persona::Persona(string _nombre, int _edad) {
    nombre = _nombre;
    edad = _edad;
}

void Persona::muestraDatos() {
    cout << endl << "Datos de la Persona: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}

void Persona::cantar() {
    cout << endl << "Soy " << nombre << " y voy a cantar" << endl;
    cout << endl << "Ay ay ay ay canta y no llores" << endl;
    cout << "Porque cantando se alegran cielito lindo los corazones" << endl;
}

// Metodo de la clase Alumno
Alumno::Alumno():Persona() {
    carrera = "ITC";
}

Alumno::Alumno(string _nombre, int _edad, string _carrera):Persona(_nombre, _edad) {
    carrera = _carrera;
}

void Alumno::muestraDatos() {
    cout << endl << "Datos del Alumno: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;   
    cout << "Carrera: " << carrera << endl;
}

void Alumno::cantar() {
    cout << endl << "YES YESSS YESSSS" << endl;
    cout << "Soy " << nombre << " y voy a cantar" << endl;
    cout << "Los borregos" << endl;
}

// Metodo de la clase Maestro
Maestro::Maestro():Persona() {
    depto = "Matematicas";
}

Maestro::Maestro(string _nombre, int _edad, string _depto):Persona(_nombre, _edad) {
    depto = _depto;
}

void Maestro::muestraDatos() {
    cout << endl << "Datos del Maestro: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Depto: " << depto << endl;
}

void Maestro::cantar() {
    cout << endl << "Soy " << nombre << " y cantare optimista" << endl;
    cout << "Todo bien al cien" << endl;
    cout << "Calma en mi para poder ver" << endl;
    cout << "Y reconocer" << endl;
    cout << "Bendiciones en mi poder" << endl;
}

int main() {
    Persona per1("Alicia",28),per2("Pedro",25),per3;
    Persona *ptrPers; // ptrPers es un apuntador a un objeto de la clase Persona

    Alumno alumno1("Carolina",19,"IFI"), alumno2("Kevin",21,"IMT"), alumno3;
    Alumno *ptrAlum; // ptrAlum es un apuntador a un objeto de la clase Alumno

    Maestro maestro1("Juan",50,"Matematicas"), maestro2("Perla",45,"Negocios"), maestro3;
    Maestro *ptrMaestro; // ptrMaes es un apuntador a un objeto de la clase Maestro

    // ptrPers apuntara a la direccion en RAM en donde esta almacenado el objeto per1
    ptrPers = &per1;

    // Llamada a los metodos de la clase Persona
    ptrPers->muestraDatos();
    
    cout << endl << "ptrPers apuntara al alumno1" << endl;
    ptrPers = &alumno1; // Actuara como persona
    ptrPers->muestraDatos();
    ptrPers->cantar();
    
    cout << endl << "ptrPers apuntara al alumno2" << endl;
    ptrPers = &alumno2; // Actuara como persona
    ptrPers->muestraDatos();
    ptrPers->cantar();

    cout << endl << "ptrPers apuntara al maestro1" << endl;
    ptrPers = &maestro1; // Actuara como persona
    ptrPers->muestraDatos();
    ptrPers->cantar();


    return 0;
}