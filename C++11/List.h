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
		__list_iterator(const self& it) {
			_pnode = it._pnode;
		}
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
			self tmp(*this);
			_pnode = _pnode->_next;
			return tmp;
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
		bool operator==(const self& it) {
			return _pnode == it->_pnode;
		}
		node* _pnode;
	};

	template<class T>
	class list {
		typedef list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		
		
		///////////////////////////////////////////////////////////////
		// List的构造
		void empty_initialize() {
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		//移动构造
		list(list<T>&& lt) {
			cout << "list(T&& x) 移动构造" << endl;
			empty_initialize();
			swap(lt);
		}
		//移动赋值
		list<T>& operator=(list<T>&& lt) {
			cout << "list<T>& operator=(list<T> lt) 移动赋值" << endl;
			swap(lt);
			return *this;
		}
		list(initializer_list<T> il) {
			cout << "list(initializer_list<T> il)" << endl;
			empty_initialize();
			for (auto e : il) {
				push_back(e);
			}
		}
		list(){
			cout << "list() 构造" << endl;
			empty_initialize();
		}
		list(int n, const T& value = T()) {
			cout << "list(int n, const T& value = T()) 构造" << endl;
			empty_initialize();
			
			for (int i = 0; i < n; ++i) {
				node* newNode = new node(value);
				node* tail = _head->_prev;
				tail->_next = newNode;
				newNode->_prev = tail;
				_head->_prev = newNode;
				newNode->_next = _head;
			}
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

		//拷贝构造 -- 现代写法
		list(const list<T>& lt) {
			cout << "list(const list<T>& lt) 拷贝构造" << endl;
			empty_initialize();
			list<T> tmp(lt.begin(), lt.end());
			swap(tmp);
		}

		//现代写法

		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}

		///////////////////////////////////////////////////////////////
		// List Iterator
		iterator begin() {
			return iterator(_head->_next);
		}

		iterator end() {
			return iterator(_head);
		}
		const_iterator begin() const {
			return const_iterator(_head->_next);
		}

		const_iterator end() const {
			return const_iterator(_head);
		}

		///////////////////////////////////////////////////////////////
		// List Capacity
		int size() const {
			return _size;
		}

		bool empty() const {
			return (_size == 0) || (_head->_next == _head);
		}

		////////////////////////////////////////////////////////////
		// List Access
		T& front() {
			assert(!empty());
			return _head->_next->_val;
		}

		const T& front()const {
			assert(!empty());
			return _head->_next->_val;
		}

		T& back() {
			assert(!empty());
			return _head->_prev->_val;
		}

		const T& back()const {
			assert(!empty());
			return _head->_prev->_val;
		}

		////////////////////////////////////////////////////////////
		// List Modify
		
		void push_back(const T& val) {
			insert(end(), val);
		}
		void push_back(T&& val) {
			insert(end(), std::forward<T>(val));
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

		iterator insert(iterator pos, T&& val) {
			node* newNode = new node(std::forward<T>(val));
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
		void clear() {

			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
		}
		list<T>& operator=(list lt) {
			swap(lt);
			return *this;
		}
	private:
		node* _head;
		int _size = 0;
	};

	void test01() {
		list<int> l1{ 1,2,3,4,5 };
		//list<int> l1;

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
		list<string> l1{"11111"};
		list<string> l2(l1);
		/*list<string> l4;
		l4 = l1;*/
		string a = "22222";
		string l5;
	}
}