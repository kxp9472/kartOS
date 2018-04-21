/*#include"types.h"
#include"gdt.h"


void printf(char * str)
{
	static uint16_t *opAddress=(uint16_t*)0xb8000;
	for(uint8_t i=0;str[i] !='\0';++i)
	     opAddress[i]=(opAddress[i] & 0xFF00)|str[i];
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;

extern "C" void callConstructors(){

for(constructor * i=&start_ctors;i!=&end_ctors;i++){
	(*i)();
}
}
extern "C" void kernelMain()
{
printf("hello world\n");
globalDescriptorTable gdt;
while(1);
}

*/
#include"types.h"
#include"gdt.h"


void printf(char * str)
{
	static uint8_t x=0,y=0;
	static uint16_t *opAddress=(uint16_t*)0xb8000;
	for(uint8_t i=0;str[i] !='\0';++i)
	{
		switch(str[i]){
		case('\n'):x=0;y++;break;
		default:
			opAddress[80*y+x]=(opAddress[80*y+x] & 0xFF00)|str[i];
			x++;break; }
		if(x==80)
		{
			x=0;y++;
		}
		if(y==25)
		{
			for(x=0;y<80;x++)
			{
				for(y=0;y<25;y++)
				{
				opAddress[80*y+x]=(opAddress[80*y+x] & 0xFF00)|' ';
 				
				}
			}
				x=0;y=0;
		}
	}

}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;

extern "C" void callConstructors(){

for(constructor * i=&start_ctors;i!=&end_ctors;i++){
	(*i)();
}
}
extern "C" void kernelMain()
{
printf("hello world");
printf("kartOS");
globalDescriptorTable gdt;
while(1);
}

