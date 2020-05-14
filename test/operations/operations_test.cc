#include "../../src/operations/trig.hh"

#include <iostream>

inline void newline() { std::cout << "\n"; }

enum Functions
{
    SIN,
    COS,
    TAN,
    CTAN,
    ASIN,
    ACOS,
    ATAN,
    ARCTAN
};

void choose_function(Functions f)
{
    switch (f)
    {
    case COS:
        std::cout << "cosine";
        newline();
        break;
    case SIN:
        std::cout << "sine";
        newline();
        break;
    case TAN:
        std::cout << "tangent";
        newline();
        break;
    case ATAN:
        std::cout << "arctangent";
        newline();
        break;
    case CTAN:
        std::cout << "cotangent";
        newline();
        break;
    case ASIN:
        std::cout << "arcsine";
        newline();
        break;
    case ACOS:
        std::cout << "arccos";
        newline();
        break;
    case ARCTAN:
        std::cout << "arccotangent";
        newline();
        break;

    default:
        break;
    }
}

int main()
{
    Functions f;
    
    f = static_cast<Functions>(five);
    std::cout << f;
}