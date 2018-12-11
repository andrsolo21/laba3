#include "stdafx.h"
#include "node.h"

template <typename T>
Node<T>::Node()
{
	right = NULL;
	left = NULL;
	parent = NULL:
	color = RED;

}

template <typename T>
Node<T>::~Node()
{
}

template <typename T>
T  Node<T>::getKey(){
	return *(key);
}

template <typename T>
int  Node<T>::getZn() {
	return zn;
}