#pragma once
#include <stdexcept>

class StackExceptions : public std::runtime_error 
	{
		public:
		using std::runtime_error::runtime_error;
	};

class PopFromEmptyStack : public StackExceptions
	{
		public:
		using StackExceptions::StackExceptions;
	};

class StackIsEmpty : public StackExceptions
	{
		public:
		using StackExceptions::StackExceptions;
	};