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
	//查找
	bool find(K key) {

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
	//中序遍历
	void InOrder() {
		_InOrder(_root);
		cout << endl;
	}
	Node* findInNode(Node* root, K key) {
		
	}
	//删除
	void erase(K key) {
		//

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
				if (cur->_left && cur->_right) {
					Node* tmp = findInNode(cur->_left);
					key = tmp->_key;
					swap(tmp->_key, cur->_key);
					
					while (cur) {
						if (key < cur->_key) {
							parent = cur;
							cur = cur->_left;
						}
						else if (key > cur->_right) {
							parent = cur;
							cur = cur->_right;
						}
						else {
							//2.只有左孩子
							if (parent->_left == cur)
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;
						}
					}
					
				}
				else if (cur->_right) {
					//3.只有右孩子
					if (parent->_left == cur)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
				else {
					//2.只有左孩子
					if (parent->_left == cur)
						parent->_left = cur->_left;
					else
						parent->_right = cur->_left;
				}
			}
		}
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
	Node* _root;
};

void BSTreeTest01() {
	BSTree<int> bst;
	int arr[] = { 3, 2, 1, 5, 4, 8, 7, 10 };
	for (auto e : arr) {
		bst.insert(e);
	}
	bst.InOrder();
	cout << bst.find(0) << endl;
	cout << bst.find(3) << endl;
}