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
	UI_16 numPrime;

	FDNum[0].SetNotPrime();
	FDNum[1].SetNotPrime();

	numPrime = 10000 - 2;
	for(int i=0; i<10000; i++){
		if(FDNum[i].isPrime()){
			for(int j=i*2; j<10000; j+=i){
				if(FDNum[j].isPrime()){
					FDNum[j].SetNotPrime();
					numPrime--;
				}
			}
		}
	}

	cout << "Prime numbers : " << numPrime << endl;

	UI_16 prime[numPrime];
	UI_16 idx = 0;

	for(int i=2; i<10000; i++){
		if(FDNum[i].isPrime()){
			prime[idx++] = i;
			cout <<' ' << i;
		}
		else{
			FDNum[i].allocateExponentArray(numPrime);
			for(int j=0; j<idx; j++){
				UI_16 wk = i;
				UI_8 cnt;
				for(cnt = 0; wk%prime[j]==0; cnt++){
					wk = wk / prime[j];
				}
				FDNum[i].setExponent(j, cnt);
			}
		}
	}

	cout << endl;

	for(int i=2; i<10000; i++){
		cout << i;
		if(FDNum[i].isPrime()){
			cout << " is prime number.";
		}
		else{
			cout << " = ";
			bool flgFirst = true;
			for(int j=0; j<numPrime; j++){
				UI_8 num = FDNum[i].getExponent(j);
				if(num){
					if(flgFirst){
						flgFirst = false;
					}
					else{
						cout << " + ";
					}
					cout << prime[j] << " ^ " << (UI_16)num;
				}
			}
		}
		cout << endl;
	}

	return 0;
}


