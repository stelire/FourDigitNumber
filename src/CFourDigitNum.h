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

	void SetNotPrime(void);
	bool isPrime(void);
	void setExponent(UI_16 divisor, UI_8 num);
	UI_8 getExponent(UI_16 divisor);
	void allocateExponentArray(UI_16 num);

private:
	UI_8 *m_pExponent;
	bool m_bFlgPrime;
};

#endif /* CFOURDIGITNUM_H_ */