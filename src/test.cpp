#include <bits/stdc++.h>
#include "all_combined.h"

using namespace std;
using Fp = atcoder::modint998244353;
using i64 = long long;

const double h = 6.62607015e-34;
const double c = 2.99792458e8;
const double k = 1.380649e-23;

double plancksLaw(double lambda_nm, double T) {
    double lambda_m = lambda_nm * 1e-9;

    double exponent = h * c / (lambda_m * k * T);

    if (exponent > 700) {
        return 0.0;
    }

    double expTerm = exp(exponent) - 1.0;

    if (expTerm == 0.0) {
        return 0.0;
    }

    double numerator = 2.0 * h * c * c;
    double denominator = pow(lambda_m, 5.0) * expTerm;
    double B_lambda = numerator / denominator;

    return B_lambda;
}

double f(double lambda_nm, double T) {
    double lambda_m = lambda_nm * 1e-9;
    return ((2 * h * c * c) / (pow(lambda_m, 5))) * (1 / (exp((h * c) / (lambda_m * k * T)) - 1));
}

int main() {
    double lambda_nm = 500.0;  // Example wavelength in nm
    double T = 6000.0;         // Example temperature in Kelvin

    cin >> lambda_nm >> T;

    double radiance = plancksLaw(lambda_nm, T);

    std::cout << "Spectral radiance at " << lambda_nm << " nm and " << T << " K is " << radiance << " W·sr⁻¹·m⁻³" << std::endl;
    std::cout << "Spectral radiance at " << lambda_nm << " nm and " << T << " K is " << f(lambda_nm, T) << " W·sr⁻¹·m⁻³" << std::endl;

    return 0;
}