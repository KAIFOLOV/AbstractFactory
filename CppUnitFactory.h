#ifndef CPPUNITFACTORY_H
#define CPPUNITFACTORY_H

#include "IUnitFactory.h"

class CppUnitFactory : public IUnitFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) const override;

    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) const override;

    std::shared_ptr<Unit> createPrintOperatorUnit(const std::string& text) const override;
};

#endif // CPPUNITFACTORY_H
