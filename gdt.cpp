
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


