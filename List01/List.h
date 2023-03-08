#pragma once

namespace weihe {
	template<class T>
	struct list_node {
		list_node(const T& val)
			:_next(nullptr),
			_prev(nullptr),
			_val(val){ }
		T _val;
		list_node* _next;
		list_node* _prev;
	};

	//是类的内置类型，像指针一样，需要指定域作用限定符来使用
	template<class T, class Ref, class Ptr>
	struct __list_iterator {
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> self;
		__list_iterator(node* p)
			:_pnode(p){ }

		Ref operator*() {
			return _pnode->_val;
		}

		Ptr operator->() {
			return &_pnode->_val;
		}

		self& operator++ () {
			_pnode = _pnode->_next;
			return *this;
		}

		self& operator++(int) {
			_pnode = _pnode->_next;
			return *this;
		}

		self& operator--() {
			_pnode = _pnode->_prev;
			return *this;
		}
		self operator--(int) {
			self tmp(*this);
			_pnode = _pnode->_prev;
			return tmp;
		}
		bool operator!=(const self& it) {
			return _pnode != it._pnode;
		}
		node* _pnode;
	};

	//const迭代器
	/*template<class T>
	struct __list_const_iterator {
		typedef list_node<T> node;
		__list_const_iterator(node* p)
			:_pnode(p) { }

		const T& operator*() {
			return _pnode->_val;
		}

		__list_const_iterator<T>& operator++ () {
			_pnode = _pnode->_next;
			return *this;
		}

		__list_const_iterator<T>& operator++(int) {
			_pnode = _pnode->_next;
			return *this;
		}

		__list_const_iterator<T>& operator--() {
			_pnode = _pnode->_prev;
			return *this;
		}
		__list_const_iterator<T>& operator--(int) {
			_pnode = _pnode->_prev;
			return *this;
		}
		bool operator!=(const __list_const_iterator& it) {
			return _pnode != it._pnode;
		}
		node* _pnode;
	};*/

	template<class T>
	class list {
		typedef list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		
		iterator begin() {
			return iterator(_head->_next);
		}

		iterator end() {
			return iterator(_head);
		}
		const_iterator begin() const {
			return const_iterator(_head->_next);
		}

		const_iterator end() const{
			return const_iterator(_head);
		}
		void empty_initialize() {
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		list(){
			empty_initialize();
		}

		template <class InputIterator>
		list(InputIterator first, InputIterator last) {
			empty_initialize();
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		void swap(list<T>& lt) {
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}
		//拷贝构造 - 传统写法
		/*list(const list& lt) {
			empty_initialize();

			for (auto& e : lt) {
				push_back(e);
			}
		}*/

		//拷贝构造 -- 现代写法
		list(const list<T>& lt) {
			empty_initialize();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		//赋值运算符重载 - 传统写法
		/*list<T>& operator=(const list<T>& lt) {
			if (_head != lt._head) {
				clear();
				for (auto& e : lt) {
					push_back(e);
				}
			}
			return *this;
		}*/

		//现代写法
		list<T>& operator=(list lt) {
			swap(lt);
			return *this;
		}

		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}
		void clear() {
			
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
		}
		void push_back(const T& val) {
			insert(end(), val);
		}
		void push_front(const T& val) {
			insert(begin(), val);
		}
		void pop_back() {
			erase(--end());
		}
		void pop_front() {
			erase(begin());
		}

		iterator insert(iterator pos, const T& val) {
			node* newNode = new node(val);
			node* cur = pos._pnode;
			node* prev = cur->_prev;

			prev->_next = newNode;
			newNode->_prev = prev;
			newNode->_next = cur;
			cur->_prev = newNode;

			++_size;

			return iterator(newNode);
		}

		iterator erase(iterator pos) {
			assert(pos != end());

			node* prev = pos._pnode->_prev;
			node* next = pos._pnode->_next;

			prev->_next = next;
			next->_prev = prev;

			delete pos._pnode;

			--_size;

			return iterator(next);
		}

		int size() const {
			return _size;
		}

		bool empty() const {
			return (_size == 0) || (_head->_next == _head);
		}
	private:
		node* _head;
		int _size = 0;
	};

	void test01() {
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);

		list<int>::iterator it = l1.begin();
		while (it != l1.end()) {
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto e : l1) {
			cout << e << " ";
		}
		cout << endl;
	}
	void test02() {
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);
		l1.push_back(6);

		for (auto e : l1) {
			cout << e << " ";
		}
		cout << endl;
		l1.pop_back();
		l1.pop_back();
		l1.pop_front();
		l1.pop_front();
		for (auto e : l1) {
			cout << e << " ";
		}
		cout << endl;

		list<int> l2(l1);
		for (auto& e : l2) {
			cout << e << " ";
		}
		cout << endl;

		list<int> l3;
		l3 = l1;
		l3.clear();
		for (auto& e : l3) {
			cout << e << " ";
		}
		cout << endl;
		l1.push_back(99);
		l3 = l1;
		
		for (auto& e : l3) {
			cout << e << " ";
		}
		cout << endl;
	}

	void prints(const list<int>& lt) {
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end()) {
			cout << *it << " ";
			it++;
		}
		cout << endl;

		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;
	}
	void test03() {
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		for (auto e : l1) {
			cout << e << " ";
		}
		cout << endl;
		prints(l1);

		list<int>::iterator it = l1.begin();
		while (it != l1.end()) {
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}

	void test04() {
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		for (auto e : l1) {
			cout << e << " ";
		}
		cout << endl;
		cout << l1.size() << endl;
		list<int> l2(l1.begin(), l1.end());
		for (auto e : l2) {
			cout << e << " ";
		}
		cout << endl;
		cout << l2.size() << endl;

		list<int> l3(l1);
		for (auto e : l3) {
			cout << e << " ";
		}
		cout << endl;
		cout << l3.size() << endl;

		list<int> l4;
		l4.push_back(99);
		cout << l4.size() << endl;

		l4 = l1;
		for (auto e : l4) {
			cout << e << " ";
		}
		cout << endl;
		cout << l4.size() << endl;

	}

	struct Pos {
		int _row;
		int _col;
		Pos(int row = 0, int col = 0)
			:_row(row),
			_col(col) { }
	};

	/*ostream& operator<<(ostream& out, const Pos& pos) {
		out << "(" << pos._row << " , " << pos._col << ")";
		return out;
	}*/

	void printss(const list<Pos>& lt) {
		list<Pos>::const_iterator it = lt.begin();
		while (it != lt.end()) {
			/*it->_row++;
			it->_col++;*/
			cout << it->_row << ":" << it->_col << " ";
			it++;
		}
		cout << endl;
	}

	void test05() {
		list<Pos> l1;
		l1.push_back(Pos(1, 1));
		l1.push_back(Pos(1, 1));
		l1.push_back(Pos(2, 2));
		l1.push_back(Pos(3, 3));
		l1.push_back(Pos(4, 4));
		l1.push_back(Pos(5, 5));

		list<Pos>::iterator it = l1.begin();
		/*while (it != l1.end()) {
			cout << *it << " ";
			++it;
		}
		cout << endl;*/
		
		while (it != l1.end()) {
			//cout << (&(*it))->_row << "," << (&(*it))->_col << " ";
			cout << it->_row << "," << it->_col << " ";
			//cout << it.operator->()->_row << "," << it.operator->()->_col << " ";

			++it;
		}
		cout << endl;


		printss(l1);
	}
}