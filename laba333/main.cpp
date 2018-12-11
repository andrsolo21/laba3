#include "stdafx.h"
#include "laba333.h"
#include "parking.h"
#include "assert.h"
#include "trueKey.h"
#include <QtWidgets/QApplication>
#include <iostream>
#include <fstream>
#include <istream>

int main(int argc, char *argv[])
{

	/*Parking<TrueKey,int>  myTree;
	TrueKey * add = new TrueKey("model","color");
	TrueKey * add1 = new TrueKey("model1", "color1");
	TrueKey * add2 = new TrueKey("model2", "color2");
	myTree.addEl(add,2);
	myTree.addEl(add1, 4);
	myTree.addEl(add2, 90);

	std::ofstream fout;
	fout.open("file3.txt");
	fout << myTree;
	fout.close();

	Parking<int, int>  myTree3;
	std::ifstream fin;
	fin.open("file.txt");
	fin >> myTree3;
	fin.close();*/

	Parking<TrueKey, int>  myTree;
	//размер пустого контейнера
	assert(myTree.getCount() == 0);

	TrueKey *uk,* uk1 = new TrueKey("model1", "color1");
	
	
	myTree.addEl(uk1, 1);	
	//размер контейнера с одним элементом
	assert(myTree.getCount() == 1);

	uk = new TrueKey("model2", "color2");
	myTree.addEl(uk, 2);
	//размер контейнера с двумя элементами
	assert(myTree.getCount() == 2);
	

	
	myTree.addEl(uk, 3);
	//размер контейнера не изменился (ключ повторяется)
	assert(myTree.getCount() == 2);
	delete uk;

	uk = new TrueKey("model3", "color3");
	myTree.addEl(uk, 2);
	//размер контейнера не изменился (значение повторяется)
	assert(myTree.getCount() == 2);
	
	
	//есть элемент с ключом uk1
	assert(myTree.checkKey(*uk1));
	//нет элемента с ключом uk
	assert(!(myTree.checkKey(*uk)));

	myTree.addEl(uk, 3);
	delete uk;

	uk = new TrueKey("model4", "color4");
	myTree.addEl(uk, 4);
	delete uk;

	uk = new TrueKey("model5", "color5");
	myTree.addEl(uk, 5);
	delete uk;

	delete uk1;
	uk1 = new TrueKey("model6", "color6");
	myTree.addEl(uk1, 6);

	uk = new TrueKey("model7", "color7");

	int count = myTree.getCount();
	//элемента с ключом 255 не существует
	assert(!(myTree.checkKey(*uk)));
	myTree.deleteEl(*uk);
	//размер не изменился
	assert(myTree.getCount() == count);
	delete uk;

	//элемент с ключом 20 существует
	assert(myTree.checkKey(*uk1));
	myTree.deleteEl(*uk1);
	//размер контейнера уменьшился на 1
	assert(myTree.getCount() == (count - 1));
	//элемента с ключом 20 больше нет
	assert(!(myTree.checkKey(*uk1)));
	delete uk1;


	uk = new TrueKey("model4", "color4");
	Parking<TrueKey, int>  myTree2(myTree);
	//равенство контейнеров после копирования
	assert(myTree == myTree2);
	myTree.deleteEl(*uk);
	//неравенство контейнеров после удаления
	assert(!(myTree == myTree2));

	

	std::ofstream fout;
	fout.open("file2.txt");
	//вывод в поток (файл)
	fout << myTree2;
	std::cout << myTree2;
	fout.close();

	Parking<TrueKey, int>  myTree3;
	std::ifstream fin;
	fin.open("file2.txt");
	//считываний из потока
	fin >> myTree3;
	fin.close();

	//равенство контейнеров
	assert(myTree2 == myTree3);
	myTree2[*uk] = 122;
	//неравенство контейнеров
	assert(!(myTree2 == myTree3));
	
	//размер до удаления
	assert(myTree.getCount() != 0);
	myTree.deleteAll();
	myTree2.deleteAll();
	myTree3.deleteAll();
	//размер после удаления
	assert(myTree.getCount() == 0);
	



	QApplication a(argc, argv);
	Laba333 w;
	w.show();
	return a.exec();
}
