#pragma once

#include <QtWidgets/QWidget>
#include "ui_laba333.h"
#include "parking.h"
#include "trueKey.h"
#include <fstream>
#include <istream>
#include "QString.h"

class Laba333 : public QWidget
{
	Q_OBJECT

public:
	Laba333(QWidget *parent = Q_NULLPTR);
public slots:
	void addNewEl();
	void getElem();
	void delElem();
	void readFilef();
	void printFilef();
	void delAll();
	void iDo1();
	void iDo2();
	void iDo3();
	void iDo4();


private:

	Parking<TrueKey, int> * _park;
	Ui::Laba333Class ui;
	TrueKey * getKey(QLineEdit * model, QLineEdit * color);
	void connections();
	void tableFulling();
	void whatAboutSize();

};
