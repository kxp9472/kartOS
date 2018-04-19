#include"types.h"


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
while(1);
}
