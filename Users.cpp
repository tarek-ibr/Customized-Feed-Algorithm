//
// Created by tarek on 5/9/2024.
//

#include "Accounts.h"

Users::Users(string u, string pass, string pref) : Accounts(u, pass), prefrence(pref){}

void Users::setPrefrence(string p) {
    prefrence = p;
}

string Users::getPrefrence() {
    return prefrence;
}
