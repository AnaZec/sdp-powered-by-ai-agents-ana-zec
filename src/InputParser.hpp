#pragma once
#include <istream>
#include <vector>
#include "FieldProcessor.hpp"

std::vector<Field> parseFields(std::istream& in);
