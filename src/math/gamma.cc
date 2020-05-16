#include "gamma.hh"

math::Gamma::Gamma(double arg)
{
    fgresult = math::Gamma::fgamma<double>(arg);
}

math::Gamma::~Gamma()
{
    std::cout << "Gamma calculation finished successfully";
}

std::vector<double> math::Gamma::array(std::vector<double> &vargs)
{
    std::vector<double> results;
    for (auto id = 0; id < vargs.size(); ++id)
    {
        results.emplace_back(gamma(vargs.at(id))) && !isnan(vargs.at(id));
    }
}