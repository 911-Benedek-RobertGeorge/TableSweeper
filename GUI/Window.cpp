//
// Created by Beni on 7/7/2021.
//

#include "Window.h"
#include "string"
#include "QHeaderView"
#include <QHeaderView>
#include <QMessageBox>

void Window::initSignals() {
    QObject::connect(this->reveal, &QPushButton::clicked, this, [this]() {
        if (location->text().toStdString().size() == 0) {
            QMessageBox::information(this, "Error!", "The location field is empty!");

        } else {
            string str = location->text().toStdString();
            int col = str[0] - 'A';
            int row = int(str[1]) - 49;
            if (row > size || col > size){
                QMessageBox::information(this, "Error!", "The location is not ok !");
                return;
            }
            //cout << row << col << endl;
            if (repo.getCell(row,col) != 0 ){
                if(repo.getCell(row,col) == 1 || repo.getCell(row,col) == 5 || repo.getCell(row,col) == 6 ){
                    QMessageBox::information(this, "Error!", "The field  already revealed !");
                    return;
                }
                if (repo.getCell(row,col) == 9  ){
                    QMessageBox::information(this, "Booooom!", "There was a bomb!");

                    repo.removeObserver(this);
                    repo.eliminate(name);
                    repo.setcell(row,col,5);
                    repo.notify();
                    this->close();
                    return;
                }
            }

            this->repo.setcell(row, col, 1);
            repo.notify();
        }

    });

    QObject::connect(this->Makrk_mine, &QPushButton::clicked, this, [this]() {
        if (location->text().toStdString().size() == 0) {
            QMessageBox::information(this, "Error!", "The location field is empty!");
            return ;
        }
        string str = location->text().toStdString();
        int col = str[0] - 'A';
        int row = int(str[1]) - 49;
        if (row > size || col > size){
            QMessageBox::information(this, "Error!", "The location is not ok !");
            return;
        }
        if(repo.getCell(row,col) == 9)
        {/// count it
            repo.add_revealed_mine();
            QMessageBox::information(this, "Good job!", "You found a bomb !");
            if (repo.discoverMine() == 1){
                string str = repo.get_winner();
                str+= " won the game !!! ";
                QMessageBox::information(this, "Good job!", QString::fromStdString(str));
                repo.close_game();
            }
            repo.setcell(row,col,6);
            repo.notify();
            return;
        }
        if(repo.getCell(row,col) == 0  ){
            QMessageBox::information(this, "Error!", "The field was empty!:(");
            repo.eliminate(this->name);
            repo.setcell(row,col,1);
            repo.notify();
            this->close();
            return ;
        }
        if(repo.getCell(row,col) == 1 || repo.getCell(row,col) == 5 || repo.getCell(row,col) == 6 )
            QMessageBox::information(this, "Error!", "The field already revealed !");

    });
}
void Window::initGUI() {
    setWindowTitle(QString::fromStdString(name));
    this->setLayout(mainLayout);

    for (int i = 0; i < size; ++i)
    {
        verHeaderList  <<   QString::fromStdString(std::to_string(i+1));
    }
    tableWidget->setVerticalHeaderLabels(verHeaderList);

    /*   for (int i = 0; i < size; ++i)
       {

           char chh = char(i) + 'A';

           string s(std::to_string(chh));
           HeaderList  <<   QString::fromStdString(s);
       }*/
    HeaderList << "A" << "B" << "C" << "D" << "E" << "F" << "G" << "H";

    tableWidget->setHorizontalHeaderLabels(HeaderList);
    init_table();
    tableWidget->horizontalHeader()->setDefaultSectionSize(50);
    tableWidget->verticalHeader()->setDefaultSectionSize(50);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    mainLayout->addWidget(tableWidget);
    mainLayout->addWidget(location);
    mainLayout->addWidget(reveal);
    mainLayout->addWidget(Makrk_mine);
    reveal->setDisabled(1);
    Makrk_mine->setDisabled(1);


}

void Window::update_() {
    if (repo.getCurent() == pozition){
        reveal->setEnabled(1);
        Makrk_mine->setEnabled(1);
    }else{
        reveal->setEnabled(0);
        Makrk_mine->setEnabled(0);
    }
    QColor c(42,142,255);
    QColor normal(17,214,155);

    QColor x(255,75,75);
    QColor marked(255,115,75);

    for(int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (repo.getCell(i,j) == 1) /// reveal
            {
                tableWidget->item(i,j)->QTableWidgetItem::setBackground(c);
                int vecini = repo.adjacentMines(i,j);

                string str =   to_string(vecini);
                tableWidget->item(i,j)->QTableWidgetItem::setText(QString::fromStdString(str));

            }
            else
            if (repo.getCell(i,j) == 5) /// mark mine
            {
                tableWidget->item(i,j)->QTableWidgetItem::setBackground(x);
                tableWidget->item(i,j)->QTableWidgetItem::setText("*");
            }
            else
            if(repo.getCell(i,j) == 6){
                tableWidget->item(i,j)->QTableWidgetItem::setBackground(marked);
                tableWidget->item(i,j)->QTableWidgetItem::setText("*");
            }
            else
                tableWidget->item(i,j)->QTableWidgetItem::setBackground(normal);//setBackgroundColor(c);


        }
    }
}

void Window::init_table() {
    QColor c(17,214,155);

    for(int i = 0; i < size; ++i){
        for (int j =0 ; j < size; ++j){
            tableWidget->setItem(i, j, new QTableWidgetItem);

            tableWidget->item(i,j)->QTableWidgetItem::setBackground(c);//setBackgroundColor(c);
        }
    }
}

void Window::set_collor() {

}

void Window::round() {
    reveal->setEnabled(1);
    Makrk_mine->setEnabled(1);
}
