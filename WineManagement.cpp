#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Vino {
private:
    string id;
    string country;
    string description;
    string designation;
    int points;
    double price;
    string province;
    string region_1;
    string region_2;
    string taster_name;
    string taster_twitter_handle;
    string title;
    string variety;
    string winery;

public:
    // Constructor
    Vino(string id, string country, string description, string designation, int points, double price, string province, string region_1, string region_2, string taster_name, string taster_twitter_handle, string title, string variety, string winery) 
        : id(id), country(country), description(description), designation(designation), points(points), price(price), province(province), region_1(region_1), region_2(region_2), 
          taster_name(taster_name), taster_twitter_handle(taster_twitter_handle), title(title), variety(variety), winery(winery) {}

    // Getters para acceder a los atributos privados
    string getId() const { return id; }
    string getCountry() const { return country; }
    string getDescription() const { return description; }
    string getDesignation() const { return designation; }
    int getPoints() const { return points; }
    double getPrice() const { return price; }
    string getProvince() const { return province; }
    string getRegion1() const { return region_1; }
    string getRegion2() const { return region_2; }
    string getTasterName() const { return taster_name; }
    string getTasterTwitterHandle() const { return taster_twitter_handle; }
    string getTitle() const { return title; }
    string getVariety() const { return variety; }
    string getWinery() const { return winery; }
};

int main() {
    // Abrir el archivo CSV
    ifstream archivo("C:\\Users\\efece\\OneDrive\\Escritorio\\vinos.csv");

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    // Vector para almacenar los objetos Vino
    vector<Vino> vinos;
    int i = 0;
    // Leer el archivo línea por línea
    string linea;
    getline(archivo, linea); // Ignorar la primera línea (cabecera)
    while (getline(archivo, linea)) {
        // Crear un stringstream para dividir la línea en campos
        stringstream ss(linea);
        string id, country, description, province, designation, region_1, region_2, taster_name, taster_twitter_handle, title, variety, winery;
        int points;
        double price;
        
        // Leer los campos separados por comas
        getline(ss, id, ',');
        getline(ss, country, ','); 
        if (ss.peek() == '"')
        {
           ss.ignore();
           ss.ignore();
           getline(ss, description, '"');
           ss.ignore();
           ss.ignore();
        }//cout << "si";
        else{
            getline(ss, description, ',');
        }
        getline(ss, designation, ',');
        ss >> points;
        ss.ignore(); // Ignorar la coma
        ss >> price;
        ss.ignore(); // Ignorar la coma
        getline(ss, province, ',');
        getline(ss, region_1, ',');
        getline(ss, region_2, ',');
        getline(ss, taster_name, ',');
        getline(ss, taster_twitter_handle, ',');
        getline(ss, title, ',');
        getline(ss, variety, ',');
        getline(ss, winery);

        // Crear un objeto Vino con los datos y agregarlo al vector
        Vino vino(id, country, description, designation, points, price, province, region_1, region_2, taster_name, taster_twitter_handle, title, variety, winery);
        vinos.push_back(vino);
    }
    // Cerrar el archivo
    archivo.close();

    // Mostrar los vinos cargados (solo los primeros 10 por simplicidad)
    for (int i = 0; i < 10 && i < vinos.size(); ++i) {
        cout << "ID: " << vinos[i].getId() << ", Pais: " << vinos[i].getCountry() << ", Descripcion: " << vinos[i].getDescription() << ", Puntos: " << vinos[i].getPoints() << ", Precio: " << vinos[i].getPrice() << endl;
    }

    return 0;
}

