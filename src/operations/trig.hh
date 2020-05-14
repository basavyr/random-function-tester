#ifndef TRIG_HH
#define TRIG_HH

#include <iostream>
namespace operations
{

    class Trig
    {
    private:
        double result;

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

    public:
        Trig(double);
        ~Trig();

    public:
        static void showResult(double &);
    };

} //namespace operations

#endif // TRIG_HH