#ifndef _PRIME_H
#define _PRIME_H
#include<bitset>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/multiprecision/cpp_bin_float.hpp>
#include<string>
#include<cmath>
#include<vector>
#define cpp_int boost::multiprecision::cpp_int
#define cpp_bin_float_100 boost::multiprecision::cpp_bin_float_100

std::vector <cpp_int> BinaryK(cpp_int); //convertion of long to binary

cpp_int ModularExpo(cpp_int , std::vector<cpp_int> &K, cpp_int n); //modular exponentiations optimised using binary

cpp_int GCD(cpp_int, cpp_int); // greatest common divisor

cpp_int pow(cpp_int, cpp_int); //raising to the power

cpp_int modpow(cpp_int, cpp_int, cpp_int);  //modular exponentiation - binary function independant

bool fermatprime(cpp_int); // fermat's primality test

bool isint(cpp_bin_float_100);

bool perfect_pow(cpp_int);

#endif
