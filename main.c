#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <systemd/sd-daemon.h>



int main (char argc, char ** argv) {
	unsigned int count = 5;

	printf("Systemd watchdog example\n");


	while(count--) {
		fprintf(stderr,"pinging watchdog\n");
		sd_notify(0, "WATCHDOG=1");
		sleep(1);
	}

	fprintf(stderr, "Watching pinging is done, service should restart\n");

	while(1){
		sleep(10);
	}

	return 0;


}