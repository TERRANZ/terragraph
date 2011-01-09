#include "example.h"

namespace Sample{
/*$GPBS$Sample$!globals!*/
// put global variables and funcs here
/*$GPBS$*/
//////////////////////class Chan////////////////////
//Sample channel 'Chan' declaration
Chan::Chan(gprt.h::Assemble*a):gprt.h::Channel(a)
{
	_state=_st_entry;
	_sent=_no_snt;
/*$GPBS$Chan$!constructor!*/
// place your code here
/*$GPBS$*/
}

Chan::~Chan()
{
/*$GPBS$Chan$!destructor!*/
// place your code here
/*$GPBS$*/
}

void Chan::_send_8()
{
	assert( _state==_st_1 || true );
	_sent=_snt_8;
	if(_state==_st_1){_state=_st_end;_active=RTL_SRV;}
	_send();
}

//////////////////////class Proc////////////////////
//Sample process 'Proc' declaration
Proc::Proc(gprt.h::Assemble*a):gprt.h::Process(a)
{
	_4=0;
	_entry=_createActivator();_entry->_send(_method_3);
	_activate_3_2=_createActivator();
	_activate_3_3=_createActivator();
	_activate_3_4=_createActivator();
	_activate_3_5=_createActivator();
	_activate_3_6=_createActivator();
	_activate_3_10=_createActivator();
	_count_3=0;
/*$GPBS$Proc$!constructor!*/
// place your code here
/*$GPBS$*/
}

Proc::~Proc()
{
	delete _entry;
	delete _activate_3_2;
	delete _activate_3_3;
	delete _activate_3_4;
	delete _activate_3_5;
	delete _activate_3_6;
	delete _activate_3_10;
/*$GPBS$Proc$!destructor!*/
// place your code here
/*$GPBS$*/
}

/*$GPBS$Proc$!usercode!*/
// place your code here
/*$GPBS$*/

//Condition 'cond'
bool Proc::6()
{
/*$GPBS$Proc$6*/
// place your code here
	return true;
/*$GPBS$*/
}

void Proc::_bindPortToChan(int port,gprt.h::Channel*c,gprt.h::Channel::ChanActivity t)
{
	if(port==_port_4 && t==gprt.h::Channel::CLI) assert(_4=dynamic_cast<Chan*>(c));
	else assert(0);
}

bool Proc::_run(int _selector)
{
	for(;;){
		switch(_selector){
			case _port_4://Client side port with type 'Chan'
				//Reseiving message from 'port' to '3'
				if(_4->_c_in_message()){_selector=_method_3;break;};
				assert(0);
				return false;
			case _method_3://Method '3' awaiting 2 messages
				if(++_count_3!=2)return true;
				_count_3=0;
				//Condition 'cond'
				if(6()){_selector=_method_5;break;}
				//Sending 'message' back to 'port'
				_4->_send_7();
				//Sending activation message to oneself
				_activate_3_2->_send(Proc::_method_3);
				//
				_activate_3_3->_send(Proc::_method_);
				//
				_activate_3_4->_send(Proc::_method_);
				//
				_activate_3_5->_send(Proc::_method_);
				//
				_activate_3_6->_send(Proc::_method_);
				//
				_->_send_();
				//
				_selector=_method_;break;
				//
				_->_send_();
				//
				_activate_3_10->_send(Proc::_method_);
				return true;
			case _method_5://Method 'method2' awaiting 1 message
				return true;
			default: return false;
		}
	}
}

//////////////////////class Asm////////////////////
//Sample assemble 'Asm' declaration
Asm::Asm(): gprt.h::Assemble()
{
/*$GPBS$Asm$!constructor!*/
// place your code here
/*$GPBS$*/
}

Asm::~Asm()
{
/*$GPBS$Asm$!destructor!*/
// place your code here
/*$GPBS$*/
}

/*$GPBS$Asm$!usercode!*/
// place your code here
/*$GPBS$*/

void Asm::gp_proc(int*p_handle,int code)
{
	if(code==Asm::Sample_Proc){
		*p_handle=_regProc(new Proc(this));
	}else{
		assert(0);
	}
}

void Asm::gp_chan(int*cli_handle,int*srv_handle,int code)
{
	if(code==Asm::Sample_Chan){
		*cli_handle=_regChan(new Chan(this));
		*srv_handle=*cli_handle+1;
	}else{
		assert(0);
	}
}

}