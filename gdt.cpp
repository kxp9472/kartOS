
#include "gdt.h"

globalDescriptorTable::globalDescriptorTable():CodeSegmentSelector(0,64*1024*1024,0x9A),
		      DataSegmentSelector(0,64*1024*1024,0x92),
		      nullSegmentSelector(0,0,0),
		      unusedSegmentSelector(0,0,0){

uint64_t loadPtr;
loadPtr=(sizeof(globalDescriptorTable)-1)<<16;
loadPtr|=((uint32_t)this)<<32;
__asm volatile("lgdt (%0)"::"p"(((uint8_t*)loadPtr)+2));


}

globalDescriptorTable::~globalDescriptorTable(){
}

uint16_t globalDescriptorTable::codeSegmentSelector(){

return (uint8_t *)&CodeSegmentSelector -(uint8_t*)this;
}





uint16_t globalDescriptorTable::dataSegmentSelector(){

return (uint8_t *)&DataSegmentSelector -(uint8_t*)this;
}


globalDescriptorTable::segmentDescriptor::segmentDescriptor(uint32_t base,uint32_t limit, uint32_t type){

uint16_t *gdtEntries=(uint16_t*)this;
uint16_t flags;
if(limit<=65535)
{
 flags=0x40;
}
else{
if(limit & 0xFFF !=0xFFF)
	limit=(limit>>12)-1;
else
	limit=limit>>12;
flags=0xC0;



}

gdtEntries[0]= limit & 0xFFFF;
gdtEntries[1]= base & 0xFFFF;
gdtEntries[2]= (base>>16)& 0xFF|(type<<8);
gdtEntries[3]= (limit>>16)& 0x0F|(flags<<4)|((base>>24)& 0xFF)<<8;


}

uint32_t globalDescriptorTable::segmentDescriptor::getBase()
{
	uint32_t result;
	uint8_t * interRes=(uint8_t*)this;
	result=interRes[7]<<24;
	result|=interRes[4]<<16;
	result|=interRes[3]<<8;
	result|=interRes[2];
	return result;






}

uint32_t globalDescriptorTable::segmentDescriptor::getLimit()
{
	uint32_t result;
	uint8_t * interRes=(uint8_t*)this;
	result=(interRes[6] & 0x0F)<<16;
	result|=interRes[1]<<8;
	result|=interRes[0];
	if(interRes[6] & 0xC0 ==0xC0)
		result=(result<<12)|0xFFF;
	return result;





}
