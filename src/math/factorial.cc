#include "factorial.hh"
#include "gamma.hh"

math::Factorial::Factorial(int arg)
{
    fact_res.fact_ = fact_function(arg);
    fact_res.strirling = fact_stirling(arg);
    fact_res.arg_copy = arg;
}

math::Factorial::~Factorial()
{
    std::cout << "The Factorial function finished succsessfully"
              << "\n";
    std::cout << fact_res.arg_copy << "! = "
              << "( " << fact_res.fact_ << " , " << fact_res.strirling << " )"
              << "\n";
}

int math::Factorial::fact_function(int arg)
{
    int fx;
    fx = 1;
    return fx;
    // auto x = math::Gamma::fgamma<int>(arg);
}

double math::Factorial::fact_stirling(int arg)
{
    auto c_fact = static_cast<double>(sqrt(2.0 * pi * arg));
    auto exp_fact = pow(static_cast<double>(arg / ee), arg);
    return c_fact * exp_fact;
}