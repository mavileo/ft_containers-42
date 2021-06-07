#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft {
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

}

#endif
