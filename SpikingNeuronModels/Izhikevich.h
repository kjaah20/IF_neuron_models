#pragma once
#include "stdafx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

class Izhikevich
{
public:
	Izhikevich(void);
	Izhikevich::Izhikevich(
		int tstop, // model time in milliseconds
		float dt, // time step
		float V_th, // firing threshold
		float V_init, // initial value of the voltage 
		float U_init, // initial value of the recovery variable
		float* I1, // input current (nA)
		char typeofCurrent, // type of current; 'f' for fixed or 'v' for variant
		float a,//parameter a describes the time scale of the recovery variable u.
				//Smaller values result in slower recovery
		float b,//parameter b describes the sensitivity of the recovery variable
				//u to the subthreshold fluctuations of the membrane potential v.
		float c,//parameter c describes the after-spike reset value of the membrane
				//potential v caused by the fast high-threshold K+ conductances 
		float d,//parameter d describes after-spike reset of the recovery variable
				//u caused by slow high-threshold Na+ and K+ conductances. 
		float x1,//It is noticed from the matlab code published by Izhikevich on   
		float x2//(http://www.izhikevich.org/publications/figure1.m) that some
		//neurocomputational features (namely, Class 1 excitable and integrator)
		//have different coefficients. These cases can be expressed using the
		//following equation:			 V = 0.04*V^2+4.1*V+108-u+I;
		//while other features have:	 V = 0.04*V^2+5*V+140-u+I;			 
		);
	~Izhikevich(void);
};
