//
// Created by Beni on 7/7/2021.
//

#include <QApplication>
#include "Repository/Repo.h"
#include "GUI/Window.h"

int main (int argc, char* argv[]){
    QApplication a(argc, argv);
    Repo repo;
    vector<Window*> windows;
    int i = 0;
    vector<string> users = repo.getUsers();
    for(i = 0; i < repo.getNrUsers(); ++i){
        windows.push_back(new Window(repo,users[i],i,repo.getSize()));
        repo.addObserver(windows[i]);
        windows[i]->resize( 500,570) ;

        windows[i]->show();
    }
    return a.exec();
}