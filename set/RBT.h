#pragma once
namespace weihe {
	enum Color {
		RED,
		BLACK
	};
	template <class T>
	struct TreeNode {
		T _val;
		TreeNode* _left;
		TreeNode* _right;
		TreeNode* _parent;
		Color _col;

		TreeNode(const T& val)
			:_val(val)
			,_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr)
			,_col(RED){ }
	};
	template<class T, class Ref, class Ptr>
	struct __RBTreeIterator {
		typedef TreeNode<T> Node;
		typedef __RBTreeIterator<T, Ref, Ptr> Self;
		typedef __RBTreeIterator<T, T&, T*> iterator;
		Node* _node;
		__RBTreeIterator(Node* node)
			:_node(node){ }
		//根据s的类型不同，这个函数分别表示拷贝构造函数或构造函数
		__RBTreeIterator(const iterator& s)
			:_node(s._node){ }
		Ref operator*() {
			return _node->_val;
		}
		Ptr operator->() {
			return &_node->_val;
		}
		Self& operator++() {
			if (_node->_right) {
				//++迭代器，说明当前及之前的节点已经走过了，该走右子树了
				//分情况：右子树存在就找右子树中最左节点（最小节点）
				//右子树不存在，持续找祖先，直到cur不是parent的右节点停止，此时parent就是结果
				Node* cur = _node->_right;
				while (cur->_left) {
					cur = cur->_left;
				}
				_node = cur;
			}
			else {
				Node* cur = _node;
				Node* parent = cur->_parent;
				
				while (parent && parent->_right == cur) {
					cur = cur->_parent;
					parent = parent->_parent;
				}
				_node = parent;
			}
			return *this;
		}
		Self& operator--() {
			if (_node->_left) {
				//--迭代器，说明需要往前走（访问左子树或往树上（父亲节点）走），此时当前节点及右子树都访问完了
				//分情况：当左子树存在，直接去找左子树的最右节点（最大节点）
				//当左子树不存在，只需向上找，直到cur不是parent的左节点
				Node* cur = _node->_left;
				while (cur->_right) {
					cur = cur->_right;
				}
				_node = cur;
			}
			else {
				Node* cur = _node;
				Node* parent = cur->_parent;
				while (parent && parent->_left == cur) {
					cur = cur->_parent;
					parent->_parent = parent;
				}
				_node = parent;
			}
			return *this;
		}
		bool operator!=(const Self& s) const {
			return _node != s._node;
		}
		bool operator==(const Self& s) const {
			return _node == s._node;
		}
	};
	template <class K, class T, class KeyOfT>
	struct RBTree {
		typedef TreeNode<T> Node;
		typedef __RBTreeIterator<T, T&, T*> iterator;
		typedef __RBTreeIterator<T, const T&, const T*> const_iterator;
		RBTree()
			:_root(nullptr) {}
		iterator begin() {
			Node* left = _root;
			while (left && left->_left) {
				left = left->_left;
			}
			return iterator(left);
		}
		iterator end() {
			return iterator(nullptr);
		}
		const_iterator begin() const {
			Node* left = _root;
			while (left && left->_left) {
				left = left->_left;
			}
			return const_iterator(left);
		}
		const_iterator end() const {
			return const_iterator(nullptr);
		}
		pair<iterator, bool> insert(const T& val) {
			if (_root == nullptr) {
				_root = new Node(val);
				_root->_col = BLACK;
				return pair<iterator, bool>(iterator(_root), true);
			}
			KeyOfT kot;//仿函数，自适应k和pair<k,v>结构
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) {
				if (kot(val) < kot(cur->_val)) {
					parent = cur;
					cur = cur->_left;
				}
				else if (kot(val) > kot(cur->_val)) {
					parent = cur;
					cur = cur->_right;
				}
				else {
					return pair<iterator, bool>(iterator(cur), false);
				}
			}

			cur = new Node(val);
			Node* newNode = cur;
			cur->_col = RED;
			if (kot(val) < kot(parent->_val)) {
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
			//确保根节点为黑
			_root->_col = BLACK;
			return pair<iterator, bool>(iterator(newNode), true);
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
		void Inorder() {
			return Inorder(_root);
		}

		bool isBlance() {
			return isBlance(_root);
		}
		
	private:
		Node* _root;
		void Inorder(Node* root) {
			if (!root) {
				return;
			}
			Inorder(root->_left);
			cout << root->_kv.first << ":" << root->_kv.second << endl;
			Inorder(root->_right);
		}
		//检查不能直接比较最长路径不超过最短路径的2倍，还要考虑连续的节点不能都为红
		//稳妥做法是对红黑树四种分别条件进行验证。如果有一条不满足就不是红黑树
		//1.根节点是黑色的
		//2.红节点的孩子节点一定都是黑节点（如果存在），即不存在两个连续的红节点
		//3.最长路径节点数不超过最短路径的2倍
		//4.每条路径的黑节点个数严格相等
		bool isBlance(Node* root) {
			if (root == nullptr) {
				return true;
			}
			//1.
			if (root->_col != BLACK) {
				cout << "违反规则：1.根节点是黑色的" << endl;
				return false;
			}
			//2.
			int ref = 0;
			Node* cur = root;
			while (cur) {
				if (cur->_col == BLACK) {
					++ref;
				}
				cur = cur->_left;
			}
			return ContinuousRedNodeAndJudgmentBlackNodeNumber(root, 0, ref);
			//3.

		}

		bool ContinuousRedNodeAndJudgmentBlackNodeNumber(Node* root, int blackNumber, int ref) {
			if (root == nullptr) {
				if (blackNumber != ref) {
					cout << "违反规则：4.每条路径的黑节点个数严格相等" << endl;
					return false;
				}
				return true;
			}
			if (root->_col == RED && root->_parent->_col == RED) {
				cout << "违反规则：2.红节点的孩子节点一定都是黑节点（如果存在），即不存在两个连续的红节点" << endl;
				return false;
			}
			if (root->_col == BLACK) {
				blackNumber++;
			}
			
			return ContinuousRedNodeAndJudgmentBlackNodeNumber(root->_left, blackNumber, ref) && ContinuousRedNodeAndJudgmentBlackNodeNumber(root->_right, blackNumber, ref);
		}
	};
	//void test03() {
	//	RBTree<int, int> rbt;
	//	int arr1[] = { 1, 2, 3, 4, 6, 7, 8 };
	//	for (auto e : arr1) {
	//		//cout << e;
	//		rbt.insert(e);
	//		//cout << rbt.isBlance() << endl;
	//		//cout << endl;
	//	}

	//	RBTree<int, int>::iterator it = rbt.begin();
	//	while (it != rbt.end()) {
	//		cout << *it << " ";
	//		++it;
	//	}
	//	cout << endl;
	//	for (const auto& e : rbt) {
	//		cout << e << " ";
	//	}
	//	cout << endl;
	//}
	//void test01() {
	//	RBTree<int, int> rbt1;
	//	//int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//	//int arr1[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//	int arr1[] = { 1, 2, 3, 4, 6, 7, 8 };
	//	for (auto e : arr1) {
	//		//cout << e;
	//		rbt1.insert(make_pair(e, e));
	//		cout << rbt1.isBlance() << endl;
	//		//cout << endl;
	//	}
	//	//rbt1.Inorder();
	//	cout << rbt1.isBlance() << endl;
	//}

	//void test02() {
	//	srand(time(0));
	//	RBTree<int, int> rbt1;
	//	const int N = 10000;
	//	for (int i = 0; i < N; ++i) {
	//		int e = rand();
	//		//cout << e;
	//		rbt1.insert(make_pair(e, e));
	//		//cout << endl;
	//		//cout << i << ":" << e << ":" << rbt1.isBlance() << endl;
	//	}
	//	//rbt1.Inorder();
	//	cout << rbt1.isBlance() << endl;
	//}
}