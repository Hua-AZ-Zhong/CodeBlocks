#include <stdio.h>
#include <string.h>

int ist_isobit57(char *Buffer)
{
	char *pDE57 = NULL;
	int seg57len=0;
	int tmplen = 0;
	int j = 0;
	int DE57flag = 0;
	int iso_Bit57Len=0;
	char    tmpbuff[10];
	unsigned char   iso_Bit57_tmp[1024];
	memset((char *)iso_Bit57_tmp,0,1024);
	unsigned char   iso_Bit57[1024];
	memset((char *)iso_Bit57,0,1024);
	unsigned char   segbit57buff[1024];
	memset((char *)segbit57buff,0,1024);
	int datalen;
	int datapos=0;

	if(Buffer)
	{

		printf("Txn has segment:BOC_BIT57,set value for field 57.\n");
		memcpy(tmpbuff,Buffer,3);
		tmpbuff[3]='\0';
		iso_Bit57Len=atoi(tmpbuff);
		memcpy(iso_Bit57_tmp,Buffer+3,iso_Bit57Len);
		printf("iso_Bit57_tmp is [%s]\n",iso_Bit57_tmp);

		seg57len = iso_Bit57Len;
		datalen=iso_Bit57Len;

		if(seg57len < 8 && seg57len > 0) /** Modify by zhonghua 2015-09-10 **/
		{
			printf("BOC_BIT57 segment format error,ist_Bit57 length is [%d], iso_Bit57:[%s]\n", seg57len, iso_Bit57_tmp); /** Modify by zhonghua 2015-09-10 **/
			iso_Bit57Len = 0;
			return 0;
		}
		while(datalen>3)
		{
			if(strncmp((char*)iso_Bit57_tmp+datapos,"AS",2) == 0)
			{
				strncpy(tmpbuff, (char *)iso_Bit57_tmp + datapos + 2, 3);
				tmpbuff[3] = '\0';
				tmplen = atoi(tmpbuff);
				j = j+5;
				seg57len = seg57len - 5;
				datapos = datapos + tmplen + 2 + 3;
				memcpy(segbit57buff,iso_Bit57_tmp,datapos);
				datalen = datalen - 5 - tmplen;
				while(1)
				{
					strncpy(tmpbuff, (char *)iso_Bit57_tmp+j, 2);
					j = j+ 2;
					if(strncmp(tmpbuff,"SE",2) == 0 || strncmp(tmpbuff,"IA",2) == 0)
					{
						strncpy(tmpbuff, (char *)iso_Bit57_tmp + j, 3);
						tmpbuff[3] = '\0';
						tmplen = atoi(tmpbuff);
						seg57len = seg57len - 5;
						if(seg57len < tmplen)
						{
							DE57flag = 1;
							break;
						}
						seg57len = seg57len - tmplen;
						j = j+3 + tmplen;
					}
					else
					{
						DE57flag = 1;
					}
					if( DE57flag == 1 || seg57len == 0)
					{
						break;
					}

				}
			}
			/** add by zhonghua 2015-09-10 **/
			else if(strncmp((char*)iso_Bit57_tmp+datapos,"TU",2) == 0)
			{
				strncpy(tmpbuff, (char*)iso_Bit57_tmp + datapos + 2, 3);
				tmpbuff[3] = '\0';
				tmplen = atoi(tmpbuff);
				datapos = datapos + tmplen + 2 + 3;
				memcpy(segbit57buff,iso_Bit57_tmp,datapos);
				datalen = datalen - 5 - tmplen;
			}
			else if(strncmp((char*)iso_Bit57_tmp+datapos,"A8",2) == 0)
			{
				strncpy(tmpbuff, (char*)iso_Bit57_tmp + datapos + 2, 3);
				tmpbuff[3] = '\0';
				tmplen = atoi(tmpbuff);
				datapos = datapos + tmplen + 2 + 3;
				datalen = datalen - 5 - tmplen;
			}
			else
			{
				DE57flag = 1;
				break;
			}
		}
	}
	else
	{
		DE57flag = 1;
	}

	if(DE57flag == 1)
	{
		printf("BOC_BIT57 segment format error,iso_Bit57:[%s]\n",iso_Bit57_tmp); /** Modify by zhonghua 2015-09-10 **/
		iso_Bit57Len = 0;
		return 0;
	}
	int final_de57_len=strlen(segbit57buff);
	memcpy(iso_Bit57,segbit57buff,final_de57_len);
	printf("final iso_Bit57:[%s],length is:[%d]\n",iso_Bit57,final_de57_len);
	return 0;
}

int main()
{
	char BIT57[100];
	int Ret=0;
	memset(BIT57,0x00,100);
	memcpy(BIT57,"025TU003TYNA8005Y7425AO00207",28);
	printf("The Orignal BIT57 is [%s]\n",BIT57);
	Ret=ist_isobit57(BIT57);
	return 0;
}
