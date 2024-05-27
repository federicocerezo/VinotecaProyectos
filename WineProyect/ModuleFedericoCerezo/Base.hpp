/*
 * @author Federico Cerezo Liebing
 */
#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>


using namespace std;

class Base {
protected:
    int id;
    string name;
    
public:
    Base(int id, string name) : id(id), name(name) {}
    int getId() const;
    string getName() const;
    virtual void mostrarinfo() = 0;
};


#endif 
