#include <iostream>
#include <string>

using namespace std;

const int MAX_CALIFICACIONES = 100; // Define el número máximo de calificaciones que un video o episodio puede tener
const int MAX_EPISODIOS = 100; // Define el número máximo de episodios que una serie puede tener
const int MAX_VIDEOS = 100; // Define el número máximo de videos que se pueden cargar

// Clase base Video
class Video {
protected:
    int id;
    string nombre;
    int duracion;
    string genero;
    int calificaciones[MAX_CALIFICACIONES];
    int numCalificaciones;

public:
    Video();
    Video(int, const string&, int, const string&);

    virtual void mostrar() const;
    void calificar(int);
    double calcularPromedio() const;
    string getGenero() const;
    double getCalificacionPromedio() const;
    string getNombre() const;
};

// Clase Pelicula que hereda de Video
class Pelicula : public Video {
public:
    Pelicula();
    Pelicula(int, const string&, int, const string&);

    void mostrar() const override;
};

// Clase Episodio
class Episodio {
    string titulo;
    int temporada;
    int calificaciones[MAX_CALIFICACIONES];
    int numCalificaciones;

public:
    Episodio();
    Episodio(const string&, int);

    void mostrar() const;
    void calificar(int);
    double calcularPromedio() const;
    int getTemporada() const;
    string getTitulo() const;
    double getCalificacionPromedio() const;
};

// Clase Serie que hereda de Video
class Serie : public Video {
    Episodio episodios[MAX_EPISODIOS];
    int numEpisodios;

public:
    Serie();
    Serie(int, const string&, int, const string&);

    void agregarEpisodio(const Episodio&);
    void mostrar() const override;
    void mostrarEpisodios(int) const;
};

// Implementación de los métodos de la clase Video
Video::Video() : id(0), nombre("Desconocido"), duracion(0), genero("Desconocido"), numCalificaciones(0) {}

Video::Video(int _id, const string& _nombre, int _duracion, const string& _genero)
    : id(_id), nombre(_nombre), duracion(_duracion), genero(_genero), numCalificaciones(0) {}

void Video::mostrar() const {
    cout << "ID: " << id << ", Nombre: " << nombre << ", Duracion: " << duracion << " min, Genero: " << genero;
    if (numCalificaciones > 0) {
        cout << ", Calificacion Promedio: " << calcularPromedio();
    }
    cout << endl;
}

void Video::calificar(int calificacion) {
    if (calificacion >= 1 && calificacion <= 5) {
        if (numCalificaciones < MAX_CALIFICACIONES) {
            calificaciones[numCalificaciones++] = calificacion;
        } else {
            cerr << "No se pueden añadir más calificaciones." << endl;
        }
    } else {
        cerr << "Calificacion invalida. Debe ser entre 1 y 5." << endl;
    }
}

double Video::calcularPromedio() const {
    if (numCalificaciones == 0) return 0.0;
    int suma = 0;
    for (int i = 0; i < numCalificaciones; ++i) suma += calificaciones[i];
    return static_cast<double>(suma) / numCalificaciones;
}

string Video::getGenero() const {
    return genero;
}

double Video::getCalificacionPromedio() const {
    return calcularPromedio();
}

string Video::getNombre() const {
    return nombre;
}

// Implementación de los métodos de la clase Pelicula
Pelicula::Pelicula() : Video() {}

Pelicula::Pelicula(int id, const string& nombre, int duracion, const string& genero)
    : Video(id, nombre, duracion, genero) {}

void Pelicula::mostrar() const {
    cout << "Pelicula - ";
    Video::mostrar();
}

// Implementación de los métodos de la clase Episodio
Episodio::Episodio() : titulo("Desconocido"), temporada(0), numCalificaciones(0) {}

Episodio::Episodio(const string& _titulo, int _temporada) : titulo(_titulo), temporada(_temporada), numCalificaciones(0) {}

void Episodio::mostrar() const {
    cout << "Titulo: " << titulo << ", Temporada: " << temporada;
    if (numCalificaciones > 0) {
        cout << ", Calificacion Promedio: " << calcularPromedio();
    }
    cout << endl;
}

void Episodio::calificar(int calificacion) {
    if (calificacion >= 1 && calificacion <= 5) {
        if (numCalificaciones < MAX_CALIFICACIONES) {
            calificaciones[numCalificaciones++] = calificacion;
        } else {
            cerr << "No se pueden añadir más calificaciones." << endl;
        }
    } else {
        cerr << "Calificacion invalida. Debe ser entre 1 y 5." << endl;
    }
}

double Episodio::calcularPromedio() const {
    if (numCalificaciones == 0) return 0.0;
    int suma = 0;
    for (int i = 0; i < numCalificaciones; ++i) suma += calificaciones[i];
    return static_cast<double>(suma) / numCalificaciones;
}

int Episodio::getTemporada() const {
    return temporada;
}

string Episodio::getTitulo() const {
    return titulo;
}

double Episodio::getCalificacionPromedio() const {
    return calcularPromedio();
}

// Implementación de los métodos de la clase Serie
Serie::Serie() : Video(), numEpisodios(0) {}

Serie::Serie(int id, const string& nombre, int duracion, const string& genero)
    : Video(id, nombre, duracion, genero), numEpisodios(0) {}

void Serie::agregarEpisodio(const Episodio& episodio) {
    if (numEpisodios < MAX_EPISODIOS) {
        episodios[numEpisodios++] = episodio;
    } else {
        cerr << "No se pueden añadir más episodios." << endl;
    }
}

void Serie::mostrar() const {
    cout << "Serie - ";
    Video::mostrar();
    for (int i = 0; i < numEpisodios; ++i) {
        episodios[i].mostrar();
    }
}

void Serie::mostrarEpisodios(int calificacionMin) const {
    cout << "Episodios con calificacion mayor o igual a " << calificacionMin << ":" << endl;
    for (int i = 0; i < numEpisodios; ++i) {
        if (episodios[i].getCalificacionPromedio() >= calificacionMin) {
            episodios[i].mostrar();
        }
    }
}

// Función del menú principal
void menu() {
    Video* videos[MAX_VIDEOS];
    int numVideos = 0;
    int opcion;

    do {
        cout << "-------------------------------------------------------------------------------------" << endl;
        cout << "\nMenu:\n";
        cout << "1. Cargar archivo de datos\n";
        cout << "2. Mostrar los videos en general con una cierta calificacion o de un cierto genero\n";
        cout << "3. Mostrar los episodios de una determinada serie con una calificacion determinada\n";
        cout << "4. Mostrar las peliculas con cierta calificacion\n";
        cout << "5. Calificar un video\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                // Limpia cualquier objeto previamente inicializado
                for (int i = 0; i < numVideos; ++i) {
                    delete videos[i];
                }
                numVideos = 0;

                // Ejemplo de inicialización de películas, series y episodios
                // Películas
                Pelicula* pelicula1 = new Pelicula(1, "Pelicula1", 120, "Accion");
                pelicula1->calificar(4);
                pelicula1->calificar(5);

                Pelicula* pelicula2 = new Pelicula(2, "Pelicula2", 90, "Comedia");
                pelicula2->calificar(3);
                pelicula2->calificar(4);

                // Episodios de una serie
                Episodio episodio1("Episodio1", 1);
                episodio1.calificar(5);
                episodio1.calificar(4);

                Episodio episodio2("Episodio2", 1);
                episodio2.calificar(3);
                episodio2.calificar(5);

                Serie* serie1 = new Serie(3, "Serie1", 30, "Drama");
                serie1->agregarEpisodio(episodio1);
                serie1->agregarEpisodio(episodio2);

                // Agregar los objetos creados al arreglo de videos
                videos[numVideos++] = pelicula1;
                videos[numVideos++] = pelicula2;
                videos[numVideos++] = serie1;

                cout << "Datos cargados exitosamente." << endl;
                break;
            }
            case 2: {
                string genero;
                int calificacionMin;
                cout << "Ingrese genero (o '*' para cualquier genero): ";
                cin >> genero;
                cout << "Ingrese calificacion minima: ";
                cin >> calificacionMin;

                for (int i = 0; i < numVideos; ++i) {
                    if ((genero == "*" || videos[i]->getGenero() == genero) && videos[i]->getCalificacionPromedio() >= calificacionMin) {
                        videos[i]->mostrar();
                    }
                }
                break;
            }
            case 3: {
                string nombreSerie;
                int calificacionMin;
                cout << "Ingrese nombre de la serie: ";
                cin >> nombreSerie;
                cout << "Ingrese calificacion minima: ";
                cin >> calificacionMin;

                for (int i = 0; i < numVideos; ++i) {
                    Serie* serie = dynamic_cast<Serie*>(videos[i]);
                    if (serie && serie->getNombre() == nombreSerie) {
                        serie->mostrarEpisodios(calificacionMin);
                    }
                }
                break;
            }
            case 4: {
                int calificacionMin;
                cout << "Ingrese calificacion minima: ";
                cin >> calificacionMin;

                for (int i = 0; i < numVideos; ++i) {
                    Pelicula* pelicula = dynamic_cast<Pelicula*>(videos[i]);
                    if (pelicula && pelicula->getCalificacionPromedio() >= calificacionMin) {
                        pelicula->mostrar();
                    }
                }
                break;
            }
            case 5: {
                string nombre;
                int calificacion;
                cout << "Ingrese el nombre del video a calificar: ";
                cin >> nombre;
                cout << "Ingrese la calificacion (1-5): ";
                cin >> calificacion;

                for (int i = 0; i < numVideos; ++i) {
                    if (videos[i]->getNombre() == nombre) {
                        videos[i]->calificar(calificacion);
                    }
                }
                break;
            }
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida, intente nuevamente.\n";
                break;
        }
    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}
