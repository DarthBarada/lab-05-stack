#pragma once
#include "AStack.hpp"

template<class T>
class Stack: public AStack<T>
	{
	public:

        void push( const T& value )
        {
            if( AStack<T>::stack_begin == nullptr && AStack<T>::stack_end == nullptr )
                {
                    Container<T>* temp = new Container<T> { value, nullptr };
                    AStack<T>::stack_begin = temp; AStack<T>::stack_end = temp;
                }
            else
                {
                    Container<T>* temp = new Container<T> { value, AStack<T>::stack_begin };
                    AStack<T>::stack_begin = temp;
                }
            ++AStack<T>::quantity;
        }
		// Function delete top of stack
		void pop()
			{
				if (  AStack<T>::stack_begin == nullptr ) // If size = 0 => throw error
					{
						throw PopFromEmptyStack( "You want to pop from empty stack!" );
					}
				else if(  AStack<T>::stack_end != nullptr )
					{
                        -- AStack<T>::quantity;
						auto temp_pointer =  AStack<T>::stack_begin; // Create new pointer on object
                        AStack<T>::stack_begin =  AStack<T>::stack_begin->prev;	   // Begin should indicate on previous object

						delete temp_pointer;
					}
			}
	};