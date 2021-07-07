//
// Created by Beni on 6/22/2021.
//

#ifndef E2_911_BENEDEK_ROBERTGEORGE_1_WINDOW_H
#define E2_911_BENEDEK_ROBERTGEORGE_1_WINDOW_H


#include <QLabel>
 #include <QTableView>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include <QPushButton>
#include "string"

#include "Observable.h"
#include "../Repository/Repo.h"
#include <QLineEdit>
#include <QTableWidget>


using std::string;

class Window : public QWidget , public Observer{
private:

    string name;
    int pozition;
    int size;
    Repo &repo;


    QPushButton* reveal = new QPushButton{"Reveal"};
    QPushButton* Makrk_mine = new QPushButton{"Mark Mine"};
    QTableWidget * tableWidget = new QTableWidget(size,size);
    QStringList verHeaderList;
    QStringList HeaderList;
    QLineEdit* location = new QLineEdit{};



    QVBoxLayout* mainLayout = new QVBoxLayout();
    QGridLayout* grid= new QGridLayout();



public:
    void initSignals();

    void initGUI();

    Window( Repo &repo, const string &name, int pozition, int size , QWidget *parent = Q_NULLPTR ) :
    name(name),
    repo(repo),
    pozition(pozition) ,
    size{size}{
        initGUI();
        initSignals();
    }

    void update_() override;


    int getSelectedIndex();

    void check();

    void init_table();
    void set_collor();
};


#endif //E2_911_BENEDEK_ROBERTGEORGE_1_WINDOW_H
