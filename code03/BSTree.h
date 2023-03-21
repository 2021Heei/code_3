#pragma once

namespace K{
	template <class K>
	struct BSTreeNode {
		K _key;
		BSTreeNode* _left;
		BSTreeNode* _right;

		BSTreeNode(K key)
			:_key(key),
			_left(nullptr),
			_right(nullptr) {}
	};

	template <class K>
	class BSTree {
		typedef BSTreeNode<K> Node;
	public:
		//构造
		BSTree()
			:_root(nullptr) {}
		// 拷贝构造
		BSTree(const BSTree<K>& t) {
			_root = _copy(t._root);
		}
		//
		BSTree<K>& operator=(BSTree<K> t) {
			swap(_root, t._root);
			return *this;
		}
		//
		~BSTree() {
			Destroy(_root);
			_root = nullptr;
		}
		//插入
		bool insert(K key) {
			//循环插入
			if (_root == nullptr) {
				_root = new Node(key);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					parent = cur;
					cur = cur->_right;
				}
				else {
					return false;
				}
			}

			cur = new Node(key);
			if (key < parent->_key) {
				parent->_left = cur;
			}
			else {
				parent->_right = cur;
			}
			return true;
		}
		bool insertR(K key) {
			//return _insertR01(_root, nullptr, key);
			return _insertR02(_root, key);
		}
		//查找
		bool find(const K& key) {
			//循环查找
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					cur = cur->_right;
				}
				else {
					return true;
				}
			}
			return false;
		}
		bool findR(const K& key) {
			return _findR(_root, key);
		}

		//中序遍历
		void InOrder() {
			_InOrder(_root);
			cout << endl;
		}

		//删除
		bool erase(const K& key) {

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					parent = cur;
					cur = cur->_right;
				}
				else {
					//1.叶子节点
					//2.只有左孩子
					//3.只有右孩子
					//4.有左右孩子
					if (cur->_left == nullptr) {
						if (parent == nullptr) {
							_root = cur->_right;
						}
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_right;
							}
							else {
								parent->_right = cur->_right;
							}
						}


						delete cur;
					}
					else if (cur->_right == nullptr) {
						if (parent == nullptr) {
							_root = cur->_left;
						}
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_left;
							}
							else {
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else {
						//左右孩子节点都有
						//找到cur的右子树的最小节点(最左节点)，替换法删除
						parent = cur;
						Node* minRight = cur->_right;
						while (minRight->_left) {
							parent = minRight;
							minRight = minRight->_left;
						}
						cur->_key = minRight->_key;

						if (parent->_left == minRight) {
							parent->_left = minRight->_right;
						}
						else {
							parent->_right = minRight->_right;
						}
						delete minRight;
					}
					return true;
				}
			}
			return false;
		}
		bool eraseR(const K& key) {
			return _eraseR(_root, key);
		}
	//private:
		void _InOrder(Node* root) {
			if (root == nullptr) {
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
		bool _findR(Node* root, const K& key) {
			if (root == nullptr) {
				return false;
			}

			if (key < root->_key) {
				return _findR(root->_left, key);
			}
			else if (key > root->_key) {
				return _findR(root->_right, key);
			}
			else {
				return true;
			}
		}
		/// <summary>
		/// 带显示的父节点的递归
		/// </summary>
		/// <param name="root">根节点</param>
		/// <param name="parent">父节点</param>
		/// <param name="key">Key</param>
		/// <returns>查找是否成功</returns>
		bool _insertR01(Node* root, Node* parent, const K& key) {
			if (root == nullptr) {
				root = new Node(key);
				if (parent == nullptr) {
					_root = root;
				}
				else {
					if (key < parent->_key) {
						parent->_left = root;
					}
					else {
						parent->_right = root;
					}
				}

				return true;
			}
			if (key < root->_key) {
				return _insertR(root->_left, root, key);
			}
			else if (key > root->_key) {
				return _insertR(root->_right, root, key);
			}
			else {
				return false;
			}
		}
		/// <summary>
		/// 使用节点指针的引用，隐式使用父节点
		/// </summary>
		/// <param name="root"></param>
		/// <param name="key"></param>
		/// <returns></returns>
		bool _insertR02(Node*& root, const K& key) {
			if (root == nullptr) {
				//这里root是上一层节点中左指针或右指针的引用，巧妙的利用引用简化代码，但需要好好想想
				//包含了两种情况：
				//1. 根节点为nullptr，此时root是根节点的引用，直接把新节点地址赋值给root即可；
				//2. 非根节点为nullptr,此时root是上一层节点的某个指针（左指针或右指针），其指向就是新节点要插入（链接）的位置
				root = new Node(key);
				return true;
			}
			if (key < root->_key) {
				_insertR02(root->_left, key);
			}
			else if (key > root->_key) {
				_insertR02(root->_right, key);
			}
			else {
				return false;
			}
		}
		bool _eraseR(Node*& root, const K& key) {
			if (root == nullptr) {
				return false;
			}

			if (key < root->_key) {
				_eraseR(root->_left, key);
			}
			else if (key > root->_key) {
				_eraseR(root->_right, key);
			}
			else {
				//讨论
				Node* del = root;
				if (root->_left == nullptr) {
					root = root->_right;
					delete del;
				}
				else if (root->_right == nullptr) {
					root = root->_left;
					delete del;
				}
				else {
					//找root右子树中最小节点（最左节点），在交换root->_key 和 minRight->_key
					Node* minRight = root->_right;
					while (minRight->_left) {
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);
					//递归删除root的右子树中的key
					_eraseR(root->_right, key);
				}

				return true;
			}
		}
		Node* _copy(Node* root) {
			if (root == nullptr) {
				return nullptr;
			}
			Node* newNode = new Node(root->_key);
			newNode->_left = _copy(root->_left);
			newNode->_right = _copy(root->_right);

			return newNode;
		}
		void Destroy(Node* root) {
			/*if (root == nullptr) {
				return;
			}
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;*/
		}
		Node* _root;
	};

	void BSTreeTest01() {
		BSTree<int> bst;
		int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
		for (auto e : arr) {
			bst.insertR(e);
		}
		BSTree<int> bst2(bst);
		bst.InOrder();
		cout << bst.findR(0) << endl;
		cout << bst.findR(3) << endl;

		bst.eraseR(14);
		bst.eraseR(3);
		bst.eraseR(8);
		bst.InOrder();

		for (auto e : arr) {
			bst.eraseR(e);
			bst.InOrder();
		}


		bst2.InOrder();
		for (auto e : arr) {
			bst2.erase(e);
			bst2.InOrder();
		}
	}
}


namespace KV {
	template <class K, class V>
	struct BSTreeNode {
		K _key;
		V _val;
		BSTreeNode* _left;
		BSTreeNode* _right;

		BSTreeNode(K key, V val)
			:_key(key)
			,_val(val)
			,_left(nullptr)
			,_right(nullptr) {}
	};

	template <class K, class V>
	class BSTree {
		typedef BSTreeNode<K, V> Node;
	public:
		//构造
		BSTree()
			:_root(nullptr) {}
		// 拷贝构造
		BSTree(const BSTree<K, V>& t) {
			_root = _copy(t._root);
		}
		//
		BSTree<K, V>& operator=(BSTree<K, V> t) {
			swap(_root, t._root);
			return *this;
		}
		//
		~BSTree() {
			Destroy(_root);
			_root = nullptr;
		}
		//插入
		bool insert(K key, V val) {
			//循环插入
			if (_root == nullptr) {
				_root = new Node(key, val);
				return true;
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					parent = cur;
					cur = cur->_right;
				}
				else {
					return false;
				}
			}

			cur = new Node(key, val);
			if (key < parent->_key) {
				parent->_left = cur;
			}
			else {
				parent->_right = cur;
			}
			return true;
		}
		//查找
		Node* find(const K& key) {
			//循环查找
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					cur = cur->_right;
				}
				else {
					return cur;
				}
			}
			return nullptr;
		}

		//中序遍历
		void InOrder() {
			_InOrder(_root);
			cout << endl;
		}

		//删除
		bool erase(const K& key) {

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) {
				if (key < cur->_key) {
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key) {
					parent = cur;
					cur = cur->_right;
				}
				else {
					//1.叶子节点
					//2.只有左孩子
					//3.只有右孩子
					//4.有左右孩子
					if (cur->_left == nullptr) {
						if (parent == nullptr) {
							_root = cur->_right;
						}
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_right;
							}
							else {
								parent->_right = cur->_right;
							}
						}


						delete cur;
					}
					else if (cur->_right == nullptr) {
						if (parent == nullptr) {
							_root = cur->_left;
						}
						else {
							if (parent->_left == cur) {
								parent->_left = cur->_left;
							}
							else {
								parent->_right = cur->_left;
							}
						}
						delete cur;
					}
					else {
						//左右孩子节点都有
						//找到cur的右子树的最小节点(最左节点)，替换法删除
						parent = cur;
						Node* minRight = cur->_right;
						while (minRight->_left) {
							parent = minRight;
							minRight = minRight->_left;
						}
						cur->_key = minRight->_key;

						if (parent->_left == minRight) {
							parent->_left = minRight->_right;
						}
						else {
							parent->_right = minRight->_right;
						}
						delete minRight;
					}
					return true;
				}
			}
			return false;
		}
		
	//private:
		void _InOrder(Node* root) {
			if (root == nullptr) {
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << " : " << root->_val << endl;
			_InOrder(root->_right);
		}
		
		Node* _copy(Node* root) {
			if (root == nullptr) {
				return nullptr;
			}
			Node* newNode = new Node(root->_key, root->_val);
			newNode->_left = _copy(root->_left);
			newNode->_right = _copy(root->_right);

			return newNode;
		}
		void Destroy(Node* root) {
			if (root == nullptr) {
				return;
			}
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}
		Node* _root;
	};

	void BSTKTest01() {
		//查找一篇文章中每个单词是否拼写错误/
		K::BSTree<string> dictory;
		//使用单词库中的单词创建一个二叉搜索树，每次读取一个文章中的单词在二叉搜索树中进行查找，找到了则拼写成功，否则拼写失败。
		//一般使用数据库储存单词库，数据储存在硬盘（磁盘），而不是在内存。
	}

	void BSTKVTest02() {
		//通过key查找val或者修改val
		KV::BSTree<string, int> countTree;
		vector<string> vs = { "apple", "apple", "pair", "pair", "banane" };

		for (auto e : vs) {
			auto cur = countTree.find(e);
			if (cur) {
				cur->_val++;
			}
			else {
				countTree.insert(e, 1);
			}
		}
		countTree.InOrder();
	}
}

