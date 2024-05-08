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
    int varietyid;
    string winery;

public:
    // Constructor
    Vino(string id, string country, string description, string designation, int points, double price, string province, string region_1, string region_2, string taster_name, string taster_twitter_handle, string title, int varietyid, string winery) 
        : id(id), country(country), description(description), designation(designation), points(points), price(price), province(province), region_1(region_1), region_2(region_2), 
          taster_name(taster_name), taster_twitter_handle(taster_twitter_handle), title(title), varietyid(varietyid), winery(winery) {}

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
    int getVarietyid() const { return varietyid; }
    string getWinery() const { return winery; }
};
class WineList {
private:
    vector<Vino> wines;

public:
    WineList() {}
    // Método para agregar un vino a la lista
    void addWine(const Vino& wine) {
        wines.push_back(wine);
    }

    // Método para obtener la cantidad de vinos en la lista
    int size() const {
        return wines.size();
    }

    // Método para imprimir todos los vinos en la lista
    void printWines() const {
        cout << "Lista de vinos:" << endl;
        for (int a = 0; a < size();a++){
            cout << "ID: " << wines[a].getId() << ", País: " << wines[a].getCountry() << ", Descripción: " << wines[a].getDescription() << endl;
        }
    
    }
    const vector<Vino>& getWines() const {
        return wines;
    }
};


class Variety {
private:
    int idVariety;
    string nameVariety;
    

public:
    Variety(int idVariety, const string& nameVariety) : idVariety(idVariety), nameVariety(nameVariety) {}

    // Getters para acceder a los atributos privados
    int getIdVariety() const { return idVariety; }
    string getNameVariety() const { return nameVariety; }
    
   
};

class VarietyList {
private:
    vector<Variety> varieties;

public:
    VarietyList() {}

    // Método para agregar una nueva variedad a la lista
    void addVariety(const Variety& variety) {
        varieties.push_back(variety);
    }

    // Método para obtener la cantidad de variedades en la lista
    int size() const {
        return varieties.size();
    }

    // Método para imprimir todas las variedades en la lista
    void printVarieties() const {
        cout << "Lista de variedades:" << endl;
        for (const auto& variety : varieties) {
            cout << "ID: " << variety.getIdVariety() << ", Nombre: " << variety.getNameVariety() << endl;
        }
    }

    // Método para encontrar el ID de la variedad por su nombre
    int findVarietyIdByName(const string& name) const {
        bool i = false;
        for (int a = 0; a < size();a++){
            if (varieties[a].getNameVariety() == name){
                i = true;
            }
        }

        if (i) {
            return varieties[i].getIdVariety();
        } else {
            return -1; // Si no se encuentra la variedad, devolvemos -1
        }
    }
};


int main() {
    // Abrir el archivo CSV
    ifstream archivo("C:\\Users\\efece\\OneDrive\\Escritorio\\vinos.csv");
    WineList allwines;
    VarietyList allvarieties;
    int idVariedad = 0;
    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }
    else {
    // Leer el archivo línea por línea
    string linea;
    getline(archivo, linea); // Ignorar la primera línea (cabecera)
    while (getline(archivo, linea)) {
        // Crear un stringstream para dividir la línea en campos
        stringstream ss(linea);
        string id, country, description, province, designation, region_1, region_2, taster_name, taster_twitter_handle, title, nameVariety, winery;
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
        getline(ss, nameVariety, ',');
        getline(ss, winery);

        int ab = allvarieties.findVarietyIdByName(nameVariety);
        if (ab != -1) //Si lo encuentra
        {
           Variety variety(idVariedad,nameVariety);

        } else{  //Si no lo encuentra
            ab = idVariedad;
            Variety variety(idVariedad,nameVariety);
            allvarieties.addVariety(variety);
            idVariedad++;
        }

        // Crear un objeto Vino con los datos y agregarlo al vector
        Vino vino(id, country, description, designation, points, price, province, region_1, region_2, taster_name, taster_twitter_handle, title, ab , winery);
        allwines.addWine(vino);
       
    }

    }
    
    // Cerrar el archivo
    archivo.close();
    // Mostrar los vinos cargados (solo los primeros 10 por simplicidad)
    for (int i = 0; i < 10; ++i) { //&& i < vinos.size()
        cout << "ID: " << allwines.getWines()[i].getId() << ", Pais: " << allwines.getWines()[i].getCountry() << ", Descripcion: " << allwines.getWines()[i].getDescription() << ", Puntos: " << allwines.getWines()[i].getPoints() << ", Precio: " << allwines.getWines()[i].getPrice() << endl;
    }

    return 0;
}

