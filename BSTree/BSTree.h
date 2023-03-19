#pragma once

template <class K>
struct BSTreeNode {
	K _key;
	BSTreeNode* _left;
	BSTreeNode* _right;

	BSTreeNode(K key)
		:_key(key),
		_left(nullptr),
		_right(nullptr){}
};

template <class K>
class BSTree {
	typedef BSTreeNode<K> Node;
public:
	//构造
	BSTree()
		:_root(nullptr){}
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
		return _insertR01(_root, nullptr, key);
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
private:
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
		else if(key > root->_key) {
			return _findR(root->_right, key);
		}
		else {
			return true;
		}
	}
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
	bool _insertR02(Node* root, const K& key) {

	}
	bool _eraseR(Node* root, const K& key) {

	}
	Node* _root;
};

void BSTreeTest01() {
	BSTree<int> bst;
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : arr) {
		bst.insertR(e);
	}
	bst.InOrder();
	cout << bst.findR(0) << endl;
	cout << bst.findR(3) << endl;

	bst.erase(14);
	bst.erase(3);
	bst.erase(8);
	bst.InOrder();
}