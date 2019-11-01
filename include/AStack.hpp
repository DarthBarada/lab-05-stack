#pragma once

#include "StackContainer.hpp"
#include "StackExceptions.hpp"

template<class T>
class AStack
	{
    protected:
		Container<T>* stack_begin = nullptr;
		Container<T>* stack_end = nullptr;
		size_t quantity = 0u;

	public:

	    AStack() = default;

		// Destructor of abstract stack class
		~AStack()
			{
				while( stack_begin != nullptr )
					{
						auto temp_pointer = stack_begin; // Create new pointer on object
                        stack_begin = stack_begin->prev;	   // Begin should indicate on previous object

						delete temp_pointer;
						--quantity;
					}
			}

		// Function push object on top of stack
        void push( T&& value )
        {
            if(stack_begin == nullptr && stack_end == nullptr )
            {
                Container<T>* temp = new Container<T> {std::forward<T>( value ), nullptr };
                stack_begin = temp; stack_end = temp;
            }
            else
            {
                Container<T>* temp = new Container<T> { std::forward<T>( value ), stack_begin };
                stack_begin = temp;
            }
            ++ quantity;
        }

    // Module allows user get information from stack
		
		// Function returns head data
		const T& head()
			{
				if( stack_begin == nullptr )
					{
						throw StackIsEmpty("No head found. Stack size is " + quantity );
					}
				return stack_begin->data;
			}
		// Function returns tail data
		const T& tail()
			{
				if( stack_end == nullptr )
					{
						throw StackIsEmpty("No tail found. Stack size is " + quantity );
					}
				return stack_end->data;
			}
		// Function returns size of stack
		size_t size() const
			{
				return quantity;
			}
	};