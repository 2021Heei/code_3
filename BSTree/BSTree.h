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
	//����
	BSTree()
		:_root(nullptr){}
	//����
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
	//����
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
	//�������
	void InOrder() {
		_InOrder(_root);
		cout << endl;
	}
	Node* findInNode(Node* root, K key) {
		
	}
	//ɾ��
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
				//1.Ҷ�ӽڵ�
				//2.ֻ������
				//3.ֻ���Һ���
				//4.�����Һ���
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
							//2.ֻ������
							if (parent->_left == cur)
								parent->_left = cur->_left;
							else
								parent->_right = cur->_left;
						}
					}
					
				}
				else if (cur->_right) {
					//3.ֻ���Һ���
					if (parent->_left == cur)
						parent->_left = cur->_right;
					else
						parent->_right = cur->_right;
				}
				else {
					//2.ֻ������
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