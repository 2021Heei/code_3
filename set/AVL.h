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
