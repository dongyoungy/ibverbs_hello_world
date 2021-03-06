#include "include.h"
#include "utils.h"
#include "process.h" 
struct benchmark_time __time;
Process::Process(){
}
Process::~Process(){
	if(!client)
		rdma_destroy_id(listener);
	rdma_destroy_event_channel(event_channel);	
	this->reset_message();
}

void Process::initialize(){
	;
}

void Process::run(){
	initialize();
	if(client)
		get_server_address_from_string();
	else
		get_self_address();
	connect();
	event_loop();
}
