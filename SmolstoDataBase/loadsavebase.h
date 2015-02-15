#ifndef LOADSAVEBASE_H
#define LOADSAVEBASE_H

#include <vector>
#include "client.h"

class LoadSaveBase {
public:
    LoadSaveBase();
    std::vector<Client> loadBase();
    void saveBase(std::vector<Client> const& temp);
};

#endif // LOADSAVEBASE_H
