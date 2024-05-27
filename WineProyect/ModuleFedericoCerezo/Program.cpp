/*
 * @author Federico Cerezo Liebing
 */

#include "Program.hpp"

int Program::getUserNameid() {
    return userNameid;
}

WineList Program::getAllWines() {
    return allwines;
}

VarietyList Program::getAllVarieties() {
    return allvarieties;
}

WineryList Program::getAllWineries() {
    return allwineries;
}
    
ProvinceList Program::getAllProvinces() {
    return allprovinces;
}
   void Program::intoduction(){
    cout << "---------------------------------------" << endl;
    cout << "WELCOME TO THE WINE MANAGEMENT PROGRAM." << endl;
    cout << "---------------------------------------" << endl;
    cout << "\nThis application is your tool for managing and exploring an extensive collection of wines." << endl;
    cout <<  "Whether you are a wine expert, or someone looking to deepen your knowledge of wines, this program offers a "<<
    "diverse collection of wine information where you can navigate through.\n\n\n";
   }
/**
 * This function searches for the ID of a variety in a given variety list by its name.
 * If the name is empty, it assigns an ID of 0. If the variety is not found in the list, it assigns a new ID based on the counter,
 * creates a new variety, adds it to the list, and increments the counter.
 *
 * @param varietyList a VarietyList object containing the varieties.
 * @param name The name of the variety to search for or add.
 * @param counter Reference to an integer used to assign new IDs to varieties.
 * @return The ID of the variety, whether it is existing or new.
 */
   int Program::loadVarietyId(VarietyList& varietyList, string name, int& counter){
    int num = varietyList.findEntityIdByName(name);
    if (name == ""){
        num = 0;
    }
    if(num == -1){
        num = counter;
        Variety variety(counter,name);
        varietyList.addEntity(variety);
        counter++;
    }
    return num;
   }
/**
 * This function does the same task as the previous one, but for Wineries.
 */
   int Program::loadWineryId(WineryList& winerylist, string name, string province,int& counter){
    int num = winerylist.findEntityIdByName(name);
    if (name == ""){
        num = 0;
    }
    if(num == -1){
        num = counter;
        Winery winery(counter,name, province);
        winerylist.addEntity(winery);
        counter++;
    }
    return num;
   }
/**
 * This function does the same task as the previous one, but for Provinces.
 */
   int Program::loadProvinceId(ProvinceList& provincelist,string nameCountry,string provinceName,string region1,string region2, int& counter1){
    int num = 0;
    for (int a =0; a < provincelist.size();a++){
            if (provincelist.getEntities()[a].getName() == provinceName && provincelist.getEntities()[a].getRegion1() == region1) {
                   num = provincelist.getEntities()[a].getId();
            }
    }
    if ((num == 0) && (provinceName != "")) {
        num = counter1;
        Province province(counter1,provinceName,nameCountry,region1,region2);
        provincelist.addEntity(province);
        counter1++;
    }
    return num; 
   }
   void Program::loadData(){
    int counter1 = 1;
    int counter2 = 1;
    int counter3 = 1;
    int idVariety, idWinery, idProvince;
   
    ifstream file("Data/wines.csv");

    if (!file.is_open()) {
        cout << "Error opening file." << endl;
    }
    else {
        cout << "\n Loading Data... Please wait.\n\n";
      string line;
      getline(file, line); 
      while (getline(file, line)) {
        
          stringstream ss(line);
          string id, country, description, province, designation, region1, region2, tasterName, tasterTwitter, title, nameVariety, nameWinery;
          int points;
          double price;
          ss.ignore();
          getline(ss, id, ','); 
          getline(ss, country, ','); 
          if (ss.peek() == '"')
          {
             ss.ignore();
             ss.ignore();
             getline(ss, description, '"');
             ss.ignore();
             ss.ignore();
          }
          else{
              getline(ss, description, ',');
          }
          getline(ss, designation, ',');
          ss >> points;
          ss.ignore();
        
          if (ss.peek() == ','){
              price = 0;
          } else{
             ss >> price;
          }
          ss.ignore();
          getline(ss, province, ',');
          getline(ss, region1, ',');
          getline(ss, region2, ',');
          getline(ss, tasterName, ',');
          getline(ss, tasterTwitter, ',');
          getline(ss, title, ',');
          getline(ss, nameVariety, ',');
          getline(ss, nameWinery,';');
          if (nameWinery.back() == '"') {
             nameWinery.pop_back();
          } 
          idVariety = loadVarietyId(allvarieties,nameVariety,counter1);
          idWinery = loadWineryId(allwineries,nameWinery, province,counter2);
          idProvince = loadProvinceId(allprovinces, country, province, region1, region2,counter3);
    
          Wine wine(id, country, description, designation, points, price, idProvince, tasterName, tasterTwitter, title, idVariety, idWinery);
          allwines.addWine(wine);
       }
       cout << "Data loaded succesfully" << endl << endl;
       file.close();
    } 
   }
   void Program::showVines(){
     cout << "ALL WINES: "<< endl<< endl;
      allwines.printWines(allvarieties,allwineries,allprovinces);
   }
/**
 * This function prints all available varieties to the console. It then asks if they want to see all wines from a specific variety. If
 * the user responds affirmatively, they are asked to provide the ID of the variety.The function then prints the name of the selected variety and 
 * all wines associated with that variety, including each wine's ID and title.
 */
   void Program::showVarieties(){
    int num;
      string answer;
      cout << "\n ALL VARIETIES: " << endl<< endl;
      allvarieties.printEntities();
      cout << "Do you want to see all wines from a variety? (Y/N)" << endl;
      cin >> answer;
      if (answer == "Y" || answer == "y"){
         cout << "Please type the Variety ID: "  << endl;
         cin >> num;
         cout << endl << "Variety: "<< allvarieties.findEntityById(num).getName() << endl << endl;
         for (int a = 0; a < allwines.size(); a++){
            if (allwines.getWines()[a].getVarietyid() == num){
                cout << "Wine " << allwines.getWines()[a].getId() << ", Title: " << allwines.getWines()[a].getTitle() << endl;
            }
         }
      }
      cout << endl;
   }
/**
 * This function does the same task as the previous one, but for Wineries.
 */
   void Program::showWineries(){
     int num;
      string answer;
      cout << "\n ALL WINERIES: " << endl<< endl;
      allwineries.printEntities();
      cout << "Do you want to see all wines from a winery? (Y/N)" << endl;
      cin >> answer;
      if (answer == "Y" || answer == "y"){
         cout << "Please type the Winery ID: "  << endl;
         cin >> num;
         cout << endl << "Winery: "<< allwineries.findEntityById(num).getName() << endl << endl;
         for (int a = 0; a < allwines.size(); a++){
            if (allwines.getWines()[a].getWineryid() == num){
                cout << "Wine " << allwines.getWines()[a].getId() << ", Title: " << allwines.getWines()[a].getTitle() << endl;
            }
         }
      }
      cout << endl;
   }
/**
 * This function does the same task as the previous one, but for Denomination Origins.
 */
   void Program::showDenominationOrigin(){
     int num;
      string answer;
      cout << "\n ALL DENOMINATION ORIGINS: " << endl<< endl;
      allprovinces.printEntities();
      cout << "Do you want to see all wines from a province? (Y/N)" << endl;
      cin >> answer;
      if (answer == "Y" || answer == "y"){
         cout << "Please type the Province ID: "  << endl;
         cin >> num;
         cout << endl << "Variety: "<< allprovinces.findEntityById(num).getName() << endl << endl;
         for (int a = 0; a < allwines.size(); a++){
            if (allwines.getWines()[a].getProvinceid() == num){
                cout << "Wine " << allwines.getWines()[a].getId() << ", Title: " << allwines.getWines()[a].getTitle() << endl;
            }
         }
      }
      cout << endl;
   }
/**
 * This function Searches for wines based on user-specified filters including minimum price, maximum price, winery ID, and variety ID. 
 * The user can skip any filter by entering 0. 
 * The function then iterates through the list of all wines and adds the wines that match the specified criteria to a
 * new WineList object, which is returned to the caller.
 *
 * @return A WineList object containing the wines that match the search.
 */
   WineList Program::wineSearch(){
    WineList wlist;
      int min, max, idWinery, idVariety;
      cout << "If you do not want to apply the filter, enter '0'";
      cout << "\nEnter the minimum price: ";
      cin >> min;
      cout << "Enter the maximum price: ";
      cin >> max;
      cout << "Enter the Winery ID: ";
      cin >> idWinery;
      cout << "Enter the Variety ID: ";
      cin >> idVariety;
      if ((max == 0) && (idWinery == 0) && (idVariety == 0)){
         for (int a = 0; a < allwines.size(); a++){
            if (min <= allwines.getWines()[a].getPrice()){
                cout << "Si";
                wlist.addWine(allwines.getWines()[a]);
            }
        }
      }else if((max != 0) && (idWinery == 0) && (idVariety == 0)){
        for (int a = 0; a < allwines.size(); a++){
            if (min <= allwines.getWines()[a].getPrice() && max >= allwines.getWines()[a].getPrice() ){
                wlist.addWine(allwines.getWines()[a]);
            }
        }

      }else if((max != 0) && (idWinery != 0) && (idVariety == 0) ){
        for (int a = 0; a < allwines.size(); a++){
            if (min <= allwines.getWines()[a].getPrice() && max >= allwines.getWines()[a].getPrice() 
              && allwines.getWines()[a].getWineryid()== idWinery){
                wlist.addWine(allwines.getWines()[a]);
            }
        }

      }else if((max != 0) && (idWinery != 0) && (idVariety != 0) ){
        for (int a = 0; a < allwines.size(); a++){
            if (min <= allwines.getWines()[a].getPrice() && max >= allwines.getWines()[a].getPrice() 
              && allwines.getWines()[a].getWineryid()== idWinery && allwines.getWines()[a].getVarietyid()== idVariety){
                wlist.addWine(allwines.getWines()[a]);
            }
        }

      }else if((max != 0) && (idWinery == 0) && (idVariety != 0)){
        for (int a = 0; a < allwines.size(); a++){
            if (min <= allwines.getWines()[a].getPrice() && max >= allwines.getWines()[a].getPrice() 
              && allwines.getWines()[a].getVarietyid()== idVariety){
                wlist.addWine(allwines.getWines()[a]);
            }
        }
      }else if((max == 0) && (idWinery != 0) && (idVariety != 0)){
        for (int a = 0; a < allwines.size(); a++){
            if (min <= allwines.getWines()[a].getPrice() && allwines.getWines()[a].getWineryid()== idWinery 
            && allwines.getWines()[a].getVarietyid()== idVariety){
                wlist.addWine(allwines.getWines()[a]);
            }
        }

      }else if((max == 0) && (idWinery == 0) && (idVariety != 0)){
        for (int a = 0; a < allwines.size(); a++){
            if (min <= allwines.getWines()[a].getPrice() && allwines.getWines()[a].getVarietyid()== idVariety){
                wlist.addWine(allwines.getWines()[a]);
            }
        }

      }else if((max == 0) && (idWinery != 0) && (idVariety == 0)){
        for (int a = 0; a < allwines.size(); a++){
            if (min <= allwines.getWines()[a].getPrice() && allwines.getWines()[a].getWineryid()== idWinery){
                wlist.addWine(allwines.getWines()[a]);
            }
        }

      }

      return wlist;
   }
/**
 * This function initiates a wine search by calling the wineSearch function. After the search, it checks if any wines were found. If no wines are found, 
 * it prints a message indicating this. Otherwise, it prints the number of wines found and displays the details of each wine by
 * calling the printWines function.
 */
   void Program::showWinesSearch(){
    WineList w2 = wineSearch();
        if(w2.size() == 0){
                cout << "No wines found" << endl;
        }else{
               cout << w2.size() << " wines have been found" << endl;
               w2.printWines(allvarieties,allwineries,allprovinces);
        }
   }
   void Program::generalinfo(){
    cout << "\n GENERAL INFORMATION:" << endl;
    cout <<"Total number of wines:" << allwines.size() << endl;
    cout <<"Total number of wineries:" << allwineries.size() << endl;
    cout <<"Total number of varieties:" << allvarieties.size() << endl;
    cout <<"Total number of provinces:" << allprovinces.size() << endl << endl;
   }
   int Program::menu(){
    int option;
    
      do{
        cout << "   MENU " << endl;
        cout << "---------------------------------------" << endl;
        cout << "  1.Show all wines" << endl;
        cout << "  2.Show wine varieties" << endl;
        cout << "  3.Show list of wineries" << endl;
        cout << "  4.Show denomination of origin wines" << endl;
        cout << "  5.Advanced search for a wine" << endl;
        cout << "  6.Show general program info" << endl;
        cout << "  7.EXIT" << endl;
        cout << "---------------------------------------" << endl;
        cout << "                                   " << endl;
        
        cin >> option;
        
        if (option > 7  || option < 1){
            cout << "Option is not valid, please choose again" << endl ;
        }

      }while (option > 7  || option < 1);
        
       return option;
    }
   