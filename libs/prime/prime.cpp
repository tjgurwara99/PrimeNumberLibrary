#include<cstdlib>
#include<vector>
#include"prime.h"
#include<boost/multiprecision/cpp_int.hpp>
#define cpp_int boost::multiprecision::cpp_int

cpp_int GCD(cpp_int a, cpp_int b){
        while(true){
                if(a<b){
                        b = b%a;
                }
                else if(b<a){
                        a = a%b;
                }
                if(a == 0){
                        return b;
                        break;
                }
                else if(b == 0){
                        return a;
                        break;
                }
                else if( a == b && a>0){
                        return a;
                        break;
                }
        }
}

cpp_int pow(cpp_int a, cpp_int b){
	cpp_int result=1;
	for(cpp_int i=1; i<=b;i++){
		result *= a;
	}
	return result;
} 

std::vector <cpp_int> BinaryK( cpp_int k)
{
    std::vector<cpp_int> K; 
    cpp_int tmp = k;
    cpp_int n = 2;
    while (tmp > 0)
    {
        K.push_back(tmp % n);
        tmp = tmp / n;
    }

    return K;
}

cpp_int ModularExpo( cpp_int a, std::vector<cpp_int> & K,  cpp_int n)
{
    if (n == 1)
        return 0;

    cpp_int b = 1;
    if (K.size() == 0)
        return b;
    cpp_int A = a;
    if (K[0] == 1)
        b = a;

    for (int i = 1; i < K.size(); i++)
    {
        A = A * A % n;
        if (K[i] == 1)
            b = A*b % n;
    }
    return (b);
}

cpp_bin_float_100 sqrt(cpp_int n){
  cpp_bin_float_100 x(n);
  cpp_bin_float_100 temp(n);
  cpp_bin_float_100 y = 1;
  cpp_bin_float_100 e = 0.1;
  while(x - y > e){
    x = (x + y)/2;
    y = temp/x;
  }
  return x;
}


cpp_int modpow(cpp_int base, cpp_int exponent, cpp_int modulus){
	if(modulus == 1)
		return 0;
	cpp_int mod = 1;
	for(cpp_int i=1;i<=exponent;i++){
		mod = (mod*base)%modulus;
	}
	return mod;
}

bool fermatprime( cpp_int a){
	cpp_int random;
	random = rand() % (a-1) ;
	random++;
	std::vector<cpp_int> v;
	v = BinaryK(a-1);
	if(GCD(random, a) != 1){
		return false;
	}
	else{
		 cpp_int p = ModularExpo(random, v, a);
		if(p == 1){
			random = rand() % (a-1);
			random++;
			p = ModularExpo(random, v, a);
			if(p == 1){
				random = rand() % (a-1);
				random++;
				p = ModularExpo(random, v, a);
				if(p == 1){
					return true;
				}
			}
		}
		else
			return false;
	}
}


/* This function calculates power of p in n! */
cpp_int countFact(cpp_int n, cpp_int p)
{
    cpp_int k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
cpp_int InverseEuler(cpp_int n, cpp_int MOD)
{
    std::vector<cpp_int> v;
    cpp_int a = 2;
    v = BinaryK(MOD-a);
    return ModularExpo(n, v, MOD);
}
 
cpp_int factMOD(cpp_int n, cpp_int MOD)
{
    cpp_int res = 1; 
    while (n > 0)
    {
        for (cpp_int i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0) 
            res = MOD - res;
    }
    return res;
}
 
cpp_int nCrModP(cpp_int n, cpp_int r, cpp_int MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;
 
    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) * 
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}

bool isPrime(cpp_int p)
{
  if(p % 2 == 0)
    return false;
  else{
    cpp_int flag=0;
    for(cpp_int i = 2; i< p/2 ; i++){
        flag = nCrModP(p, i, p);
        if(flag != 0)
          return false;
    }
    return true;
  }
}

bool isPrimeGCD(cpp_int p)
{
  if(p % 2 == 0){
    std::cout<<p<<" is not a prime.\n";
  }
  else{
    cpp_int flag = 1;
    cpp_int nn(sqrt(p));
    for(cpp_int i = 2; i < nn ;++i){
      flag = GCD(p, i);
      if(flag != 1)
        return false;
    }
    return true;
  }
}
