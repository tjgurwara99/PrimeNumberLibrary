#include<stdio.h>
#include<sstream>
#include"prime/prime.h"

int main(int argc, char** argv){
        if(argc == 2){
                unsigned long long n;
                std::istringstream iss( argv[1]);
                if(iss >> n){
                        if(fermatprime(n)){
				printf("%lld number is probably prime.\n", n);
			}
			else
				printf("%lld number is not a prime.\n", n);
                }
        }
	else{
		printf("Incorrect Arguments\n");
	}
}
