#pragma once

//仿函数，以解决非整数相容型类型转换为整数
template<class K>
struct HashFunction {
	size_t operator()(const K& key) {
		return (size_t)key;
	}
};
//特化
template< >
struct HashFunction<string> {
	size_t operator()(const string& key) {
		//return key[0];
		int hashi = 0;
		for (auto& e : key) {
			hashi *= 31;//或者131
			hashi += e;
		}
		return hashi;
	}
};

namespace closehash {


	enum State {//闭hash的状态记录，便于哈希冲突后在表中寻找key
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
			//负载因子，有效元素个数与容器总容量的比值，控制在0.7-0.8比较好
			//比值越大，容器越满，冲突的概率越大
			//比值越小，容器越空，冲突的概率越小
			//即再插入元素之前先判断该比值，确保该比值小于0.7，否则就扩容
			//现代写法，借用另一个HashTable对象的力量
			if (_n * 10 / _table.size() >= 7) {
				//扩容
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
				//不考虑_state为DELETE的元素
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
		vector<data> _table;//简单哈希表
		size_t _n = 0;//有效元素个数
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
		string arr[] = { "苹果", "西瓜", "香蕉", "草莓", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
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
