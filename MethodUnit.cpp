#include "MethodUnit.h"

#include "qglobal.h"

MethodUnit::MethodUnit(const std::string &name, const std::string &returnType, Flags flags) :
    _name( name ), _returnType( returnType ), _flags( flags ) { }

void MethodUnit::add(const std::shared_ptr<Unit> &unit, Flags flags) {
    Q_UNUSED(flags);
    _body.push_back(unit);
}

std::string MethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);
    if(_flags & STATIC) {
        result += "static ";
    } else if(_flags & VIRTUAL) {
        result += "virtual ";
    }
    result += _returnType + " ";
    result += _name + "()";
    if(_flags & CONST) {
        result += " const";
    }
    result += " {\n";
    for (const auto &b : _body) {
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
