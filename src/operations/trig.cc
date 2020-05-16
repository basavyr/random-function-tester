#include "trig.hh"

namespace operations
{
    //seed
    std::random_device rd;
    //rng initialized with rd-like seed
    static std::mt19937 twister{rd()};
} // namespace operations

operations::Trig::Trig(double x)
{
    chosen_function = generateRandomTrigFunction();
    result = computeTrigFunction(chosen_function, x);
    arg_copy = x;
}

operations::Trig::~Trig()
{
    showResult(chosen_function, arg_copy, result);
}

double operations::Trig::computeTrigFunction(Functions f, double arg)
{
    double fx;
    switch (f)
    {
    case COS:
        fx = cos(arg);
        break;
    case SIN:
        fx = sin(arg);
        break;
    case TAN:
        fx = tan(arg);
        break;
    case ATAN:
        fx = atan(arg);
        break;
    case CTAN:
        fx = static_cast<double>(cos(arg) / sin(arg));
        break;
    case ASIN:
        fx = asin(arg);
        break;
    case ACOS:
        fx = acos(arg);
        break;
    case ARCTAN:
        fx = atan(static_cast<double>(1.0 / arg));
        break;
    default:
        break;
    }
    return fx;
}

std::vector<double> operations::Trig::computeTrigArray(Functions f, std::vector<double> &v)
{
    // auto f = generateRandomTrigFunction();
    std::vector<double> results;
    for (auto id = 0; id < v.size(); ++id)
    {
        auto arg = v.at(id);
        results.emplace_back(computeTrigFunction(f, arg));
    }
    return results;
}

std::string operations::Trig::functionName(Functions &f)
{
    std::string fName;
    switch (f)
    {
    case COS:
        fName = "cos";
        break;
    case SIN:
        fName = "sin";
        break;
    case TAN:
        fName = "tan";
        break;
    case ATAN:
        fName = "atan";
        break;
    case CTAN:
        fName = "ctan";
        break;
    case ASIN:
        fName = "asin";
        break;
    case ACOS:
        fName = "acos";
        break;
    case ARCTAN:
        fName = "arctan";
        break;
    default:
        break;
    }
    return fName;
}

operations::Trig::Functions operations::Trig::generateRandomTrigFunction()
{
    std::uniform_int_distribution<int> udist(0, static_cast<int>(Functions::MAXENUM) - 1);
    auto function = static_cast<Functions>(udist(twister));
    return function;
}

void operations::Trig::showResult(Functions &f, double &arg, double &result)
{
    auto fName = functionName(f);
    std::cout << fName << "(" << arg << ")= " << result;
}