#ifndef _GRAPH_PLUS_MODULE_Sample
#define _GRAPH_PLUS_MODULE_Sample

#include <string.h>
#include <assert.h>

#include "another_module_file"

/*$GPBS$Sample$!include!*/
// reference additional headers here
/*$GPBS$*/

//Пример простой
namespace Sample{

//Sample channel 'Chan' declaration
class Chan:public gprt.h::Channel{
public:
	Chan(gprt.h::Assemble*a);
	~Chan();
public:
	struct 8{//<1>:Channel 'Chan' 'entry' state 
/*$GPBS$Chan$8*/
// place your code here
/*$GPBS$*/
	};
public:
	void _send_8();
public:
	8* _get_8(){return &_mes_8;}
private:
	Chan::8  _mes_8;
private:
	enum _state_Iface{
		_st_1,//Channel 'Chan' 'entry' state
		_st_2//Channel 'Chan' terminal state
	};
	enum _sent_Iface{_no_snt,
		_snt_8
	};
private:
	enum _state_Iface _state;
	enum _sent_Iface _sent;
public:
	// access tests for message '8'
	bool _s_in_8(){return _active==SRV && _sent==_snt_8;}
	bool _c_in_8(){return _active==CLI && _sent==_snt_8;}
	bool _s_out_8(){return _active==SRV && (false);}
	bool _c_out_8(){return _active==CLI && (_state==_st_1||false);}
};

//Sample process 'Proc' declaration
class Proc:public gprt.h::Process{
public:
	Proc(gprt.h::Assemble*a);
	~Proc();
private:
	//methods
	//conditions
	bool 6();//Condition 'cond'

/*$GPBS$Proc$!userdata!*/
// place your code here
/*$GPBS$*/

public:
	enum{
		_port_4,//Client side port with type 'Chan'
		_method_3,//Method '3' awaiting 2 messages
		_method_5//Method 'method2' awaiting 1 message
	};
public:
	void _bindPortToChan(int port,gprt.h::Channel*c,gprt.h::Channel::ChanActivity t);
protected:
	virtual bool _run(int _selector);
private:
	// ports
	Chan* _4;//Client side port with type 'Chan'
	// initial activator
	gprt.h::Activator* _entry;
	// internal activators
	gprt.h::Activator* _activate_3_2;
	// synchronization counters
	int _count_3;
};

//Sample assemble 'Asm' declaration
class Asm:public gprt.h::Assemble{
public:
	Asm();
	~Asm();

/*$GPBS$Asm$!userdata!*/
// place your code here
/*$GPBS$*/

public:
	enum{
		//channel factory codes
		Sample_Chan,
		//process factory codes
		Sample_Proc
	};
	void gp_proc(int*p_handle,int code);// process factory
	void gp_chan(int*cli_handle,int*srv_handle,int code);//channel factory
};

}
#endif