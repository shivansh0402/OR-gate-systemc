#include"systemc.h"
#include"design.cpp"
#include"stimulus.cpp"

int sc_main(int argc, char* argv[])
{
	sc_clock clock("clock", 10, SC_NS, 0.5);
	sc_signal<bool>a;
	sc_signal<bool>b;
	sc_signal<bool>output;

	//connect dut
	example e1("design");
	e1.clk(clock);
	e1.a(a);
	e1.b(b);
	e1.output(output);

	example_stim s1("stimulus");
	s1.clk(clock);
	s1.a(a);
	s1.b(b);
	s1.output(output);

	//setting up waveform
	sc_trace_file* t = sc_create_vcd_trace_file("wave");
	sc_trace(t, clock, "clock");
	sc_trace(t, a, "a");
	sc_trace(t, b, "b");
	sc_trace(t, output, "output");

	sc_start(40, SC_NS);

	sc_close_vcd_trace_file(t);

	return 0;

}