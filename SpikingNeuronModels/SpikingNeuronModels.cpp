#include "stdafx.h"
#include "IFNeuron.h"
#include "LIFNeuron.h"
#include "QIFNeuron.h"
#include "Izhikevich.h"

void main()
{
	/*
	simulating QIF neuron model using system-defined parameters 
	(see QIFNeuron.cpp & QIFNeuron.h)
	*/
	QIFNeuron();

	/*
	simulating QIF neuron model using user-defined parameters 
	*/
	// the below variables are explained in the header file (QIFNeuron.h)

	float C=1, k=0.02,  V_peak=10, dt = 1,  
		V_th=-40, V_init=0, V_reset=-80;
	int tstop=100;
	char typeofCurrent='f';
	float fixedCurrent = 10;

	QIFNeuron( tstop,  dt,  V_th, V_init,  V_reset, 
		&fixedCurrent,  typeofCurrent,  C, k,
		V_peak,V_reset);

}


