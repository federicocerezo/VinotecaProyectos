/*
 * @author Federico Cerezo Liebing
 */
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <vector>
#include "Base.hpp"


using namespace std;


class Winery : public Base {
private:
    string province;

public:
    Winery(int id, string name, string province);
    Winery();
    string getProvince() const;
    void mostrarinfo();
};

class Variety : public Base {
public:
    Variety(int id, string name);
    Variety();
    void mostrarinfo();
};

class Province : public Base {
private:
    string nameCountry;
    string region1;
    string region2;

public:
    Province(int id, string name, string nameCountry, string region1, string region2);
    Province();
    string getNameCountry() const;
    string getRegion1() const;
    string getRegion2() const;
    void mostrarinfo();
};

class ProvinceList {
private:
    vector<Province> entities;
public:
    void addEntity(Province province);
    vector<Province> getEntities();
    int size();
    int findEntityIdByName(string name);
    Province findEntityById(int id);
    void printEntities();
};

class VarietyList {
private:
    vector<Variety> entities;
public:
    void addEntity(Variety variety);
    vector<Variety> getEntities();
    int size();
    int findEntityIdByName(string name);
    Variety findEntityById(int id);
    void printEntities();
};

class WineryList {
private:
    vector<Winery> entities;
public:
    void addEntity(Winery winery);
    vector<Winery> getEntities();
    int size();
    int findEntityIdByName(string name);
    Winery findEntityById(int id);
    void printEntities();
};


#endif
