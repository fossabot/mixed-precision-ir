#include <version.hpp>

namespace ir {

std::string get_semver() {
	return MAJOR_VERSION + std::string(".") + MINOR_VERSION + std::string(".") + PATCH_VERSION;
}

}
