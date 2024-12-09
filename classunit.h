#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "Unit.h"

#include <iostream>
#include <vector>

class ClassUnit : public Unit {
public:
    using Fields = std::vector<std::shared_ptr<Unit>>;

    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    static const std::vector<std::string> ACCESS_MODIFIERS;

    explicit ClassUnit( const std::string& name );
    void add( const std::shared_ptr< Unit >& unit, Flags flags );
    std::string compile( unsigned int level = 0 ) const;

private:
    std::string _name;
    std::vector< Fields > _fields;
};

#endif // CLASSUNIT_H
