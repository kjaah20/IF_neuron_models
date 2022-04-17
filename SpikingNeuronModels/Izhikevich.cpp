#include "Izhikevich.h"

Izhikevich::Izhikevich(void)
{
	// the below variables are explained in the header file (Izhikevich.h)
	// values of (a, b, c and d) replicate the tonic bursting feature
	float a = 0.02, b = 0.2,  c = -50,  d = 2, 
		dt = 0.25, V_th=30, V_init=-70, 
		U_init = b*V_init, x1 = 0.04, x2 = 140;
	int tstop=200;
	char typeofCurrent='f';
	float fixedCurrent = 15;

	Izhikevich( tstop,  dt,  V_th, V_init,  U_init, 
		&fixedCurrent,  typeofCurrent,  a, b,
		c,  d,  x1,  x2);
}

Izhikevich::Izhikevich(int tstop, float dt, float V_th,float V_init, float U_init, 
					   float* I1, char typeofCurrent, float a,float b,
					   float c, float d, float x1, float x2
					   )
{
	FILE	*fs= fopen("Izhikevich_voltages.dat","w");
	int t;
	float tsteps=0;//the integration steps
	float v=V_init;		
	float u=U_init;
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
		if (v>=V_th)					// did it fire?
		{
			v = c;					// voltage reset
			u+=d;					// recovery variable reset
		}	

		//implementation of the voltage equation
		v+=dt*((x1*v+5)*v+x2-u+I2[t]); 
		//implementation of the recovery variable equation
		u+=dt*(a*(b*v-u));

		//reset to the peak value (V_th) for plotting purposes
		if (v>=V_th) v=V_th;
		fprintf(fs, "%lf  ", v);

	}
	fclose(fs);

}
Izhikevich::~Izhikevich(void)
{
}
