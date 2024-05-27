#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


class User {
protected:
    string username;
    string password;
    string repeatpassword;
    string dateOfBirth;

public:
    virtual ~User() {}
    virtual void registrationDetails() = 0;

    void setUsername(const string& username1) {
        username = username1;
    }
    void setPassword(const string& password1) {
        password = password1;
    }
    void setDateOfBirth(const string& dateOfBirth1) {
        dateOfBirth = dateOfBirth1;
    }
    void setRepeatpassword(const string& repeatpassword1) {
        repeatpassword = repeatpassword1;
    }
};

class UserNotRegistered : public User {
public:
    void registrationDetails() override {
        cout << "Your username: ";
        cin >> username;
        setUsername(username);

        cout << "What is your date of birth (YYYY/MM/DD): ";
        cin >> dateOfBirth;
        setDateOfBirth(dateOfBirth);

        cout << "Introduce your password: ";
        cin >> password;
        setPassword(password);

        cout << "Repeat password for confirmation: ";
        cin >> repeatpassword;
        setRepeatpassword(repeatpassword);

        if (password != repeatpassword) {
            cout << "Your passwords are not the same, please try it again" << endl;
        }
        else {
            cout << "Your password is correct." << endl;
            cout << "Your registration was successfully completed" << endl;

 
            string filePath = "C:\\Users\\edela\\OneDrive\\Escritorio\\Info.txt";

            ofstream dataFile(filePath, ios::app); 
            if (dataFile.is_open()) {
                dataFile << username << ", " << dateOfBirth << ", " << password << endl;
                dataFile.close();
            }
            else {
                cout << "Not able to open Info.txt" << endl;
            }
        }
    }
};

class UserRegistered : public User {
public:
    void registrationDetails() override {
        cout << "This function is not used for registered users." << endl;
    }

    void registrationDetails( string username2,  string password2) {
        string filePath = "C:\\Users\\edela\\OneDrive\\Escritorio\\Info.txt";

        ifstream dataFile(filePath);

        bool userFound = false;

        if (dataFile.is_open()) {
            string fileUsername, fileDateOfBirth, filePassword;

            while (dataFile >> fileUsername >> fileDateOfBirth >> filePassword) {
                if (username2 == fileUsername && password2 == filePassword) {
                    userFound = true;
                    cout << "The user is: " << fileUsername << endl;
                    break;
                }
            }

            dataFile.close();

            if (!userFound) {
                cout << "The user was not found or the password is incorrect" << endl;
                return;
            }
        }
        else {
            cout << "Not able to open Info.txt" << endl;
            return;
        }

        vector<string> favourites;
        int option;

        do {
            cout << "         User Registered Menu         " << endl;
            cout << "1. List of favourites" << endl;
            cout << "2. Add new favourite to list by name" << endl;
            cout << "3. Remove favourite from list by name" << endl;
            cout << "0. Exit" << endl;
            cout << "Select an option between 0 and 3: ";
            cin >> option;

            if (option == 1) {
                cout << "List of favourites: " << endl;
                for (const auto& favourite : favourites) {
                    cout << favourite << endl;
                }
            }
            else if (option == 2) {
                string newFavourite;
                cout << "Enter the name of the new favourite: ";
                cin >> newFavourite;
                favourites.push_back(newFavourite);
                cout << "Favourite added." << endl;
            }
            else if (option == 3) {
                string favouriteToRemove;
                cout << "Enter the name: ";
                cin >> favouriteToRemove;

                auto it = std::find(favourites.begin(), favourites.end(), favouriteToRemove);
                if (it != favourites.end()) {
                    favourites.erase(it);
                    cout << "Favourite removed." << endl;
                }
                else {
                    cout << "Favourite not found." << endl;
                }
            }
            else if (option == 0) {
                cout << "Exiting the User Registered Menu." << endl;
            }
            else {
                cout << "Invalid option." << endl;
            }
        } while (option != 0);
    }
};

int main() {
    WineList allWines;
    Wine w1("", "", "", "", 10, 10, "", "", "", "", "", "", "", "");
    allWines.addWine(w1);

    UserNotRegistered userNotReg;
    UserRegistered userReg;

    userNotReg.registrationDetails();
    userReg.registrationDetails("pepe", "1234");

    return 0;
}