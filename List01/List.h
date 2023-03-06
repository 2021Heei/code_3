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
	template<class T>
	struct __list_iterator {
		typedef list_node<T> node;
		__list_iterator(node* p)
			:_pnode(p){ }

		T& operator*() {
			return _pnode->_val;
		}

		__list_iterator<T>& operator++ () {
			_pnode = _pnode->_next;
			return *this;
		}

		__list_iterator<T>& operator++(int) {
			_pnode = _pnode->_next;
			return *this;
		}

		bool operator!=(const __list_iterator& it) {
			return _pnode != it._pnode;
		}
		node* _pnode;
	};

	template<class T>
	class list {
		typedef list_node<T> node;
		
	public:
		typedef __list_iterator<T> iterator;
		iterator begin() {
			return iterator(_head->_next);
		}
		iterator end() {
			return iterator(_head);
		}
		list(){
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}
		void push_back(const T& val) {
			node* newNode = new node(val);
			//找尾
			node* tail = _head->_prev;
			tail->_next = newNode;
			newNode->_prev = tail;
			_head->_prev = newNode;
			newNode->_next = _head;
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
}