#include "ClassUnit.h"
#include "IUnitFactory.h"
#include "CppUnitFactory.h"
#include "MethodUnit.h"

#include <QCoreApplication>

void generateCode(const IUnitFactory& factory) {
    auto classUnit = factory.createClassUnit("MyClass");
    auto methodUnit = factory.createMethodUnit("myMethod", "void", MethodUnit::STATIC);

    auto printOperator = factory.createPrintOperatorUnit("Hello, world!");

    methodUnit->add(printOperator);
    classUnit->add(methodUnit, ClassUnit::PUBLIC);

    std::cout << classUnit->compile() << std::endl;
}

std::string generateProgram() {
    ClassUnit myClass("MyClass");

    myClass.add(std::make_shared<MethodUnit>("testFunc1", "void", 0), ClassUnit::PUBLIC);

    myClass.add(std::make_shared<MethodUnit>("testFunc2", "void", MethodUnit::STATIC),
        ClassUnit::PRIVATE
        );

    myClass.add(
        std::make_shared<MethodUnit>("testFunc3", "void", MethodUnit::VIRTUAL |
        MethodUnit::CONST),
        ClassUnit::PUBLIC);

    auto method = std::make_shared< MethodUnit >("testFunc4", "void",
                                               MethodUnit::STATIC);
    method->add( std::make_shared< PrintOperatorUnit >(R"(Hello, world!\n)"));
    myClass.add(method, ClassUnit::PROTECTED);
    return myClass.compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CppUnitFactory cppFactory;

    std::cout << "C++ Code:" << std::endl;
    generateCode(cppFactory);

    return a.exec();
}
