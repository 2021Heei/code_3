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
			return true;
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
	private:
		Node* _root;
	};
}