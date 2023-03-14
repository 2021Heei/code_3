#pragma once

namespace weihe {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin() {
			return _start;
		}
		
		const_iterator begin() const{
			return _start;
		}
		iterator end() {
			return _finish;
		}
		const_iterator end() const{
			return _finish;
		}
		// construct and destroy
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) { }

		template <class InputIterator>
		vector(InputIterator first, InputIterator last) 
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) {
			while (first != last) {
				push_back(*first);
				first++;
			}
		}
		
		vector(size_t n, const T& val) 
			:_start(nullptr)
			,_finish(nullptr)
			,_end_of_storage(nullptr){
			for (int i = 0; i < n; i++) {
				push_back(val);
			}
		}
		vector(int n, const T& val)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) {
			for (int i = 0; i < n; i++) {
				push_back(val);
			}
		}
		//�ִ�д��
		//��������
		vector(const vector<T>& v)
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) {
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		/*vector(const vector<T>& v) 
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr) {
			vector<T> tmp;
			for (auto e : v) {
				tmp.push_back(e);
			}
			swap(tmp);
		}*/
		//��ֵ��������� - �ִ�д��
		vector<T>& operator=(vector<T> v) {
			swap(v);
			return *this;
		}

		~vector() {
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}
		// capacity
		int size() const {
			return _finish - _start;
		}
		int capacity() const {
			return _end_of_storage - _start;
		}
		void reserve(size_t n) {
			if (n > capacity()) {
				int oldSize = size();
				int newCapacity = n;
				T* tmp = new T[newCapacity];
				if (_start) {
					//memcpy(tmp, _start, oldSize*sizeof(T));
					//���memcpy�����Ķ��������⣬
					for (int i = 0; i < oldSize; i++) {
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + oldSize;
				_end_of_storage = tmp + newCapacity;
			}
		}
		void resize(size_t n, const T& val = T()) {
			//n > capacity()
			//size() < n <= capacity()
			// n <= size()
			if (n > capacity()) {
				reserve(n);
			}
			if (n > size()) {
				while (_finish < _start + n) {
					*_finish = val;
					_finish++;
				}
			}
			else {
				_finish = _start + n;
			}
		}
		///////////////access///////////////////////////////
		T& operator[](size_t pos) {
			assert(pos < _finish - _start);
			return _start[pos];
		}
		const T& operator[](size_t pos)const {
			assert(pos < _finish - _start);
			return _start[pos];
		}

		///////////////modify/////////////////////////////
		void push_back(const T& val) {
			if (_finish == _end_of_storage) {
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			*_finish = val;
			_finish++;
		}
		void pop_back() {
			assert(!empty());
			_finish--;
		}
		void swap(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		void insert(iterator pos, const T& val) {
			assert(pos >= _start && pos <= _finish);
			if (_finish == _end_of_storage) {
				int len = pos - _start;
				int newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
				//������ʧЧ - ָ��posָ��ԭ���ռ��λ�ã����º�������Ƿ������ڴ棬Ұָ���ˣ���Ҫ����һ��
				pos = _start + len;
			}
			//�ƶ�Ԫ�� - �Ӻ���ǰ
			iterator end = _finish;
			while (end > pos) {
				*end = *(end - 1);
				end--;
			}
			_finish++;
			*pos = val;
		}
		
		//������pos��ɾ�������ʧЧ�������Ϊ�ˣ�erase�����µĵ�����λ�����ڸ���pos
		iterator erase(iterator pos) {
			assert(pos < _finish && pos >= _start);
			
			iterator cur = pos + 1;
			while (cur < _finish) {
				*(cur - 1) = *cur;
				cur++;
			}
			--_finish;
			return pos;
		}
		
		bool empty() {
			return _start == _finish;
		}
		
	private:
		iterator _start;//��ʼ
		iterator _finish;//��ЧԪ�ص���һ����ַ
		iterator _end_of_storage;//���Ԫ�ص���һ����ַ
	};

	void prints(vector<int>& v) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	void test01() {
		vector<int> v1;
		prints(v1);
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		prints(v1);

		cout << v1.size() << endl;
		cout << v1.capacity() << endl;

		v1.reserve(100);
		cout << v1.capacity() << endl << endl;

		cout << v1.size() << endl;
		v1.resize(200);
		prints(v1);
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		v1.resize(10);
		prints(v1);
		cout << v1.size() << endl;
		v1.resize(20, 9);
		prints(v1);
		cout << v1.size() << endl;
	}

	void test02() {
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		v1.push_back(5);
		prints(v1);

		v1.insert(v1.begin(), 10);
		v1.insert(v1.begin(), 11);
		v1.insert(v1.begin()+5, 99);
		prints(v1);

		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		prints(v1);
		/*v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		v1.pop_back();
		prints(v1);*/
	}
	void test03() {
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		//v1.push_back(5);
		prints(v1);
		/*std::vector<int>::iterator it = find(v1.begin(), v1.end(), 3);
		if (it != v1.end()) {
			v1.erase(it);
		}
		prints(v1);*/


		
		//ɾ������ż��
		vector<int>::iterator it = v1.begin();
		while (it != v1.end()) {
			if ((*it) % 2 == 0) {
				it = v1.erase(it);
			}
			else {
				it++;
			}
			
		}
		prints(v1);
	}

	void test04() {
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		prints(v1);

		vector<int> v2(v1);
		prints(v2);

		vector<int> v3;
		v3 = v1;
		prints(v3);
	}

	//����������Ԫ�ػ���������ʱ��������������⣬������ʽ�Ľ���˵�һ��������ڶ�������ǳ���������´���
	void test05() {
		/*vector<int> v(10, 1);
		prints(v);*/

		vector<vector<int>> vv;
		vector<int> v(10, 1);
		vv.push_back(v);
		vv.push_back(v);
		vv.push_back(v);
		vv.push_back(v);
		vv.push_back(v);

		for (int i = 0; i < vv.size(); i++) {
			for (int j = 0; j < vv[i].size(); j++) {
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
	}
}
