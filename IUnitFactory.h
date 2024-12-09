#ifndef IUNITFACTORY_H
#define IUNITFACTORY_H

#include "classunit.h"
#include "MethodUnit.h"

#include <memory.h>

class IUnitFactory {
public:
    virtual ~IUnitFactory() = default;
    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const = 0;
    virtual std::shared_ptr<Unit> createPrintOperatorUnit(const std::string& text) const = 0;
};

#endif // IUNITFACTORY_H
