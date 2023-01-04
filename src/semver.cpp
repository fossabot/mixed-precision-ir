#include "mpir.hpp"

static const std::string HEADER = "Iterative Improvement with Universal Number Systems";

int main(int argc, char* argv[])
try {
	std::cout << HEADER << '\n';

	std::cout << "VERSION: " << ir::get_semver() << '\n';
}
catch(...) {
	std::cerr << "Caught unexpected exception" << std::endl;
}

