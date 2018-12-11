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
	//������ ������� ����������
	assert(myTree.getCount() == 0);

	TrueKey *uk,* uk1 = new TrueKey("model1", "color1");
	
	
	myTree.addEl(uk1, 1);	
	//������ ���������� � ����� ���������
	assert(myTree.getCount() == 1);

	uk = new TrueKey("model2", "color2");
	myTree.addEl(uk, 2);
	//������ ���������� � ����� ����������
	assert(myTree.getCount() == 2);
	

	
	myTree.addEl(uk, 3);
	//������ ���������� �� ��������� (���� �����������)
	assert(myTree.getCount() == 2);
	delete uk;

	uk = new TrueKey("model3", "color3");
	myTree.addEl(uk, 2);
	//������ ���������� �� ��������� (�������� �����������)
	assert(myTree.getCount() == 2);
	
	
	//���� ������� � ������ uk1
	assert(myTree.checkKey(*uk1));
	//��� �������� � ������ uk
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
	//�������� � ������ 255 �� ����������
	assert(!(myTree.checkKey(*uk)));
	myTree.deleteEl(*uk);
	//������ �� ���������
	assert(myTree.getCount() == count);
	delete uk;

	//������� � ������ 20 ����������
	assert(myTree.checkKey(*uk1));
	myTree.deleteEl(*uk1);
	//������ ���������� ���������� �� 1
	assert(myTree.getCount() == (count - 1));
	//�������� � ������ 20 ������ ���
	assert(!(myTree.checkKey(*uk1)));
	delete uk1;


	uk = new TrueKey("model4", "color4");
	Parking<TrueKey, int>  myTree2(myTree);
	//��������� ����������� ����� �����������
	assert(myTree == myTree2);
	myTree.deleteEl(*uk);
	//����������� ����������� ����� ��������
	assert(!(myTree == myTree2));

	

	std::ofstream fout;
	fout.open("file2.txt");
	//����� � ����� (����)
	fout << myTree2;
	std::cout << myTree2;
	fout.close();

	Parking<TrueKey, int>  myTree3;
	std::ifstream fin;
	fin.open("file2.txt");
	//���������� �� ������
	fin >> myTree3;
	fin.close();

	//��������� �����������
	assert(myTree2 == myTree3);
	myTree2[*uk] = 122;
	//����������� �����������
	assert(!(myTree2 == myTree3));
	
	//������ �� ��������
	assert(myTree.getCount() != 0);
	myTree.deleteAll();
	myTree2.deleteAll();
	myTree3.deleteAll();
	//������ ����� ��������
	assert(myTree.getCount() == 0);
	



	QApplication a(argc, argv);
	Laba333 w;
	w.show();
	return a.exec();
}
