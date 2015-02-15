#ifndef FINDER_H
#define FINDER_H

#include <vector>
#include <string>
#include "client.h"

class Finder {
public:
    Finder();
    std::vector<int> findSubstring(std::vector <Client> const& temp, std::string substr, std::string column);
};

#endif // FINDER_H
