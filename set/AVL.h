#pragma once

namespace KV {
	template <class K, class V>
	struct TreeNode {
		pair<K, V> _val;
		int _bf;// balance factor
		TreeNode* _left;
		TreeNode* _right;
		TreeNode* _parent;
		TreeNode(const pair<K, V>& val)
			:_val(val)
			,_bf(0)
			,_left(nullptr)
			,_right(nullptr)
			,_parent(nullptr){ }
	};

	template <class K, class V>
	class AVL {
		typedef TreeNode<K, V> Node;
	public:

		void RotateL(Node* parent) {
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			//parent的右指向subR的左即subRL
			parent->_right = subRL;
			//如果subRL不为nullptr，subRL的父指针指向parent
			if(subRL){
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
			//修改parent和subR的平衡因子为0
			parent->_bf = subR->_bf = 0;
		}
		void RotateR(Node* parent) {
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			parent->_left = subLR;
			if (subRL) {
				subRL->_parent = parent;
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
	private:
		Node* _root;
	};
};
