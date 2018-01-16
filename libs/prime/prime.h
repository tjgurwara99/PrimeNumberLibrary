#pragma once
#include<bitset>
#include<string>
#include<vector>

std::vector <int> BinaryK(unsigned long long); //convertion of long to binary

unsigned long long ModularExpo(unsigned long long, std::vector<int> &K, unsigned long long n); //modular exponentiations optimised using binary

long long GCD(long long, long long); // greatest common divisor

long long pow(long long, long long); //raising to the power

long long modpow(long long, long long, long long);  //modular exponentiation - binary function independant

bool fermatprime(unsigned long long); // fermat's primality test


