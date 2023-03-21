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
		//����
		BSTree()
			:_root(nullptr) {}
		// ��������
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
		//����
		bool insert(K key) {
			//ѭ������
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
		//����
		bool find(const K& key) {
			//ѭ������
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

		//�������
		void InOrder() {
			_InOrder(_root);
			cout << endl;
		}

		//ɾ��
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
					//1.Ҷ�ӽڵ�
					//2.ֻ������
					//3.ֻ���Һ���
					//4.�����Һ���
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
						//���Һ��ӽڵ㶼��
						//�ҵ�cur������������С�ڵ�(����ڵ�)���滻��ɾ��
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
		/// ����ʾ�ĸ��ڵ�ĵݹ�
		/// </summary>
		/// <param name="root">���ڵ�</param>
		/// <param name="parent">���ڵ�</param>
		/// <param name="key">Key</param>
		/// <returns>�����Ƿ�ɹ�</returns>
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
		/// ʹ�ýڵ�ָ������ã���ʽʹ�ø��ڵ�
		/// </summary>
		/// <param name="root"></param>
		/// <param name="key"></param>
		/// <returns></returns>
		bool _insertR02(Node*& root, const K& key) {
			if (root == nullptr) {
				//����root����һ��ڵ�����ָ�����ָ������ã�������������ü򻯴��룬����Ҫ�ú�����
				//���������������
				//1. ���ڵ�Ϊnullptr����ʱroot�Ǹ��ڵ�����ã�ֱ�Ӱ��½ڵ��ַ��ֵ��root���ɣ�
				//2. �Ǹ��ڵ�Ϊnullptr,��ʱroot����һ��ڵ��ĳ��ָ�루��ָ�����ָ�룩����ָ������½ڵ�Ҫ���루���ӣ���λ��
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
				//����
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
					//��root����������С�ڵ㣨����ڵ㣩���ڽ���root->_key �� minRight->_key
					Node* minRight = root->_right;
					while (minRight->_left) {
						minRight = minRight->_left;
					}
					swap(root->_key, minRight->_key);
					//�ݹ�ɾ��root���������е�key
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
		//����
		BSTree()
			:_root(nullptr) {}
		// ��������
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
		//����
		bool insert(K key, V val) {
			//ѭ������
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
		//����
		Node* find(const K& key) {
			//ѭ������
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

		//�������
		void InOrder() {
			_InOrder(_root);
			cout << endl;
		}

		//ɾ��
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
					//1.Ҷ�ӽڵ�
					//2.ֻ������
					//3.ֻ���Һ���
					//4.�����Һ���
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
						//���Һ��ӽڵ㶼��
						//�ҵ�cur������������С�ڵ�(����ڵ�)���滻��ɾ��
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
		//����һƪ������ÿ�������Ƿ�ƴд����/
		K::BSTree<string> dictory;
		//ʹ�õ��ʿ��еĵ��ʴ���һ��������������ÿ�ζ�ȡһ�������еĵ����ڶ����������н��в��ң��ҵ�����ƴд�ɹ�������ƴдʧ�ܡ�
		//һ��ʹ�����ݿⴢ�浥�ʿ⣬���ݴ�����Ӳ�̣����̣������������ڴ档
	}

	void BSTKVTest02() {
		//ͨ��key����val�����޸�val
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

