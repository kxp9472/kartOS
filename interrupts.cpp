#include"interrupts.h"

interruptManager::interruptManager(){
}

interruptManager::~interruptManager(){
}

void interruptManager::globalActivate()
{

	__asm__("sti");

}

void interruptManager::globalDectivate()
{

	__asm__("cli");
}

void interruptManager::initIntDescTable(uint8_t intNum,void (*handler)(),uint16_t codeSegmentOffset,uint8_t descriptorType,uint8_t descriptorPrivilegeLevel.uint8_t present);
{

	intDescTable[i].handlerLower=(uint16_t)handler & 0xFFFF;
	intDescTable[i].codeSegment=codeSegment;
	intDescTable[i].reserved=0x00;
	intDesctable[i].typeAndDpl=(present<<7)|(descriptorPrivilegeLevel <<5)|(0<<4)|(descriptorType& 0x0F);
	intDescTable[i].handlerUpper=(uint16_t)((handler>>16) & 0xFFFF);

}
