#pragma once
#include "hash.h"
namespace weihe {
	template<class K, class Hash = HashFunction<K>>
	class unordered_set {
		struct SetKeyOfT {
			const K& operator()(const K& key) {
				return key;
			}
		};
	public:
		typedef typename buckethash::HashTable<K, K, Hash, SetKeyOfT>::iterator iterator;
		iterator begin() {
			return _ht.begin();
		}
		iterator end() {
			return _ht.end();
		}
		pair<iterator, bool>insert(const K& key) {
			return _ht.insert(key);
		}
	private:
		buckethash::HashTable<K, K, Hash, SetKeyOfT> _ht;
	};

	void test_unordered_set() {
		unordered_set<int> us;
		us.insert(1);
		us.insert(11);
		us.insert(21);
		us.insert(31);
		us.insert(41);
		us.insert(141);
		us.insert(4111);
		us.insert(41111);
		us.insert(141111);

		unordered_set<int>::iterator it = us.begin();
		while (it != us.end()) {
			cout << (*it) << " ";
			++it;
		}
		cout << endl;

		for (auto& e : us) {
			cout << e << " ";
		}
		cout << endl;
	}
}
