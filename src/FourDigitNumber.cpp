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
	CFourDigitNum FDNum[CFourDigitNum::E_MAX_NUMBER + 1];
	UI_16 numPrime;
	int rslt = 0;

	FDNum[0].SetNotPrime();
	FDNum[1].SetNotPrime();

	numPrime = CFourDigitNum::E_MAX_NUMBER + 1 - 2;
	for(int i=0; i<CFourDigitNum::E_MAX_NUMBER + 1; i++){
		if(FDNum[i].isPrime()){
			for(int j=i*2; j<CFourDigitNum::E_MAX_NUMBER + 1; j+=i){
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

	for(int i=2; i<CFourDigitNum::E_MAX_NUMBER + 1; i++){
		if(FDNum[i].isPrime()){
			prime[idx] = i;
			idx++;
			cout <<' ' << i;
		}
		else{
			for(int j=0; j<idx; j++){
				UI_16 wk = i;
				while(wk%prime[j] == 0){
					if(!FDNum[i].addDivisor(prime[j])){
						rslt = -1;
					}
					wk = wk / prime[j];
				}
			}
		}
	}

	cout << endl;

	for(int i=2; i<CFourDigitNum::E_MAX_NUMBER + 1; i++){
		cout << i;
		if(FDNum[i].isPrime()){
			cout << " is prime number.";
		}
		else{
			bool flgFirst = true;
			UI_8 numDivisor = FDNum[i].getNumDivisor();
			UI_8 idx = 0;

			cout <<" (" << (UI_16)numDivisor << ") = ";

			while(idx < numDivisor){
				UI_16 divisor = FDNum[i].getDivisor(idx);
				UI_8 cnt;
				idx++;
				for(cnt=1; FDNum[i].getDivisor(idx)==divisor && idx<numDivisor; cnt++){
					idx++;
				}
				if(flgFirst){
					flgFirst = false;
				}
				else{
					cout << " * ";
				}
				cout << divisor << " ^ " << (UI_16)cnt;
			}
		}
		cout << endl;
	}

	return rslt;
}


