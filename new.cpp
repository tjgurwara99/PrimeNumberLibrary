#include<cstdlib>
#include<vector>
#include<cmath>
#include<boost/multiprecision/cpp_int.hpp>
#include<boost/math/special_functions/binomial.hpp>
#define binomial boost::math::binomial_coefficient
#define cpp_int boost::multiprecision::cpp_int

template <class T>

T nCr(T n, T r) {
    if(r > n / 2)
         r = n - r; // This is because nCr(n, r) == nCr(n, n - r)
    T ans = 1;
    int i;
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
	return ans;
}

template <class T> 

bool AKS_Primality(T num){
	std::vector<T> ans;
	float l = log(num)/log(2);
	for(T a = 2; a<=l+1	
	for(T i=2; i<=l;++i){
		if(pow(a,i) == num)
			return false;
		
	}
	T maxk = pow(l,2);
	bool nextR = true;
	for(T r=2;nextR,++r){
		nextR = false;
		for(T k=1; (!nextR) && k<= maxk; ++k){
			nextR=(pow(num, k)%r == 1) || (pow(num,k) % r == 0);
	}
	r--;
	if(GCD(
	for(T i=1; i<=num/2; i++)
		ans.push_back(nCr(num,i));
	for(unsigned i=0;i<ans.size();++i){
		if(ans[i]%num != 0)
			return false;
	}
	return true;
}

template<class T>
T ModularExpo(T a, std::vector<T> & K,  T n)
{
    if (n == 1)
        return 0;
    T b = 1;
    if (K.size() == 0)
        return b;
    T A = a;
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

template<class T>
T modexp(T num, T r, T mod){
	if(mod == 1)	return 0;
	T b = 1;
	T a = 1;
	if(r> num/2)	r = num - r;
	for(int i=r+1; i<=num ; i++){
		 = 

int main(){
	cpp_int num;
	std::cin>>num;
	if(AKS_Primality(num))
		std::cout<< num <<" is prime.\n";
	else
		std::cout<< num <<" is not a prime.\n";
	return 0;
}
