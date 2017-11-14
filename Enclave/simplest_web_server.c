// Copyright (c) 2015 Cesanta Software Limited
// All rights reserved

#include "mongoose.h"
#include <time.h>




static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

unsigned long long readrdtsc(void);
unsigned long long init_readrdtsc(void);
extern unsigned long long microFreq;


extern unsigned long long start_counter;
extern unsigned long long stop_counter;


static void ev_handler(struct mg_connection *nc, int ev, void *p) {
  if (ev == MG_EV_HTTP_REQUEST) {
    mg_serve_http(nc, (struct http_message *) p, s_http_server_opts);

  }

}


#ifdef UNSAFE_COMPILE	
void public_heap_init(unsigned long long, unsigned long long);
#endif



int main(int argc, char* argv[]) {
#ifdef UNSAFE_COMPILE	
	public_heap_init(0x3000000000, 0x100000000-0x1000);
#endif
  //sscanf(argv[2], "%llu", &start_counter);
  //sscanf(argv[3], "%llu", &stop_counter);
  //printf("timer bounds are = %llu, %llu\n", start_counter, stop_counter);
  printf("Entering main\n");
  //microFreq = init_readrdtsc();
  struct mg_mgr mgr;
  struct mg_connection *nc;
  //unsigned long long start_time = readrdtsc();
  mg_mgr_init(&mgr, NULL);
  printf("Starting web server on port %s\n", s_http_port);
  nc = mg_bind(&mgr, s_http_port, ev_handler);
  if (nc == NULL) {
    printf("Failed to create listener\n");
    return 1;
  }

  // Set up HTTP server parameters
  mg_set_protocol_http_websocket(nc);
  s_http_server_opts.document_root = ".";  // Serve current directory
  s_http_server_opts.enable_directory_listing = "yes";

  for (;;) {
    mg_mgr_poll(&mgr, 1000);
    //if(readrdtsc()-start_time >= microFreq * 1000000 * 20)
	//  break;
  }
  mg_mgr_free(&mgr);

  return 0;
}
int sgx_main(int argc, char* argv[]) {
	return main(argc, argv);
}
