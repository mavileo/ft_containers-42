#include "stack.hpp"

namespace ft {

	template < class T >
	class vector_iterator {
		public :
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef value_type*				pointer;
			typedef const value_type*		const_pointer;
			typedef typename std::ptrdiff_t difference_type;

			vector_iterator(void) {}
			vector_iterator(pointer ptr) { _ptr = ptr; }
			vector_iterator(vector_iterator const &src) { *this = src; } ;
			vector_iterator &operator=(vector_iterator const &src) { _ptr = src.operator->(); return (*this); }
			~vector_iterator() {}

			vector_iterator operator ++() {
				_ptr++;
				return (*this);
			}
		
			vector_iterator operator ++(int) {
				_ptr++;
				return (vector_iterator(_ptr - 1));
			}
		
			vector_iterator operator --() {
				_ptr--;
				return (*this);
			}
		
			vector_iterator operator --(int) {
				_ptr--;
				return (vector_iterator(_ptr + 1));
			}

			void operator +=(difference_type v) { _ptr += v; }
			void operator -=(difference_type v) { _ptr -= v; }

			bool operator ==(vector_iterator const& v) const { return _ptr == v._ptr; }
			bool operator !=(vector_iterator const& v) const { return _ptr != v._ptr; }
			bool operator <(vector_iterator const& v) const { return _ptr < v._ptr; }
			bool operator <=(vector_iterator const& v) const { return _ptr <= v._ptr; }
			bool operator >(vector_iterator const& v) const { return _ptr > v._ptr; }
			bool operator >=(vector_iterator const& v) const { return _ptr >= v._ptr; }

			vector_iterator operator +(difference_type v) { return vector_iterator(_ptr + v); }
			vector_iterator operator -(difference_type v) { return vector_iterator(_ptr - v); }
			difference_type operator +(vector_iterator v) { return _ptr + v._ptr; }
			difference_type operator -(vector_iterator v) { return _ptr - v._ptr; }

			reference operator *() { return *_ptr; }
			const_reference operator *() const { return *_ptr; }
			pointer operator ->() { return _ptr; }
			pointer operator ->() const { return _ptr; }
			reference operator [](difference_type n) { return *(_ptr + n); }
			const_reference operator [](difference_type n) const { return *(_ptr + n); }

			pointer get_ptr() { return _ptr; }
		private :
			pointer _ptr;
	};


	template < class T >
	class vector_const_iterator {
		public :
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef value_type*				pointer;
			typedef const value_type*		const_pointer;
			typedef typename std::ptrdiff_t difference_type;

			vector_const_iterator(void) {}
			vector_const_iterator(pointer ptr) { _ptr = ptr; }
			vector_const_iterator(vector_iterator<T> const &src) { _ptr = src.operator->(); }
			vector_const_iterator(vector_const_iterator const &src) { *this = src; }
			vector_const_iterator &operator=(vector_const_iterator const &src) { _ptr = src.operator->(); return (*this); }
			~vector_const_iterator() {}

			vector_const_iterator operator ++() {
				_ptr++;
				return (*this);
			}
		
			vector_const_iterator operator ++(int) {
				_ptr++;
				return (vector_const_iterator(_ptr - 1));
			}
		
			vector_const_iterator operator --() {
				_ptr--;
				return (*this);
			}
		
			vector_const_iterator operator --(int) {
				_ptr--;
				return (vector_const_iterator(_ptr + 1));
			}

			bool operator ==(vector_const_iterator const& v) const { return _ptr == v._ptr; }
			bool operator !=(vector_const_iterator const& v) const { return _ptr != v._ptr; }
			bool operator <(vector_const_iterator const& v) const { return _ptr < v._ptr; }
			bool operator <=(vector_const_iterator const& v) const { return _ptr <= v._ptr; }
			bool operator >(vector_const_iterator const& v) const { return _ptr > v._ptr; }
			bool operator >=(vector_const_iterator const& v) const { return _ptr >= v._ptr; }

			vector_const_iterator operator +(difference_type v) { return vector_const_iterator(_ptr + v); }
			vector_const_iterator operator -(difference_type v) { return vector_const_iterator(_ptr - v); }
			difference_type operator +(vector_const_iterator v) { return _ptr + v._ptr; }
			difference_type operator -(vector_const_iterator v) { return _ptr - v._ptr; }

			const_reference operator *() const { return *_ptr; }
			pointer operator ->() { return _ptr; }
			pointer operator ->() const { return _ptr; }
			const_reference operator [](difference_type n) const { return *(_ptr + n); }

			pointer get_ptr() { return _ptr; }
		private :
			pointer _ptr;
	};


	template < class iterator >
	class vector_reverse_iterator {
		public :
			typedef iterator							iterator_type;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::difference_type	difference_type;

			vector_reverse_iterator(void) {}
			vector_reverse_iterator(pointer ptr) { _ptr = ptr; }
			vector_reverse_iterator(vector_iterator<value_type> const &src) { _ptr = src.operator->(); }
			vector_reverse_iterator(vector_reverse_iterator const &src) { *this = src; } ;
			vector_reverse_iterator &operator=(vector_reverse_iterator const &src) { _ptr = src.operator->(); return (*this); }
			~vector_reverse_iterator() {}

			vector_reverse_iterator operator ++() {
				_ptr--;
				return (*this);
			}
		
			vector_reverse_iterator operator ++(int) {
				_ptr--;
				return (vector_reverse_iterator(_ptr + 1));
			}
		
			vector_reverse_iterator operator --() {
				_ptr++;
				return (*this);
			}
		
			vector_reverse_iterator operator --(int) {
				_ptr++;
				return (vector_reverse_iterator(_ptr - 1));
			}

			void operator +=(difference_type v) { _ptr -= v; }
			void operator -=(difference_type v) { _ptr += v; }

			bool operator ==(vector_reverse_iterator const& v) const { return _ptr == v._ptr; }
			bool operator !=(vector_reverse_iterator const& v) const { return _ptr != v._ptr; }
			bool operator <(vector_reverse_iterator const& v) const { return _ptr < v._ptr; }
			bool operator <=(vector_reverse_iterator const& v) const { return _ptr <= v._ptr; }
			bool operator >(vector_reverse_iterator const& v) const { return _ptr > v._ptr; }
			bool operator >=(vector_reverse_iterator const& v) const { return _ptr >= v._ptr; }

			vector_reverse_iterator operator +(difference_type v) { return vector_reverse_iterator(_ptr - v); }
			vector_reverse_iterator operator -(difference_type v) { return vector_reverse_iterator(_ptr + v); }
			difference_type operator +(vector_reverse_iterator v) { return _ptr - v._ptr; }
			difference_type operator -(vector_reverse_iterator v) { return _ptr + v._ptr; }

			reference operator *() { return *_ptr; }
			const_reference operator *() const { return *_ptr; }
			pointer operator ->() { return _ptr; }
			pointer operator ->() const { return _ptr; }
			reference operator [](difference_type n) { return *(_ptr + n); }
			const_reference operator [](difference_type n) const { return *(_ptr + n); }

			pointer get_ptr() { return _ptr; }
		private :
			pointer _ptr;
	};


	template < class iterator >
	class vector_const_reverse_iterator {
		public :
			typedef iterator							iterator_type;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::difference_type	difference_type;

			vector_const_reverse_iterator(void) {}
			vector_const_reverse_iterator(pointer ptr) { _ptr = ptr; }
			vector_const_reverse_iterator(vector_iterator<value_type> const &src) { _ptr = src.operator->(); }
			vector_const_reverse_iterator(vector_const_reverse_iterator const &src) { *this = src; } ;
			vector_const_reverse_iterator &operator=(vector_const_reverse_iterator const &src) { _ptr = src.operator->(); return (*this); }
			~vector_const_reverse_iterator() {}

			vector_const_reverse_iterator operator ++() {
				_ptr--;
				return (*this);
			}

			vector_const_reverse_iterator operator ++(int) {
				_ptr--;
				return (vector_const_reverse_iterator(_ptr + 1));
			}

			vector_const_reverse_iterator operator --() {
				_ptr++;
				return (*this);
			}
		
			vector_const_reverse_iterator operator --(int) {
				_ptr++;
				return (vector_const_reverse_iterator(_ptr - 1));
			}

			bool operator ==(vector_const_reverse_iterator const& v) const { return _ptr == v._ptr; }
			bool operator !=(vector_const_reverse_iterator const& v) const { return _ptr != v._ptr; }
			bool operator <(vector_const_reverse_iterator const& v) const { return _ptr < v._ptr; }
			bool operator <=(vector_const_reverse_iterator const& v) const { return _ptr <= v._ptr; }
			bool operator >(vector_const_reverse_iterator const& v) const { return _ptr > v._ptr; }
			bool operator >=(vector_const_reverse_iterator const& v) const { return _ptr >= v._ptr; }

			vector_const_reverse_iterator operator +(difference_type v) { return vector_const_reverse_iterator(_ptr - v); }
			vector_const_reverse_iterator operator -(difference_type v) { return vector_const_reverse_iterator(_ptr + v); }
			difference_type operator +(vector_const_reverse_iterator v) { return _ptr - v._ptr; }
			difference_type operator -(vector_const_reverse_iterator v) { return _ptr + v._ptr; }

			const_reference operator *() const { return *_ptr; }
			pointer operator ->() { return _ptr; }
			pointer operator ->() const { return _ptr; }
			const_reference operator [](difference_type n) const { return *(_ptr + n); }

			pointer get_ptr() { return _ptr; }
		private :
			pointer _ptr;
	};


	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public :
			typedef T 								value_type;
			typedef Alloc							allocator_type;
			typedef typename std::size_t 			size_type;
			typedef typename std::ptrdiff_t 		difference_type;
			typedef typename Alloc::reference 		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;

			typedef typename ft::vector_iterator<T>							iterator;
			typedef typename ft::vector_const_iterator<T>					const_iterator;
			typedef typename ft::vector_reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::vector_const_reverse_iterator<iterator>	const_reverse_iterator;

			explicit vector (const allocator_type& alloc = allocator_type()) {
				_alloc = alloc;
				_ptr = NULL;
				_size = 0;
				_size_alloc = 0;
			}

			template <class InputIterator>
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
				_alloc = alloc;
				_ptr = NULL;
				_size = 0;
				_size_alloc = 0;
				while (first != last) {
					push_back(*first);
					first++;
				}
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				_alloc = alloc;
				_ptr = NULL;
				_size = 0;
				_size_alloc = 0;
				while (n--)
					push_back(val);
			}

			vector (const vector& x) { *this = x; }

			~vector () {
				clear();
				//if (_size_alloc > 0)
					//_alloc.deallocate(_ptr, _size_alloc);
				//_size_alloc = 0;
			}

			// ITERATORS

			iterator begin() { return iterator(_ptr); }
			const_iterator begin() const { return const_iterator(_ptr); }

			iterator end() { return iterator(_ptr + _size); }
			const_iterator end() const { return const_iterator(_ptr + _size); }

			reverse_iterator rbegin() { return reverse_iterator(_ptr + _size - 1); }
			const_reverse_iterator rbegin() const { return rbegin(); }

			reverse_iterator rend() { return reverse_iterator(_ptr - 1); }
			const_reverse_iterator rend() const { return rend(); }


			// CAPACITY

			size_type size() const { return _size; }

			size_type max_size() const { return std::numeric_limits<size_type>::max(); }

			void resize (size_type n, value_type val = value_type()) {
				value_type *new_ptr;

				new_ptr = _alloc.allocate(n);
				if (n > _size) {
					for (size_t i = 0; i < _size; i++)
						_alloc.construct(new_ptr + i, *(_ptr + i));
					for (size_t i = 0; i < n - _size; i++)
						_alloc.construct(new_ptr + _size + i, val);
				}
				else {
					for (size_t i = 0; i < n; i++)
						_alloc.construct(new_ptr + i, *(_ptr + i));
				}
				if (_size) {
					_alloc.destroy(_ptr);
					_alloc.deallocate(_ptr, _size_alloc);
				}
				_size_alloc = n;
				_size = n;
				_ptr = new_ptr;
			}

			size_type capacity() const { return _size_alloc; }

			bool empty() const { return (_size == 0); }

			void reserve(size_type n) {
				value_type	*new_ptr;

				if (n <= _size_alloc)
					return ;
				new_ptr = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
					_alloc.construct(new_ptr + i, *(_ptr + i));
				_size_alloc = n;
				_ptr = new_ptr;
			}

			// ELEMENT ACCESS

			reference operator[] (size_type n) { return _ptr[n]; }
			const_reference operator[] (size_type n) const { return _ptr[n]; }

			reference		at(size_type n) {
				if (n >= _size)
					throw std::out_of_range(std::to_string(n));
				return (_ptr[n]);
			}
			const_reference	at(size_type n) const {
				if (n >= _size)
					throw std::out_of_range(std::to_string(n));
				return (_ptr[n]);
			}

			reference front() { return *_ptr; }
			const_reference	front() const { return *_ptr; }

			reference back() { return *(_ptr + (_size - 1)); }
			const_reference	back() const { return *(_ptr + (_size - 1)); }


			// MODIFIERS

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) {
				clear();
				while (first != last)
					push_back(first++);
			}

			void assign (size_type n, const value_type& val) {
				clear();
				while (n--)
					push_back(val);
			}

			void push_back (const value_type& val) {
				if (_size == _size_alloc)
					_extend();
				_alloc.construct(_ptr + _size, val);
				_size++;
			}

			void pop_back () {
				if (!_size)
					return ;
				_alloc.destroy(_ptr + _size - 1);
				_size--;
			}

			iterator	insert(iterator position, const value_type& val) {
				iterator fit;
				difference_type diff = position - begin();

				if (capacity() == size())
					_extend();
				fit = begin() + diff;

				vector tmp(fit, end());
				for (size_t i = 0; i < tmp.size(); i++)
					pop_back();
				push_back(val);
				iterator it = tmp.begin();
				for (size_t i = 0; i < tmp.size(); i++, it++)
					push_back(*it);
				return begin() + diff;
			};

			void insert(iterator position, size_type n, const value_type& val) {
				difference_type	diff = position - begin();

				while (_size_alloc - _size < n)
					_extend();
				vector tmp(begin() + diff, end());
				for (size_t i = 0; i < tmp.size(); i++)
					pop_back();
				while (n-- > 0)
					push_back(val);
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
			}

			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last) {
				size_t i = 0;
				difference_type diff = position - this->begin();

				while (first != last) {
					first++;
					i++;
				}
				first -= i;
				while (_size_alloc - _size < i)
					_extend();

				vector tmp(begin() + diff, end());

				for (size_t j = 0; j < tmp.size(); j++)
					pop_back();
				while (first != last)
					push_back(*(first++));
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
			}

			iterator erase (iterator position) {
				vector	tmp(position + 1, end());

				for (size_t i = 0; i <= tmp.size(); i++)
					pop_back();
				for (iterator it = tmp.begin(); it != tmp.end(); it++)
					push_back(*it);
				return (position);
			}

			iterator erase (iterator first, iterator last) {
				iterator tmp(first);

				while (tmp++ != last)
					erase(first);
				return (first);
			}

			void swap (vector& x) {
				T	*tmp_ptr = x._ptr;
				size_t tmp_size = x._size;
				size_t tmp_size_alloc = x._size_alloc;

				x._ptr = _ptr;
				x._size = _size;
				x._size_alloc = _size_alloc;

				_ptr = tmp_ptr;
				_size = tmp_size;
				_size_alloc = tmp_size_alloc;
			}

			void clear()
			{
				if (_size > 0)
				{
					iterator it = this->begin();
					while (it != this->end())
						_alloc.destroy(&(*it++));
					_size = 0;
				}
			}


		private :
			allocator_type	_alloc;
			value_type		*_ptr;
			size_t			_size_alloc;
			size_t			_size;

			void _extend(void) {
				if (_size_alloc == 0) {
					_ptr = _alloc.allocate(1);
					_size_alloc++;
				}
				else {
					T *new_arr = _alloc.allocate(_size_alloc * 2);
					for (size_t i = 0; i < _size; i++) {
						_alloc.construct(new_arr + i, *(_ptr + i));
						_alloc.destroy(_ptr + i);
					}
					_alloc.deallocate(_ptr, _size_alloc);
					_ptr = new_arr;
					_size_alloc *= 2;
				}
			};
	};


	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename ft::vector<T>::const_iterator	it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator	it_rhs = rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (it_lhs != lhs.end() && it_rhs != rhs.end() && *it_lhs == *it_rhs) {
			it_lhs++;
			it_rhs++;
		}
		return (it_lhs == lhs.end() && it_rhs == rhs.end());
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename ft::vector<T>::const_iterator	it_lhs = lhs.begin();
		typename ft::vector<T>::const_iterator	it_rhs = rhs.begin();

		if (lhs == rhs)
			return (false);
		while (it_lhs != lhs.end() && it_rhs != rhs.end() && *it_lhs == *it_rhs) {
			it_lhs++;
			it_rhs++;
		}
		if (it_rhs != rhs.end())
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs == rhs || lhs < rhs) ? true : false;
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs) && !(lhs < rhs)) ? true : false;
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs)) ? true : false;
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
}
