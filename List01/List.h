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
	template<class T, class Ref>
	struct __list_iterator {
		typedef list_node<T> node;
		typedef __list_iterator<T, Ref> self;
		__list_iterator(node* p)
			:_pnode(p){ }

		Ref& operator*() {
			return _pnode->_val;
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
		typedef __list_iterator<T, T&> iterator;
		typedef __list_iterator<T, const T&> const_iterator;
		
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
		//拷贝构造
		list(list& lt) {
			empty_initialize();

			for (auto& e : lt) {
				push_back(e);
			}
		}
		//赋值运算符重载
		list& operator=(list& lt) {
			if (_head != lt._head) {
				clear();
				for (auto& e : lt) {
					push_back(e);
				}
			}
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

			return iterator(newNode);
		}

		iterator erase(iterator pos) {
			assert(pos != end());

			node* prev = pos._pnode->_prev;
			node* next = pos._pnode->_next;

			prev->_next = next;
			next->_prev = prev;

			delete pos._pnode;
			return iterator(next);
		}
	private:
		node* _head;
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
}