#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

class IFNeuron
{
public:
	IFNeuron();
	IFNeuron(int tstop, int abs_ref, float I, float V_th);
	~IFNeuron(void);

};
