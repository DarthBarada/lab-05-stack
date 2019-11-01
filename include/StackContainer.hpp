#pragma once

template<typename T>
struct Container
	{
		T data;
		Container *prev = nullptr;
	};