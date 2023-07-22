#include"systemc.h"
using namespace std;

SC_MODULE(example_stim)
{
	sc_in<bool>clk;
	sc_out<bool>a;
	sc_out<bool>b;
	sc_out<bool>c;
	sc_in<bool>output;

	void function()
	{
		while (true)
		{
			a.write(false);
			b.write(false);
			c.write(false);
			wait();
			a.write(false);
			b.write(false);
			c.write(true);
			wait();
			a.write(false);
			b.write(true);
			c.write(false);
			wait();
			a.write(false);
			b.write(true);
			c.write(true);
			wait();
			a.write(true);
			b.write(false);
			c.write(false);
			wait();
			a.write(true);
			b.write(true);
			c.write(false);
			wait();
			a.write(true);
			b.write(false);
			c.write(true);
			wait();
			a.write(true);
			b.write(true);
			c.write(true);
			wait();
		}
	}
	void output_monitor()
	{
		while (true)
		{
			cout << " a :" << a.read() << " b :" << b.read()<<" c :"<<c.read() << "  output :" << output.read() << "  " << sc_time_stamp() << endl;
			wait();
		}
	}
	SC_CTOR(example_stim)
	{
		SC_THREAD(function);
		sensitive << clk.neg();
		SC_CTHREAD(output_monitor, clk.neg());

	}
};
