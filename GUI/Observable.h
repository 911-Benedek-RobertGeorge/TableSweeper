//
// Created by Beni on 6/22/2021.
//

//
// Created by Beni on 6/21/2021.



//
// Created by Beni on 6/20/2021.
//
#pragma once


#include <iostream>
#include <QMessageBox>
#include "vector"
#include "algorithm"
using std::vector;

class Observer
{
public:
    // functie pur abstracta pentru actualizare
    virtual void update_() = 0;
};

class Observable {

private:
    vector<Observer*> observers;
public:
    // adauga un observer in lista de observeri (raportat la obiectul observabil)
    void addObserver(Observer* o)
    {
        observers.push_back(o);
    }
    void removeObserver(Observer *obs)
    {
        auto it = std::find(observers.begin(), observers.end(), obs);
        if (it != observers.end())
            observers.erase(it);
    }
    // anunta observerii inscrisi ca a avut loc modificare
    void notify()
    {
        if (observers.size() == 0){

    std::cout << "game OVER";
        }
        for (auto &  x : observers)
            x->update_();
    }
};


