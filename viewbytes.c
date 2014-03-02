// Program viewbytes by Chris Minich

#include <stdio.h>
#include <stdlib.h>

int main(int arg,char *arr[])
	{
	FILE *srcfile;
	srcfile = fopen(arr[1],"r");
	if(srcfile==NULL)
		{
		printf("Cannot open source file.\n");
		exit(10);
		}
	int ch[16];
	int count = 0;
	int mem = 0;
	int i, lastchar;
	printf("%08x  ",mem);
	ch[count] = getc(srcfile);
	while(ch[count] != EOF)
		{
		printf("%02x ", ch[count]);
		if(count == 7) printf(" ");
		count++;
		mem++;
		if(count>15) 
			{
			printf(" |");
			for(i=0; i<16; i++)
				if((ch[i] > 31) && (ch[i] < 127)) printf("%c",ch[i]);
				else printf(".");
			printf("|\n%08x  ",mem);
			count = 0;
			}
		ch[count] = getc(srcfile);
		}
	//print eof character
	lastchar = ch[count];
		
	// if there is a partial line, then finish up:
	if(count > 0)
		{
		while(count < 16)
			{
			printf("   ");
			ch[count] = 32;
			if(count == 7) printf(" ");
			count++;
			}
		printf(" |");
		for(i=0; i<16; i++)
			if((ch[i] > 31) && (ch[i] < 127)) printf("%c",ch[i]);
			else printf(".");
		printf("|\n%08x\n",mem);
		// printf("%d %10x\n", lastchar, lastchar); // eof value in decimal and hex formats
		}
	else printf("\n");
	}
	
