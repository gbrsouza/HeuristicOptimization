//
// Created by gabri on 11/10/2020.
//

#ifndef MODULE1_SPLITTER_H
#define MODULE1_SPLITTER_H


#include <string>
#include <vector>

class Splitter {
public:
    virtual ~Splitter();

    Splitter();

    static std::vector<std::string> split(const std::string& text);
};


#endif //MODULE1_SPLITTER_H
