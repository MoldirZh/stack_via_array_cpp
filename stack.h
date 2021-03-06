#ifndef STACK_INCLUDED
#define STACK_INCLUDED  1

#include <iostream>
#include <initializer_list>
#include <stdexcept>

class stack
{
   size_t current_size;
   size_t current_capacity;

   double* data;
      // INVARIANТ: has been allocated with size current_capacity.
      // 0 <= current_size <= current_capacity.

   void ensure_capacity( size_t c );
      // Ensure that stack has capacity of at least c.
      // This function is given, so you don't have to write it.

public:
   stack( );
      // Constructs empty stack.

   stack( const stack& s );

   ~stack( ) {
		delete[] data;
	}

   const stack& operator = ( const stack& s );

   stack( std::initializer_list<double> init );

   void push( double d );

	void pop( ) { // not changed
		if (current_size == 0) {
			throw std::runtime_error("pop: stack is empty");
		} else {
			current_size--;
		}
	}

	void clear( ) { // no deallocation -> keep hold of memory
		current_size = 0;
	}

	void reset( size_t s ) {
		if ( s <= size() ) {
			current_size = s;
		}
	}

	double peek( ) const { // not changed
		if (current_size == 0) {
			throw std::runtime_error("peek: stack is empty");
		} else {
			return data[current_size - 1];
		}
	}

	size_t size( ) const { // not changed
		return current_size;
	}

	bool empty( ) const { // not changed
		return (current_size == 0);
	}

   friend std::ostream& operator << ( std::ostream& out, const stack& data) {
   		out << "[";
		for (size_t i = 0; i < data.current_size; ++i) {
			if (i > 0) {
				out << ", ";
			}
		out << data.data[i];
		}
		out << "]";

		return out;
   }

};

std::ostream& operator << ( std::ostream& out, const stack& data);

#endif
