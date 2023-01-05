/** ************************************************************************
* example: skeleton for working with Universal
*
* @author:     Theodore Omtzigt
* @date:       2023-01-04
* @copyright:  Copyright (c) 2023 Stillwater Supercomputing, Inc.
* @license:    MIT Open Source license
*
* This file is part of the Mixed Precision Iterative Refinement project
* *************************************************************************
*/
#include <iostream>
#include <iomanip>

#include <universal/number/cfloat/cfloat.hpp>

int main() 
try {
	using namespace sw::universal;

	half a, b, c;
	a = 1.5f;
	b = 0.75f;
	c = a * b;
	std::cout << a << " * " << b << " = " << c << '\n';
	std::cout << to_binary(a) << " * " << to_binary(b) << " = " << to_binary(c) << '\n';
}
catch(const char* msg) {
	std::cerr << "Caught unexcpected exception: " << msg << std::endl;
	return EXIT_FAILURE;
}
