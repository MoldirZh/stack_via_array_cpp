#include "stack.h"

// Use this method for all your reallocations:

void stack::ensure_capacity( size_t c )
{
   if( current_capacity < c )
   {
        // New capacity will be the greater of c and
        // 2 * current_capacity.

        if( c < 2 * current_capacity )
        	c = 2 * current_capacity;

        double* newdata = new double[ c ];
        for( size_t i = 0; i < current_size; ++ i )
    		newdata[i] = data[i];

        current_capacity = c;
        delete[] data;
        data = newdata;
   }
}

stack::stack( ) : //DONE
   	current_size(0),
   	current_capacity(5),
   	data(new double[current_capacity])
{

}

stack::stack( const stack& s ) : //DONE
	data(new double[s.current_capacity]),
	current_size(s.current_size),
	current_capacity(s.current_capacity)
{
	for (size_t i = 0; i < s.current_size; ++i) {
		data[i] = s.data[i];
	}
}

const stack& stack::operator = ( const stack& s ) { /* move the initializations into the body
											  * we may have to deallocate data array first before reallocating to take on the values of new stack
											  * take care of the case of assigning a stack to itself:
											  * (before deallocation) :
											  * 	- check if allocated array size is the same
											  * 		YES: you don't have to delete/reallocate -> just copy over
											  * Use the function ensure_capacity */

	if (current_size < s.current_size) {
		ensure_capacity (s.current_size);
	}

	current_size = s.current_size;

	for (size_t i = 0; i < s.current_size; ++i) {
		data[i] = s.data[i];
	}

	return *this;
}

stack::stack( std::initializer_list<double> init ) : /* So that you can write s = { 1,2,3 };
      												  * You can use init. size( ) to see the size, and
    											      * for( double d : init ) to go through all
     												  * elements in the initializer_list. */
	current_size(init.size()),
	current_capacity(init.size())
{
	size_t i = 0;
	for (double d : init) {
		data[i] = d;
		++i;
}
}

void stack::push(double d) { /* check to make sure that array capacity is large enough to accomodate a new item
								* compare the current size with capacity
								* if equal -> full
								* 	TODO:
								* 	- allocating new data array
								* 	- copying the values over
								* 	- deallocate old array
								* 	- reset the pointer to data to new data
								* Use the function ensure_capacity */
	ensure_capacity(current_size);

	data[current_size] = d;
	++current_size;
}

