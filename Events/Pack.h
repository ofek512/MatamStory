#pragma once
#include "Monster.h"

class Pack: public Monster{
protected:
    int size;
public:
    Pack(Monster*, int);
    string getDescription() const override;
};