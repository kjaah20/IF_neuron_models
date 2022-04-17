#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

class QIFNeuron
{
public:
	QIFNeuron(void);//default constructor
	QIFNeuron::QIFNeuron(
		int tstop, // model time in milliseconds
		float dt, // time step
		float V_th, // firing threshold
		float V_init, // initial value of the voltage 
		float V_reset, // resting voltage
		float* I1, // input current (nA)
		char typeofCurrent, // type of current; 'f' for fixed or 'v' for variant
		float C,//capacitance
		float k,//k >0 is a parameter
		float V_peak,//To avoid simulating ‘infinity’, the voltage is clipped
					 // at some sufficiently large value, V_peak  
		float c //after-spike resetting potential
		);
	~QIFNeuron(void);//destructor
};
