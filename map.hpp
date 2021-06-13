#include "vector.hpp"

namespace ft {

	template <class Key, class T>
	class	map_node
	{
		public:

			typedef map_node<Key, T>		node;
			typedef node *					node_ptr;
			typedef const node *			const_node_ptr;
			typedef std::pair<Key, T>		value_type;

			map_node() {
				_top = NULL;
				_left = NULL;
				_right = NULL;
			}

			map_node(value_type const &pair) {
				_keyval = pair;
				_top = NULL;
				_left = NULL;
				_right = NULL;
			}

			map_node(value_type const &pair, node_ptr top) {
				_keyval = pair;
				_top = top;
				_left = NULL;
				_right = NULL;
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

			void	set_top(const node_ptr node)	{ _top = node; };
			void	set_left(const node_ptr node)	{ _left = node; };
			void	set_right(const node_ptr node)	{ _right = node; };

			const_node_ptr	get_curr(void) const  { return (this); };
			node_ptr		get_top(void) const   { return (_top); };
			node_ptr		get_left(void) const  { return (_left); };
			node_ptr		get_right(void) const { return (_right); };

			void	set_key(const Key &key)		{ _keyval.first = key; };
			void	set_val(const T &val)		{ _keyval.second = val; };
			void	set_pair(const value_type &val)	{ *_keyval = val; };

			Key			&get_key(void) { return (_keyval.first); };
			Key const	&get_key(void) const { return (_keyval.first); };
			T			&get_val(void) { return (_keyval.second); };
			value_type	&get_pair(void) { return (_keyval); };
			//pair const	get_pair(void) const { return (_keyval); };

			node_ptr	get_left_most(node_ptr root) {
				while (root->get_left())
					root = root->get_left();
				return root;
			}

			node_ptr	get_first(node_ptr root) {
				if (!root)
					return NULL;
				return get_left_most(root);
			}

			node_ptr	get_next(node_ptr root) {
				if (root->get_right())
					return get_left_most(root->get_right());
				else {
					while (root->get_top() && root == root->get_top()->get_right())
						root = root->get_top();
					return root->get_top();
				}
			}


		private:

			value_type	_keyval;
			node_ptr	_top;
			node_ptr	_left;
			node_ptr	_right;
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
			typedef node*									node_ptr;
			typedef value_type *							pointer;
			typedef value_type &							reference;
			typedef reference								const_reference;

			map_iterator() {}
			map_iterator(node_ptr p) {ptr = p;}
			map_iterator(node_ptr r, node_ptr p) {root = r; ptr = p;}
			map_iterator &operator= (const map_iterator& cp) {
				if (&cp == this)
					return (*this);
				this->_node = cp._node;
				return (*this);
			}
			~map_iterator() {}

			map_iterator operator ++() { ptr = ptr->get_next(ptr); return (*this); }

			map_iterator operator ++(int) {
				map_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			map_iterator operator --() { 
				node_ptr tmp = root;
				node_ptr prev = NULL;
				while (tmp && tmp->get_val() != ptr->get_val()) {
					prev = tmp;
					tmp = tmp->get_next(tmp);
				}
				ptr = prev;
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
				ptr->set_val(val);
				return this;
			}

			bool operator ==(map_iterator const& b) const { return (ptr == b.ptr); }
			bool operator !=(map_iterator const& b) const { return (ptr != b.ptr); }

			reference operator *() { return ptr->get_pair(); }
			const_reference operator *() const { return ptr->get_pair(); }
			//pointer operator ->() { return ((ptr->get_pair())); }
			pointer operator ->() { pointer tmp = &ptr->get_pair(); return (tmp); }

			node_ptr get_ptr() { return ptr; };


		private :
			node_ptr root;
			node_ptr ptr;
	};


	template < class Key,                          //map::key_type
	class T,                                       // map::mapped_type
	class Compare = std::less<Key>,                     // map::key_compare
	class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
	> class map {
		
		public :
			
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef std::pair<const Key, T>									value_type;
			typedef Compare													key_compare;
			typedef Alloc													allocator_type;
			typedef typename std::size_t 									size_type;
			typedef typename std::ptrdiff_t 								difference_type;
			typedef typename Alloc::const_reference							const_reference;
			typedef typename Alloc::pointer									pointer;
			typedef typename Alloc::const_pointer							const_pointer;
			typedef typename ft::map_iterator<key_type, mapped_type>		iterator;
			//typedef typename ft::map_const_iterator<T>						const_iterator;
			//typedef typename ft::map_reverse_iterator<iterator>				reverse_iterator;
			//typedef typename ft::map_const_reverse_iterator<iterator>		const_reverse_iterator;

			//typedef Compare												value_compare;

			typedef map_node<Key, T>										node;
			typedef node*													node_ptr;

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				_node = NULL;
				_comp = comp;
				_alloc = alloc;
				_size = 0;
				_last = new node;
			}

			// ITERATORS

			iterator begin() { return iterator(_node, _get_first(_node)); }

			iterator end() { return iterator(_node, NULL); }

			// CAPACITY

			size_type size() { return _size; }


			// ELEMENT ACCESS


			// MODIFIERS

			//std::pair<iterator,bool> insert (const value_type& val) {
			std::pair<node_ptr,bool> insert (const value_type& val) {
				if (!_node) {
					_node = new node(val);
					_size++;
					//return std::pair<iterator,bool>(iterator(_node), true);
					return std::pair<node_ptr,bool>(_node, true);
				}
				std::pair<bool, node_ptr> p = _search_node(_node, val.first);
				bool already_exist = p.first;
				node_ptr tmp = p.second;
				if (already_exist)
					return std::pair<node_ptr,bool>(tmp, false);
				node_ptr new_node = new node(val, tmp);
				if (_comp(val.first, tmp->get_key()))
					tmp->set_left(new_node);
				else
					tmp->set_right(new_node);
				_size++;
				return std::pair<node_ptr,bool>(new_node, true);
			}

			void		iterate() {
				node_ptr n = _get_first(_node);
				while (n) {
					std::cout << n->get_val() << std::endl;
					n = _get_next(n);
				}
			}

			T get_key() {return _node->get_key();}
			T get_val() {return _node->get_val();}

			node_ptr		_node;

		private :

			key_compare		_comp;
			allocator_type	_alloc;
			size_t			_size;
			node_ptr		_last;

			std::pair<bool, node_ptr> _search_node(node_ptr tmp, key_type key) {
				if (tmp->get_key() == key)
					return std::pair<bool, node_ptr>(true, tmp);
				if ((!tmp->get_right() && _comp(tmp->get_key(), key)) || (!tmp->get_left() && _comp(key, tmp->get_key())))
					return std::pair<bool, node_ptr>(false, tmp);
				if (_comp(tmp->get_key(), key))
					return _search_node(tmp->get_right(), key);
				return _search_node(tmp->get_left(), key);
			}

			node_ptr	_get_left_most(node_ptr root) {
				while (root->get_left())
					root = root->get_left();
				return root;
			}

			node_ptr	_get_first(node_ptr root) {
				if (!root)
					return NULL;
				return _get_left_most(root);
			}

			node_ptr	_get_next(node_ptr root) {
				if (root->get_right())
					return _get_left_most(root->get_right());
				else {
					while (root->get_top() && root == root->get_top()->get_right())
						root = root->get_top();
					return root->get_top();
				}
			}

			node_ptr	_get_last() {
				node_ptr n = _get_first(_node);
				while (n)
					n = _get_next(n);
				return n;
			}

	};

}