//
// Created by Beni on 7/7/2021.
//

#ifndef E3_911_BENEDEK_ROBERTGEORGE_REPO_H
#define E3_911_BENEDEK_ROBERTGEORGE_REPO_H
#include "string"
#include "vector"
#include "fstream"
#include "../GUI/Observable.h"

using namespace std;

class Repo : public Observable {
private:
    int size;
    int a[100][100]={};
public:
    int getSize() const;

    int getMines() const;
    int getNrUsers()const;
    const vector<string> &getUsers() const;

private:
    int mines;
    vector<string> users;
public:
    Repo(){read_users();
    place_mines();
    };
    void read_users();
    void setcell(int i,int j, int val);
    int** getTable();
    void place_mines();
    int getCell(int i, int h);
    int adjacentMines(int i,int j);
};


#endif //E3_911_BENEDEK_ROBERTGEORGE_REPO_H
