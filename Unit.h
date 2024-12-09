#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <memory>

class Unit {
public:
    using Flags = unsigned int;

    virtual ~Unit() = default;
    virtual void add( const std::shared_ptr< Unit >& , Flags )
    {}
    virtual std::string compile( unsigned int level = 0 ) const = 0;

protected:
    virtual std::string generateShift( unsigned int level ) const
    {
        static const auto DEFAULT_SHIFT = " ";
        std::string result;
        for( unsigned int i = 0; i < level; ++i ) {
            result += DEFAULT_SHIFT;
        }
        return result;
    }
};

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const std::string& text ) : m_text( text ) { }
    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    std::string m_text;
};

#endif // UNIT_H
