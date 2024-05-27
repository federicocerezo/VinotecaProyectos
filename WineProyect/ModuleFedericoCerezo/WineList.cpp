/*
 * @author Federico Cerezo Liebing
 */
#include "WineList.hpp"


void WineList::addWine(Wine wine) {
    wines.push_back(wine);
}


int WineList::size() {
    return wines.size();
}


void WineList::printWines(VarietyList v1, WineryList w1, ProvinceList p1) {
    int b = wines.size();
    cout << "List of wines: " << endl << endl;
    for(int a = 0; a < b; a++) {
        wines[a].mostrarinfo(v1, w1, p1);
    }
}


vector<Wine> WineList::getWines() {
    return wines;
}

