#include "IFNeuron.h"
// default constructor
IFNeuron::IFNeuron(void)
{
	// IFNeuron(int tstop, int abs_ref, float I, float V_th)
	IFNeuron(100,5,1,10);
}
// tstop is the model's time in milliseconds
// abs_ref is the absolute refractory period 
// I is the input current (nA)
// V_th is the spike threshold (mV)
IFNeuron::IFNeuron(int tstop, int abs_ref, float I, float V_th)
{
	FILE	*fs= fopen("voltages.dat","w");
	int t;	

	// capacitance and leak resistance
	float C = 1; // nF

	// I & F implementation dV/dt = I/C
	// Using h = 1 ms step size, Euler method

	float V = 0;

	int ref = 0; // absolute refractory period counter

	for (t=0;t<tstop;t++)	{

		if (!ref)
			V = V + (I/C);
		else {
			ref = ref - 1;
			V = 0.2*V_th; // reset voltage
		}

		if (V > V_th) {
			V = 50;  // emit spike
			ref = abs_ref; // set refractory counter
		}

		fprintf(fs, "%lf  ", V); // record the voltage
	}
	fclose(fs);
}
// default destructor 
IFNeuron::~IFNeuron(void)
{
}
