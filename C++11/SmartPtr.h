#pragma once
//智能指针
namespace weihe {
	template<class T>
	class auto_ptr {
	public:
		auto_ptr(T* p)
			:_ptr(p) { }
		~auto_ptr() {
			delete[] _ptr;
			cout << _ptr << endl;
			_ptr = nullptr;
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
		T& operator[](size_t pos) {
			return *(_ptr + pos);
		}
	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr {
	public:
		unique_ptr(T* p)
			:_ptr(p) { }
		~unique_ptr() {
			delete _ptr;
			_ptr = nullptr;
		}
		T& operator*() {
			return *_ptr;
		}
		T* operator->() {
			return _ptr;
		}
	private:
		unique_ptr(const unique_ptr<T>& up) {

		}
		unique_ptr<T>& operator=(const unique_ptr<T>& up) {

		}
		T* _ptr;
	};

	//思路：1.计数器	2.map或unordered_map容器，使每个shared_ptr对象与指针对应起来
	template<class T>
	class shared_ptr {
	public:
		shared_ptr(T* p)
			:_ptr(p) {
			_pcount = new int;
			*_pcount = 1;
		}
		~shared_ptr() {
			if (--(*_pcount) == 0) {
				delete _ptr;
				_ptr = nullptr;
				delete _pcount;
				_pcount = nullptr;
			}
		}
		T& operator*() {
			return *_ptr;
		}
		/*T* operator->() {
			return _ptr;
		}*/
		shared_ptr(const shared_ptr<T>& sp) {
			_ptr = sp._ptr;
			_pcount = sp._pcount;
			(*_pcount)++;
		}
		shared_ptr<T>& operator=(const shared_ptr& sp) {
			if (_ptr != sp._ptr) {
				if (--(*_pcount) == 0) {
					delete _ptr;
					delete _pcount;
				}
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				(*_pcount)++;
			}
			return *this;
		}
		int use_count() const {
			return *_pcount;
		}
	private:
		T* _ptr;
		int* _pcount;
	};

	void SmartPtrTest01() {
		const int n = 100000;
		shared_ptr<int> sp1(new int);
		thread t1([&]() {
			for (int i = 0; i < n; ++i) {
				shared_ptr<int> sp2(sp1);
				cout << sp1.use_count() << endl;

			}
			}
		);
		thread t2([&]() {
			for (int i = 0; i < n; ++i) {
				shared_ptr<int> sp3(sp1);
				cout << sp1.use_count() << endl;

			}
		}
		);

		t1.join();
		t2.join();
		cout << sp1.use_count() << endl;
	}
}
