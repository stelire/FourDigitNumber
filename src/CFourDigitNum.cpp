/*
 * CFourDigitNum.cpp
 *
 *  Created on: 2018/08/30
 *      Author: stelire
 */

#include "CFourDigitNum.h"

CFourDigitNum::CFourDigitNum(void)
	: m_pExponent()
	, m_bFlgPrime(true)
{
}

CFourDigitNum::~CFourDigitNum(void)
{
	if(m_pExponent){
		delete [] m_pExponent;
	}
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
		m_pExponent[divisor] = num;
	}
}

UI_8 CFourDigitNum::getExponent(UI_16 divisor)
{
	if(divisor < 10000){
		return m_pExponent[divisor];
	}
	else {
		return 0;
	}
}

void CFourDigitNum::allocateExponentArray(UI_16 num)
{
	m_pExponent = new UI_8[num]();
}


