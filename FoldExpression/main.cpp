#include <iostream>

// Using traditional templated arbitary argument function 
auto sum()
{
	return 0;
}

template <typename N>
auto sum(N n)
{
	return n;
}

template <typename N0, typename... Ns>
auto sum(N0 n0, Ns... ns)
{
	return n0 + sum(ns...);
}

// Using Fold expression of C++17

// This is an example of Binary Right Fold Expression
template<typename... Ns>
auto sum_fold_exp(Ns... ns)
{
	return (ns + ... + 0);
}

// This is an example of Unary Left Fold
template <typename... Bs>
bool all(Bs... bs)
{
	return(... && bs);
}

int main()
{
	auto x = sum(1.2, 2, 3, 4);
	std::cout << x << std::endl;
	
	std::cout << "Calculate sum using Binary Right Fold Expression" << std::endl;
	auto a = sum(3.14, 1e7, -42, 17);
	// The above statement behaves in the following way
	// 3.14 + (1e7 + (-42 + (17 + 0)))

	std::cout << a << std::endl;

	std::cout << "Example of Unary Left Fold using && operator" << std::endl;
	bool b = all(true, true, true, false);
	// The above statements behaves in the following way
	// ((true && true) && true) && false)
	std::cout << b << std::endl;

	std::cin.get();
}