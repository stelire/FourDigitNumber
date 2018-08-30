/*
 * CFourDigitNum.cpp
 *
 *  Created on: 2018/08/30
 *      Author: stelire
 */

#include "CFourDigitNum.h"

CFourDigitNum::CFourDigitNum(void)
	: m_naExponent()
	, m_bFlgPrime(true)
{
}

CFourDigitNum::~CFourDigitNum(void)
{
}

void CFourDigitNum::SetNotPrime(void)
{
	m_bFlgPrime = false;
}

bool CFourDigitNum::isPrime(void)
{
	return m_bFlgPrime;
}

void CFourDigitNum::setExponent(UI_16 divisor, UI_8 num)
{
	if(divisor < 10000){
		m_naExponent[divisor] = num;
	}
}

UI_8 CFourDigitNum::getExponent(UI_16 divisor)
{
	if(divisor < 10000){
		return m_naExponent[divisor];
	}
	else {
		return 0;
	}
}
