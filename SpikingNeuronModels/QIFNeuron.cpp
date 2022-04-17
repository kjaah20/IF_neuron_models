#include "QIFNeuron.h"

QIFNeuron::QIFNeuron(void)
{
	float C=1, k=0.02,  V_peak=10, dt = 1,  
		V_th=-40, V_init=0, V_reset=-80;
	int tstop=100;
	char typeofCurrent='f';
	float fixedCurrent = 10;

	QIFNeuron( tstop,  dt,  V_th, V_init,  V_reset, 
		&fixedCurrent,  typeofCurrent,  C, k,
		V_peak,V_reset);

}

QIFNeuron::QIFNeuron(int tstop, float dt,float V_th, float V_init,float V_reset,float* I1, 
					 char typeofCurrent, float C,float k,float V_peak, float c){
	FILE	*fs= fopen("QIF_voltages.dat","w");
	int t;
	float tsteps=0;//the integration steps
	float v=V_init;		
	float * I2; // the content of I1 will be copied to this variable
	I2 = new float [tstop/dt];// dynamic memory allocation
	//check if variant current; then the address of I1 is assigned to I2
	if (typeofCurrent=='v') 
		I2 = I1;
	//otherwise; I1 is a pointer to one value (dereference: *I1)
	//that represents the fixed current
	else for (t=0;t<tstop/dt;t++) I2[t]=*I1;

	//write the integration steps to the output file
	//for plotting purposes
	for (tsteps=0;tsteps<tstop;tsteps=tsteps+dt)
		fprintf(fs, "%lf  ", tsteps);
	
	fprintf(fs, "\n");

	// (tstop/dt)= the total number of integration steps
	for (t=0;t<(tstop/dt);t++)				
	{
		if (v>=V_peak)					// PREVENT INFINITY
		{
			v = c;					// voltage reset			
		}	

		//implementation of the voltage equation
		 v += dt*(k*(v-V_reset)*(v-V_th)+I2[t]) /C; 

		//reset to the peak value (V_peak) 
		if (v>=V_peak) v=V_peak;
		fprintf(fs, "%lf  ", v);

	}
	fclose(fs);
}

QIFNeuron::~QIFNeuron(void)
{
}
