//
// Created by gabri on 11/10/2020.
//

#include <sstream>
#include <iterator>
#include "Splitter.h"

std::vector<std::string> Splitter::split(const std::string& text) {
    std::istringstream iss(text);
    std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                     std::istream_iterator<std::string>());
    return results;
}

Splitter::Splitter() = default;

Splitter::~Splitter() = default;
