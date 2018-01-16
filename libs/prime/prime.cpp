#include<cstdlib>
#include<vector>
#include"prime.h"

long long GCD(long long a, long long b){
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

long long pow(long long a, long long b){
	long long result=1;
	for(long long i=1; i<=b;i++){
		result *= a;
	}
	return result;
} 

std::vector <int> BinaryK(unsigned long long k)
{
    std::vector<int> K; 
    int tmp = k;
    while (tmp > 0)
    {
        K.push_back(tmp % 2);
        tmp = tmp / 2;
    }

    return K;
}

unsigned long long ModularExpo(unsigned long long a, std::vector<int> & K, unsigned long long n)
{
    if (n == 1)
        return 0;

    int b = 1;
    if (K.size() == 0)
        return b;
    int A = a;
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

long long modpow(long long base, long long exponent, long long modulus){
	if(modulus == 1)
		return 0;
	long long mod = 1;
	for(long long i=1;i<=exponent;i++){
		mod = (mod*base)%modulus;
	}
	return mod;
}

bool fermatprime(unsigned long long a){
	unsigned long long random;
	random = rand() % (a-1) ;
	random++;
	std::vector<int> v = BinaryK(a-1);
	if(GCD(random, a) != 1){
		return false;
	}
	else{
		unsigned long long p = ModularExpo(random, v, a);
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
