f='C:\VCProjects\SpikingNeuronModels\SpikingNeuronModels\QIF_voltages.dat';
load(f)
%QIF_voltages(1,:) represents time in milliseconds
%QIF_voltages(2,:) represents the output voltage trace
plot(QIF_voltages(1,:),QIF_voltages(2,:))
xlabel('Time (ms)')
ylabel('Membrane voltage (mV)')