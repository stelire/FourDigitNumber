/*
 * CFourDigitNum.cpp
 *
 *  Created on: 2018/08/30
 *      Author: stelire
 */

#include "CFourDigitNum.h"

CFourDigitNum::CFourDigitNum(void)
	: m_naDivisor()
	, m_nIdxDivisor(0)
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

bool CFourDigitNum::addDivisor(UI_16 num)
{
	bool flgRslt = true;

	if(m_nIdxDivisor < E_MAX_DIVISOR){
		m_naDivisor[m_nIdxDivisor] = num;
		m_nIdxDivisor++;
	}
	else{
		flgRslt = false;
	}

	return flgRslt;
}

void CFourDigitNum::clearDivisor(void)
{
	m_nIdxDivisor = 0;
}

UI_8 CFourDigitNum::getNumDivisor(void)
{
	return m_nIdxDivisor;
}

UI_16 CFourDigitNum::getDivisor(UI_8 idx)
{
	if(idx < m_nIdxDivisor){
		return m_naDivisor[idx];
	}
	else{
		return 0;
	}
}


