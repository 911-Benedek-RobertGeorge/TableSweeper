
#include "string"
#include "vector"
#include "fstream"
#include "../GUI/Observable.h"
#pragma once
using namespace std;

class Repo : public Observable {
private:
    int size;
    int a[100][100]={};
    int discovered_Mines = 0 ;
    int mines;
    vector<string> users;
    int freq[100] = {};
    int curent = 0;
    int winner[100] = {};

public:

    int getSize() const;

    int getMines() const;
    int getNrUsers()const;
    const vector<string> &getUsers() const;

    Repo(){
        read_users();
        place_mines();
    };
    void read_users();
    void setcell(int i,int j, int val);
    int** getTable();
    void place_mines();
    int getCell(int i, int h);
    int adjacentMines(int i,int j);
    void next();
    int getCurent();
    bool discoverMine();

    void eliminate(string name);
    void add_revealed_mine();

    string get_winner();
};


