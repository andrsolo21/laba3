#pragma once
#include "QString.h"
#include <iostream>
class TrueKey
{
public:
	TrueKey() {
		_model = nullptr;
		_color = nullptr;
		_isExist[0] = false;
		_isExist[1] = false;
	}
	TrueKey(QString model, QString color) {
		_isExist[0] = false;
		_isExist[1] = false;
		if (model != "") {
			_isExist[0] = true;
			_model = model;
		}
		if (color != "") {
			_color = color;
			_isExist[1] = true;
		}
			
	}
	~TrueKey() {}
	bool operator==(TrueKey& dr) const
	{
		if (this->getModel() == dr.getModel() && this->getColor() == dr.getColor())
			return true;		
		return false;
	}
	bool operator<(TrueKey& dr) const
	{
		if (this->getModel() < dr.getModel())
			return true;
		if (this->getModel() > dr.getModel())
			return false;
		if (this->getColor() < dr.getColor())
			return true;
		return false;
	}
	QString getModel() const {
		return _model;
	}
	QString getColor() const {
		return _color;
	}
	void setModel(QString model){
		if (model != "") {
			_model = model;
			_isExist[0] = true;
		}
	}
	void setColor(QString color) {
		if (color != "") {
			_color = color;
			_isExist[1] = true;
		}
	}
	friend std::ostream& operator<< (std::ostream &out, const TrueKey &data)
	{
		out << (data.getModel()).toStdString() << " " << (data.getColor()).toStdString();
		return out;
		
	}
	friend std::istream& operator>> (std::istream &in, TrueKey &data)
	{
		std::string str1;
		std::string str2;
		in >> str1 >> str2;
		data.setModel(QString::fromStdString(str1));
		data.setColor(QString::fromStdString(str2));
		return in;
	}
	bool isExist() {
		return (_isExist[0] && _isExist[1]);
	}
private:
	QString _model, _color;
	bool _isExist[2];
};