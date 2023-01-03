#pragma once
#include <string>

namespace ir {

static constexpr std::string MAJOR_VERSION = "0";
static constexpr std::string MINOR_VERSION = "1";
static constexpr std::string PATCH_VERSION = "0";

std::string get_semver();
}
