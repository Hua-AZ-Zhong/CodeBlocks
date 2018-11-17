/*
 * SM4/SMS4 algorithm test programme
 * 2012-4-21
 */

#include <string.h>
#include <stdio.h>
#include "sm4.h"

int main()
{
	unsigned char key[16] = {0x30,0x16,0x74,0x5A,0xB2,0x89,0xEF,0xCD,0xBA,0xDC,0xFE,0x03,0x25,0x47,0x69,0x81};
	unsigned char initial_vector[16];
	unsigned char input[16] = {0x01,0x23,0x45,0x67,0x89,0xAB,0xCD,0xEF,0xFE,0xDC,0xBA,0x98,0x76,0x54,0x32,0x10};
	unsigned char mac_block_buffer[64] = {0x30,0x38,0x30,0x30,0x20,0x31,0x30,0x33,0x31,0x31,0x33,0x35,0x35,0x33,0x35,0x20,
										  0x30,0x31,0x34,0x34,0x32,0x36,0x20,0x31,0x34,0x30,0x30,0x30,0x30,0x30,0x30,0x30,
										  0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x20,0x31,0x30,0x31,0x20,0x30,0x38,0x30,0x31,
										  0x30,0x34,0x30,0x30,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
										  //0x30,0x34,0x30,0x30,0x30,0x30};
	unsigned char mac_key[16] = {0x40,0xA1,0x8A,0x29,0xF1,0xA7,0x80,0x62,0x1A,0xC8,0x75,0xC1,0x98,0xD5,0x04,0x34};
	unsigned char asc[] = "123456789";
	int asc_len=0;
	asc_len=strlen(asc);
	char mac_buffer[1024];
	memset(mac_buffer,0x00,1024);
	memcpy(mac_buffer,asc,asc_len);
	memset(mac_buffer+asc_len,0x00,1024-asc_len);
	unsigned char output[16];
	sm4_context ctx;
	unsigned long i;

	/*Display the Encrypt Key*/
	printf("The Clear Encrypt KEY=[");
	for(i=0;i<16;i++)
		printf("%02X", key[i]);
	printf("]\n");
	/*encrypt standard testing vector*/
	sm4_setkey_enc(&ctx,key);
	memset(initial_vector,0x00,16);
	sm4_crypt_ecb(&ctx,1,16,initial_vector,output);
	printf("The Key CheckVal Data=[");
	for(i=0;i<16;i++)
		printf("%02X", output[i]);
	printf("]\n");

	sm4_crypt_ecb(&ctx,1,16,input,output);
	printf("The  Encrypted   Data=[");
	for(i=0;i<16;i++)
		printf("%02X", output[i]);
	printf("]\n");

	/*decrypt testing*/
	sm4_setkey_dec(&ctx,key);
	sm4_crypt_ecb(&ctx,0,16,output,output);
	for(i=0;i<16;i++)
		printf("%02X", output[i]);
	printf("\n");

	/* SM4 MAC Calculate Processing */
	sm4_setkey_enc(&ctx,mac_key);
	memset(initial_vector,0x00,16);
	//sm4_crypt_cbc(&ctx,1,sizeof(mac_block_buffer),initial_vector,mac_block_buffer,output);
	sm4_crypt_cbc(&ctx,1,asc_len,initial_vector,mac_buffer,output);
	printf("The  Encrypted   MAC =[");
	for(i=0;i<16;i++)
		printf("%02X", output[i]);
	printf("]\n");

	#if 0
	/* SM4 CBC Decrypt Processing */
	sm4_setkey_dec(&ctx,mac_key);
	memset(initial_vector,0x00,16);
	sm4_crypt_cbc(&ctx,2,sizeof(mac_block_buffer),initial_vector,mac_block_buffer,output);
	printf("The Decrypted Value=[");
	for(i=0;i<16;i++)
		printf("%02X", output[i]);
	printf("]\n");

	/*decrypt 1M times testing vector based on standards.*/
	i = 0;
	sm4_setkey_enc(&ctx,input);
	while (i<1000000) 
    {
		sm4_crypt_ecb(&ctx,1,16,input,input);
		i++;
    }
	for(i=0;i<16;i++)
		printf("%02X", input[i]);
	printf("\n");
	#endif
	
    return 0;
}
