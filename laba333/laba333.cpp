#include "stdafx.h"
#include "laba333.h"

bool fileIsExist(const std::string & filePath);

Laba333::Laba333(QWidget *parent)
	: QWidget(parent)
{
	
	ui.setupUi(this);
	_park = new Parking<TrueKey, int>;
	connections();

	whatAboutSize();

	ui.add->setVisible(false);
	ui.get->setVisible(false);
	ui.files->setVisible(false);
	ui.tableWidget->setVisible(false);

	readFilef();
}

TrueKey * Laba333::getKey(QLineEdit * model, QLineEdit * color) {
	TrueKey * tempKey = new TrueKey(model->text(), color->text());
	return tempKey;
}

void Laba333::addNewEl() {
	TrueKey * key = getKey(ui.modelAdd, ui.colorAdd);
	bool ok1;
	int zn = (ui.znAdd->text()).toInt(&ok1);
	if (ok1 && key->isExist()) {
		ui.modelAdd->clear();
		ui.colorAdd->clear();
		ui.znAdd->clear();
		_park->addEl(key, zn);
	}
	delete key;
}

void Laba333::getElem() {
	TrueKey * key = getKey(ui.modelGet, ui.colorGet);
	if (_park->checkKey(*key)) {
		ui.znGet->setText(QString::number((*_park)[*key]));
	}
	else
		ui.znGet->setText("NULL");
}

void Laba333::delElem() {
	TrueKey * key = getKey(ui.modelGet, ui.colorGet);
	if (_park->checkKey(*key)) {
		_park->deleteEl(*key);
		ui.modelGet->clear();
		ui.colorGet->clear();
		ui.znGet->clear();
	}
}

void Laba333::readFilef(){
	if (fileIsExist((ui.nameFiles->text()).toStdString())) {
		std::ifstream fin;
		fin.open((ui.nameFiles->text()).toStdString());
		_park->deleteAll();
		fin >> *_park;
		fin.close();
		ui.nameFiles->clear();
	}
}

void Laba333::printFilef() {
	std::ofstream fout;
	fout.open((ui.nameFiles->text()).toStdString());
	fout << *_park;
	fout.close();
	ui.nameFiles->clear();
}

void Laba333::delAll() {
	_park->deleteAll();
}

void Laba333::iDo1() {
	if (ui.add->isVisible()) {
		ui.add->setVisible(false);
		setFixedSize(230, 210);
	}
	else {
		ui.add->setVisible(true);
		ui.get->setVisible(false);
		ui.files->setVisible(false);
		ui.tableWidget->setVisible(false);
		setFixedSize(460, 210);
	}
}

void Laba333::iDo2() {
	if (ui.get->isVisible()) {
		ui.get->setVisible(false);
		setFixedSize(230, 210);
	}
	else {
		ui.add->setVisible(false);
		ui.get->setVisible(true);
		ui.files->setVisible(false);
		ui.tableWidget->setVisible(false);
		setFixedSize(460, 210);
	}
}

void Laba333::iDo3() {
	if (ui.files->isVisible()) {
		ui.files->setVisible(false);
		setFixedSize(230, 210);
	}
	else {
		ui.add->setVisible(false);
		ui.get->setVisible(false);
		ui.files->setVisible(true);
		ui.tableWidget->setVisible(false);
		setFixedSize(460, 210);
	}
}

void Laba333::iDo4() {
	if (ui.tableWidget->isVisible()) {
		ui.tableWidget->setVisible(false);
		setFixedSize(230, 210);
	}
	else {
		ui.add->setVisible(false);
		ui.get->setVisible(false);
		ui.files->setVisible(false);
		ui.tableWidget->setVisible(true);
		setFixedSize(690, 210);
		tableFulling();
	}
}

void Laba333::whatAboutSize() {
	
	ui.menu->setGeometry(10, 10, 210, 190);
	ui.add->setGeometry(230, 10, 220, 190);
	ui.get->setGeometry(230, 10, 220, 190);
	ui.files->setGeometry(230, 10, 220, 190);
	ui.tableWidget->setGeometry(230, 10, 450, 190);
	move(200,200);
	setFixedSize(230, 210);

	ui.tableWidget->setColumnWidth(0, ui.tableWidget->width()*0.307);
	ui.tableWidget->setColumnWidth(1, ui.tableWidget->width()*0.31);
	ui.tableWidget->setColumnWidth(2, ui.tableWidget->width()*0.31);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

	
}

void Laba333::connections() {
	connect(ui.addAdd, SIGNAL(clicked()), this, SLOT(addNewEl()));
	connect(ui.getGet, SIGNAL(clicked()), this, SLOT(getElem()));
	connect(ui.delGet, SIGNAL(clicked()), this, SLOT(delElem()));
	connect(ui.menuAdd, SIGNAL(clicked()), this, SLOT(iDo1()));
	connect(ui.menuGet, SIGNAL(clicked()), this, SLOT(iDo2()));
	connect(ui.menuFiles, SIGNAL(clicked()), this, SLOT(iDo3()));
	connect(ui.menuGetAll, SIGNAL(clicked()), this, SLOT(iDo4()));
	connect(ui.addFile, SIGNAL(clicked()), this, SLOT(readFilef()));
	connect(ui.printFile, SIGNAL(clicked()), this, SLOT(printFilef()));
	connect(ui.delAllFiles, SIGNAL(clicked()), this, SLOT(delAll()));
}

void Laba333::tableFulling() {
	QTableWidgetItem *item1, *item2, *item3;
	//ui.tableWidget->clear();
	ui.tableWidget->setRowCount(_park->getCount());
	int j = 0;
	if (_park->getCount()) {
		ui.tableWidget->setRowCount(_park->getCount());
		for (auto i = _park->begin(); i.isEnd(); i++) {
			item1 = new QTableWidgetItem();
			item1->setText((i.getKey()).getModel());
			item1->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(j, 0, item1);

			item2 = new QTableWidgetItem();
			item2->setText((i.getKey()).getColor());
			item2->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(j, 1, item2);

			item3 = new QTableWidgetItem();
			item3->setText(QString::number((*_park)[i.getKey()]));
			item3->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(j++, 2, item3);
		}
	}
}

bool fileIsExist(const std::string & filePath)
{
	bool isExist = false;
	std::ifstream fin(filePath.c_str());

	if (fin.is_open())
		isExist = true;

	fin.close();
	return isExist;
}
