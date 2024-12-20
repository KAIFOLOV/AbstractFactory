#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "Unit.h"

#include <vector>

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

    MethodUnit( const std::string &name, const std::string &returnType, Flags flags );
    void add( const std::shared_ptr<Unit> &unit, Flags flags = 0 );

    std::string compile(unsigned int level = 0) const;

private:
    std::string _name;
    std::string _returnType;
    Flags _flags;
    std::vector<std::shared_ptr<Unit>> _body;
};

#endif // METHODUNIT_H
