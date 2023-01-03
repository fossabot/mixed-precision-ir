#pragma once
#include <string>

namespace ir {

static const std::string MAJOR_VERSION = std::string("0");
static const std::string MINOR_VERSION = std::string("1");
static const std::string PATCH_VERSION = std::string("0");

std::string get_semver();

}
