/*
 * @author Federico Cerezo Liebing
 */
#include "Entity.hpp"


Winery::Winery(int id, string name, string province) : Base(id, name), province(province) {}
Winery::Winery() : Base(0, ""), province("") {}

string Winery::getProvince() const {
    return province;
}

void Winery::mostrarinfo() {
    cout << "Winery " << id << ":\nName:" << name << "\nProvince:" << province << endl << endl;
}


Variety::Variety(int id, string name) : Base(id, name) {}
Variety::Variety() : Base(0, "") {}

void Variety::mostrarinfo() {
    cout << "Variety " << id << ": \nName:" << name << endl << endl;
}


Province::Province(int id, string name, string nameCountry, string region1, string region2) 
    : Base(id, name), nameCountry(nameCountry), region1(region1), region2(region2) {}

Province::Province() : Base(0, ""), nameCountry(""), region1(""), region2("") {}

string Province::getNameCountry() const { 
    return nameCountry;
}

string Province::getRegion1() const { 
    return region1; 
}

string Province::getRegion2() const { 
    return region2; 
}

void Province::mostrarinfo() {
    if (region2 == "") {
        cout << "Province " << id << ":\nName:" << name << "\nName Country:" << nameCountry 
                  << "\nName Region1:" << region1 << endl << endl;
    } else {
        cout << "Province " << id << ":\nName:" << name << "\nName Country:" << nameCountry 
                  << "\nName Region1:" << region1 << "\nName Region2:" << region2 << endl << endl;
    }
}


void ProvinceList::printEntities() {
    int b = entities.size();
    cout << "List of provinces: " << endl << endl;
    for (int a = 0; a < b; a++) {
        entities[a].mostrarinfo();
    }
}

void ProvinceList::addEntity(Province entity) {
    entities.push_back(entity);
}


vector<Province> ProvinceList :: getEntities() {
    return entities;
}

int ProvinceList ::size() {
    return entities.size();
}

int ProvinceList ::findEntityIdByName(string name) {
    for (int a = 0; a < size(); a++) {
        if (entities[a].getName() == name) {
            return entities[a].getId();
        }
    }
    return -1; 
}

Province ProvinceList ::findEntityById(int id) {
    for (int a = 0; a < size(); a++) {
        if (entities[a].getId() == id) {
            return entities[a];
        }
    }
    return Province();
}


void VarietyList::printEntities() {
    int b = entities.size();
    cout << "List of varieties: " << endl << endl;
    for (int a = 0; a < b; a++) {
        entities[a].mostrarinfo();
    }
}

void VarietyList::addEntity(Variety entity) {
    entities.push_back(entity);
}


vector<Variety> VarietyList:: getEntities() {
    return entities;
}

int VarietyList ::size() {
    return entities.size();
}

int VarietyList ::findEntityIdByName(string name) {
    for (int a = 0; a < size(); a++) {
        if (entities[a].getName() == name) {
            return entities[a].getId();
        }
    }
    return -1; 
}

Variety VarietyList::findEntityById(int id) {
    for (int a = 0; a < size(); a++) {
        if (entities[a].getId() == id) {
            return entities[a];
        }
    }
    return Variety();
}


void WineryList::printEntities() {
    int b = entities.size();
    cout << "List of wineries: " << endl << endl;
    for (int a = 0; a < b; a++) {
        entities[a].mostrarinfo();
    }
}
void WineryList::addEntity(Winery entity) {
    entities.push_back(entity);
}


vector<Winery> WineryList:: getEntities() {
    return entities;
}

int WineryList::size() {
    return entities.size();
}

int WineryList::findEntityIdByName(string name) {
    for (int a = 0; a < size(); a++) {
        if (entities[a].getName() == name) {
            return entities[a].getId();
        }
    }
    return -1; 
}

Winery WineryList::findEntityById(int id) {
    for (int a = 0; a < size(); a++) {
        if (entities[a].getId() == id) {
            return entities[a];
        }
    }
    return Winery();
}

