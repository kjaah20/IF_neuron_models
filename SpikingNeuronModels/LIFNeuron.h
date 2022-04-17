#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

class LIFNeuron
{
public:

	LIFNeuron();
	LIFNeuron(int tstop, int abs_ref, float* I, 
		char typeofCurrent, float V_th);
	~LIFNeuron(void);
};
