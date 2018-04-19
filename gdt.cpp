
#include "gdt.h"

globalDescriptorTable::globalDescriptorTable():codeSegmentSelector(0,64*1024*1024,0x9A),
		      dataSegmentSelector(0,64*1024*1024,0x92),
		      nullSegmentSelector(0,0,0),
		      unusedSegmentSelector(0,0,0){

uint64_t loadPtr;
loadPtr=(sizeof(globalDescriptorTable)-1)<<16;
loadPtr|=((uint32_t)this)<<32;
__asm volatile("lgdt (%0)"::"p"(((uint8_t*)loadPtr)+2));


}

globalDescriptorTable::~globalDescriptorTable(){
}

globalDescriptorTable::uint16_t codeSegmentSelector(){

return (uint8_t *)&codeSegmentSelector -(uint8_t*)this;
}





globalDescriptorTable::uint16_t dataSegmentSelector(){

return (uint8_t *)&dataSegmentSelector -(uint8_t*)this;
}


globalDescriptorTable::segmentDescriptor::segmentDescriptor(uint32_t abse,uint32_t limit, uint32_t type){
uint16_t gdtEntries[4];
uint16_t flags=0xC0;
gdtEntries[0]= limit & 0xFFFF;
gdtEntries[1]= base & 0xFFFF;
gdtEntries[2]= (base>>16)& 0xFF|(type<<8);
gdtEntries[3]= (limit>>16)& 0x0F|((flags)<<4)|((base>>24)& 0xFF)<<8;

}
