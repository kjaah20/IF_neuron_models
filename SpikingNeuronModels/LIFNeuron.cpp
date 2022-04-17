#include "LIFNeuron.h"
// default constructor
LIFNeuron::LIFNeuron(void)
{
	int tstop = 100;//(model's time in milliseconds)
	int abs_ref = 5;//absolute refractory period
	float fixedCurrent = 1;//fixed input current
	float * I = new float [tstop];//variant input current
	char typeofCurrent='f';//type of current; 'f' for fixed or 'v' for variant
	float V_th = 10;//spike threshold

	LIFNeuron(tstop,abs_ref,&fixedCurrent,typeofCurrent,V_th);
}
// tstop: is the model's time in milliseconds
// abs_ref: is the absolute refractory period 
// I1: is the input current (nA)
// typeofCurrenttype: type of current; 'f' for fixed or 'v' for variant
// V_th: is the spike threshold (mV)
LIFNeuron::LIFNeuron(int tstop, int abs_ref, float* I1, 
					 char typeofCurrent, float V_th)
{
	// the voltage trace is written to 'LIF_voltages.dat'
	FILE	*fs= fopen("LIF_voltages.dat","w");
	int t;	
	float * I2; // the content of I1 will be copied to this variable
	// capacitance and leak resistance
	float C = 1; // nF
	float R = 40; // M ohms
	// Leaky I & F implementation dV/dt = - (V/(R*C)) + I2/C
	// Using t = 1 ms step size, Euler method
	float V = 0;
	int ref = 0; // absolute refractory period counter

	I2 = new float [tstop];// dynamic memory allocation
	//check if variant current; then the address of I1 is assigned to I2
	if (typeofCurrent=='v') 
		I2 = I1;
	//otherwise; I1 is a pointer to one value (dereference: *I1)
	//that represents the fixed current
	else for (t=0;t<tstop;t++) I2[t]=*I1;

	for (t=0;t<tstop;t++)	{

		if (!ref)
			 V = V - (V/(R*C)) + (I2[t]/C);

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
LIFNeuron::~LIFNeuron(void)
{
}
