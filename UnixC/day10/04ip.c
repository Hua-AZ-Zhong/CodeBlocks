#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main()
{
	in_addr_t nip;
	char sip[16];
	inet_pton(AF_INET, "192.168.182.10", &nip);
	unsigned char* p = (unsigned char*)&nip;
	int i;
	for(i=0; i<4; i++) printf("%d ",*p++);
	printf("\n");
	inet_ntop(AF_INET, &nip, sip, sizeof(sip));
	puts(sip);
}

