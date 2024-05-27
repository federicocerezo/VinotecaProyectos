/*
 * @author Federico Cerezo Liebing
 */
 
#include "Wine.hpp"

Wine:: Wine(string id, string country, string description, string designation, int points, double price, int provinceid, 
         string tasterName, string tasterTwitter, string title, int varietyid, int wineryid) 
        : id(id), country(country), description(description), designation(designation), points(points), price(price), provinceid(provinceid), 
          tasterName(tasterName), tasterTwitter(tasterTwitter), title(title), varietyid(varietyid), wineryid(wineryid) {}

Wine:: Wine() : id(""), country(""), description(""), designation(""), points(0), price(0), provinceid(0), 
tasterName(""), tasterTwitter(""), title(""), varietyid(0), wineryid(0) {}

    string Wine :: getId() const { 
        return id;
    }
    string Wine ::getCountry() const {
         return country; 
    }
    string Wine ::getDescription() const { 
        return description; 
    }
    string Wine ::getDesignation() const { 
        return designation;
    }
    int Wine ::getPoints() const { 
        return points; 
    }
    double Wine :: getPrice() const {
         return price; 
    }
    int Wine :: getProvinceid() const { 
        return provinceid;
    }
    string Wine ::getTasterName() const { 
        return tasterName;
    }
    string Wine :: getTasterTwitter() const {
         return tasterTwitter;
    }
    string Wine :: getTitle() const {
         return title;
    }
    int Wine ::getVarietyid() const { 
        return varietyid; 
    }
    int Wine ::getWineryid() const {
         return wineryid; 
    }
    void Wine :: mostrarinfo(VarietyList v1, WineryList w1, ProvinceList p1) {
       cout << "Wine " << id << endl << "Title: " << getTitle() << endl;
        if (price!= 0){
           cout << "Price: " << price << "$"<< endl;
        }
        cout << "Country: " << country << endl << "Designation: " << designation << endl << "Variety: " << v1.findEntityById(varietyid).getName() << endl
        << "Winery: " << w1.findEntityById(getWineryid()).getName() << endl<< "Province: " << p1.findEntityById(provinceid).getName()
        << endl << "Description: " << description << endl;
        if (tasterName!= "" && points!= 0){
               cout << "This wine was tasted by " << getTasterName() << " and the score is: " << getPoints() << "/100" << endl ;
        } 
        cout << endl;
    }


