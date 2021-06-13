#include "vector.hpp"

namespace ft {

	template <class Key, class T>
	class	map_node
	{
		public:

			typedef map_node<Key, T>		node;
			typedef node *					node_point;
			typedef const node *			const_node_point;
			typedef std::pair<Key, T>		value_type;

			map_node() {
				_top = NULL;
				_left = NULL;
				_right = NULL;
				_is_first = false;
			}

			map_node(bool f) {
				_top = NULL;
				_left = NULL;
				_right = NULL;
				_is_first = f;
			}

			map_node(value_type const &pair) {
				_keyval = pair;
				_top = NULL;
				_left = NULL;
				_right = NULL;
				_is_first = false;
			}

			map_node(value_type const &pair, node_point top) {
				_keyval = pair;
				_top = top;
				_left = NULL;
				_right = NULL;
				_is_first = false;
			}

			map_node(map_node const &src) { *this = src; }

			map_node &operator=(map_node const &src) {
				_keyval = src._keyval;
				_top = src._top;
				_left = src._left;
				_right = src._right;
				return (*this);
			}

			virtual ~map_node() {}

			void	set_top(const node_point node)	{ _top = node; };
			void	set_left(const node_point node)	{ _left = node; };
			void	set_right(const node_point node)	{ _right = node; };

			const_node_point	get_curr(void) const  { return (this); };
			node_point		get_top(void) const   { return (_top); };
			node_point		get_left(void) const  { return (_left); };
			node_point		get_right(void) const { return (_right); };

			void	set_key(const Key &key)		{ _keyval.first = key; };
			void	set_val(const T &val)		{ _keyval.second = val; };
			void	set_pair(const value_type &val)	{ *_keyval = val; };

			Key			&get_key(void) { return (_keyval.first); };
			Key const	&get_key(void) const { return (_keyval.first); };
			T			&get_val(void) { return (_keyval.second); };
			value_type	&get_pair(void) { return (_keyval); };
			bool		get_first(void) { return (_is_first); };
			//pair const	get_pair(void) const { return (_keyval); };

			node_point	get_left_most(node_point root) {
				while (root->get_left() && !root->get_left()->get_first())
					root = root->get_left();
				return root;
			}

			node_point	get_first(node_point root) {
				if (!root)
					return NULL;
				return get_left_most(root);
			}

			node_point	get_next(node_point root) {
				if (root->get_right())
					return get_left_most(root->get_right());
				else {
					while (root->get_top() && root == root->get_top()->get_right())
						root = root->get_top();
					return root->get_top();
				}
			}

			node_point	get_last(node_point root) {
				node_point n = get_first(root);
				node_point prev = NULL;

				while (n) {
					prev = n;
					n = get_next(n);
				}
				return prev;
			}


		private:

			value_type	_keyval;
			node_point	_top;
			node_point	_left;
			node_point	_right;
			bool		_is_first;
	};

	template < class Key, class T >
	class map_iterator {
		public :
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef std::pair<Key, T>					value_type;
			typedef typename std::size_t 					size_type;
			typedef typename std::ptrdiff_t 				difference_type;
			typedef map_node<Key, T>						node;
			typedef node*									node_point;
			typedef value_type *							pointer;
			typedef pointer									const_pointer;
			typedef value_type &							reference;
			typedef reference								const_reference;

			map_iterator() {}
			map_iterator(node_point p) {_ptr = p;}
			map_iterator(node_point r, node_point p) {_root = r; _ptr = p;}
			map_iterator &operator= (const map_iterator& cp) {
				if (&cp == this)
					return (*this);
				this->_ptr = cp._ptr;
				return (*this);
			}
			~map_iterator() {}

			map_iterator operator ++() { _ptr = _ptr->get_next(_ptr); return (*this); }

			map_iterator operator ++(int) {
				map_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			map_iterator operator --() { 
				if (!_ptr) {
					_ptr = _root->get_last(_root);
					return (*this);
				}
				node_point tmp = _root;
				node_point prev = NULL;
				while (tmp && tmp->get_val() != _ptr->get_val()) {
					prev = tmp;
					tmp = tmp->get_next(tmp);
				}
				_ptr = prev;
				return (*this);
			}

			map_iterator operator --(int)
			{
				map_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			map_iterator operator =(value_type val)
			{
				_ptr->set_val(val);
				return this;
			}

			bool operator ==(map_iterator const& b) const { return (_ptr == b._ptr); }
			bool operator !=(map_iterator const& b) const { return (_ptr != b._ptr); }

			reference operator *() { return _ptr->get_pair(); }
			const_reference operator *() const { return _ptr->get_pair(); }
			pointer operator ->() { return (&(_ptr->get_pair())); }
			const_pointer operator ->() const { return (&(_ptr->get_pair())); }

			node_point get__ptr() { return _ptr; };


		private :
			node_point _root;
			node_point _ptr;
	};


	template < class Key, class T >
	class map_const_iterator {
		public :
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef std::pair<Key, T>				value_type;
			typedef typename std::size_t 			size_type;
			typedef typename std::ptrdiff_t 		difference_type;
			typedef map_node<Key, T>				node;
			typedef node*							node_point;
			typedef value_type *					pointer;
			typedef pointer							const_pointer;
			typedef value_type &					reference;
			typedef reference						const_reference;

			map_const_iterator() {}
			map_const_iterator(node_point p) {_ptr = p;}
			map_const_iterator(node_point r, node_point p) {_root = r; _ptr = p;}
			map_const_iterator &operator= (const map_const_iterator& cp) {
				if (&cp == this)
					return (*this);
				this->_ptr = cp._ptr;
				return (*this);
			}
			~map_const_iterator() {}

			map_const_iterator operator ++() { _ptr = _ptr->get_next(_ptr); return (*this); }

			map_const_iterator operator ++(int) {
				map_const_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			map_const_iterator operator --() { 
				if (!_ptr) {
					_ptr = _root->get_last(_root);
					return (*this);
				}
				node_point tmp = _root;
				node_point prev = NULL;
				while (tmp && tmp->get_val() != _ptr->get_val()) {
					prev = tmp;
					tmp = tmp->get_next(tmp);
				}
				_ptr = prev;
				return (*this);
			}

			map_const_iterator operator --(int)
			{
				map_const_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			map_const_iterator operator =(value_type val)
			{
				_ptr->set_val(val);
				return this;
			}

			bool operator ==(map_const_iterator const& b) const { return (_ptr == b._ptr); }
			bool operator !=(map_const_iterator const& b) const { return (_ptr != b._ptr); }

			const_reference operator *() const { return _ptr->get_pair(); }
			const_pointer operator ->() const { return (&(_ptr->get_pair())); }

			node_point get__ptr() { return _ptr; };


		private :
			node_point _root;
			node_point _ptr;
	};


	template < class iterator >
	class map_reverse_iterator {
		public :
			typedef typename iterator::mapped_type 		mapped_type;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::size_type		size_type;
			typedef typename iterator::difference_type	difference_type;
			typedef typename iterator::node				node;
			typedef typename iterator::node_point			node_point;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;

			map_reverse_iterator() {}
			map_reverse_iterator(node_point p) {_ptr = p;}
			map_reverse_iterator(node_point r, node_point p) {_root = r; _ptr = p;}
			map_reverse_iterator(node_point r, node_point p, node_point f) {_root = r; _ptr = p;; _first = f;}
			map_reverse_iterator &operator= (const map_reverse_iterator& cp) {
				if (&cp == this)
					return (*this);
				this->_ptr = cp._ptr;
				return (*this);
			}
			~map_reverse_iterator() {}

			map_reverse_iterator operator --() { _ptr = _ptr->get_next(_ptr); return (*this); }

			map_reverse_iterator operator ++(int) {
				map_reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			map_reverse_iterator operator ++() { 
				if (!_ptr) {
					_ptr = _ptr->get_last(_root);
					return (*this);
				}
				if (_ptr == _first) {
					_ptr = NULL;
					return (*this);
				}
				if (_ptr == _root->get_first(_root)) {
					_ptr = _first;
					return (*this);
				}
				node_point tmp = _root->get_first(_root);
				node_point prev = _first;
				while (tmp && tmp->get_key() != _ptr->get_key()) {
					prev = tmp;
					tmp = tmp->get_next(tmp);
				}
				_ptr = prev;
				return (*this);
			}

			map_reverse_iterator operator --(int)
			{
				map_reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			map_reverse_iterator operator =(value_type val)
			{
				_ptr->set_val(val);
				return this;
			}

			bool operator ==(map_reverse_iterator const& b) const { return (_ptr == b._ptr); }
			bool operator !=(map_reverse_iterator const& b) const { return (_ptr != b._ptr); }

			reference operator *() { return _ptr->get_pair(); }
			const_reference operator *() const { return _ptr->get_pair(); }
			pointer operator ->() { return (&(_ptr->get_pair())); }
			const_pointer operator ->() const { return (&(_ptr->get_pair())); }


		private :
			node_point _first;
			node_point _root;
			node_point _ptr;
	};


	template < class iterator >
	class map_const_reverse_iterator {
		public :
			typedef typename iterator::mapped_type 		mapped_type;
			typedef typename iterator::value_type		value_type;
			typedef typename iterator::size_type		size_type;
			typedef typename iterator::difference_type	difference_type;
			typedef typename iterator::node				node;
			typedef typename iterator::node_point			node_point;
			typedef typename iterator::pointer			pointer;
			typedef typename iterator::const_pointer	const_pointer;
			typedef typename iterator::reference		reference;
			typedef typename iterator::const_reference	const_reference;

			map_const_reverse_iterator() {}
			map_const_reverse_iterator(node_point p) {_ptr = p;}
			map_const_reverse_iterator(node_point r, node_point p) {_root = r; _ptr = p;}
			map_const_reverse_iterator(node_point r, node_point p, node_point f) {_root = r; _ptr = p;; _first = f;}
			map_const_reverse_iterator &operator= (const map_const_reverse_iterator& cp) {
				if (&cp == this)
					return (*this);
				this->_ptr = cp._ptr;
				return (*this);
			}
			~map_const_reverse_iterator() {}

			map_const_reverse_iterator operator --() { _ptr = _ptr->get_next(_ptr); return (*this); }

			map_const_reverse_iterator operator ++(int) {
				map_const_reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			map_const_reverse_iterator operator ++() { 
				if (!_ptr) {
					_ptr = _ptr->get_last(_root);
					return (*this);
				}
				if (_ptr == _first) {
					_ptr = NULL;
					return (*this);
				}
				if (_ptr == _root->get_first(_root)) {
					_ptr = _first;
					return (*this);
				}
				node_point tmp = _root->get_first(_root);
				node_point prev = _first;
				while (tmp && tmp->get_key() != _ptr->get_key()) {
					prev = tmp;
					tmp = tmp->get_next(tmp);
				}
				_ptr = prev;
				return (*this);
			}

			map_const_reverse_iterator operator --(int)
			{
				map_const_reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			map_const_reverse_iterator operator =(value_type val)
			{
				_ptr->set_val(val);
				return this;
			}

			bool operator ==(map_const_reverse_iterator const& b) const { return (_ptr == b._ptr); }
			bool operator !=(map_const_reverse_iterator const& b) const { return (_ptr != b._ptr); }

			const_reference operator *() const { return _ptr->get_pair(); }
			const_pointer operator ->() const { return (&(_ptr->get_pair())); }


		private :
			node_point _first;
			node_point _root;
			node_point _ptr;
	};


	template < class Key,                          //map::key_type
	class T,                                       // map::mapped_type
	class Compare = std::less<Key>,                     // map::key_compare
	class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
	> class map {
		
		public :
			
			typedef Key																key_type;
			typedef T																mapped_type;
			typedef std::pair<const Key, T>											value_type;
			typedef Compare															key_compare;
			typedef Alloc															allocator_type;
			typedef typename std::size_t 											size_type;
			typedef typename std::ptrdiff_t 										difference_type;
			typedef typename Alloc::const_reference									const_reference;
			typedef typename Alloc::pointer											pointer;
			typedef typename Alloc::const_pointer									const_pointer;
			typedef typename ft::map_iterator<key_type, mapped_type>				iterator;
			typedef typename ft::map_const_iterator<key_type, mapped_type>			const_iterator;
			typedef typename ft::map_reverse_iterator<iterator>						reverse_iterator;
			typedef typename ft::map_const_reverse_iterator<iterator>				const_reverse_iterator;

			//typedef Compare												value_compare;

			typedef map_node<Key, T>										node;
			typedef node*													node_point;

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				_first = new node(true);
				_node = NULL;
				_comp = comp;
				_alloc = alloc;
				_size = 0;
			}

			// ITERATORS

			iterator begin() { return _node ? iterator(_node, _get_first(_node)) : iterator(_node, NULL); }

			const_iterator begin() const { return _node ? const_iterator(_node, _get_first(_node)) : const_iterator(_node, NULL); }

			iterator end() { return iterator(_node, NULL); }

			const_iterator end() const { return const_iterator(_node, NULL); }

			reverse_iterator rbegin() { return reverse_iterator(_node, _get_last(), _first); }

			const_reverse_iterator rbegin() const { return const_reverse_iterator(_node, _get_last(), _first); }

			reverse_iterator rend() { return reverse_iterator(_node, _first, _first); }

			const_reverse_iterator rend() const { return const_reverse_iterator(_node, _first, _first); }

			// CAPACITY

			bool empty() const { return (_size) ? false : true;}

			size_type size() { return _size; }

			size_type max_size() const { return (std::numeric_limits<size_type>::max() / (sizeof(value_type))); }


			// ELEMENT ACCESS

			mapped_type& operator[] (const key_type& k) {
				std::pair<bool, node_point> p = _search_node(_node, k);
				node_point tmp = p.second;

				if (p.first)
					return tmp->get_val();
				node_point new_node = new node;
				if (_comp(k, tmp->get_key())) {
					tmp->set_left(new_node);
					if (new_node == _get_first(_node)) {
						_first->set_top(new_node);
						new_node->set_left(_first);
					}
				}
				else
					tmp->set_right(new_node);
				_size++;
				return new_node->get_val();
			}


			// MODIFIERS

			std::pair<iterator,bool> insert (const value_type& val) {
				if (!_node) {
					_node = new node(val);
					_size++;
					_first->set_top(_node);
					_node->set_left(_first);
					return std::pair<iterator,bool>(iterator(_node), true);
				}
				std::pair<bool, node_point> p = _search_node(_node, val.first);
				bool already_exist = p.first;
				node_point tmp = p.second;
				if (already_exist)
					return std::pair<iterator,bool>(iterator(tmp), false);
				node_point new_node = new node(val, tmp);
				if (_comp(val.first, tmp->get_key())) {
					tmp->set_left(new_node);
					if (new_node == _get_first(_node)) {
						_first->set_top(new_node);
						new_node->set_left(_first);
					}
				}
				else
					tmp->set_right(new_node);
				_size++;
				return std::pair<iterator,bool>(iterator(new_node), true);
			}

			iterator insert (iterator position, const value_type& val) {
				(void)position;
				if (!_node) {
					_node = new node(val);
					_size++;
					_first->set_top(_node);
					_node->set_left(_first);
					return iterator(_node);
				}
				std::pair<bool, node_point> p = _search_node(_node, val.first);
				bool already_exist = p.first;
				node_point tmp = p.second;
				if (already_exist)
					return iterator(tmp);
				node_point new_node = new node(val, tmp);
				if (_comp(val.first, tmp->get_key())) {
					tmp->set_left(new_node);
					if (new_node == _get_first(_node)) {
						_first->set_top(new_node);
						new_node->set_left(_first);
					}
				}
				else
					tmp->set_right(new_node);
				_size++;
				return iterator(new_node);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while (first != last) {
					insert(*first);
					first++;
					_size++;
				}
			}

			void erase (iterator position) {
				std::pair<key_type, mapped_type> jj = *position;
				key_type key = jj.first;

				std::pair<bool, node_point> p = _search_node(_node, key);
				if (!p.first)
					return ;
				
				node_point tmp = p.second;
				if (tmp->get_top()) {
					if (tmp->get_top()->get_left() == tmp)
						tmp->get_top()->set_left(tmp->get_left());
					if (tmp->get_top()->get_right() == tmp)
						tmp->get_top()->set_right(tmp->get_right());
				}
				if (tmp->get_left())
					tmp->get_left()->set_top(tmp->get_top());
				if (tmp->get_right())
					tmp->get_right()->set_top(tmp->get_top());
				if (tmp == _node) {
					if (tmp->get_left() && tmp->get_left() != _first) {
						_node = tmp->get_left();
						tmp->get_left()->set_right(tmp->get_right());
					}
					else if (tmp->get_right()) {
						_node = tmp->get_right();
						tmp->get_right()->set_left(tmp->get_left());
					}
					else
						_node = NULL;
				}
				delete tmp;
				_size--;
			}

			size_type erase (const key_type& k) {
				std::pair<bool, node_point> p = _search_node(_node, k);
				if (!p.first)
					return 0;
				erase(iterator(p.second));
				return 1;
			}

			void erase (iterator first, iterator last) {
				while (first != last)
					erase(first++);
			}

			void swap (map& x) {
				node_point		_first_tmp = x._first;
				node_point		_node_tmp = x._node;
				key_compare		_comp_tmp = x._comp;
				allocator_type	_alloc_tmp = x._alloc;
				size_t			_size_tmp = x._size;

				x._first = _first;
				x._node = _node;
				x._comp = _comp;
				x._alloc = _alloc;
				x._size = _size;

				_first = _first_tmp;
				_node = _node_tmp;
				_comp = _comp_tmp;
				_alloc = _alloc_tmp;
				_size = _size_tmp;
			}

		private :

			node_point		_first;
			node_point		_node;
			key_compare		_comp;
			allocator_type	_alloc;
			size_t			_size;

			std::pair<bool, node_point> _search_node(node_point tmp, key_type key) {
				if (tmp->get_key() == key)
					return std::pair<bool, node_point>(true, tmp);
				if ((!tmp->get_right() && _comp(tmp->get_key(), key)) || ((!tmp->get_left() || tmp->get_left() == _first) && _comp(key, tmp->get_key())))
					return std::pair<bool, node_point>(false, tmp);
				if (_comp(tmp->get_key(), key))
					return _search_node(tmp->get_right(), key);
				return _search_node(tmp->get_left(), key);
			}

			node_point	_get_left_most(node_point root) {
				while (root->get_left() && root->get_left() != _first)
					root = root->get_left();
				return root;
			}

			const node_point	_get_left_most(node_point root) const {
				while (root->get_left() && root->get_left() != _first)
					root = root->get_left();
				return root;
			}

			node_point	_get_first(node_point root) {
				if (!root)
					return NULL;
				return _get_left_most(root);
			}

			const node_point	_get_first(node_point root) const {
				if (!root)
					return NULL;
				return _get_left_most(root);
			}

			node_point	_get_next(node_point root) {
				if (root->get_right())
					return _get_left_most(root->get_right());
				else {
					while (root->get_top() && root == root->get_top()->get_right())
						root = root->get_top();
					return root->get_top();
				}
			}

			const node_point	_get_next(node_point root) const {
				if (root->get_right())
					return _get_left_most(root->get_right());
				else {
					while (root->get_top() && root == root->get_top()->get_right())
						root = root->get_top();
					return root->get_top();
				}
			}

			node_point	_get_last() {
				node_point n = _get_first(_node);
				node_point prev = NULL;

				while (n) {
					prev = n;
					n = _get_next(n);
				}
				return prev;
			}

			const node_point	_get_last() const {
				node_point n = _get_first(_node);
				node_point prev = NULL;

				while (n) {
					prev = n;
					n = _get_next(n);
				}
				return prev;
			}

	};

}