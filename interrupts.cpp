#include"interrupts.h"
#include"gdt.h"


interruptManager::gateDescriptor interruptManager::intDescTable[256];
interruptManager::interruptManager(globalDescriptorTable * gdtPtr){
for(int i=0;i<256;i++)
{
	

}

}

interruptManager::~interruptManager()
{
}

void interruptManager::globalActivate()
{

	__asm__("sti");

}

void interruptManager::globalDeactivate()
{

	__asm__("cli");
}

void interruptManager::initIntDescTable(uint8_t intNum,void (*handler)(),
uint16_t codeSegmentOffset,uint8_t descriptorType,uint8_t descriptorPrivilegeLevel,uint8_t present)
{

	intDescTable[intNum].handlerLower=((uint32_t) handler) & 0xFFFF;
	intDescTable[intNum].codeSegment=codeSegmentOffset;
	intDescTable[intNum].reserved=0x00;
	intDescTable[intNum].typeAndDpl=(present<<7)|(descriptorPrivilegeLevel <<5)|(0<<4)|(descriptorType& 0x0F);
	intDescTable[intNum].handlerUpper=((((uint32_t )handler)>>16) & 0xFFFF);

}
