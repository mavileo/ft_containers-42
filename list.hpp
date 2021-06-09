#include <memory>
#include <unistd.h>

template < class T >
class Node {
	private :
		T value;
		Node *prev;
		Node *next;
		bool last;

	public :
	
		Node() {
			value = 0;
			prev = NULL;
			next = NULL;
			last = true;
		}

		Node(T val, Node<T> *p, Node<T> *n) {
			value = val;
			prev = p;
			next = n;
			last = false;
		}

		~Node() {}

		void	set_value(T val) {
			value = val;
		}
		void	set_prev(Node<T> *prevPtr) {
			prev = prevPtr;
		}
		void	set_next(Node<T> *nextPtr) {
			next = nextPtr;
		}
		void	set_last(bool l) {
			last = l;
		}

		T	&get_value() {
			return value;
		}
		Node	*get_prev() {
			return prev;
		}
		Node	*get_next() {
			return next;
		}
		bool	get_last() {
			return last;
		}
		Node	*get_ptr() {
			return this;
		}

};

namespace ft {
	template < class T >
	class list_iterator {
		public :
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef Node<T>*				pointer;
			typedef Node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t	difference_type;

			list_iterator() {}
			list_iterator(pointer p) {ptr = p;}
			list_iterator &operator= (const list_iterator& cp) {
				if (&cp == this)
					return (*this);
				this->_node = cp._node;
				return (*this);
			}
			~list_iterator() {}

			list_iterator operator ++() { ptr = ptr->get_next(); return (*this); }

			list_iterator operator ++(int)
			{
				list_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			list_iterator operator --() { ptr = ptr->get_prev(); return (*this); }

			list_iterator operator --(int)
			{
				list_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			list_iterator operator =(value_type val)
			{
				ptr->set_value(val);
				return this;
			}

			bool operator ==(list_iterator const& b) const { return (ptr == b.ptr); }
			bool operator !=(list_iterator const& b) const { return (ptr != b.ptr); }

			value_type operator *() { return (ptr->get_last()) ? ptr->get_next()->get_value() : ptr->get_value(); }
			const_reference operator *() const { return (ptr->get_last()) ? ptr->get_next()->get_value() : ptr->get_value(); }
			pointer operator ->() { return (ptr); }
			pointer operator ->() const { return (ptr); }

			pointer get_ptr() { return ptr; };
		private :
			pointer ptr;
	};

	template < class T >
	class list_const_iterator {
		public :
			typedef T						value_type;
			typedef value_type&				reference;
			typedef const value_type&		const_reference;
			typedef Node<T>*				pointer;
			typedef Node<T> const *			const_pointer;
			typedef typename std::ptrdiff_t	difference_type;

			list_const_iterator() {}
			list_const_iterator(pointer p) {ptr = p;}
			list_const_iterator &operator= (const list_const_iterator& cp)
			{
				if (&cp == this)
					return (*this);
				this->_node = cp._node;
				return (*this);
			}
			~list_const_iterator() {}

			list_const_iterator operator ++() { ptr = ptr->get_next(); return (*this); }

			list_const_iterator operator ++(int)
			{
				list_const_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			list_const_iterator operator --() { ptr = ptr->get_prev(); return (*this); }

			list_const_iterator operator --(int)
			{
				list_const_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			bool operator ==(list_const_iterator const& b) const { return (ptr == b.ptr); }
			bool operator !=(list_const_iterator const& b) const { return (ptr != b.ptr); }

			const_reference operator *() const { return (ptr->get_last()) ? ptr->get_next()->get_value() : ptr->get_value(); }
			pointer operator ->() { return (ptr); }
			pointer operator ->() const { return (ptr); }

			pointer get_ptr() { return ptr; };
		private :
			pointer ptr;
	};

	template < class iterator >
	class list_reverse_iterator {
		public :
			typedef iterator							iterator_type;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::difference_type	difference_type;

			list_reverse_iterator() {}
			list_reverse_iterator(pointer p) {ptr = p;}
			list_reverse_iterator &operator= (const list_reverse_iterator& cp)
			{
				if (&cp == this)
					return (*this);
				this->_node = cp._node;
				return (*this);
			}
			~list_reverse_iterator() {}

			iterator_type base() const {
				return (ptr->get_next()->get_last()) ? ptr->get_next()->get_next() : ptr->get_next();
			}

			list_reverse_iterator operator ++() { ptr = ptr->get_prev(); return (*this); };

			list_reverse_iterator operator ++(int)
			{
				list_reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			list_reverse_iterator operator --() { ptr = ptr->get_next(); return (*this); };

			list_reverse_iterator operator --(int)
			{
				list_reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			bool operator ==(list_reverse_iterator const& b) const { return (ptr == b.ptr); };
			bool operator !=(list_reverse_iterator const& b) const { return (ptr != b.ptr); };

			value_type operator *() { return (ptr->get_last()) ? ptr->get_next()->get_value() : ptr->get_value(); };
			const_reference operator *() const { return (ptr->get_last()) ? ptr->get_next()->get_value() : ptr->get_value(); };
			pointer operator ->() { return (ptr); };
			pointer operator ->() const { return (ptr); };	
			reference operator [](difference_type n) {
				difference_type i = 0;
				
				while (i++ < n) {
					ptr++;
				}
				return (ptr->get_value());
			};
		private :
			pointer ptr;
	};

	template < class iterator >
	class list_const_reverse_iterator {
		public :
			typedef iterator							iterator_type;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::difference_type	difference_type;

			list_const_reverse_iterator() {}
			list_const_reverse_iterator(pointer p) {ptr = p;}
			list_const_reverse_iterator &operator= (const list_const_reverse_iterator& cp)
			{
				if (&cp == this)
					return (*this);
				this->_node = cp._node;
				return (*this);
			}
			~list_const_reverse_iterator() {}

			iterator_type base() const {
				return (ptr->get_next()->get_last()) ? ptr->get_next()->get_next() : ptr->get_next();
			}

			list_const_reverse_iterator operator ++() { ptr = ptr->get_prev(); return (*this); };

			list_const_reverse_iterator operator ++(int)
			{
				list_const_reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			};

			list_const_reverse_iterator operator --() { ptr = ptr->get_next(); return (*this); };

			list_const_reverse_iterator operator --(int)
			{
				list_const_reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			};

			bool operator ==(list_const_reverse_iterator const& b) const { return (ptr == b.ptr); };
			bool operator !=(list_const_reverse_iterator const& b) const { return (ptr != b.ptr); };

			const_reference operator *() const { return (ptr->get_last()) ? ptr->get_next()->get_value() : ptr->get_value(); };
			pointer operator ->() { return (ptr); };
			pointer operator ->() const { return (ptr); };	
		private :
			pointer ptr;
	};


	template < class T, class Alloc = std::allocator<T> >
	class list {

		public :
			typedef T													value_type;
			typedef Alloc												allocator_type;
			typedef typename std::size_t								size_type;
			typedef typename std::ptrdiff_t								difference_type;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;

			typedef typename ft::list_iterator<T>						iterator;
			typedef typename ft::list_const_iterator<T>					const_iterator;
			typedef typename ft::list_reverse_iterator<iterator>		reverse_iterator;
			typedef typename ft::list_const_reverse_iterator<iterator>	const_reverse_iterator;

			// MEMBER FUNCS
			explicit list (const allocator_type& alloc = allocator_type()) {
				(void)alloc;
				_node = NULL;
				_size = 0;
				_last = new Node<T>();
			}
			explicit list (size_type n, const value_type& val = value_type(),
            const allocator_type& alloc = allocator_type()) {
				(void)alloc;
				_node = NULL;
				_size = 0;
				_last = new Node<T>();
				while (n--)
					push_back(val);
			}
			template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
				(void)alloc;
				_node = NULL;
				_size = 0;
				_last = new Node<T>();
				while (first != last) {
					this->push_back(*first);
					first++;
				}
			}
			list (const list& x) {
				const_iterator first = x.begin();
				const_iterator last = x.end();

				_node = NULL;
				_size = 0;
				_last = new Node<T>();
				while (first != last) {
					this->push_back(*first);
					first++;
				}
			}

			list& operator= (const list& x) {
				const_iterator first = x.begin();
				const_iterator last = x.end();

				_node = NULL;
				_size = 0;
				_last = new Node<T>();
				while (first != last) {
					this->push_back(*first);
					first++;
				}
				return *this;
			}

			~list() {
				//this->clear();
				//delete _last;
			}

			// ITERATORS
			iterator begin() {
				return (_last->get_prev()) ? iterator(_node) : iterator(_last);
			}
			const_iterator begin() const { 
				return (_last->get_prev()) ? const_iterator(_node) : const_iterator(_last);
			}
			reverse_iterator rbegin() {
				return (_last->get_prev()) ? reverse_iterator(_last->get_prev()) : iterator(_last);
			}
			const_reverse_iterator rbegin() const { 
				return (_last->get_prev()) ? const_reverse_iterator(_node) : const_reverse_iterator(_last);
			}
			iterator end() {
				return iterator(_last);
			}
			const_iterator end() const {
				return const_iterator(_last);
			}
			reverse_iterator rend() {
				return reverse_iterator(_last);
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(_last);
			}

			// CAPACITY
			bool empty() {
				if (_size)
					return false;
				return true;
			}
			size_t size() const {
				return _size;
			}
			size_t max_size() const {
				return std::numeric_limits<size_t>::max() / (sizeof(value_type));
			}			

			// ELEMENT ACCESS
			reference front() {
				return _node->get_value();
			}
			reference back() {
				return _last->get_prev()->get_value();
			}

			// MODIFIERS
			void assign (size_type n, const value_type& val) {
				this->clear();
				while (n--)
					push_back(val);
			}
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last) {
				this->clear();
				while (first != last)
					push_back((first++)->get_value());
			}
			void push_front(T value) {
				if (!_node) {
					Node<T> *n = new Node<T>(value, _last, _last);
					_last->set_prev(n);
					_last->set_next(n);
					_node = n;
				}
				else {
					Node<T> *n = new Node<T>(value, _last, _node);
					_node->set_prev(n);
					_last->set_next(n);
					_node = n;
				}
				_size++;
			}
			void pop_front() {
				if (!_node) {
					return ;
				} else if (_node->get_next() == _last) {
					delete _node;
					_node = NULL;
				} else {
					_node->get_next()->set_prev(NULL);
					Node<T> *tmp = _node;
					_node = _node->get_next();
					_last->set_next(_node);
					delete tmp;
				}
				_size--;
			}
			void push_back(T value) {
				if (!_node) {
					Node<T> *n = new Node<T>(value, _last, _last);
					_last->set_prev(n);
					_last->set_next(n);
					_node = n;
				}
				else {
					Node<T> *last = _last->get_prev();
					Node<T> *n = new Node<T>(value, last, _last);
					last->set_next(n);
					_last->set_prev(n);
				}
				_size++;
			}
			void pop_back() {
				if (!_node) {
					return ;
				} else if (_node->get_next() == _last) {
					delete _node;
					_node = NULL;
				} else {
					Node<T> *last = _last->get_prev();
					last->get_prev()->set_next(_last);
					_last->set_prev(last->get_prev());
					delete last;
				}
				_size--;
			}
			iterator insert (iterator position, const value_type& val) {
				_push_node(position, val);
				return position->get_prev();
			}
			void insert (iterator position, size_type n, const value_type& val) {
				
				while (n--)
					_push_node(position, val);
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last) {
				while (first != last) {
					value_type val = first->get_value();
					insert(position, val);
					first++;
				}
			}
			iterator erase (iterator position) {
				iterator ret = position->get_next();
				_pop_node(position);
				return (ret);
			}
			iterator erase(iterator first, iterator last) {
				while (first != last)
					erase(first++);
				return (last);
			}
			void swap (list& x) {
				Node<T> *n = _node;
				size_t s = _size;
				Node<T> *l = _last;
				
				_node = x._node;
				_size = x._size;
				_last = x._last;

				x._node = n;
				x._size = s;
				x._last = l;
			}
			void resize (size_type n, value_type val = value_type()) {
				if (_size < n)
					while (_size < n)
						this->push_back(val);
				else
					while (_size > n)
						this->pop_back();
			}
			void clear() {
				if (!_node) {
					return ;
				} else {
					_node = _node->get_next();
					while (_node != _last) {
						delete _node->get_prev();
						_node = _node->get_next();
					}
					delete _node->get_prev();
					_node = NULL;
					_last->set_prev(NULL);
					_last->set_next(NULL);
					_size = 0;
				}
			}

			// OPERATIONS
			void splice (iterator position, list& x) {
				iterator beg = x.begin();
				
				while (beg != x.end())
					_push_node(position, (beg++)->get_value());
				x.clear();
			}
			void splice (iterator position, list& x, iterator i) {
				(void)x;
				i->get_next()->set_prev(i->get_prev());
				i->get_prev()->set_next(i->get_next());
				_push_node(position, i->get_value());
				//delete i->get_ptr();
			}
			void splice (iterator position, list& x, iterator first, iterator last) {
				(void)x;
				if (first == x.begin() && last == x.end())
					return splice(position, x);
				while (first != last) {
					first->get_next()->set_prev(first->get_prev());
					first->get_prev()->set_next(first->get_next());
					_push_node(position, first->get_value());
					first++;
					//delete first->get_prev();
				}
			}
			void remove (const value_type& val) {
				iterator it = begin();

				while (it != end()) {
					if (it->get_value() == val)
						_pop_node(it);
					it++;
				}
			}
			template <class Predicate>
			void remove_if (Predicate pred) {
				iterator it = begin();

				while (it != end()) {
					if (pred(*it))
						_pop_node(it);
					it++;
				}
			}
			void merge (list& x) {
				splice(_last->get_prev(), x);
				sort();
			}
			template <class Compare>
			void merge (list& x, Compare comp) {
				splice(_last->get_prev(), x);
				sort(comp);
			}
			void unique() {
				iterator it = begin();
				it++;

				while (it != end()) {
					if (it->get_value() == it->get_prev()->get_value())
						_pop_node(it);
					it++;
				}
			}
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred) {
				iterator it = begin();
				it++;

				while (it != end()) {
					if (binary_pred(it->get_value(), it->get_prev()->get_value()))
						_pop_node(it);
					it++;
				}
			}
			void sort() {
				iterator it = begin();

				while (++it != end()) {
					if (it->get_value() < it->get_prev()->get_value()) {
						_swap_nodes(it->get_prev(), it);
						sort();
					}
				}
			}
			template <class Compare>
			void sort (Compare comp) {
				iterator it = begin();

				while (++it != end()) {
					if (!comp(it->get_prev()->get_value(), it->get_value())) {
						_swap_nodes(it->get_prev(), it);
						sort();
					}
				}
			}
			void reverse() {
				size_t i = 0;
				
				while (i < _size / 2) {
					iterator it = _get_it(i);
					iterator it2 = _get_it(_size - i - 1);
					_swap_nodes(it, it2);
					i++;
				}
			}

		private :
			Node<T> *_node;
			size_t _size;
			Node<T> *_last;

			void _pop_node(int pos) {
				int i = 0;
				Node<T> *tmp = _node;
				
				if (pos < 0 || _size < 1 || pos > _size)
					return ;
				while (i++ < pos)
					tmp = tmp->get_next();
				if (tmp->get_prev() == _last && tmp->get_next() == _last)
					return this->clear();
				tmp->get_prev()->set_next(tmp->get_next());
				tmp->get_next()->set_prev(tmp->get_prev());
				delete tmp;
				_size--;
			}
			void _pop_node(iterator it) {
				if (it->get_ptr() == _node && it->get_next() != _last)
					_node = _node->get_next();
				if (it->get_prev() == _last && it->get_next() == _last)
					return this->clear();
				it->get_prev()->set_next(it->get_next());
				it->get_next()->set_prev(it->get_prev());
				delete it->get_ptr();
				_size--;
			}
			void _push_node(iterator it, const value_type& val) {
				Node<T> *tmp = new Node<T>(val, it->get_prev(), it->get_ptr());
				it->get_prev()->set_next(tmp);
				it->set_prev(tmp);
				_node = _last->get_next();
				_size++;
			}
			// it should be before it2 in the list
			void _swap_nodes(iterator it, iterator it2) {
				Node<T> *it_addr = it->get_ptr();
				Node<T> *tmp = new Node<T>(it->get_value(), it->get_prev(), it->get_next());

				if (_node == it->get_ptr())
					_node = it2->get_ptr();
				if (it->get_next() == it2->get_ptr()) {
					it->get_prev()->set_next(it2->get_ptr());
					
					it2->get_next()->set_prev(it_addr);
					
					it->set_prev(it2->get_ptr());
					it->set_next(it2->get_next());
					
					it2->set_next(it->get_ptr());
					it2->set_prev(tmp->get_prev());
				} else {
					it->get_prev()->set_next(it2->get_ptr());
					it->get_next()->set_prev(it2->get_ptr());
					
					it2->get_prev()->set_next(it_addr);
					it2->get_next()->set_prev(it_addr);
					
					it->set_prev(it2->get_prev());
					it->set_next(it2->get_next());
					
					it2->set_next(tmp->get_next());
					it2->set_prev(tmp->get_prev());
				}
			}
			iterator _get_it(size_t pos) {
				iterator it = begin();
				size_t i = 0;
				
				while (i < _size && i < pos) {
					it++;
					i++;
				}
				return it;
			}
			void	print_lst() {
				ft::list<int>::iterator it = begin();
				while (it != end()) {
					std::cout << *it << std::endl;
					it++;
				}
				std::cout << "\n";
			}

	};

	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		typename ft::list<T>::const_iterator	it = lhs.begin();
		typename ft::list<T>::const_iterator	it2 = rhs.begin();

		if (lhs.size() != rhs.size())
			return (false);
		while (it != lhs.end() && it2 != rhs.end() &&
				*it == *it2)
		{
			it++;
			it2++;
		}
		return (it == lhs.end() && it2 == rhs.end());
	};
	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		typename ft::list<T>::const_iterator	it = lhs.begin();
		typename ft::list<T>::const_iterator	it2 = rhs.begin();

		if (lhs == rhs)
			return (false);
		while (it != lhs.end() && it2 != rhs.end() &&
				*it == *it2)
		{
			it++;
			it2++;
		}
		if (it2 != rhs.end())
			return (true);
		return (false);
	};
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (lhs == rhs || lhs < rhs) ? true : false;
	};
	template <class T, class Alloc>
	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (!(lhs == rhs) && !(lhs < rhs)) ? true : false;
	};
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs) {
		return (!(lhs < rhs)) ? true : false;
	};
}

