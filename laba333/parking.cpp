#include "stdafx.h"
#include "parking.h"

/*template <typename T>
Parking<T>::Parking()
{
	_tree = NULL;
}*/

//template <typename T>
//Parking<T>::~Parking()
//{
//
//}

/*template <typename T>
void Parking<T>::addEl(T * key, int zn) {
	if (!(getEl(&key))) {
		struct node * n = new node;
		//T * uk = new T(*key)
		n->color = RAD;
		n->left = NULL;
		n->right = NULL;
		n->parent = NULL;
		n->zn = zn;
		n->key = key;

		if (_tree) {

			struct node * pr = _tree;
			while (pr) {
				if (*(n->key) < *(pr->key)) {
					if (pr->left)
						pr = pr->left;
					else {
						pr->left = n;
						n->parent = pr;
						pr = NULL;
					}
				}
				else {
					if (pr->right)
						pr = pr->right;
					else {
						pr->right = n;
						n->parent = pr;
						pr = NULL;
					}
				}
			}
		}
		else
			_tree = n;
		insertCase1(n);
	}

}*/



//template <typename T>
//void Parking<T>::deleteEl(Parking<T>::node * pr) {
//	if (pr) {
//		int k = countChild(pr);
//		if (k == 2) {
//			node * newDel = theSmallest(pr->right);
//			*(pr->key) = *(newDel->key);
//			*(pr->zn) = *(newDel->zn);
//			deleteEl(newDel);
//		}
//		if (k == 1) {
//			deleteOneChild(pr);
//		}
//		if (k == 0) {
//			if ((pr->parent->left) and (pr->parent->left->key == pr->key)) {
//				pr->parent->left = NULL;
//			}
//			else {
//				pr->parent->right = NULL;				
//			}
//			delete pr;
//		}
//	}
//}
//
//
//template <typename T>
//void Parking<T>::deleteAllPr(Parking<T>::node *pr) {
//	if (pr) {
//		deleteAllPr(pr->left);
//		deleteAllPr(pr->right);
//		delete pr->key;
//		delete pr;
//	}
//}

/*template <typename T>
int Parking<T>::getCountPr(Parking<T>::node *n) const {
	if (n) {
		return (getCountPr(n->left) + getCountPr(n->right) + 1);
	}
	else
		return 0;
}*/

/*template <typename T>
struct node * Parking<T>::getEl(T * key, struct node * pr) const {
	while (pr) {
		if (*(pr->key) == *key) {
			return pr;
		}
		if (*(pr->key) < *key) {
			pr = pr->right;
		}
		else
		{
			pr = pr->left;
		}
	}
	return NULL;
}*/

//template <typename T>
//int Parking<T>::operator[] (T key) {
//	struct node * pr = getEl(key, _tree);
//	if (pr) {
//		return pr->zn;
//	}
//	return 0;
//}

/*template <typename T>
int Parking<T>::getZn(T * key, struct node * pr) const {
	struct node * pr = getEl(key, pr);
	if (pr) {
		return pr->zn;
	}
	return 0;
}*/

//template <typename T>
//std::ostream& operator<< (std::ostream &out, const Parking<T> &data) {
//	out << data->getCount();
//	for (auto i = data.begin(); i; i++)
//		out << i->getKey() << " " << i->getZn() << endl;
//	return out;
//}

//template <typename T>
//std::istream& operator>> (std::istream &in, Parking<T> &data)  {
//	int c;
//	T * key, k;
//	int zn;
//	i >> c;
//	for (int i = 0; i < c; i++) {
//		in >> k >> zn;
//		key = new T(k);
//		data.addEl(key, zn);
//	}
//	return in;
//}

//template <typename T>
//bool Parking<T>::operator== (const Parking<T>& dr) const {
//	if (this->getCount() != dr.getCount())
//		return false;
//	for (auto i = this->begin(); i; i++) {
//		if (!(i->getZn() == dr.getZn(i->getKey())))
//			return false;
//	}
//	return true;
//}

//template <typename T>
//bool Parking<T>::checkKey(T * key) {
//	if (getEl(key, _tree)) {
//		return true;
//	}
//	return false;
//}

/*template <typename T>
Parking<T>::node * Parking<T>::grandparent( node *n) const
{
	if ((n != NULL) && (n->parent != NULL))
		return n->parent->parent;
	else
		return NULL;
}*/

/*template <typename T>
Parking<T>::node * Parking<T>::uncle( node *n) const
{
	struct node *g = grandparent(n);
	if (g == NULL)
		return NULL; // No grandparent means no uncle
	if (n->parent == g->left)
		return g->right;
	else
		return g->left;
}*/

/*template <typename T>
Parking<T>::node * Parking<T>::sibling( node *n) const
{
	if (n == n->parent->left)
		return n->parent->right;
	else
		return n->parent->left;
}*/

//template <typename T>
//void Parking<T>::rotateLeft(struct node *n)
//{
//	node *pivot = n->right;
//
//	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
//	if (n->parent != NULL) {
//		if (n->parent->left == n)
//			n->parent->left = pivot;
//		else
//			n->parent->right = pivot;
//	}
//
//	n->right = pivot->left;
//	if (pivot->left != NULL)
//		pivot->left->parent = n;
//
//	n->parent = pivot;
//	pivot->left = n;
//}

//template <typename T>
//void Parking<T>::rotateRight(struct node *n)
//{
//	node *pivot = n->left;
//
//	pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
//	if (n->parent != NULL) {
//		if (n->parent->left == n)
//			n->parent->left = pivot;
//		else
//			n->parent->right = pivot;
//	}
//
//	n->left = pivot->right;
//	if (pivot->right != NULL)
//		pivot->right->parent = n;
//
//	n->parent = pivot;
//	pivot->right = n;
//}

/*template <typename T>
void Parking<T>::insertCase1(struct node *n)
{
	if (n->parent == NULL)
		n->color = BLACK;
	else
		insertCase2(n);
}*/

//template <typename T>
//void Parking<T>::insertCase2(struct node *n)
//{
//	if (n->parent->color == BLACK)
//		return; /* Tree is still valid */
//	else
//		insertCase3(n);
//}

//template <typename T>
//void Parking<T>::insertCase3(struct node *n)
//{
//	node *u = uncle(n), *g;
//
//	if ((u != NULL) && (u->color == RED)) {
//		// && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
//		n->parent->color = BLACK;
//		u->color = BLACK;
//		g = grandparent(n);
//		g->color = RED;
//		insertCase1(g);
//	}
//	else {
//		insertCase4(n);
//	}
//}

//template <typename T>
//void Parking<T>::insertCase4(struct node *n)
//{
//	node *g = grandparent(n);
//	if ((n == n->parent->right) && (n->parent == g->left)) {
//		rotate_left(n->parent);
//		n = n->left;
//	}
//	else if ((n == n->parent->left) && (n->parent == g->right)) {
//		rotate_right(n->parent);
//		n = n->right;
//	}
//	insertCase5(n);
//}

//template <typename T>
//void Parking<T>::insertCase5(struct node *n)
//{
//	node *g = grandparent(n);
//
//	n->parent->color = BLACK;
//	g->color = RED;
//	if ((n == n->parent->left) && (n->parent == g->left)) {
//		rotateRight(g);
//	}
//	else { /* (n == n->parent->right) && (n->parent == g->right) */
//		rotateLeft(g);
//	}
//}

//template <typename T>
//void Parking<T>::deleteOneChild(struct node *n)
//{
//	/*
//	 * Условие: n имеет не более одного ненулевого потомка.
//	 */
//	node *child = is_leaf(n->right) ? n->left : n->right;
//
//	replace_node(n, child);
//	if (n->color == BLACK) {
//		if (child->color == RED)
//			child->color = BLACK;
//		else
//			deleteCase1(child);
//	}
//	delete n;
//}
//
//template <typename T>
//void Parking<T>::deleteCase1(struct node *n)
//{
//	if (n->parent != NULL)
//		deleteCase2(n);
//}
//
//template <typename T>
//void Parking<T>::deleteCase2(struct node *n)
//{
//	struct node *s = sibling(n);
//
//	if (s->color == RED) {
//		n->parent->color = RED;
//		s->color = BLACK;
//		if (n == n->parent->left)
//			rotateLeft(n->parent);
//		else
//			rotateRight(n->parent);
//	}
//	deleteCase3(n);
//}
//
//template <typename T>
//void Parking<T>::deleteCase3(struct node *n)
//{
//	struct node *s = sibling(n);
//
//	if ((n->parent->color == BLACK) &&
//		(s->color == BLACK) &&
//		(s->left->color == BLACK) &&
//		(s->right->color == BLACK)) {
//		s->color = RED;
//		deleteCase1(n->parent);
//	}
//	else
//		deleteCase4(n);
//}
//
//template <typename T>
//void Parking<T>::deleteCase4(struct node *n)
//{
//	struct node *s = sibling(n);
//
//	if ((n->parent->color == RED) &&
//		(s->color == BLACK) &&
//		(s->left->color == BLACK) &&
//		(s->right->color == BLACK)) {
//		s->color = RED;
//		n->parent->color = BLACK;
//	}
//	else
//		deleteCase5(n);
//}
//
//template <typename T>
//void Parking<T>::deleteCase5(struct node *n)
//{
//	struct node *s = sibling(n);
//
//	if (s->color == BLACK) { /* this if statement is trivial,
//due to case 2 (even though case 2 changed the sibling to a sibling's child,
//the sibling's child can't be red, since no red parent can have a red child). */
///* the following statements just force the red to be on the left of the left of the parent,
//   or right of the right, so case six will rotate correctly. */
//		if ((n == n->parent->left) &&
//			(s->right->color == BLACK) &&
//			(s->left->color == RED)) { /* this last test is trivial too due to cases 2-4. */
//			s->color = RED;
//			s->left->color = BLACK;
//			rotateRight(s);
//		}
//		else if ((n == n->parent->right) &&
//			(s->left->color == BLACK) &&
//			(s->right->color == RED)) {/* this last test is trivial too due to cases 2-4. */
//			s->color = RED;
//			s->right->color = BLACK;
//			rotateLeft(s);
//		}
//	}
//	deleteCase6(n);
//}
//
//template <typename T>
//void Parking<T>::deleteCase6(struct node *n)
//{
//	struct node *s = sibling(n);
//
//	s->color = n->parent->color;
//	n->parent->color = BLACK;
//
//	if (n == n->parent->left) {
//		s->right->color = BLACK;
//		rotate_left(n->parent);
//	}
//	else {
//		s->left->color = BLACK;
//		rotate_right(n->parent);
//	}
//}
//
//template <typename T>
//int Parking<T>::countChild(struct node *n) {
//	int k = 0;
//	if (n->left)
//		k++;
//	if (n->right)
//		k++;
//	return k;
//}
//
//template <typename T>
//int Parking<T>::theSmallest(struct node *n) {
//	while (n->left) {
//		n = n->left;
//	}
//	return n;
//}