/*
 * @author Federico Cerezo Liebing
 */
#ifndef WINE_HPP
#define WINE_HPP

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>

#include "Entity.hpp"

using namespace std; 

class Wine {
private:
    string id;
    string country;
    string description;
    string designation;
    int points;
    double price;
    int provinceid;
    string tasterName;
    string tasterTwitter;
    string title;
    int varietyid;
    int wineryid;

public:
    Wine(string id, string country, string description, string designation, int points, double price, int provinceid, 
         string tasterName, string tasterTwitter, string title, int varietyid, int wineryid);
    Wine();
    string getId() const;
    string getCountry() const;
    string getDescription() const;
    string getDesignation() const;
    int getPoints() const;
    double getPrice() const;
    int getProvinceid() const;
    string getTasterName() const;
    string getTasterTwitter() const;
    string getTitle() const;
    int getVarietyid() const;
    int getWineryid() const;
    void mostrarinfo(VarietyList v1, WineryList w1, ProvinceList p1);
};

#endif 
