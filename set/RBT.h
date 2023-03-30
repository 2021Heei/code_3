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
		//����s�����Ͳ�ͬ����������ֱ��ʾ�������캯�����캯��
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
				//++��������˵����ǰ��֮ǰ�Ľڵ��Ѿ��߹��ˣ�������������
				//����������������ھ���������������ڵ㣨��С�ڵ㣩
				//�����������ڣ����������ȣ�ֱ��cur����parent���ҽڵ�ֹͣ����ʱparent���ǽ��
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
				//--��������˵����Ҫ��ǰ�ߣ������������������ϣ����׽ڵ㣩�ߣ�����ʱ��ǰ�ڵ㼰����������������
				//������������������ڣ�ֱ��ȥ�������������ҽڵ㣨���ڵ㣩
				//�������������ڣ�ֻ�������ң�ֱ��cur����parent����ڵ�
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
			KeyOfT kot;//�º���������Ӧk��pair<k,v>�ṹ
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

			//���������ĺ�ɫ�ڵ�ʱ��Ҫ���������
			while (parent && parent->_col == RED) {
				Node* grandFather = parent->_parent;
				if (parent == grandFather->_left) {
					Node* uncle = grandFather->_right;
					//���1���ֵܴ�����ΪRED��ͬ���ı�Ϊblack����һ����Ϊred
					if (uncle && uncle->_col == RED) {
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandFather->_col = RED;

						cur = grandFather;
						parent = cur->_parent;
						//����û��break����Ϊ�������п��ܴ����µ������ĺ�ڵ�
					}
					else {
						if (cur == parent->_left) {
							//���2���ҵ���
							RotateR(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else {
							//���3������˫��
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
						//���1
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandFather->_col = RED;

						cur = grandFather;
						parent = cur->_parent;
					}
					else {
						if (cur == parent->_right) {
							//���2������
							RotateL(grandFather);
							parent->_col = BLACK;
							grandFather->_col = RED;
						}
						else {
							//���3������˫��
							RotateR(parent);
							RotateL(grandFather);
							cur->_col = BLACK;
							grandFather->_col = RED;
						}
						break;
					}
				}
			}
			//ȷ�����ڵ�Ϊ��
			_root->_col = BLACK;
			return pair<iterator, bool>(iterator(newNode), true);
		}

		void RotateL(Node* parent) {
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			//parent����ָ��subR����subRL
			parent->_right = subRL;
			//���subRL��Ϊnullptr��subRL�ĸ�ָ��ָ��parent
			if (subRL) {
				subRL->_parent = parent;
			}
			//subR����ָ��parent
			subR->_left = parent;
			Node* ppNode = parent->_parent;
			//parent�ĸ�ָ��ָ��subR
			parent->_parent = subR;
			//parentԭ�ȵĸ��ڵ㲻���ڣ���parent����������ԭ���ĸ�����ת��subR�����µĸ�����Ҫ����_root����subR�ĸ��ڵ���Ϊnullptr
			if (!ppNode) {
				_root = subR;
				subR->_parent = nullptr;
			}
			else {
				//parentԭ�ȵĸ��ڵ�ppNode���ڣ�parent�����������ĸ�����ת��subRҲ�����������ĸ�����Ҫ����ԭ��parentλ��ppNode����߻����ұ߶�Ӧ�ı�subRλppNodeҲλ��ppNode����߻����ұߣ�Ȼ����ʹsubR�ĸ��ڵ�ָ��ppNode
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
		//��鲻��ֱ�ӱȽ��·�����������·����2������Ҫ���������Ľڵ㲻�ܶ�Ϊ��
		//���������ǶԺ�������ֱַ�����������֤�������һ��������Ͳ��Ǻ����
		//1.���ڵ��Ǻ�ɫ��
		//2.��ڵ�ĺ��ӽڵ�һ�����Ǻڽڵ㣨������ڣ��������������������ĺ�ڵ�
		//3.�·���ڵ������������·����2��
		//4.ÿ��·���ĺڽڵ�����ϸ����
		bool isBlance(Node* root) {
			if (root == nullptr) {
				return true;
			}
			//1.
			if (root->_col != BLACK) {
				cout << "Υ������1.���ڵ��Ǻ�ɫ��" << endl;
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
					cout << "Υ������4.ÿ��·���ĺڽڵ�����ϸ����" << endl;
					return false;
				}
				return true;
			}
			if (root->_col == RED && root->_parent->_col == RED) {
				cout << "Υ������2.��ڵ�ĺ��ӽڵ�һ�����Ǻڽڵ㣨������ڣ��������������������ĺ�ڵ�" << endl;
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