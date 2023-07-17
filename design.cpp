
#include"systemc.h"
using namespace std;

SC_MODULE(example)
{
	sc_in<bool>clk;
	sc_in<bool>a;
	sc_in<bool>b;
	sc_out<bool>output;

	void result()
	{
		output.write(a.read() | b.read());
	}
	SC_CTOR(example)
	{
		SC_METHOD(result);
		sensitive << clk.pos();
	}
};