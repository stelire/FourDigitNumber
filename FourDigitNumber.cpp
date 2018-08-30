/*
 * FourDigitNumber.cpp
 *
 *  Created on: 2018/08/30
 *      Author: stelire
 */

#include <iostream>
using namespace std;

#include "CFourDigitNum.h"

int main()
{
	CFourDigitNum FDNum[10000];

	FDNum[0].SetNotPrime();
	FDNum[1].SetNotPrime();

	for(int i=0; i<10000; i++){
		if(FDNum[i].isPrime()){
			for(int j=i; j<10000; j+=i){
				FDNum[j].setExponent(i, 1);
				if(j!=i){
					FDNum[j].SetNotPrime();
				}
			}
		}
	}

	for(int i=0; i<10000; i++){
		if(FDNum[i].isPrime()){
			cout << i << ' ';
		}
	}

	return 0;
}


