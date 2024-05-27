/*
 * @author Federico Cerezo Liebing
 */
#ifndef WINELIST_HPP
#define WINELIST_HPP

#include "Wine.hpp"
#include "Entity.hpp"
#include <iostream>
#include <vector>

using namespace std;

class WineList {
private:
    vector<Wine> wines;

public:
    void addWine(Wine wine);
    int size();
    void printWines(VarietyList v1, WineryList w1, ProvinceList p1);
    vector<Wine> getWines();
};

#endif
