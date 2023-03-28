#pragma once
namespace KV {
	enum Color {
		RED,
		BLACK
	};
	template <class T, class V>
	struct TreeNode {
		pair<K, V> _kv;
		TreeNode* _left;
		TreeNode* _right;
		TreeNode* _parent;
		Color _col;

		TreeNode(pair<K, V>& kv)
			:_kv(kv)
			,_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_col(RED){ }
	};

	template <class T, class V>
	struct RBTree {
		typedef TreeNode<T, V> Node*;
		RBTree()
			:_root(nullptr){}

		bool insert(const pair<K, V>& kv) {
			if (_root == nullptr) {
				_root = new Node(val);
				_root->_col = BLACK;
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) {
				if (kv.first < cur->_kv.first) {
					parent = cur;
					cur = cur->_left;
				}
				else if (kv.first > cur->_kv.first) {
					parent = cur;
					cur = cur->_right;
				}
				else {
					return false;
				}
			}

			cur = new Node(val);
			cur->_col = RED;
			if (kv.first < cur->_kv.first) {
				parent->_left = cur;
				cur->_parent = parent;
			}
			else {
				parent->_right = cur;
				cur->_parent = parent;
			}

			//出现连续的红色节点时需要分情况处理
			while (parent && parent->_col == RED) {
				Node* grandFather = parent->_parent;
				if (parent == grandFather->_left) {
					Node* uncle = grandFather->_right;
					//情况1，兄弟存在且为RED，同级的变为black，上一级变为red
					if (uncle && uncle->_col == RED) {
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandFather->_col = RED;

						cur = grandFather;
						parent = cur->_parent;
						//这里没有break，因为调整后还有可能存在新的连续的红节点
					}
					else {
						if (cur == parent->_left) {
							//情况2：右单旋
							RotateR(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else {
							//情况3：左右双旋
							RotateL(parent);
							RotateR(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break;
					}
				}
				else {
					//parent == grandFather->_right
					Node* uncle = grandFather->_left;
					if (uncle && uncle->_col == RED) {
						//情况1
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandFather->_col = RED;

						cur = grandFather;
						parent = cur->_parent;
					}
					else {
						if (cur == parent->_right) {
							//情况2：左单旋
							RotateL(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else {
							//情况3：右左双旋
							RotateR(parent);
							RotateL(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break;
					}
				}
			}
			return true;
		}

		void RotateL(Node* parent) {
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			//parent的右指向subR的左即subRL
			parent->_right = subRL;
			//如果subRL不为nullptr，subRL的父指针指向parent
			if (subRL) {
				subRL->_parent = parent;
			}
			//subR的左指向parent
			subR->_left = parent;
			Node* ppNode = parent->_parent;
			//parent的父指针指向subR
			parent->_parent = subR;
			//parent原先的父节点不存在，即parent是整棵树的原来的根，旋转后subR就是新的根，需要更改_root，且subR的父节点置为nullptr
			if (!ppNode) {
				_root = subR;
				subR->_parent = nullptr;
			}
			else {
				//parent原先的父节点ppNode存在，parent不是整棵树的根，旋转后subR也不是整棵树的根，需要根据原先parent位于ppNode的左边还是右边对应改变subR位ppNode也位于ppNode的左边还是右边，然后是使subR的父节点指向ppNode
				if (ppNode->_left == parent) {
					ppNode->_left = subR;
				}
				else {
					ppNode->_right = subR;
				}
				subR->_parent = ppNode;
			}
		}
		void RotateR(Node* parent) {
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subLR) {
				subLR->_parent = parent;
			}
			subL->_right = parent;
			Node* ppNode = parent->_parent;
			parent->_parent = subL;

			if (!ppNode) {
				_root = subL;
				_root->_parent = nullptr;
			}
			else {
				if (ppNode->_left == parent) {
					ppNode->_left = subL;
				}
				else {
					ppNode->_right = subL;
				}
				subL->_parent = ppNode;
			}
		}
	private:
		Node* _root;
	};
}