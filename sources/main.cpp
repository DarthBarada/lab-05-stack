#include <iostream>

#include "Stack.hpp"

int main()
{
    Stack<int> temp;
    for( int index = 1; index <= 10; ++index )
        {
            temp.push( std::move(index) );
            std::cout << temp.head() << " | " << temp.tail() << " | "<< "\n";
        }
    std::cout << "\n";
    for( int index = 1; index <= 10; ++index )
        {
            std::cout << temp.head() << " | " << temp.tail() << " | " << "\n";
            temp.pop();
        }

    return 0;
}
