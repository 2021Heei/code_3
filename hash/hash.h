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
