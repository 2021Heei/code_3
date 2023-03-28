#pragma once

namespace KV {
	template <class K, class V>
	struct TreeNode {
		pair<K, V> _kv;
		int _bf;// balance factor
		TreeNode* _left;
		TreeNode* _right;
		TreeNode* _parent;
		TreeNode(const pair<K, V>& kv)
			:_kv(kv)
			,_bf(0)
			,_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr){ }
	};

	template <class K, class V>
	class AVLTree {
		typedef TreeNode<K, V> Node;
	public:
		AVLTree()
			:_root(nullptr){ }
		~AVLTree() {
			destroy(_root);
			_root = nullptr;
		}
		AVLTree(const AVLTree<K, V>& avl) {
			_root = copy(avl._root, nullptr);
		}
		AVLTree<K, V>& operator=(AVLTree avl) {
			swap(_root, avl._root);
			return *this;
		}
		void Inorder() {
			Inorder(_root);
		}
		void find(const K& k) {
			return find(_root, k);
		}
		bool insert(const pair<K, V>& kv) {
			if (!_root) {
				_root = new Node(kv);
				return true;
			}
			//�Ȳ��� K,V
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur) {
				if (kv.first < cur->_kv.first) {
					parent = cur;
					cur = cur->_left;
				}
				else if(kv.first > cur->_kv.first){
					parent = cur;
					cur = cur->_right;
				}
				else {
					return false;
				}
			}
			cur = new Node(kv);
			if (kv.first < parent->_kv.first) {
				parent->_left = cur;
			}
			else {
				parent->_right = cur;
			}
			cur->_parent = parent;

			//����ת �� ����ƽ������
			while (parent) {
				if (cur == parent->_left) {
					parent->_bf--;
				}
				else {
					parent->_bf++;
				}
				//˵��ƽ��
				if (parent->_bf == 0) {
					return 0;
				}
				//˵��parent�����������1��֮ǰ���0����Ҫ���ϸ��¸��ף�
				else if (parent->_bf == 1 || parent->_bf == -1) {
					cur = parent;
					parent = parent->_parent;
				}
				//˵�������������2��֮ǰ���1����Ҫ�͵���ת
				else if (parent->_bf == 2 || parent->_bf == -2) {
					//�������ߣ����½ڵ���������Ҳ࣬�γ�ֱ��״��������������������ѹ
					if (parent->_bf == 2 && cur->_bf == 1) {
						RotateL(parent);
					}
					//�������ߣ����½ڵ����������࣬�γ�ֱ��״�������ҵ�������������ѹ
					else if (parent->_bf == -2 && cur->_bf == -1) {
						RotateR(parent);
					}
					//����˫�������½ڵ�����������������Ҳ࣬�γ�����״��
					//�ȶ�parent->_left�����������ٶ�parent�����ҵ���
					else if (parent->_bf == -2 && cur->_bf == 1) {
						RoteteLR(parent);
					}
					//����˫��,���½ڵ����������������࣬�γ�����״��
					//�ȶ�parent->_right�����ҵ������ڶ�parent��������
					else if (parent->_bf == 2 && cur->_bf == -1) {
						RotateRL(parent);
					}
					else {
					//��������������㣬����
						assert(false);
					}
					break;
				}
				else {
					assert(false);//ƽ�����ӳ���
				}
				
			}
			return true;
		}
		void RotateL(Node* parent) {
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			//parent����ָ��subR����subRL
			parent->_right = subRL;
			//���subRL��Ϊnullptr��subRL�ĸ�ָ��ָ��parent
			if(subRL){
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
			//�޸�parent��subR��ƽ������Ϊ0
			parent->_bf = subR->_bf = 0;
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
			parent->_bf = subL->_bf = 0;
		}
		void RoteteLR(Node* parent) {
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			int bf = subLR->_bf;

			RotateL(subL);
			RotateR(parent);

			//����ƽ������
			if (bf == -1) {
				subLR->_bf = 0;
				subL->_bf = 0;
				parent->_bf = 1;
			}
			else if (bf == 1) {
				subLR->_bf = 0;
				subL->_bf = -1;
				parent->_bf = 0;
			}
			else if(bf == 0){
				subLR->_bf = 0;
				subL->_bf = 0;
				parent->_bf = 0;
			}
			else {
				assert(false);//�������������
			}
		}
		void RotateRL(Node* parent) {
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			int bf = subRL->_bf;

			RotateR(subR);
			RotateL(parent);

			//����ƽ������
			if (bf == -1) {
				subRL->_bf = 0;
				parent->_bf = 0;
				subR->_bf = 1;
			}
			else if (bf == 1) {
				subRL->_bf = 0;
				parent->_bf = -1;
				subR->_bf = 0;
			}
			else if (bf == 0) {
				subRL->_bf = 0;
				parent->_bf = 0;
				subR->_bf = 0;
			}
			else {
				assert(false);
			}
		}
		
		int getHeight() {
			return getHeight(_root);
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
		bool find(Node* root, const K& k) {
			if (!root) {
				return false;
			}
			
			return root->kv.first == k
				|| find(root->_left, k)
				|| find(root->_right, k);
		}
		int getHeight(Node* root) {
			if (!root) {
				return 0;
			}

			return max(getHeight(root->_left), getHeight(root->_right)) + 1;
		}
		bool isBlance(Node* root) {
			if (!root) {
				return true;
			}
			int left_height = getHeight(root->_left);
			int right_height = getHeight(root->_right);

			if (right_height - left_height != root->_bf) {
				cout << root->_kv.first << ":" << "ƽ�������쳣" << endl;
				return false;
			}

			return abs(left_height - right_height) < 2
				&& isBlance(root->_left)
				&& isBlance(root->_right);
		}
		void destroy(Node* root) {
			if (!root) {
				return;
			}
			destroy(root->_left);
			destroy(root->_right);
			delete root;
		}
		Node* copy(Node* root, Node* parent) {
			if (!root) {
				return nullptr;
			}
			Node* ret = new Node(root->_kv);
			ret->_bf = root->_bf;
			ret->_parent = parent;
			ret->_left = copy(root->_left, ret);
			ret->_right = copy(root->_right, ret);
			return ret;
			
		}
	};

	void test01() {
		AVLTree<int, int> avl;
		int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		int arr2[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
		int arr3[] = { 1, 2, 3, 4, 6, 7, 8 };
		for (auto e : arr3) {
			//cout << e;
			avl.insert(make_pair(e, e));
			cout << avl.isBlance() << endl;
			//cout << endl;
		}
		avl.Inorder();
		//cout << avl.isBlance() << endl;
	}

	void test02() {
		srand(time(0));
		AVLTree<int, int> avl;
		const int N = 10000;
		for (int i = 0; i < N; ++i) {
			int e = rand();
			//cout << e;
			avl.insert(make_pair(e, e));
			//cout << endl;
			cout << i << ":" << e << ":" << avl.isBlance() << endl;
		}
		avl.Inorder();
		cout << avl.isBlance() << endl;
	}

	void test03() {
		AVLTree<int, int> avl;
		int arr1[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
		for (auto e : arr1) {
			avl.insert(make_pair(e, e));
		}
		avl.Inorder();
		cout << avl.isBlance() << endl;
		AVLTree<int, int> avl2(avl);
		avl2.Inorder();
		cout << avl2.isBlance() << endl;
	}
};
