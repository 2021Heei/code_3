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
		int hashi = 0;
		for (auto& e : key) {
			hashi *= 31;//����131
			hashi += e;
		}
		return hashi;
	}
};

namespace closehash {


	enum State {//��hash��״̬��¼�����ڹ�ϣ��ͻ���ڱ���Ѱ��key
		EXIST,
		EMPTY,
		DELETE
	};
	template <class K, class V>
	struct HashData {
		pair<K, V> _kv;
		State _state;
		HashData()
			:_state(EMPTY){ }
	};

	

	template<class K, class V, class hash = HashFunction<K>>
	class HashTable {
		typedef HashData<K, V> data;
	public:
		HashTable()
			:_n(0) {
			_table.resize(10);
			
		}
		bool insert(const pair<K, V>& kv) {
			if (find(kv.first)) {
				return false;
			}
			//�������ӣ���ЧԪ�ظ����������������ı�ֵ��������0.7-0.8�ȽϺ�
			//��ֵԽ������Խ������ͻ�ĸ���Խ��
			//��ֵԽС������Խ�գ���ͻ�ĸ���ԽС
			//���ٲ���Ԫ��֮ǰ���жϸñ�ֵ��ȷ���ñ�ֵС��0.7�����������
			//�ִ�д����������һ��HashTable���������
			if (_n * 10 / _table.size() >= 7) {
				//����
				HashTable<K, V> tmp;
				tmp._table.resize(_table.size() * 2);
				
				for (size_t i = 0; i < _table.size(); ++i) {
					if (_table[i]._state == EXIST) {
						tmp.insert(_table[i]._kv);
					}
				}
				_table.swap(tmp._table);
			}
			hash hf;
			size_t hashi = hf(kv.first) % _table.size();
			
			while (_table[hashi]._state == EXIST) {
				++hashi;
				hashi %= _table.size();
			}
			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;
			return true;
		}
		data* find(const K& key) {
			hash hf;
			size_t hashi = hf(key) % _table.size();
			while (_table[hashi]._state != EMPTY) {
				//������_stateΪDELETE��Ԫ��
				if (_table[hashi]._state == EXIST && _table[hashi]._kv.first == key) {
					return &_table[hashi];
				}
				hashi++;
				hashi %= _table.size();
			}
			return nullptr;

		}
		bool erase(const K& key) {
			HashData<K, V>* ret = find(key);
			if (ret) {
				ret->_state = DELETE;
				--_n;
				return true;
			}
			else {
				return false;
			}
		}
		void print() {
			for (size_t i = 0; i < _table.size(); ++i) {
				if (_table[i]._state == EXIST) {
					cout << _table[i]._kv.first << ":" << _table[i]._kv.second << endl;
				}
			}
		}
	private:
		vector<data> _table;//�򵥹�ϣ��
		size_t _n = 0;//��ЧԪ�ظ���
	};

	void test01() {
		int arr[] = { 7,17,27,37,47,8 };
		HashTable<int, int> hash;
		for (auto& e : arr) {
			hash.insert(make_pair(e, 1));
		}
		//hash.print();
		cout << hash.find(47) << endl;
		cout << hash.find(8) << endl;
		hash.erase(47);
		cout << hash.find(47) << endl;
		cout << hash.find(8) << endl;

	}

	void test02() {
		string arr[] = { "ƻ��", "����", "�㽶", "��ݮ", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
		HashTable<string, int> hs;
		for (auto& e : arr) {
			HashData<string, int>* p = hs.find(e);
			if (p) {
				p->_kv.second++;
			}
			else {
				hs.insert(make_pair(e, 1));
			}
		}
		hs.print();
	}
}


////////////////////////////////////////////////////////////////////////////////////////////


namespace buckethash {
	template<class K, class V>
	struct HashNode {
		pair<K, V> _kv;
		HashNode* _next;
		HashNode(const pair<K, V> kv)
			:_kv(kv)
			,_next(nullptr){ }
	};

	template<class K, class V, class Hash = HashFunction<K>>
	class HashTable {
		typedef HashNode<K, V> Node;
	public:
		HashTable() 
			:_n(0) {
			//_table.resize(10);
			_table.resize(__stl_next_prime(0));
		}
		~HashTable() {
			for (int i = 0; i < _table.size(); ++i) {
				Node* cur = _table[i];
				while (cur) {
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
		}
		bool insert(const pair<K, V> kv) {
			if (find(kv.first)) {
				return false;//�ҵ��˾Ͳ��ٲ���
			}
			//�жϸ������ӣ���Ҫ������1,��������һ��Ͱ��һ��Ԫ��
			if (_n == _table.size()) {
				HashTable<K, V, Hash> tmp;
				//tmp._table.resize(2 * _table.size());
				tmp._table.resize(2 * __stl_next_prime(_table.size()));
				for (auto& cur : _table) {
					while (cur) {
						tmp.insert(cur->_kv);
						cur = cur->_next;
					}
				}
				_table.swap(tmp._table);
			}

			size_t hashi = Hash()(kv.first) % _table.size();//ͳһת��Ϊ�޷�������
			//ͷ��
			Node* newNode = new Node(kv);
			newNode->_next = _table[hashi];
			_table[hashi] = newNode;
			++_n;
			return true;
		}
		Node* find(const K& key) {
			size_t hashi = Hash()(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur) {
				if (cur->_kv.first == key) {
					//return true;
					return cur;
				}
				cur = cur->_next;
			}
			//return false;
			return nullptr;
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

	void testBucketHash01() {
		HashTable<int, int> hb;
		hb.insert(make_pair(1, 1));
		hb.insert(make_pair(2, 2));
		hb.insert(make_pair(3, 3));
		hb.insert(make_pair(4, 4));
		hb.insert(make_pair(5, 5));
		hb.insert(make_pair(6, 6));
		hb.insert(make_pair(7, 7));
		hb.insert(make_pair(8, 8));
		hb.insert(make_pair(9, 9));
		hb.insert(make_pair(10, 10));
		hb.insert(make_pair(11, 11));
		hb.insert(make_pair(21, 21));

		hb.erase(1);
		hb.erase(21);
		hb.erase(11);
	}
}