/*
 * @author Federico Cerezo Liebing
 */
#include "Interface.hpp"

void interface( ){
   int userNameid;

    try {
        cout << "Enter the user code (numbers only):";
        cin >> userNameid;
        if (cin.fail()) {
            throw runtime_error("The code is only integers");
        }
       
    Program p1(userNameid);
    p1.intoduction();
    p1.loadData();
    int num;
    do{ 
        num = p1.menu();
        switch (num){
        case 1:
            p1.showVines();
            break;
        case 2:
            p1.showVarieties();
            break;
        case 3:
            p1.showWineries();
            break;
        case 4:
            p1.showDenominationOrigin();
            break;
        case 5:
            p1.showWinesSearch();
            break;
        case 6:
            p1.generalinfo();
            break;
        case 7:
            cout << "Program exit with success" << endl;
            break;
        }
       
    }while (num != 7);
    } catch (const exception& e) {
        cout << "An error has occurred"<< endl;
    } 
}