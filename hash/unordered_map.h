#pragma once
namespace weihe {
	template<class K, class V, class Hash = HashFunction<K>>
	class unordered_map {
		struct MapKeyOfT {
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
	public:
		typedef typename buckethash::HashTable<K, pair<const K, V>, Hash, MapKeyOfT>::iterator iterator;
		iterator begin() {
			return _ht.begin();
		}
		iterator end() {
			return _ht.end();
		}
		pair<iterator, bool> insert(const pair<K, V>& val) {
			return _ht.insert(val);
		}
		V& operator[](const K& key) {
			pair<iterator, bool> ret = _ht.insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		buckethash::HashTable<K, pair<const K, V>, Hash, MapKeyOfT> _ht;
	};
	void test_unordered_map() {
		unordered_map<string, int, HashFunction<string>> um;
		string arr1[] = { "Æ»¹û", "Î÷¹Ï", "Ïã½¶", "²ÝÝ®", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };
		string arr2[] = { "a", "b", "c", "d", "e", "a", "a", "e", "e"};
		for (auto& e : arr1) {
			um[e]++;
		}
		unordered_map<string, int>::iterator it = um.begin();
		while (it != um.end()) {
			cout << (*it).first << ":" << (*it).second << endl;
			++it;
		}
		cout << endl;
	}
}
