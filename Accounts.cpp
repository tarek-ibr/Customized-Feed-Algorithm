//
// Created by tarek on 5/9/2024.
//

#include "Accounts.h"

Accounts::Accounts(string u, string p) : username(u), password(p){}

void Accounts::setusername(string u) {
    username = u;
}

void Accounts::setpassword(string p) {
    password = p;
}

string Accounts::getusername() {
    return username;
}

string Accounts::getpassword() {
    return password;
}
