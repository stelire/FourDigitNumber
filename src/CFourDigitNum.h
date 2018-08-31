/*
 * FourDigitNum.h
 *
 *  Created on: 2018/08/30
 *      Author: stelire
 */

#ifndef CFOURDIGITNUM_H_
#define CFOURDIGITNUM_H_

#include "common.h"

class CFourDigitNum
{
public:
	CFourDigitNum(void);
	~CFourDigitNum(void);

	enum{
		E_MAX_NUMBER = 9999
	};

	void SetNotPrime(void);
	bool isPrime(void);
	bool addDivisor(UI_16 num);
	void clearDivisor(void);
	UI_8 getNumDivisor(void);
	UI_16 getDivisor(UI_8 idx);


private:
	enum{
		E_MAX_DIVISOR = 13
	};
	UI_16 m_naDivisor[E_MAX_DIVISOR];
	UI_8 m_nIdxDivisor;
	bool m_bFlgPrime;
};

#endif /* CFOURDIGITNUM_H_ */
