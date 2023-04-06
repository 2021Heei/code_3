#pragma once

//�º������Խ������������������ת��Ϊ����
template<class K>
struct HashFunction {
	size_t operator()(const K& key) {
		return (size_t)key;
	}
};
//�ػ�
template< >
struct HashFunction<string> {
	size_t operator()(const string& key) {
		//return key[0];
		size_t hashi = 0;
		for (auto& e : key) {
			hashi *= 31;//����131
			hashi += e;
		}
		
		return hashi;
	}
};
////////////////////////////////////////////////////////////////////////////////////////////


namespace buckethash {
	template<class T>
	struct HashNode {
		//pair<K, T> _kv;
		T _val;
		HashNode* _next;
		HashNode(const T& val)
			:_val(val)
			,_next(nullptr){ }
	};

	template<class K, class T, class Hash, class KeyOfT>
	class HashTable;

	template<class K, class T, class Hash, class KeyOfT>
	struct __HTIterator {
		typedef HashNode<T> Node;
		typedef __HTIterator<K, T, Hash, KeyOfT> Self;
		typedef HashTable<K, T, Hash, KeyOfT> HT;

		Node* _node;
		HT* _ht;
		__HTIterator(Node* node, HT* ht) {
			_node = node;
			_ht = ht;
		}

		T& operator*() {
			return _node->_val;
		}
		T* operator->() {
			return &_node->_val;
		}
		bool operator!=(const Self& s) const {
			return _node != s._node;
		}
		//ǰ��++,����++֮��ĵ�����
		Self& operator++() {
			if (_node->_next) {
				_node = _node->_next;
			}
			else {
				KeyOfT kot;
				Hash hash;
				size_t hashi = hash(kot(_node->_val)) % _ht->_table.size();//
				++hashi;
				while (hashi < _ht->_table.size()) {
					if (_ht->_table[hashi]) {
						_node = _ht->_table[hashi];
						break;
					}
					else {
						++hashi;
					}
				}
				if (hashi == _ht->_table.size()) {
					_node = nullptr;
				}
			}
			return *this;
		}

	};

	template<class K, class T, class Hash, class KeyOfT>
	class HashTable {
		typedef HashNode<T> Node;
		//��Ԫ��
		template<class K, class T, class Hash, class KeyOfT>
		friend struct __HTIterator;
	public:
		typedef __HTIterator<K, T, Hash, KeyOfT> iterator;
		iterator begin() {
			for (int i = 0; i < _table.size(); ++i) {
				if (_table[i]) {
					return iterator(_table[i], this);
				}
			}
			return iterator(nullptr, this);
		}

		iterator end() {
			return iterator(nullptr, this);
		}

		HashTable() 
			:_n(0) {
			//_table.resize(10);
			_table.resize(__stl_next_prime(0));
		}
		~HashTable() {
			for (size_t i = 0; i < _table.size(); ++i) {
				Node* cur = _table[i];
				while (cur) {
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}
		pair<iterator, bool> insert(const T& val) {
			KeyOfT kot;
			iterator it = find(kot(val));
			if (it != end()) {
				return make_pair(it, false);
			}

			//�жϸ������ӣ���Ҫ������1,��������һ��Ͱ��һ��Ԫ��
			if (_n == _table.size()) {
				//HashTable<K, T, Hash> tmp;
				////tmp._table.resize(2 * _table.size());
				//tmp._table.resize(2 * __stl_next_prime(_table.size()));
				//for (auto& cur : _table) {
				//	while (cur) {
				//		tmp.insert(cur->_kv);
				//		cur = cur->_next;
				//	}
				//}
				//_table.swap(tmp._table);

				vector<Node*> newTable;
				newTable.resize(2 * __stl_next_prime(_table.size()));
				for (size_t i = 0; i < _table.size(); ++i) {
					Node* cur = _table[i];
					while (cur) {
						Node* next = cur->_next;
						size_t hashi = Hash()(kot(cur->_val)) % newTable.size();
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;
						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newTable);
			}

			size_t hashi = Hash()(kot(val)) % _table.size();//ͳһת��Ϊ�޷�������
			//ͷ��
			Node* newNode = new Node(val);
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			++_n;

			cout << "insert:" << hashi << " ";

			return make_pair(iterator(newNode, this), true);
		}
		iterator find(const K& key) {
			KeyOfT kot;
			size_t hashi = Hash()(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur) {
				if (kot(cur->_val) == key) {
					//return true;
					return iterator(cur, this);
				}
				cur = cur->_next;
			}
			//return false;
			return iterator(nullptr, this);
		}

		bool erase(const K& key) {
			size_t hashi = Hash()(key) % _table.size();
			Node* prev = nullptr;
			Node* cur = _table[hashi];
			while (cur) {
				if (cur->_kv.first == key) {
					//����ͷָ�룬��Ҫ���⴦��
					if (cur == _table[hashi]) {
						_table[hashi] = cur->_next;
					}
					else {
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					//cur = prev->_next;
					return true;
				}
				else {
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
		}

		inline unsigned long __stl_next_prime(unsigned long n)
		{
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
				53, 97, 193, 389, 769,
				1543, 3079, 6151, 12289, 24593,
				49157, 98317, 196613, 393241, 786433,
				1572869, 3145739, 6291469, 12582917, 25165843,
				50331653, 100663319, 201326611, 402653189, 805306457,
				1610612741, 3221225473, 4294967291
			};

			for (int i = 0; i < __stl_num_primes; ++i)
			{
				if (__stl_prime_list[i] > n)
				{
					return __stl_prime_list[i];
				}
			}
		}
	private:
		vector<Node*> _table;//�ڵ�ָ��vector
		size_t _n;//�ڵ�ָ�������hash bucket�ĸ���
	};

}