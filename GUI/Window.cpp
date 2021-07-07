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
            QMessageBox::information(this, "Error!", "The description field is empty!");

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
                QMessageBox::information(this, "Error!", "The  field is not empty!");
                if (repo.getCell(row,col) == 9  ){
                    repo.removeObserver(this);
                    this->close();
                    repo.setcell(row,col,5);
                    repo.notify();
                    return;
                }
            }

            this->repo.setcell(row, col, 1);
            repo.notify();
        }

    });

    QObject::connect(this->Makrk_mine, &QPushButton::clicked, this, [this]() {
        if (location->text().toStdString().size() == 0) {
            QMessageBox::information(this, "Error!", "The description field is empty!");
            return ;
        }
        string str = location->text().toStdString();
        int col = str[0] - 'A';
        int row = int(str[1]) - 49;
        if (row > size || col > size){
            QMessageBox::information(this, "Error!", "The location is not ok !");
            return;
        }
        repo.setcell(row,col,5);
        repo.notify();
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



}

void Window::update_() {
    QColor c(42,142,255);
    QColor normal(17,214,155);

    QColor x(255,75,75);

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
