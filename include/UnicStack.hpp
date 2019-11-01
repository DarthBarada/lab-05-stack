#pragma once

#include "AStack.hpp"

template<typename T>
class UnicStack : public AStack<T>
	{
		public:
		template<typename ... Args>
		void push_emplace( Args&&... value )
			{
				if(  AStack<T>::stack_begin == nullptr &&  AStack<T>::stack_end == nullptr )
					{
                        AStack<T>::stack_begin = new Container<T> {std::forward<Args>( value ) ..., nullptr };
                        AStack<T>::stack_end =  AStack<T>::stack_begin;
                        AStack<T>::stack_begin->prev = nullptr;
					}
				else
					{
						Container<T>* temp = new Container<T> { std::forward<Args>( value ) ..., AStack<T>::stack_begin };
                        AStack<T>::stack_begin = temp;
					}
				++ AStack<T>::quantity;
			}

		T pop()
			{
				if (  AStack<T>::stack_begin == nullptr ) // If size = 0 => thow error
					{
						throw PopFromEmptyStack( "You want to pop from empty stack!" );
					}

                auto temp_pointer =  AStack<T>::stack_begin; // Create new pointer on object
                AStack<T>::stack_begin =  AStack<T>::stack_begin->prev;	   // Begin should indicate on previous object

                T info = std::move( temp_pointer->data );
                delete temp_pointer;
                -- AStack<T>::quantity;

                return info;
			}
	};