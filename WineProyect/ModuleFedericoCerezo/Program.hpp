/*
 * @author Federico Cerezo Liebing
 */
#ifndef Program_hpp
#define Program_hpp

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>

#include "WineList.hpp"
#include "Entity.hpp"
#include "Base.hpp"
#include "Wine.hpp"

using namespace std;

class Program{
private:
   int userNameid;
   WineList allwines;
   VarietyList allvarieties;
   WineryList allwineries;
   ProvinceList allprovinces;
public:

   Program(int userNameid) : userNameid(userNameid) {}
   int getUserNameid();
   WineList getAllWines();
   VarietyList getAllVarieties();
   WineryList getAllWineries();
   ProvinceList getAllProvinces();
   void intoduction();
   int loadVarietyId(VarietyList& varietyList, string name, int& counter);
   int loadWineryId(WineryList& winerylist, string name, string province,int& counter);
   int loadProvinceId(ProvinceList& provincelist,string nameCountry,string provinceName,string region1,string region2, int& counter1); 
   void loadData();
   void showVines();
   void showVarieties();
   void showWineries();
   void showDenominationOrigin();
   WineList wineSearch();
   void showWinesSearch();
   void generalinfo();
   int menu();
};


#endif