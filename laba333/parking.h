#pragma once

template <typename T, typename U>
class Parking
{
public:
	enum Color { RED, BLACK };
	struct node {
		node * left, *right, *parent;
		T * key;
		Color color;
		U zn;
	};
	class Iterator {
	public:
		Iterator(node * ptr) {
			_ptr = ptr;
			if (ptr)
				_isEnd = true;
			else
				_isEnd = false;
		}
		~Iterator() {}
		/*Iterator& left() {
			_ptr = _ptr->left;
			return *this;
		}
		Iterator& right() {
			_ptr = _ptr->right;
			return *this;
		}*/
		Iterator operator++(int) {
			Iterator i = *this;
			if (_ptr->left) {
				_ptr = _ptr->left;
				return i;
			}
			if (_ptr->right) {
				_ptr = _ptr->right;
				return i;
			}

			node * uk = _ptr->parent;
			while (uk && (!(isLeft(uk, _ptr) || !(uk->right)))) {
				uk = uk->parent;
			}
			if (uk)
				_ptr = uk->right;
			else
				_isEnd = false;
			return i;

		}
		bool isLeft(node * predok, node * el) const {
			if (getEl2(el->key, predok->left))
				return true;
			else
				return false;
		}
		bool getEl2(T * key, node * pr) const {
			while (pr)
				if (*(pr->key) == *key)
					return true;
				else
					if (*(pr->key) < *key)
						pr = pr->right;
					else
						pr = pr->left;
			return false;
		}
		Iterator& operator++() {
			if (_ptr->left) {
				_ptr = _ptr->left;
				return *this;
			}
			if (_ptr->right) {
				_ptr = _ptr->right;
				return *this;
			}

			node * uk = _ptr->parent;
			while (uk && (!(isLeft(uk, _ptr) || !(uk->right)))) {
				uk = uk->parent;
			}
			if (uk)
				_ptr = uk->right;
			else
				_isEnd = false;
			return *this;
		}
		T& getKey() const {
			return *(_ptr->key);
		}
		U& getZn() const {
			return _ptr->zn;
		}
		/*T & operator*() const {
			return _ptr->key;
		}
		bool operator==(const Iterator& rhs) const {
			return _ptr == rhs._ptr;
		}
		bool operator!=(const Iterator& rhs) const {
			return !(_ptr == rhs._ptr);
		}*/
		bool isEnd() {
			return _isEnd && _ptr;
		}
	private:
		node * _ptr;
		bool _isEnd;
	};

	Parking() {
		_tree = NULL;
	}
	Parking(const Parking & add) {
		_tree = NULL;
		for (auto  i = add.begin(); i.isEnd() ; i++) {

			U zn = i.getZn();
			T * key = new T(i.getKey());
			addEl(key, zn);
		}
	}
	//~Parking();
	void addEl(T * key, U zn) {
		if (!(getEl(key, _tree)) && !(checkZn(_tree,zn))) {
			node * n = new node;
			T * uk = new T(*key);
			n->color = RED;
			n->left = NULL;
			n->right = NULL;
			n->parent = NULL;
			n->zn = zn;
			n->key = uk;

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
				insertCase1(n);
			}
			else {
				_tree = n;
				_tree->color = BLACK;
			}
		}
	}
	bool checkKey(T  key) const {
		if (getEl(&key, _tree)) {
			return true;
		}
		return false;
	}
	void deleteEl(T  key)
	{
		node * pr = getEl(&key, _tree);
		if (pr) {
			int k = countChild(pr);
			if (k == 2) {
				node * newDel = theSmallest(pr->right);
				T * tempKey = new T( *(newDel->key));
				pr->zn = newDel->zn;
				deleteEl(*tempKey);
				delete (pr->key);
				pr->key = tempKey;
			}
			if (k == 1) {
				deleteOneChild(pr);
			}
			if (k == 0) {
				if ((pr->parent->left) && (pr->parent->left->key == pr->key)) {
					pr->parent->left = nullptr;
				}
				else {
					pr->parent->right = nullptr;
				}
				delete pr->key;
				delete pr;
			}
		}
	}
	void deleteAll() {
		deleteAllPr(_tree);
		_tree = NULL;
	}
	int getCount() const {
		return getCountPr(_tree);
	}
	friend std::ostream& operator<< (std::ostream &out,const Parking<T,U>&data)
	{
		out << data.getCount() << '\n';
		for (auto i = data.begin(); i.isEnd(); i++)
			out << i.getKey() << " " << i.getZn() <<'\n';
		return out;
	}
	friend std::istream& operator>> (std::istream &in,  Parking<T,U> &data)
	{
		int c, zn;
		T * key, k;
		in >> c;
		for (int i = 0; i < c; i++) {
			in >> k >> zn;
			key = new T(k);
			data.addEl(key, zn);
		}
		return in;
	}
	Iterator begin() const {
		return Iterator(_tree);
	}
	U& operator[] (T key) 
	{
		struct node * pr = getEl(&key, _tree);
		if (pr) {
			return pr->zn;
		}
		throw std::exception("key is not exist");
	}
	bool operator==( Parking<T,U>& dr) const
	{
		if (this->getCount() != dr.getCount())
			return false;
		for (auto i = this->begin(); i.isEnd(); i++) {
			if (!(i.getZn() == dr[i.getKey()]))
				return false;
		}
		return true;
	}
	
private:
	node * _tree;
	bool checkZn(node * pr, U zn) const{
		if (pr) {
			if (pr->zn == zn) {
				return true;
			}
			return (checkZn(pr->left, zn) || checkZn(pr->right, zn));
		}
		return false;
	}
	struct node * getEl(T * key, node * pr) const
	{
		while (pr) {
			if (*(pr->key) == *key) {
				return pr;
			}
			else
				if (*(pr->key) < *key) {
					pr = pr->right;
				}
				else
				{
					pr = pr->left;
				}
		}
		return NULL;
	}
	int getCountPr(struct node *n) const {
		if (n) {
			return (getCountPr(n->left) + getCountPr(n->right) + 1);
		}
		else
			return 0;
	}
	void deleteAllPr(node *pr)
	{
		if (pr) {
			deleteAllPr(pr->left);
			deleteAllPr(pr->right);
			delete pr->key;
			delete pr;
		}
	}
	struct node * grandparent(node *n) const {
		if ((n != NULL) && (n->parent != NULL))
			return n->parent->parent;
		else
			return NULL;
	}
	struct node * uncle(node *n) const {
		struct node *g = grandparent(n);
		if (g == NULL)
			return NULL; // No grandparent means no uncle
		if (n->parent == g->left)
			return g->right;
		else
			return g->left;
	}
	struct node * sibling(node *n) const
	{
		if (n == n->parent->left)
			return n->parent->right;
		else
			return n->parent->left;
	}
	void rotateLeft( node *n)
	{
		node *pivot = n->right;

		pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
		if (n->parent != NULL) {
			if (n->parent->left == n)
				n->parent->left = pivot;
			else
				n->parent->right = pivot;
		}
		else {
			_tree = pivot;
		}

		n->right = pivot->left;
		if (pivot->left != NULL)
			pivot->left->parent = n;

		n->parent = pivot;
		pivot->left = n;
	}
	void rotateRight( node *n)
	{
		node *pivot = n->left;

		pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
		if (n->parent != NULL) {
			if (n->parent->left == n)
				n->parent->left = pivot;
			else
				n->parent->right = pivot;
		}
		else {
			_tree = pivot;
		}

		n->left = pivot->right;
		if (pivot->right != NULL)
			pivot->right->parent = n;

		n->parent = pivot;
		pivot->right = n;
	}
	void insertCase1( node *n)
	{
		if (n->parent == NULL)
			n->color = BLACK;
		else
			insertCase2(n);
	}
	void insertCase2( node *n)
	{
		if (n->parent->color == BLACK)
			return; /* Tree is still valid */
		else
			insertCase3(n);
	}
	void insertCase3( node *n)
	{
		node *u = uncle(n), *g;

		if ((u != NULL) && (u->color == RED)) {
			// && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
			n->parent->color = BLACK;
			u->color = BLACK;
			g = grandparent(n);
			g->color = RED;
			insertCase1(g);
		}
		else {
			insertCase4(n);
		}
	}
	void insertCase4( node *n)
	{
		struct node *g = grandparent(n);
		if ((n == n->parent->right) && (n->parent == g->left)) {
			rotateLeft(n->parent);
			n = n->left;
		}
		else if ((n == n->parent->left) && (n->parent == g->right)) {
			rotateRight(n->parent);
			n = n->right;
		}
		insertCase5(n);
	}
	void insertCase5( node *n)
	{
		node *g = grandparent(n);

		n->parent->color = BLACK;
		g->color = RED;
		if ((n == n->parent->left) && (n->parent == g->left)) {
			rotateRight(g);
		}
		else { /* (n == n->parent->right) && (n->parent == g->right) */
			rotateLeft(g);
		}
	}
	void deleteOneChild( node *n)
	{
		/*
		 * Условие: n имеет не более одного ненулевого потомка.
		 */
		node *child = leaf(n);

		replaceNode(n, child);
		if (n->color == BLACK) {
			if (child->color == RED)
				child->color = BLACK;
			else
				deleteCase1(child);
		}
		delete n->key;
		delete n;
	}
	void deleteCase1( node *n)
	{
		if (n->parent != NULL)
			deleteCase2(n);
	}
	void deleteCase2( node *n)
	{
		struct node *s = sibling(n);

		if (s->color == RED) {
			n->parent->color = RED;
			s->color = BLACK;
			if (n == n->parent->left)
				rotateLeft(n->parent);
			else
				rotateRight(n->parent);
		}
		deleteCase3(n);
	}
	void deleteCase3( node *n)
	{
		struct node *s = sibling(n);

		if ((n->parent->color == BLACK) &&
			(s->color == BLACK) &&
			(s->left->color == BLACK) &&
			(s->right->color == BLACK)) {
			s->color = RED;
			deleteCase1(n->parent);
		}
		else
			deleteCase4(n);
	}
	void deleteCase4( node *n)
	{
		struct node *s = sibling(n);

		if ((n->parent->color == RED) &&
			(s->color == BLACK) &&
			(s->left->color == BLACK) &&
			(s->right->color == BLACK)) {
			s->color = RED;
			n->parent->color = BLACK;
		}
		else
			deleteCase5(n);
	}
	void deleteCase5( node *n)
	{
		struct node *s = sibling(n);

		if (s->color == BLACK) { /* this if statement is trivial,
	due to case 2 (even though case 2 changed the sibling to a sibling's child,
	the sibling's child can't be red, since no red parent can have a red child). */
	/* the following statements just force the red to be on the left of the left of the parent,
	   or right of the right, so case six will rotate correctly. */
			if ((n == n->parent->left) &&
				(s->right->color == BLACK) &&
				(s->left->color == RED)) { /* this last test is trivial too due to cases 2-4. */
				s->color = RED;
				s->left->color = BLACK;
				rotateRight(s);
			}
			else if ((n == n->parent->right) &&
				(s->left->color == BLACK) &&
				(s->right->color == RED)) {/* this last test is trivial too due to cases 2-4. */
				s->color = RED;
				s->right->color = BLACK;
				rotateLeft(s);
			}
		}
		deleteCase6(n);
	}
	void deleteCase6( node *n)
	{
		struct node *s = sibling(n);

		s->color = n->parent->color;
		n->parent->color = BLACK;

		if (n == n->parent->left) {
			s->right->color = BLACK;
			rotateLeft(n->parent);
		}
		else {
			s->left->color = BLACK;
			rotateRight(n->parent);
		}
	}
	int countChild( node *n) const {
		int k = 0;
		if (n->left)
			k++;
		if (n->right)
			k++;
		return k;
	}
	node * theSmallest( node *n) const {
		while (n->left) {
			n = n->left;
		}
		return n;
	}
	node * leaf(node * n) const {
		if (n->left)
			return n->left;
		else
			return n->right;
	}
	void replaceNode(node *n1, node *n2) {
		n2->parent = n1->parent;
		if (n1->parent->left->key == n1->key)
			n1->parent->left = n2;
		else
			n1->parent->right = n2;
	}
};

