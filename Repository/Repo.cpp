//
// Created by Beni on 7/7/2021.
//

#include <ctime>
#include "Repo.h"

void Repo::read_users() {
    ifstream file;
    file.open("../input.txt");
    string name;
    file >> this->size;
    file >> mines;
    while(file >> name){
        users.push_back(name);
    }
    file.close();
}

int Repo::getSize() const {
    return size;
}

int Repo::getMines() const {
    return mines;
}

const vector<string> &Repo::getUsers() const {
    return users;
}

int Repo::getNrUsers() const {
    return users.size();
}

void Repo::setcell(int i, int j, int val) {
    this->next();
    a[i][j] = val;
}

int** Repo::getTable() {
    return nullptr;
}

void Repo::place_mines() {
    srand(time(NULL));
    a[1][1] = 9;
    int x = rand()%size ;
    int y = rand()%size ;
    for(int i = 1; i < mines; ++i){
        while(a[x][y] != 0 ){
            x = rand()%size ;
            y = rand()%size ;
        }
        a[x][y] = 9;
    }

}

int Repo::getCell(int i,int h) {
    return a[i][h];
}

int Repo::adjacentMines(int i, int j) {
    ///for coordinate (i, j) in array[row][col]
    int count =0 ;
    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5|| a[i][j] ==6){
            count ++;
        }

    }
    i ++ ;
    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5|| a[i][j] ==6){
            count ++;
        }

    }j--;
    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5|| a[i][j] ==6){
            count ++;
        }

    }j+=2;

    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5|| a[i][j] ==6){
            count ++;
        }

    }
    i--;
    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5|| a[i][j] ==6){
            count ++;
        }

    }
    i--;
    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5|| a[i][j] ==6){
            count ++;
        }

    }
    j--;
    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5|| a[i][j] ==6){
            count ++;
        }

    }
    j--;
    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5|| a[i][j] ==6){
            count ++;
        }

    }
    i ++;
    if ((0 <= i) && (i < size) && (0 <= j) && (j < size)) {
        if (a[i][j] == 9 || a[i][j] == 5 || a[i][j] ==6){
            count ++;
        }
    }
    return count;
}

void Repo::next() {
    int nr = users.size();
    curent = (curent +1) %nr;
    while(freq[curent])
    {
        curent = (curent +1) %nr;
    }
}

int Repo::getCurent() {
    return curent;
}

bool Repo::discoverMine() {
    discovered_Mines ++;
    if(discovered_Mines < mines) return 0;
    return 1;
}

void Repo::eliminate(string name) {
    freq[curent] = 1;


}

string Repo::get_winner() {
    int maxx = 0, poz = 0;
    for(int i = 0; i < users.size(); ++i)
    {
        if(maxx < winner[i]){
            maxx = winner[i];
            poz = i;
        }
    }
    return users[poz];
}
void Repo::add_revealed_mine() {
    winner[curent] ++;
}
