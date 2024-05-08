// Modulo proyectos progra.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;



class Wine {
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
    Wine(string id, string country, string description, string designation, int points, double price, string province, string region_1, string region_2, string taster_name, string taster_twitter_handle, string title, string variety, string winery)
        : id(id), country(country), description(description), designation(designation), points(points), price(price), province(province), region_1(region_1), region_2(region_2),
        taster_name(taster_name), taster_twitter_handle(taster_twitter_handle), title(title), variety(variety), winery(winery) {}

    // Getters 
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

Wine wines (id, country, description, designation, points, province, region_1, region_2, taster_name, taster_twitter_handle, title, variety, winery);
add.wine(wines);


class Winelist {
private:
    int amount;
    vector<Wine> wines;
public:
    void addWine(Wine wine) {
        wine.push_back(wine);
    }

    Wine vino;
    void showWines() {
        for( cons &wine : wines) {
            cout << "ID: " <<  << "" << 
        
        }
    
    }
    
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
        for (const auto& wine : wines) {
            cout << "ID: " << wine.getId() << ", País: " << wine.getCountry() << ", Descripción: " << wine.getDescription() << endl;
        }
    }
    const vector<Vino>& getWines() const {
        return wines;
    }
};

class Person {
protected:
    int id;
    string name;
    string surname;

public: 
    //Constructor
    Person (int id, string name, string surname) 
        : id(id), name(name), surname(surname) {}

    
    void personInformation() {
        cout << "ID: " << id << "Name: " << name << "Surname: " << surname << endl;
    }

    
};


class taster : public Person{
private:
    WineList tastedWines;
    string twitter;

public:
    //Constructor
    Taster(int id, string name, string surname, string twitter) 
        : Person(id, name, surname) {}

    void tasterWineInformation() {
        cout << "Tasted wines: " << tastedWines << endl;
        cout << "Twitter" << twitter << endl;
    }
    
};

class User : public Person {
    WineList favouriteWines;

public:
    //Constructor
    User(int id, string name, string surname) 
        : Person(id, name, surname) {}

    void tasterWineInformation() {
        cout << "Favourite wines: " << wines << endl;
    }

};


int main()
{
    std::cout << "Hello World!\n";
}
