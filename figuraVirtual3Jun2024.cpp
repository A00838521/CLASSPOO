// Bruno Vázquez Espinoza - A00838521

// Este programa crea y manipula objetos de las clases Figura, Cuadrado y Triangulo
// En su relacion de herencia e introduce las funciones virtuales

// Incluir las librerias
#include <iostream>
using namespace std;

// Declarar la clase Figura
class Figura {
    protected:
        int numLados;
        string colorFigura;
    public:
        Figura();
        Figura(int, string);

        virtual void muestraDatos();
        virtual void dibuja();
        virtual void calcArea();
};

// Declarar la clase Cuadrado

class Cuadrado : public Figura {
    private:
        int tamanoLado;
    public:
        Cuadrado();
        Cuadrado(int, string, int);

        void muestraDatos();
        void dibuja();
        void calcArea();
};

// Declarar la clase Triangulo

class Triangulo : public Figura {
    private:
        int base;
        int altura;
    public:
        Triangulo();
        Triangulo(int, string, int, int);

        void muestraDatos();
        void dibuja();
        void calcArea();
};

// Declarar la clase Circulo

class Circulo : public Figura {
    private:
        int radio;
    public:
        Circulo();
        Circulo(int, string, int);

        void muestraDatos();
        void dibuja();
        void calcArea();
};

// Declarar la clase Pentagono

class Pentagono : public Figura {
    private:
        int tamanoLado;
        int apotema;
    public:
        Pentagono();
        Pentagono(int, string, int, int);

        void muestraDatos();
        void dibuja();
        void calcArea();
};

// Definir los metodos de las clases segun el orden de declaracion
// Metodo de la clase Figura
Figura::Figura() {
    numLados = 0;
    colorFigura = "Sin color";
}

Figura::Figura(int _numLados, string _colorFigura) {
    numLados = _numLados;
    colorFigura = _colorFigura;
}

void Figura::muestraDatos() {
    cout << endl << "Datos de la Figura: " << endl;
    cout << "Numero de lados: " << numLados << endl;
    cout << "Color de la figura: " << colorFigura << endl;
}

void Figura::dibuja() {
    cout << endl << "****** No se puede dibujar si no sabemos que figura es ******" << endl;
}

void Figura::calcArea() {
    cout << endl << "No se puede calcular el area si no sabemos que figura es" << endl;
}

// Metodo de la clase Cuadrado
Cuadrado::Cuadrado():Figura() {
    tamanoLado = 5;
}

Cuadrado:: Cuadrado(int _numLados, string _colorFigura, int _tamanoLado):Figura(_numLados, _colorFigura) {
    tamanoLado = _tamanoLado;
}

void Cuadrado::muestraDatos() {
    cout << endl << "Datos del Cuadrado: " << endl;
    cout << "Numero de lados: " << numLados << endl;
    cout << "Color de la figura: " << colorFigura << endl;
    cout << "Tamaño del lado: " << tamanoLado << endl;
}

void Cuadrado::dibuja() {
    cout << endl << "*******" << endl;
    cout << "*******" << endl;
    cout << "*******" << endl;
    cout << "*******" << endl;
}

void Cuadrado::calcArea() {
    cout << endl << "El area del cuadrado es: " << tamanoLado * tamanoLado << endl;
}

// Metodo de la clase Triangulo
Triangulo::Triangulo():Figura() {
    base = 7;
    altura = 10;
    numLados = 3;
}

Triangulo::Triangulo(int _numLados, string _colorFigura, int _base, int _altura):Figura(_numLados, _colorFigura) {
    base = _base;
    altura = _altura;
}

void Triangulo::muestraDatos() {
    cout << endl << "Datos del Triangulo: " << endl;
    cout << "Numero de lados: " << numLados << endl;
    cout << "Color de la figura: " << colorFigura << endl;
    cout << "Base: " << base << endl;
    cout << "Altura: " << altura << endl;
}

void Triangulo::dibuja(){
    cout << endl << "*" << endl;
    cout << "**" << endl;
    cout << "***" << endl;
    cout << "****" << endl;
    cout << "*****" << endl;
}

void Triangulo::calcArea(){
    cout << endl << "El area del triangulo es: " << (base * altura)/2 << endl;
}

Circulo::Circulo():Figura(){
    radio = 1;
}

Circulo::Circulo(int _numLados, string _colorFigura, int _radio):Figura(_numLados, _colorFigura){
    radio = _radio;
}

void Circulo::muestraDatos(){
    cout << endl << "Datos del Circulo: " << endl;
    cout << "Numero de lados: " << numLados << endl;
    cout << "Color de la figura: " << colorFigura << endl;
    cout << "Radio: " << radio << endl;
}

void Circulo::dibuja(){
    cout << endl << "   O" << endl;
    cout << "  OOO" << endl;
    cout << " OOOOO" << endl;
    cout << "OOOOOOO" << endl;
    cout << " OOOOO" << endl;
    cout << "  OOO" << endl;
    cout << "   O" << endl;
}

void Circulo::calcArea(){
    cout << endl << "El area del circulo: " << (3.1415*(radio*radio)) << endl;
}

Pentagono::Pentagono():Figura(){
    tamanoLado = 1;
    apotema = 1;
}

Pentagono::Pentagono(int _numLados, string _colorFigura, int _tamanoLado, int _apotema):Figura(_numLados, _colorFigura){
    tamanoLado = _tamanoLado;
    apotema = _apotema;
}

void Pentagono::muestraDatos(){
    cout << endl << "Datos del Pentagono: " << endl;
    cout << "Numero de lados: " << numLados << endl;
    cout << "Color de la figura: " << colorFigura << endl;
    cout << "Tamaño de lado: " << tamanoLado << endl;
    cout << "Apotema: " << apotema << endl;
}

void Pentagono::dibuja(){
    cout << endl << "      *   " << endl;
    cout << "    * * * " << endl;
    cout << "  * * * * *" << endl;
    cout << "* * * * * * *" << endl;
    cout << " * * * * * *" << endl;
    cout << "  * * * * *" << endl;
}

void Pentagono::calcArea(){
    cout << "El area del pentagono es: " << ((tamanoLado*5) * apotema) /2 << endl;
}

// Crear y manipular objetos en el main

int main(){
    // Crear objetos de la clase Figura, Cuadrado y Triangulo
    Figura fig1(5,"Verde"), fig2(7,"Rosa"), fig3;
    Cuadrado cuad1(4,"Morado", 15), cuad2(4,"Celeste", 10), cuad3;
    Triangulo trian1(3,"Blanco",5,7), trian2(3,"Amarillo",3,20),trian3;
    Circulo circ1(0,"Rojo", 10), circ2(0,"Azul", 15), circ3;
    Pentagono pent1(5,"Negro", 5, 10), pent2;

    // Declarar un apuntador a objetos de la clase Figura
    Figura *ptrFigura;

    cout << endl << "ptrFigura apunta a fig1" << endl;
    ptrFigura = &fig1;
    ptrFigura->dibuja();
    ptrFigura->muestraDatos();
    ptrFigura->calcArea();

    cout << endl << "ptrFigura apunta a cuad1" << endl;
    ptrFigura = &cuad1;
    ptrFigura->dibuja();
    ptrFigura->muestraDatos();
    ptrFigura->calcArea();
    
    cout << endl << "ptrFigura apunta a trian2" << endl;
    ptrFigura = &trian2;
    ptrFigura->dibuja();
    ptrFigura->muestraDatos();
    ptrFigura->calcArea();
    
    cout << endl << "ptrFigura apunta a circ1" << endl;
    ptrFigura = &circ1;
    ptrFigura->dibuja();
    ptrFigura->muestraDatos();
    ptrFigura->calcArea();

    cout << endl << "ptrFigura apunta a pent1" << endl;
    ptrFigura = &pent1;
    ptrFigura->dibuja();
    ptrFigura->muestraDatos();
    ptrFigura->calcArea();
}