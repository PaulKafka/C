class const_iterator {
	public:
		const_iterator( ) : current( NULL ) { } // Constructor
          
        const object & operator* ( ) const	// Accessor returns object at current poisition
          { return retrieve( ); }
        
        const_iterator & operator++ ( ) {		// pre increment
            current = current->next;
            return *this;
        }

        const_iterator operator++ ( int ) {		// post increment
            const_iterator old = *this;
            ++( *this );
            return old;
        }

        const_iterator & operator-- ( ) {		// pre decrement
            current = current->prev;
            return *this;
        }

        const_iterator operator-- ( int ) {		// post decrement
            const_iterator old = *this;
            --( *this );
            return old;
        }
            
        bool operator== ( const const_iterator & rhs ) const
          { return current == rhs.current; }

        bool operator!= ( const const_iterator & rhs ) const
          { return !( *this == rhs ); }

	protected:
		Node *current;
        object & retrieve( ) const		// returns object at current poisition
			{ return current->data; }
        const_iterator( Node *p ) :  current( p ) { }	// constuctor expects pointer for current position
          
	friend class List<object>;	// shares member data with List class
    };

class iterator : public const_iterator {	// inherits from const_iterator
	public:
        iterator( ) { }	// constructor

        object & operator* ( )			// returns object at current poisition
          { return this->retrieve( ); }

        const object & operator* ( ) const
          { return const_iterator::operator*( ); }
        
        iterator & operator++ ( ) {			// pre increment
            this->current = this->current->next;
            return *this;
        }

        iterator operator++ ( int ) {		// post increment
            iterator old = *this;
            ++( *this );
            return old;
        }

        iterator & operator-- ( ) {			// pre decrement
            this->current = this->current->prev;
            return *this;
        }

        iterator operator-- ( int ) {		// post decrement
            iterator old = *this;
            --( *this );
            return old;
        }

	protected:
		iterator( Node *p ) : const_iterator( p ) { }	// constructor
        friend class List<object>;	// shares member data with List class
    };
